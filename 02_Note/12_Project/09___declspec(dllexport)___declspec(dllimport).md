# DLL

## 概念

DLL：Dynamic Link Library，即动态链接库，这种库包含了可由多个程序同时使用的代码和数据。

## 由来

DLL最初用于节约应用程序所需要的磁盘和内存空间。早前，在传统的非共享库中，一部分代码简单地附加到调用的程序中。如果两个程序同时调用同一个子程序，就会出现两份那段代码。相反，许多应用共享的代码能够切分到一个DLL中，在硬盘上存为一个文档，在内存中只需使用一个实例。

## DLL的优缺点

优点：

（1）节省内存和代码重用：当多个程序使用同一个函数库时，DLL可以减少在磁盘和物理内存中加载代码的重复量，且有助于代码的重用。

（2）模块化：DLL有助于促进模块式程序开发。模块化允许仅仅更改几个应用程序共享使用的一个DLL中的代码和数据而不需要更改应用程序自身。这种模块话的基本形式允许如Microsoft Office、Microsoft Visual Studio、甚至windows自身这样大的应用程序 使用较为紧凑的补丁和服务包。

缺点：

DLL Hell：即DLL地狱，指几个应用程序在使用同一个共享的DLL库时发生版本冲突。

究其原因，八个字：成也共用，败也共用。因为DLL Hell正是由于动态链接库可与其他程序共用函数、资源所导致。

主要有两种情况：

设想这样一个场景：程序A会使用1.0版本的动态链接库X，则在程序A安装到系统时，会同时安装该1.0版本的动态链接库X。假设另一个程序B也会使用到动态链接库X，那么程序B直接复制到硬盘中即可正常运行，因为动态链接库已经存在于系统中。然而有一天，另一程序C也要使用动态链接库X，但是由于程序C开发的时间较晚，其需要较新版本---2.0版本的动态链接库X。则在程序C被安装到系统时，2.0版本的动态链接库X 也必须随之安装到系统中，此时系统中1.0版本的动态链接库将被2.0版本所取代（替换）。

情况1：新版本的动态链接库不兼容旧版本。如，A何B需要X所提供的功能，在升级到2.0后，新版本的X竟然把此功能取消了（很难想象吧，呵呵但有时候就是如此....）。则此时虽然C能正常运行，但A和B均无法工作了。

情况2：新版本的动态链接库兼容旧版本，但是存在一个bug。

可看下面的例子（仅仅为了说明问题）：

```c++
// X1.0 version
void func(int count)
{
    if(count < 0)
        count = 0;
    ....
}
 
// X2.0 version
void func(int count)
{
    //负数处理被移除!
    ...
}
```

一旦出现count为负数的情况，则程序A在新版本的处理下就会有问题。
解决办法：Side-by-side Assembly，是windows Xp以及以上系统解决动态链接库版本冲突所使用的技术，重点在于编译程序时，由VS生成一个manifest文件，指明当前应用程序所使用的动态链接库版本号；发布程序时需同时发布该manifest文件，供客户计算机上的DLL Loader根据manifest加载适当版本的DLL，若不发布该项manifest，客户机则按默认版本加载DLL。下图为其典型的场景：

## DLL与lib的关系

咋一看：lib是静态链接库；DLL是动态链接库，一个编译时提供；一个运行时提供，完了。

其实没那么简单！lib也有静态lib和动态lib之分。

静态lib：它将导出声明（后面会讲）和实现均放到lib中，编译后所有代码都嵌入到宿主程序中去。

动态lib：相当于一个h文件，它是对实现部分（.DLL）的导出部分的声明。编译后只是将导出声明部分编译到宿主程序中，运行时需要相应的DLL文件的支持，否则无法工作。当生成一个新的DLL时，也会有配套的lib产生（即二者需一起分发），此时的lib即为动态lib（后面会有还有实验）。

五、如何生成一个DLL
在VC++6.0开发环境下，打开File\New\Project选项，可以选择Win32 Dynamic-Link Library或MFC AppWizard【dll】来以不同的方式创建Non-MFC DLL、Regular DLL、Extension DLL等不同种类的动态链接库。下面以选择Win32 Dynamic-Link Library方式来创建一个DLL（实现加法运算）：

1、创建一个Win32 Dynamic-Link Library方式的空工程，取名为myDLL

2、分别添加头文件(.h)和源文件(.cpp)

```c++
// mydll.h file
extern "C" _declspec(dllexport) int add(int a, int b);
 
//mydll.cpp file
#include "mydll.h"
int add(int a, int b) //该DLL需要导出的函数功能：加法
{
    return a + b;
}
```

说明：
（1）前面的 extern “C” 告诉编译器函数可以在本模块或其他模块中使用，其中“C”表明需按照C语言方式编译和连接它，因为C++编译时，会对函数名进行修饰，用于实现函数重载，而C里面没有这个功能，所以需要用extern "C"在头文件进行声明的时候加以区分，以便链接时能进行正确地函数名查找。

（2）_declspec(dllexport)为导出函数关键字，意为需从DLL中导出该函数，以便使用。

3、编译连接
在进行编译连接后会在Debug目录下找到DLL文件和对应的lib文件

六、如何调用一个DLL
下面实现两种调用方式：单独.dll 和.h + .lib + .dll结合

注：需把对应的 .dll 文件以及.lib 文件和.h文件（结合方式时）拷贝至调用的程序目录下

（1）单纯使用.dll

```c++
#include<wtypes.h>
#include <winbase.h>
#include <iostream>
_declspec(dllimport) int Add(int a, int b); //导入声明，亦可以不加，如果加上可加快程序运行

typedef int(*pAdd)(int a,int b);

int main()
{

    HINSTANCE hDLL;
    pAdd Add;
    hDLL=LoadLibrary("mydll.dll");  //加载 DLL文件
    if(hDLL == NULL)std::cout<<"Error!!!\n";
    Add=(pAdd)GetProcAddress(hDLL,"add");  //取DLL中的函数地址，以备调用

    int a =Add(5,8);
    std::cout<<"a: "<<a<<std::endl;

    FreeLibrary(hDLL);
    return 0;
}

```

（2）.h + .lib + .dll 结合方式

```c++
#include<wtypes.h> 
#include <winbase.h> 
#include <iostream>
#include "mydll.h"
#pragma comment(lib,"mydll.lib")  //将mydll.lib库文件连接到目标文件中（即本工程）
extern "C"_declspec(dllimport) int add(int a,int b);
int main()
{

    int a =add(5,8);
    std::cout<<"a: "<<a<<std::endl;

    return 0;
}
```

输出：

反例演示：此时如果去掉 .dll 文件（即只有.lib 和 .h文件），则会出错：

# __declspec(dllexport) 

`__declspec(dllexport)` 将一个函数声名为导出函数，就是说这个函数要被包含她的程序之外的程序调用。  
`extern "C"` 指示编译器用C语言方法给函数命名。
在制作DLL导出函数时由于C++存在函数重载，因此`__declspec(dllexport)` `function(int,int)` 在DLL会被decorate，例如被decorate成为`function_int_int`，而且不同的编译器`decorate`的方法不同，造成了在用`GetProcAddress`取得`function`地址时的不便，使用extern "C"时，上述的decorate不会发生，因为C没有函数重载，但如此一来被extern"C"修饰的函数，就不具备重载能力，可以说`extern` 和`extern "C"`不是一回事。

# __declspec(dllimport)

我相信写WIN32程序的人，做过DLL，都会很清楚__declspec(dllexport)的作用，它就是为了省掉在DEF文件中手工定义导出哪些函数的一个方法。当然，如果你的DLL里全是C++的类的话，你无法在DEF里指定导出的函数，只能用__declspec(dllexport)导出类。但是，MSDN文档里面，对于__declspec(dllimport)的说明让人感觉有点奇怪，先来看看MSDN里面是怎么说的：

不使用 `__declspec(dllimport)` 也能正确编译代码，但使用`__declspec(dllimport)` 使编译器可以生成更好的代码。编译器之所以能够生成更好的代码，是因为它可以确定函数是否存在于 `DLL` 中，这使得编译器可以生成跳过间接寻址级别的代码，而这些代码通常会出现在跨 DLL 边界的函数调用中。但是，必须使用`__declspec(dllimport)`才能导入`DLL`中使用的变量。

初看起来，这段话前面的意思是，不用它也可以正常使用DLL的导出库，但最后一句话又说，必须使用`__declspec(dllimport)`才能导入 DLL 中使用的变量这个是什么意思？？

那我就来试验一下，假定，你在DLL里只导出一个简单的类，注意，我假定你已经在项目属性中定义了 SIMPLEDLL_EXPORT

```c++
SimpleDLLClass.h

#ifdef SIMPLEDLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
class DLL_EXPORT SimpleDLLClass
{
public:
SimpleDLLClass();
virtual ~SimpleDLLClass();
virtual getValue() { return m_nValue;};
private:
int m_nValue;
};
SimpleDLLClass.cpp

#include "SimpleDLLClass.h"
SimpleDLLClass::SimpleDLLClass()
{
m_nValue=0;
}
SimpleDLLClass::~SimpleDLLClass()
{
}
```

然后你再使用这个DLL类，在你的APP中`include SimpleDLLClass.h`时，你的APP的项目不用定义`SIMPLEDLL_EXPORT`所以，`DLL_EXPORT` 就不会存在了，这个时候，你在APP中，不会遇到问题。这正好对应MSDN上说的__declspec(dllimport)定义与否都可以正常使用。但我们也没有遇到变量不能正常使用呀。 那好，我们改一下SimpleDLLClass,把它的m_nValue改成static,然后在cpp文件中加一行

```c++
int SimpleDLLClass::m_nValue=0;
```

改完之后，再去LINK一下，你的APP，看结果如何， 结果是LINK告诉你找不到这个m_nValue。明明已经定义了，为什么又没有了？？ 肯定是因为我把m_nValue定义为static的原因。但如果我一定要使用Singleton的Design Pattern的话，那这个类肯定是要有一个静态成员，每次LINK都没有，那不是完了？ 如果你有Platform SDK，用里面的Depend程序看一下，DLL中又的确是有这个m_nValue导出的呀。
再回去看看我引用MSDN的那段话的最后一句。 那我们再改一下`SimpleDLLClass.h`，把那段改成下面的样子:

```c++
#ifdef SIMPLEDLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
```

再LINK，一切正常。原来dllimport是为了更好的处理类中的静态成员变量的，如果没有静态成员变量，那么这个__declspec(dllimport)无所谓。