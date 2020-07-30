<!-- TOC -->

- [2. Mat的方法](#2-mat的方法)
  - [2.1. 下面介绍几种常见的创建方式](#21-下面介绍几种常见的创建方式)
  - [2.2. Mat数据的输出](#22-mat数据的输出)
  - [2.3. Mat数据的读取和遍历](#23-mat数据的读取和遍历)
- [3. 矩阵数据类型](#3-矩阵数据类型)

<!-- /TOC -->

属性|说明
---|---
data|uchar型的指针。Mat类分为了两个部分:矩阵头和指向矩阵**数据部分**的**指针**，data就是指向矩阵数据的指针。
dims|矩阵的**维度**，例如5*6矩阵是二维矩阵，则dims=2，三维矩阵dims=3.
rows|矩阵的**行**数
cols|矩阵的**列**数
size|矩阵的大小，size(**cols**,**rows**)
channels()|矩阵元素拥有的**通道数**，例如常见的彩色图像，每一个像素由RGB
type()|表示了矩阵中元素的类型以及矩阵的通道个数，它是一系列的预定义的常量，其命名规则为CV_(**位数**）+（**数据类型**）+（**通道数**）如：,CV_8UC3
depth()|矩阵中元素的一个通道的数据类型，这个值和type是相关的。例如 type为 CV_8UC**3**，一个3通道的**16位**的有符号整数。那么，depth则是CV_8UC
elemSize()|矩阵一个元素占用的字节数(不区分通道，即多个通道的总和)
elemSize1()|矩阵一个元素**每个通道**占用的字节数(区分通道，单个个通道的值)
flags|一个int型数字，保存了许多有用的信息，flags说明

# 2. Mat的方法

## 2.1. 下面介绍几种常见的创建方式

1、Mat M  
创建一个矩阵头，没有数据。  
2、Mat M(2,2,CV_8UC3,Scalar(0,0,1));  
2*2大小的矩阵，每个元素为3通道8位无符号整数，如下：  
0 0 1 0 0 1  
0 0 1 0 0 1  
3、Mat M(2,2,CV_8UC1,Scalar(10));  
与上面类似：  
10 10  
10 10  
4、Mat M(2,2,CV_8UC1,Scalar::all(0));  
数据全为0；  
5、Mat M = (Mat_(3,3) << 1,2,3,4,5,6,7,8,9);  
初始化赋值  
注意问题：Mat可以通过row(),col()函数来访问每一行每一列，Mat结构可以通过clone(),copyTo()函数进行复制，直接赋值的话只会把新Mat的data指向原来Mat的data，而不会重新创建一个数据域；  

除此之外，Mat还有一些常见的函数用来创建和初始化矩阵：  
Mat E = Mat::eye(4,4,CV_64F);  
Mat Z = Mat::zeros(4,4,CV_32F);  
Mat O = Mat::ones(4,4,CV_8UC1);  
分别用来创建一个4*4的单位矩阵，全0矩阵，全1矩阵，类似于Matlab中的矩阵创建。  

## 2.2. Mat数据的输出  

在vs中Mat输出数据很方便，直接用cout 就可以数据Mat中的数据了，还包括了一些不同的输出格式。可以通过format（Mat，“ ”）函数来实现，“ ”中不同的值代表不同的输出格式：C，python，csv，numpy，默认的格式与matlab相同。

## 2.3. Mat数据的读取和遍历

由于Mat主要用来存放图像数据，因此这里不详细说明其数据的遍历方法，具体的方法可以看下一篇OpenCV-图像的基本操作；  

下面为Mat创建矩阵的相关测试代码：

```c++
#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;  

int main()
{
    Mat E = Mat::eye(4,4,CV_64F);
    Mat Z = Mat::zeros(4,4,CV_32F);
    Mat O = Mat::ones(4,4,CV_8UC1);
    cout << "E:\n" << E << endl;
    cout << "Z:\n" << Z << endl;
    cout << "O:\n" << O << endl;

    Mat M(2,2,CV_8UC3,Scalar(0,0,1));
    Mat M1(2,2,CV_8UC1,Scalar::all(0));
    Mat M2;
    M2.create(2,2,CV_8UC1);
    Mat M3 = (Mat_<double>(3,3) << 1,2,3,4,5,6,7,8,9);
    Mat M4 = M3.row(1);
    Mat M5(5,5,CV_8UC1,Scalar(10));

    cout << "M:\n" << M << endl;
    cout << "M1:\n" << M1 << endl;
    cout << "M2:\n" << M2 << endl;
    cout << "M3:\n" << M3 << endl;
    cout << "M4:\n" << M4 << endl;
    cout << "M4(Format C):\n" << format(M4,"C") << endl;    //不同形式的输出
    cout << "M5:\n" << M5 << endl;

    waitKey(0);
    return 0;
}
```

# 3. 矩阵数据类型

CV_<bit_depth>(S|U|F)C<number_of_channels>

S = 符号整型 U = 无符号整型 F = 浮点型

例：

CV_8UC1 是指一个8位无符号整型单通道矩阵,

CV_32FC2是指一个32位浮点型双通道矩阵

CV_8UC1 CV_8SC1 CV_16U C1 CV_16SC1
CV_8UC2 CV_8SC2 CV_16UC2 CV_16SC2
CV_8UC3 CV_8SC3 CV_16UC3 CV_16SC3
CV_8UC4 CV_8SC4 CV_16UC4 CV_16SC4
CV_32SC1 CV_32FC1 CV_64FC1
CV_32SC2 CV_32FC2 CV_64FC2
CV_32SC3 CV_32FC3 CV_64FC3
CV_32SC4 CV_32FC4 CV_64FC4

**其中，通道表示每个点能存放多少个值，类似于RGB彩色图中的每个像素点有三个值，即三通道的。

图片中的深度表示每个值由多少位来存储，是一个精度问题，一般图片是8bit（位）的，那么深度是8。**