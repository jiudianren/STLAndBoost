partition
ForwardIterator partition (ForwardIterator first, ForwardIterator last, UnaryPredicate pred);

first,last��ʾԪ�ط�Χ[first,last); 
pred:��ʾ��������������һ��һԪ������Ҳ�����Ǻ���ָ��������� 
����ֵ��һ����������ָ��ڶ���Ԫ����ĵ�һ��Ԫ�أ����������ǿյģ��������һ��Ԫ�ء�


	std::vector<double> temperatures {65, 75, 56, 48, 31, 28, 32, 29, 40, 41, 44, 50};
	std::copy(std::begin(temperatures), std::end(temperatures), //List the values
	std::ostream_iterator<double>{std::cout, " "});
	std::cout << std::endl;
	auto average = std::accumulate(std::begin(temperatures),std::end(temperatures), 0.0)/temperatures.size();
	std::cout << "Average temperature: "<< average << std::endl;
	std::partition(std::begin(temperatures), std::end(temperatures),[average](double t) { return t < average; });
	std::copy(std::begin(temperatures), std::end(temperatures),std::ostream_iterator<doiible>{std::cout, " "});
	std::cout << std::endl;