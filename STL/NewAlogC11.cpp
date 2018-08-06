/*
 * NewAlogC11.cpp
 *
 *  Created on: 2018年6月7日
 *      Author: Administrator
 *
 *      http://www.cnblogs.com/qicosmos/p/3960304.html
 */




/*
 *
 * all_of:检查区间[first, last)中是否所有的元素都满足一元判断式p，所有的元素都满足条件返回true，否则返回false。
any_of：检查区间[first, last)中是否至少有一个元素都满足一元判断式p，只要有一个元素满足条件就返回true，否则返回true。
none_of：检查区间[first, last)中是否所有的元素都不满足一元判断式p，所有的元素都不满足条件返回true，否则返回false。
 *
 *   算法库的查找算法新增了一个find_if_not，它的含义和find_if是相反的，即查找不符合某个条件的元素，find_if也可以实现find_if_not的功能，
 *   只需要将判断式改为否定的判断式即可，现在新增了find_if_not之后，就不需要再写否定的判断式了，可读性也变得更好
 *
 *
 * 　算法库还增加了一个copy_if算法，它相比原来的copy算法多了一个判断式，用起来更方便了，下面是它的基本用法：
 *
 *   算法库新增了iota用来方便的生成有序序列，比如我们需要一个定长数组，
 *   这个数组中的元素都是在某一个数值的基础之上递增的，那么用iota可以很方便的生成这个数组了
 *
 *
 *   算法库还新增了一个同时获取最大值和最小值的算法minmax_element，这样我们如果想获取最大值和最小值的时候就不用分别调用max_element和max_element算法了，
 *   用起来会更方便，minmax_element会将最小值和最大值的迭代器放到一个pair中返回，下面是它的基本用法
 *
 *
 *    算法库新增了is_ sorted和is_ sorted_until算法，is_sort用来判断某个序列是否是排好序的，
 *    is_sort_until则用来返回序列中前面已经排好序的部分序列
 * */
