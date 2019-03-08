

参考：
more effetive c++ 侯捷  Item M29：引用计数


https://www.cnblogs.com/cycxtz/p/4742970.html



https://www.cnblogs.com/KillerAery/p/9096558.html

https://www.cnblogs.com/wxquare/p/4759020.html


注意：
虽然本文简单介绍了auto_ptr。
但是不要用auto_ptr! 不要用auto_ptr!

虽然它是c++11以前的最原始的智能指针，但是在c++11中已经被弃用（使用的话会被警告）了。
它的替代品，也就是c++11新智能指针unique_ptr,shared_ptr,weak_ptr将在下文出现




针对空悬指针问题：

空悬指针问题是指：无法知道指针指向的堆内存是否已经释放。

得益于引入的weak_count,weak_ptr指针可以使计数区域的生命周期受weak_ptr控制，

从而能使weak_ptr获取 被管理资源的shared计数，从而判断被管理对象是否已被释放。（可以实时动态地知道指向的对象是否被释放,从而有效解决空悬指针问题）

它的成员函数expired()就是判断指向的对象是否存活。