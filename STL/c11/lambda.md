
�﷨���⣺

	[= 1] ( 2 ) mutable3  throw 4 ->int 5
	{
		6
	}
	

1. Capture �Ӿ䣨�� C++ �淶��Ҳ��Ϊ lambda ��������
2. �����б���ѡ���� ��Ҳ��Ϊ lambda ������)
3. �ɱ�淶����ѡ����
4. �쳣�淶����ѡ����
5. β�淵�����ͣ���ѡ����
6. ��lambda �塱


##1. Capture  
Lambda �����������������µı������� C++14�����������Է��ʣ��򡰲��񡱣��ܱ߷�Χ�ڵı�����   
Lambda �� Capture �Ӿ䣨��׼�﷨�е� lambda ��������ͷ��
��ָ��Ҫ����ı����Լ���ͨ��ֵ�������ý��в��� 
����� (&) ǰ׺�ı���ͨ�����÷��ʣ�û�и�ǰ׺�ı���ͨ��ֵ���ʡ�
�� capture �Ӿ� [ ] ָʾ lambda ���ʽ�����岻���ʷ�շ�Χ�еı�����
����ʹ��Ĭ�ϲ���ģʽ����׼�﷨�е� capture-default����ָʾ��β��� lambda �����õ��κ��ⲿ������
    
    [&] ��ʾͨ�����ò������õ����б������� [=] ��ʾͨ��ֵ�������ǡ�
    
 ����ʹ��Ĭ�ϲ���ģʽ��Ȼ��Ϊ�ض�������ʽָ���෴��ģʽ��
 
  ���磬��� lambda ��ͨ�����÷����ⲿ���� total ��ͨ��ֵ�����ⲿ���� factor�������� capture �Ӿ��Ч��
  	
	[&total, factor]
	[factor, &total]
	[&, factor]
	[factor, &]
	[=, &total]
	[&total, =]
	
	
ʹ�� capture-default ʱ��ֻ�� lambda ���ἰ�ı����Żᱻ����    
��� capture �Ӿ���� capture-default&����� capture �Ӿ�� identifier ��û���κ� capture �ɲ��� & identifier ��ʽ��      
 ͬ������� capture �Ӿ���� capture-default=����� capture �Ӿ�� capture ���ܲ��� = identifier ��ʽ��   
  identifier �� this �� capture �Ӿ��г��ֵĴ������ܳ���һ�Ρ�
   ���´���Ƭ�θ�����һЩʾ����
   
   
    struct S { void f(int i); };
	void S::f(int i) {
	[&, i]{}; // OK
	[&, &i]{}; // ERROR: i preceded by & when & is the default
	[=, this]{}; // ERROR: this when = is the default
	[i, i]{}; // ERROR: i repeated
	}
	
capture ���ʡ�Ժ��ǰ���չ�������¿ɱ����ģ��ʾ������ʾ��
 
 
	template<class... Args>
	void f(Args... args) {
	 auto x = [args...] { return g(args...); };
	 x();
	}
	
	
Ҫ���෽����������ʹ�� lambda ���ʽ���뽫 this ָ�봫�ݸ� Capture �Ӿ䣬���ṩ�Է����ķ��������ݳ�Ա�ķ���Ȩ�ޡ�   
�й�չʾ��ν� lambda ���ʽ���෽��һ��ʹ�õ�ʾ��������� Lambda ���ʽ��ʾ���еġ�ʾ�����ڷ�����ʹ�� Lambda ���ʽ����
��ʹ�� capture �Ӿ�ʱ���������ס���¼��㣨������ʹ�ò�ȡ���̵߳� lambda ʱ����

	���ò���������޸��ⲿ��������ֵ����ȴ����ʵ�ִ˲����� ��mutable�����޸ĸ������������޸�ԭʼ���
	���ò���ᷴӳ�ⲿ�����ĸ��£���ֵ����ȴ���ᷴӳ��
	���ò��������������������ֵ����ȴû������������� �� lambda ���첽��ʽ����ʱ����һ��������Ҫ�� ������첽 lambda ��ͨ�����ò��񱾵ر������ñ��ر������ܿ����� lambda ����ʱ��ʧ���Ӷ���������ʱ���ʳ�ͻ��

ͨ�ò��� (C++14)
�� C++14 �У����� Capture �Ӿ������벢��ʼ���µı�����������ʹ��Щ���������� lambda �����ķ�շ�Χ�ڡ�
 ��ʼ�������κ�������ʽ��ʾ���ҽ��Ӹñ��ʽ���ɵ������Ƶ��±��������͡�
  �˹��ܵ�һ���ô��ǣ��� C++14 �У��ɴ��ܱ߷�Χ����ֻ�ƶ��ı��������� std::unique_ptr������ lambda ��ʹ�����ǡ�
  
  
  
# 2 �����б�
���˲��������lambda ���ɽ������������ �����б��ڱ�׼�﷨�г�Ϊ lambda ���������ǿ�ѡ�ģ����ڴ�������������ں����Ĳ����б�

	auto y = [] (auto first, auto second)
	{
	 return first + second;
	};
	


lambda ���ʽ���Խ���һ�� lambda ���ʽ��Ϊ�������
 �й���ϸ��Ϣ������� Lambda ���ʽ��ʾ�������е�
    
    ���߽� Lambda ���ʽ����
    
���ڲ����б��ǿ�ѡ�ģ�����ڲ����������ݵ� lambda ���ʽ��
������ lambda-declarator: ������ exception-specification��trailing-return-type �� mutable ������£�����ʡ�Կ����š�

# �ɱ�淶
ͨ����lambda �ĺ������������Ϊ const-by-value������ mutable �ؼ��ֵ�ʹ�ÿɽ���ȡ����  
 ���������ɿɱ�����ݳ�Ա�� ���ÿɱ�淶��lambda ���ʽ����������޸�ͨ��ֵ����ı����� 
 ���ĺ����һЩʾ������ʾ���ʹ�� mutable��

# �쳣�淶
�����ʹ�� throw() �쳣�淶��ָʾ lambda ���ʽ���������κ��쳣�� ����ͨ����һ������� lambda ���ʽ���� C4297 �쳣�淶�� lambda �������쳣��Visual C++ �����������ɾ��� throw()��������ʾ��

	// throw_lambda_expression.cpp
	// compile with: /W4 /EHsc 
	int main() // C4297 expected
	{
	 []() throw() { throw 5; }();
	}

#  ��������
���Զ��Ƶ� lambda ���ʽ�ķ������͡� ����ʹ�� auto �ؼ��֣�����ָ��β�淵�����͡�
 trailing-return-type ��������ͨ���������ķ������Ͳ��֡�
  ���ǣ��������ͱ�����ڲ����б�ĺ��棬������ڷ�������ǰ����� trailing-return-type �ؼ��� ->��
��� lambda �������һ��������������ʽ������ֵ�������ʡ�� lambda ���ʽ�ķ������Ͳ��֡�
 ��� lambda ���������������䣬���������ӷ��ر��ʽ�������Ƶ��������͡� ���򣬱������Ὣ���������Ƶ�Ϊ void�� ����Ĵ���ʾ��Ƭ��˵������һԭ��
 
 
 
	auto x1 = [](int i){ return i; }; // OK: return type is int
	auto x2 = []{ return{ 1, 2 }; }; // ERROR: return type is void, deducing 
	     // return type from braced-init-list is not valid
	     
lambda ���ʽ����������һ�� lambda ���ʽ��Ϊ�䷵��ֵ�� �й���ϸ��Ϣ������� Lambda ���ʽ��ʾ���еġ��߽� Lambda ���ʽ����



# Lambda ��
lambda ���ʽ�� lambda �壨��׼�﷨�е� compound-statement���ɰ�����ͨ��������������ɰ������κ����ݡ�
 ��ͨ������ lambda ���ʽ��������ɷ������±������ͣ�

	�ӷ�շ�Χ�����������ǰ������
	����
	������������
	�����ݳ�Ա�������ڲ��������Ҳ��� this ʱ��
	���о�̬�洢����ʱ����κα��������磬ȫ�ֱ�����
����ʾ������ͨ��ֵ��ʽ������� n ��ͨ��������ʽ������� m �� lambda ���ʽ��


	// captures_lambda_expression.cpp
	// compile with: /W4 /EHsc 
	#include <iostream>
	using namespace std;
	 
	int main()
	{
	 int m = 0;
	 int n = 0;
	 [&, n] (int a) mutable { m = ++n + a; }(4);
	 cout << m << endl << n << endl;
	}
	

�����

	5
	0
	

���ڱ��� n ��ͨ��ֵ����ģ�����ڵ��� lambda ���ʽ�󣬱�����ֵ�Ա��� 0 ���䡣 mutable �淶������ lambda ���޸� n��
���� lambda ���ʽֻ�ܲ�������Զ��洢����ʱ��ı�������������� lambda ���ʽ��������ʹ�þ��о�̬�洢����ʱ��ı����� ����ʾ��ʹ�� generate ������ lambda ���ʽΪ vector �����е�ÿ��Ԫ�ظ�ֵ�� lambda ���ʽ���޸ľ�̬������������һ��Ԫ�ص�ֵ��

	
	void fillVector(vector<int>& v)
	{
	 // A local static variable.
	 static int nextValue = 1;
	 
	 // The lambda expression that appears in the following call to
	 // the generate function modifies and uses the local static 
	 // variable nextValue.
	 generate(v.begin(), v.end(), [] { return nextValue++; }); 
	 //WARNING: this is not thread-safe and is shown for illustration only
	}
	

	
����Ĵ���ʾ��ʹ����һʾ���еĺ������������ʹ�� STL �㷨 generate_n �� lambda ���ʽ��ʾ���� �� lambda ���ʽ�� vector �����Ԫ��ָ�ɸ�ǰ����Ԫ��֮�͡� ʹ���� mutable �ؼ��֣���ʹ lambda ���ʽ����������޸� lambda ���ʽͨ��ֵ������ⲿ���� x �� y �ĸ����� ���� lambda ���ʽͨ��ֵ����ԭʼ���� x �� y��������ǵ�ֵ�� lambda ִ�к���Ϊ 1��


	// compile with: /W4 /EHsc
	#include <algorithm>
	#include <iostream>
	#include <vector>
	#include <string>
	 
	using namespace std;
	 
	template <typename C> void print(const string& s, const C& c) {
	 cout << s;
	 
	 for (const auto& e : c) {
	 cout << e << " ";
	 }
	 
	 cout << endl;
	}
	 
	void fillVector(vector<int>& v)
	{
	 // A local static variable.
	 static int nextValue = 1;
	 
	 // The lambda expression that appears in the following call to
	 // the generate function modifies and uses the local static 
	 // variable nextValue.
	 generate(v.begin(), v.end(), [] { return nextValue++; });
	 //WARNING: this is not thread-safe and is shown for illustration only
	}
	 
	int main()
	{
	 // The number of elements in the vector.
	 const int elementCount = 9;
	 
	 // Create a vector object with each element set to 1.
	 vector<int> v(elementCount, 1);
	 
	 // These variables hold the previous two elements of the vector.
	 int x = 1;
	 int y = 1;
	 
	 // Sets each element in the vector to the sum of the 
	 // previous two elements.
	 generate_n(v.begin() + 2,
	 elementCount - 2,
	 [=]() mutable throw() -> int { // lambda is the 3rd parameter
	 // Generate current value.
	 int n = x + y;
	 // Update previous two values.
	 x = y;
	 y = n;
	 return n;
	 });
	 print("vector v after call to generate_n() with lambda: ", v);
	 
	 // Print the local variables x and y.
	 // The values of x and y hold their initial values because 
	 // they are captured by value.
	 cout << "x: " << x << " y: " << y << endl;
	 
	 // Fill the vector with a sequence of numbers
	 fillVector(v);
	 print("vector v after 1st call to fillVector(): ", v);
	 // Fill the vector with the next sequence of numbers
	 fillVector(v);
	 print("vector v after 2nd call to fillVector(): ", v);
	}
	
	
	
�����

	  vector v after call to generate_n() with lambda: 1 1 2 3 5 8 13 21 34
	x: 1 y: 1
	vector v after 1st call to fillVector(): 1 2 3 4 5 6 7 8 9
	vector v after 2nd call to fillVector(): 10 11 12 13 14 15 16 17 18




# ����� ��Ϊ����������
