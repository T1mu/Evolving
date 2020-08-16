# template函数

```c++
template <temptype type>ret-type funcName(parameter list)
```
实现一个模板函数的代码:
```c++
#include <stdafx.h>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
T const& Max(T const& a, T const& b){
	return a > b ? a : b;
}

int main()
{
	int a = 3;
	int b = 4;
	cout << " Max(a, b) " << Max(a, b) << endl;
	double c = 2.0;
	double d = 3.1415926;
	cout << " Max(c, d) " << Max(c, d) << endl;
	string e = "123";
	string f = "124";
	cout << " Max(e, f) " << Max(e, f) << endl;

	return 0;
}
```
控制台输出的信息:
```
 Max(a, b) 4
 Max(c, d) 3.14159
 Max(e, f) 124
请按任意键继续. . .
```

# template类
模板类声明定义格式的代码:
```c++
template <class type> class className{
    ```
}
```
模板类的使用:
```c++
//类的声明
template <class T> class Stack{
private:
    vector<T> elems;
public:
    void push(const T&);
    void pop();
    T const& top();
    bool isEmpty();
}
//类方法的定义
template<class T>
void Stack<T>::push(const T& elem){
    elems.push_back(elem);
}
template<class T>
void Stack<T>::pop(){
    if(isEmpty())
        throw out_of_range("Stack<>::pop: empty stack");
    else
        elems.pop_back();
}
template<class T>
T const& Stack<T>::top(){
    if(isEmpty())
        throw out_of_range("Stack<>::top: empty stack");
    else
        return elems.back();
}
template<class T>
bool Stack<T>::isEmpty(){
    if(elems.empty())
        return true;
    else
        return false;
}
//main函数
int main(){
    try{
        Stack<int> intStack;
        Stack<string> stringStack;
        intStack.push(9573);
        cout<<"intStack.top():"<<intStack.top()<<endl;
        cout<<"stringStack.isEmpty():"<<stringStack.isEmpty()<<endl;
        intStack.pop();
        intStack.top();
        stringStack.pop();
    }
}
```
控制台输出的结果信息:
```
intStack.top():9573
stringStack.isEmpty():1
Exception:Stack<>::pop: empty stack
请按任意键继续. . .
```