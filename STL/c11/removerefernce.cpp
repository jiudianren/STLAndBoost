
#if 0

template <class T>
auto func(T beg,T end)   -> typename std::remove_refernce<decltype *beg>::type
{
	return *beg;
}

#endif
