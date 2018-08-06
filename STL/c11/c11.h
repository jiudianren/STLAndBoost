

#ifndef C11_H_
#define C11_H_

/*
 * 如果不支持c++11 ,则退出编译
 *
 * */

#if __cplusplus < 201103L
    #error "should use c++11 implementation"
#endif

#endif /* SKIPLIST_H_ */
