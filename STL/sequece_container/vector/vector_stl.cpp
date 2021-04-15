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
	auto iterbegin = std::remove(v.begin(),v.end(),40);//ɾ��vector v��ĳ����Χ��ֵΪ40��Ԫ��
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
		vec[ix] = ix;//vecΪ�գ�vec[ix]����δ���*(vec+ix)����һ��δ֪��ַ����ɶδ���
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
	
	//�ɴ˿�֪������������ָ�룬���Ե���������++��--��*��==��
}



int main()
{
	iterator_test();
	return 0;
}
