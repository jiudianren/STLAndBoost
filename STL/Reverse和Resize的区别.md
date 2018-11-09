vector的reserve和resize以及capacity和size

https://blog.csdn.net/u014082714/article/details/44221369

	
	1.capacity 指容器在不分配新的存储空间的前提下它最多可以保存多少元素。
	2. size 指当前容器已经保存的元素的数目。


在弄清这两个概念以后，很容易懂resize和reserve的区别:

vector 的reserve增加了vector的capacity，但是它的size没有改变！而resize改变了vector的capacity同时也增加了它的size！

原因如下：
  
	reserve是容器预留空间，但在空间内不真正创建元素对象，所以在没有添加新的对象之前，不能引用容器内的元素。
    
 加入新的元素时，要调用push_back()/insert()函数。c.reserve(n)指分配至少能容纳n个元素的内存空间。

	resize是改变容器的大小，且在创建对象。
  
   因此，调用这个函数之后，就可以引用容器内的对象了，因此当加入新的元素时，用operator[]操作符，或者用迭代器来引用元素对象。此时再调用push_back()函数，是加在这个新的空间后面的。
 
  两个函数的参数形式也有区别的:
  
	 reserve函数之后一个参数，即需要预留的容器的空间；
	 resize函数可以有两个参数，第一个参数是容器新的大小， 第二个参数是要加入容器中的新元素，如果这个参数被省略，那么就调用元素对象的默认构造函数。

