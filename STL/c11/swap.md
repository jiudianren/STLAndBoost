#C++11之前的swap

先看swap的实现：


	template<classT>void swap ( T& a, T& b ){　 T c(a); a=b; b=c;}

下面结合示例代码看看发生了什么。

当swap调用了T C(a)的时候，实际上是调用了拷贝构造函数，当swap代码调用了赋值操作时，实际上是调用了赋值运算符。

由于拷贝构造函数和赋值运算符包含内存拷贝操作，而这样的操作共执行了三次，所以在一个swap中一共存在三次内存拷贝操作。这种不必要的内存操作很多情况下都会影响C++的执行效率。

#C++11之后的swap

引入了右值引用和数据移动的概念之后，代码变成下面的样子：

	template<classT>void swap (T& a, T& b){　 T c(std::move(a)); a=std::move(b); b=std::move(c);}

由于std::move将变量类型转换为右值引用，TestData有机会提供下面针对右值引用的构造函数和赋值运算符。

TestData(TestData&& d)　 :size(d.size)　 ,data(d.data){　 d.size=0;　 d.data=nullptr;}TestData&operator=(const　TestData&& d){　 size=d.size;　 data=d.data;　 return*this;}

由于代码中使用内存移管代替了不必要的内存拷贝，因此效率会大大提高。

