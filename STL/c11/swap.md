#C++11֮ǰ��swap

�ȿ�swap��ʵ�֣�


	template<classT>void swap ( T& a, T& b ){�� T c(a); a=b; b=c;}

������ʾ�����뿴��������ʲô��

��swap������T C(a)��ʱ��ʵ�����ǵ����˿������캯������swap��������˸�ֵ����ʱ��ʵ�����ǵ����˸�ֵ�������

���ڿ������캯���͸�ֵ����������ڴ濽���������������Ĳ�����ִ�������Σ�������һ��swap��һ�����������ڴ濽�����������ֲ���Ҫ���ڴ�����ܶ�����¶���Ӱ��C++��ִ��Ч�ʡ�

#C++11֮���swap

��������ֵ���ú������ƶ��ĸ���֮�󣬴�������������ӣ�

	template<classT>void swap (T& a, T& b){�� T c(std::move(a)); a=std::move(b); b=std::move(c);}

����std::move����������ת��Ϊ��ֵ���ã�TestData�л����ṩ���������ֵ���õĹ��캯���͸�ֵ�������

TestData(TestData&& d)�� :size(d.size)�� ,data(d.data){�� d.size=0;�� d.data=nullptr;}TestData&operator=(const��TestData&& d){�� size=d.size;�� data=d.data;�� return*this;}

���ڴ�����ʹ���ڴ��ƹܴ����˲���Ҫ���ڴ濽�������Ч�ʻ�����ߡ�

