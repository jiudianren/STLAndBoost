partition
ForwardIterator partition (ForwardIterator first, ForwardIterator last, UnaryPredicate pred);

first,last表示元素范围[first,last); 
pred:表示分组条件，它是一个一元函数，也可以是函数指针或函数对象。 
返回值是一个迭代器，指向第二个元素组的第一个元素；如果这个组是空的，则是最后一个元素。


	std::vector<double> temperatures {65, 75, 56, 48, 31, 28, 32, 29, 40, 41, 44, 50};
	std::copy(std::begin(temperatures), std::end(temperatures), //List the values
	std::ostream_iterator<double>{std::cout, " "});
	std::cout << std::endl;
	auto average = std::accumulate(std::begin(temperatures),std::end(temperatures), 0.0)/temperatures.size();
	std::cout << "Average temperature: "<< average << std::endl;
	std::partition(std::begin(temperatures), std::end(temperatures),[average](double t) { return t < average; });
	std::copy(std::begin(temperatures), std::end(temperatures),std::ostream_iterator<doiible>{std::cout, " "});
	std::cout << std::endl;