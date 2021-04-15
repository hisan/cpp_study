#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ope_test()
{
	vector<int> v;
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);

	cout<<"Size of vector before remove ==>"<<v.size()<<endl;
	auto iterbegin = std::remove(v.begin(),v.end(),40);//删除vector v中某个范围的值为40的元素
	cout<<"Size of vector after remove ==>"<<v.size()<<endl;
	v.erase(iterbegin,v.end());
	cout<<"Size of vector after erase ==>"<<v.size()<<endl;
	
	cout<<"v[1].val: "<<v[1]<<endl;
	
	//for (auto &var:v)
	for (auto var = v.begin();var != v.end();var++)
	{
		cout<<"vector var ==>"<<*var<<endl;
	}
}

void capacity_test()
{
	vector<int> vec;
	for (decltype(vec.size()) ix = 0;ix != 10;ix++)
	{
		vec[ix] = ix;//vec为空，vec[ix]引起段错误。*(vec+ix)访问一个未知地址，造成段错误
		//Program terminated with signal SIGSEGV, Segmentation fault.
	}
}

void index_test()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	
	cout<<vec[2]<<endl;
	
	#if 0
	root@ubuntu:/home/zyb/CODE/CPP/STL# ./vector_stl
	30
	#endif
}

void iterator_test()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	
	auto itr_begin = vec.begin();
	auto itr_end = vec.end();
	
	cout<<"itr_begin: "<<(void *)&itr_begin<<endl;	
	cout<<"itr_end:   "<<(void *)&itr_end<<endl;
	
	#if 0
	root@ubuntu:/home/zyb/CODE/CPP/STL# ./vector_stl
	itr_begin: 0xbfb32878
	itr_end:   0xbfb3287c
	#endif 
	
	//由此可知，迭代器类似指针，所以迭代器可以++、--、*、==、
}



int main()
{
	iterator_test();
	return 0;
}
