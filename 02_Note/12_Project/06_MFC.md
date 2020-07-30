# MFC学习

## DECLARE_MESSAGE_MAP()

只要当前类是**CCmdTarget**派生的，则必须提供**消息映射**以处理消息。
> 类CCmdTarget是MFC类库中消息映射体系的一个基类，是MFC处理命令消息的基础、核心。消息映射把命令或消息引导给用户为之编写的响应函数。

代码|位置与作用
---|---
DECLARE_MESSAGE_MAP|在类或者结构体末尾-声明消息映射
BEGIN_MESSAGE_MAP|在定义类成员函数的.CPP-开始和终止消息映射

具体方式是在类或者结构体末尾添加DECLARE_MESSAGE_MAP（无分号），然后在定义类成员函数的.CPP文件中，使用BEGIN_MESSAGE_MAP（）宏和 END_MESSAGE_MAP（）宏来实现对消息的处理。

在你的类的成员函数的实现文件（.CPP）中，使用BEGIN_MESSAGE_MAP宏开始消息映射，然后为**每个消息处理函数加入一个入口**，最后用END_MESSAGE_MAP宏结束消息映射。

每个**消息映射入口**的格式如下：
ON_Notification(id, memberFxn)
其中id指定了发送通知的控件的子窗口的ID，而memberFxn指定了处理该通知的父对象中的成员函数名。
父对象的函数原型格式如下：
afx_msg void memberFxn( );


ON_COMMAND是MFC提供的宏，实现命令消息（如菜单、工具栏的选项消息）的消息响应函数的**注册**。
使用方法为ON_COMMAND（消息ID, 响应函数名）
注册了响应函数之后，一旦主窗口接收到该命令消息，程序就会调用我们提供的消息响应函数进行处理