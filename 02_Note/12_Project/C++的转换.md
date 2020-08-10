
# 隐式类型转换

又称为“标准转换”，包括以下几种情况：

## 算术转换(Arithmetic conversion) : 在混合类型的算术表达式中, 最宽的数据类型成为目标转换类型。

```c++
int ival = 3;
double dval = 3.14159;
```

ival + dval;//ival被提升为double类型

## 一种类型表达式赋值给另一种类型的对象：目标类型是被赋值对象的类型

```c++
int *pi = 0; // 0被转化为int *类型
ival = dval; // double->int
```

例外：void指针赋值给其他指定类型指针时，不存在标准转换，编译出错

## 将一个表达式作为实参传递给函数调用，此时形参和实参类型不一致：目标转换类型为形参的类型

```c++
extern double sqrt(double); //Square Root 平方根

cout << "The square root of 2 is " << sqrt(2) << endl;
//2被提升为double类型：2.0
```

## 从一个函数返回一个表达式，表达式类型与返回类型不一致：目标转换类型为函数的返回类型

```c++
double difference(int ival1, int ival2)
{
    return ival1 - ival2;
    //返回值被提升为double类型
}
```