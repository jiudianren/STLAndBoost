什么是 Coroutine？
Coroutine 可以被翻译为协程，它与 Subroutine（子程序）有什么区别呢？其实我们绝大多数接触到的函数也好，方法也好，都是 Subroutine 的一种，它的特点就是，子程序从函数入口开始，一直到 return 语句结束，也就是说，一旦子程序返回了，它这一阶段的所有使命就完成了。

而 Coroutine 是一种可以与其他 Coroutine 或 Subroutine 交叉运行的程序，这也是为什么 Coroutine 叫做 Coroutine 的原因了，一般来讲，一段 Coroutine 也会存在一个返回语句（通常叫做 yield），一旦执行到此语句，Coroutine 就会保存上下文并且将控制权交出（睡眠），此时调用这段 Coroutine 的 whatever-routine 就会『拿到 CPU 的控制权』，并且得到 yield 出来的变量，一旦时机成熟，刚才睡眠的 Coroutine 就又可以原地复苏，从刚才暂停下来的 yield 语句继续向下执行，直到 return 才彻底结束。

它与线程有什么关系？
我不知道是不是中文名字相近的缘故，很多人认为协程一定意义上意味着多线程。OK，我可以告诉大家，『Coroutine』 与 『Thread』 没有半毛钱的关系，它们的关系可以说就是：


https://zhuanlan.zhihu.com/p/25979906

Boost coroutine 协程

https://blog.csdn.net/zrs19800702/article/details/52816064

c++中boost协程5种使用实例
https://blog.csdn.net/shixin_0125/article/details/78848431


https://blog.csdn.net/racaljk/article/details/78507498