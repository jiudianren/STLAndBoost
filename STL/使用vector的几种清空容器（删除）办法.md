https://blog.csdn.net/u012580994/article/details/43932701

vector <int> vecInt;
    for (int i=0;i<500;i++)
    {
        vecInt.push_back(i);
    }
    int j= vecInt.capacity();   //j=512
    i = vecInt.size();          //i=500            

��һ�ְ취ʹ�� clear �����Ԫ�أ��������տռ�
    vecInt.clear();
    j= vecInt.capacity();      //j=512
    i = vecInt.size();         //i=0

�ڶ��ְ취ʹ�� eraseѭ��ɾ�������ͬ��
vector <int>::iterator iter=vecInt.begin();
    for ( ;iter!=vecInt.end();)
    {
        iter=vecInt.erase(iter);
    }
    j= vecInt.capacity();      //j=512
    i = vecInt.size();         //i=0        
erase��ÿ�β���ʱ��������ָ�������ǰ��1������ÿ�ζ��ᡰ�ᡱȫ�����ݣ�����vector���ʺ���Ƶ��ɾ��������

�����ְ취 ��򵥵�ʹ��swap,���Ԫ�ز������ڴ�
    vector <int>().swap(vecInt);  //�����������С������������
//   vecInt.swap(vector<int>()) ;     ��һ��д��
    j= vecInt.capacity();       //j=0  
    i = vecInt.size();          //i=0        
���������vector <int>(vecInt).swap(vecInt)�ı��������һ�½�������csdn��

std::vector<T>(v).swap(v);�������൱�ڣ�    
  {   
  std::vector<T>   temp(v);//1   
  temp.swap(v);//2   
  }   
  ��һ�����һ����v����һģһ����vector��ֻ����temp��������ǡ���������С��   
  �ڶ����v��temp����   
  Ȼ��temp���Զ���������   

  ����д�������ǣ���v��������С�����ֵ
