C++�����õ�����ɾ��Ԫ�ػᷢ��ʲô��

��1�����ڹ�����������map��set��multimap��multiset����ɾ����ǰ��iterator��
������ʹ��ǰ��iteratorʧЧ��ֻҪ��eraseʱ��������ǰ��iterator���ɡ�
������Ϊmap֮���������ʹ���˺������ʵ�֣����룬ɾ��һ����㲻�������������Ӱ�졣ʹ�÷�ʽ�������ӣ�

	set<int> valset = { 1,2,3,4,5,6 };
	set<int>::iterator iter;
	for (iter = valset.begin(); iter != valset.end(); )
	{
	     if (3 == *iter)
	          valset.erase(iter++);
	     else
	          ++iter;
	}

��Ϊ����erase����iter��һ��������iter++����һ����Ч�ĵ�������

��2����������ʽ��������vector��deque��list�ȣ���ɾ����ǰ��iterator��ʹ��������Ԫ�ص�iterator��ʧЧ��
������Ϊvector��dequeʹ��������������ڴ棬ɾ��һ��Ԫ�ص��º������е�Ԫ�ػ���ǰ�ƶ�һ��λ�á�
����erase�������Է�����һ����Ч��iterator��ʹ�÷�ʽ����,���磺



	vector<int> val = { 1,2,3,4,5,6 };
	vector<int>::iterator iter;
	for (iter = val.begin(); iter != val.end(); )
	{
	     if (3 == *iter)
	          iter = val.erase(iter);     //������һ����Ч�ĵ�����������+1
	     else
	          ++iter;
	}
