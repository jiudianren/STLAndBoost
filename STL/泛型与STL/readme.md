�����һƪ ��Ҫ��ϸ�Ķ�

concept  ����  ��һϵ�������ļ���

���� Iterator ��һ�������ʵ�֣�����˸����Ǹ���A.
��ô iterator Ҫ���� ����A��һЩ��������
��������Լ�����һ��myIt��ֻ��Ҫ���myIt �ܹ��������A.�Ϳ�����

Iterator�����˲�ͬ���͵ĵ�������
��Щ������֮����һЩ��ϵ��
���� Input Iterator ����������һ�㻯��Iterator������֮�⣬����Ҫ����һЩ�����������

input iterator ֻ����
output iterator : ����ֻд�� *it=x ���� inset_iterator
forward iterator
const iterator 
multa iterator 

bidirection  iterator
radom iterator 

Refinement(),������������֮��Ĺ�ϵ��
����concept2 �ܹ����� concept1�������ܹ�������ʹ�ó��ϡ�����concept2 ����һЩ���صĹ���
��ôconcept2��concept1�� refinement

Associated Type
һЩ���� T ,��Ҫ������һЩ���ʽ�����ʱ�����T�������� һ��concept�Ĳ���

iterator��ָ��ĳ�������������;���Associated type

����3.1��Ҫ�������
iterator_traits ���ڵ�����������  
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


���� ��������
��һ��������������һ������ʱ������ʹ�ã�
���� ����һ���ж��ǲ���ż���ĺ�����
��ô����Ҫ�ٶ�����ǲ��������ĺ�����ֻ��Ҫ�ú��������� ���ж�ż���ĺ���������һ�¾Ϳ�����

���ʱ�򣬾ͻ��õ� ���������argument_type  result_type��  ���塣



stl�и��� ����˼   ������һϵ�����������
