# containers
![containers](pic/02_containers_vector.png)

关于vector，是一个**动态增长**的数组，有一个指针指向**一片连续**的内存空间，当空间装不下的时候会自动申请一片更大的空间（空间配置器）将原来的数据拷贝到新的空间，然后就会释放旧的空间。当删除的时候空间并不会被释放只是清空了里面的数据。