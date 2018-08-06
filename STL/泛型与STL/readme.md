本书第一篇 需要详细阅读

concept  概念  是一系列条件的集合

比如 Iterator 是一个概念的实现，加入此概念是概念A.
那么 iterator 要满足 概念A的一些列条件。
比如可以自己定义一个myIt，只需要这个myIt 能够满足概念A.就可以了

Iterator包含了不同类型的迭代器。
这些迭代器之间有一些关系。
比如 Input Iterator ，除了满足一般化的Iterator的条件之外，还需要满足一些额外的条件。

input iterator 只读性
output iterator : 具有只写性 *it=x 具有 inset_iterator
forward iterator
const iterator 
multa iterator 

bidirection  iterator
radom iterator 

Refinement(),用来描述概念之间的关系。
比如concept2 能够满足 concept1的所有能够，所有使用场合。并且concept2 还有一些独特的功能
那么concept2是concept1的 refinement

Associated Type
一些泛型 T ,需要满足于一些表达式，这个时候这个T才能用作 一个concept的参数

iterator会指向某物，这个东西的类型就是Associated type

本书3.1主要讲这个：
iterator_traits 存在的作用与意义  
https://blog.csdn.net/virtual_func/article/details/48398451  

template<class Iterator>  
struct iterator_traits  
{  
    typedef typename Iterator::value_type       value_type;  
    typedef typename Iterator::difference_type  difference_type;  
    typedef typename Iterator::reference_type   reference_type;  
    typedef typename Iterator::point_type       point_type;  
    typedef typename Iterator::iterator_category    iterator_category;  
};  


函数 适配器：
用一个函数定义另外一个函数时，可以使用：
比如 定义一个判断是不是偶数的函数，
那么不需要再定义个是不是奇数的函数，只需要用函数适配器 讲判断偶数的函数，适配一下就可以了

这个时候，就会用到 函数对象的argument_type  result_type等  定义。



stl中概念 的意思   概念是一系列条件的组合
