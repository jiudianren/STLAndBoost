https://blog.csdn.net/iicy266/article/details/11906189

#1 按照key 排序
template < class Key, class T, class Compare = less<Key>,
           class Allocator = allocator<pair<const Key,T> > > class map; 
           
map默认按照less 自动排序，可以指定

#2 按照value排序

1.  将map存储的pair，转化为 序列式容器

2. pair重载了 < 操作符，并不能直接使用

3 ， 自定义比较函数

	typedef pair<string, int> PAIR;
	 bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {  return lhs.second < rhs.second;} 
	 
	 struct CmpByValue { 
	 	 bool operator()(const PAIR& lhs, const PAIR& rhs) {   
	  					return lhs.second < rhs.second;  }
	  	}


	int main() {  
		map<string, int> name_score_map;  
		name_score_map["LiMin"] = 90; 
	 	name_score_map["ZiLinMi"] = 79;  
		name_score_map["BoB"] = 92;  
	 	name_score_map.insert(make_pair("Bing",99));  
	 	name_score_map.insert(make_pair("Albert",86)); 
	 
	    //把map中元素转存到vector中   
	 	vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());  
	 	sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue()); 
	 
	 // sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value); 
	  
	    for (int i = 0; i != name_score_vec.size(); ++i) {  
	    	cout << name_score_vec[i] << endl;  
	    }  
	    return 0;
	    }

