# OpenCV Mat数据类型指针ptr的使用

```c++
cv::Mat img = cv::Mat(327,957,CV_8UC1);
uchar *data00 = img.ptr<uchar>(0);
uchar *data10 = img.ptr<uchar>(1);
uchar *data01 = img.ptr<uchar>(0)[1];
```

- 定义了Mat实例img
- data00是指向img的第一行第一个元素的指针
- data10是指向img的第二行第一个元素的指针
- data01是指向img的第一行第二个元素的指针