https://blog.csdn.net/u012580994/article/details/43932701

vector <int> vecInt;
    for (int i=0;i<500;i++)
    {
        vecInt.push_back(i);
    }
    int j= vecInt.capacity();   //j=512
    i = vecInt.size();          //i=500            

第一种办法使用 clear ，清空元素，但不回收空间
    vecInt.clear();
    j= vecInt.capacity();      //j=512
    i = vecInt.size();         //i=0

第二种办法使用 erase循环删除，结果同上
vector <int>::iterator iter=vecInt.begin();
    for ( ;iter!=vecInt.end();)
    {
        iter=vecInt.erase(iter);
    }
    j= vecInt.capacity();      //j=512
    i = vecInt.size();         //i=0        
erase在每次操作时，迭代器指针会整体前移1，就是每次都会“搬”全部数据，所以vector不适合做频繁删除的容器

第三种办法 最简单的使用swap,清除元素并回收内存
    vector <int>().swap(vecInt);  //清除容器并最小化它的容量，
//   vecInt.swap(vector<int>()) ;     另一种写法
    j= vecInt.capacity();       //j=0  
    i = vecInt.size();          //i=0        
该语句是由vector <int>(vecInt).swap(vecInt)的变体而来，一下解释引自csdn：

std::vector<T>(v).swap(v);的作用相当于：    
  {   
  std::vector<T>   temp(v);//1   
  temp.swap(v);//2   
  }   
  第一句产生一个和v内容一模一样的vector，只不过temp的容量是恰好满足其大小的   
  第二句把v和temp交换   
  然后temp就自动解析掉了   

  这样写的作用是：把v的容量缩小到最佳值
