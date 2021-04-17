#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


template <typename T1,typename T2>
void output_pair(pair<T1,T2> &pr)
{
	cout << "[first]: " << pr.first << " 	[second]: " << pr.second << endl<<endl;
}

void map_test()
{
	map<string,string> mp;
	mp["c"] = "学C保平安!";
	mp["java"] = "java大法好！";
	mp["c++"] = "c++穷一生!";
	
	for (map<string,string>::iterator itr = mp.begin();itr != mp.end();++itr)
	{
		cout<<itr->first<<"       ==>    "<<itr->second<<endl;
	}
	
	
	#if 0
	自动排序
	c       ==>    学C保平安!
	c++       ==>    c++穷一生!
	java       ==>    java大法好！
	#endif 
}


void init_pair()
{	
	pair<string,double> pair1;
	output_pair(pair1);
	
	pair<string,string> pair2("C","学C保平安!");
	output_pair(pair2);
	
	pair<string,string> pair3(pair2);
	output_pair(pair3);
	
	pair<string,string> pair4(make_pair("c++","c++穷一生!"));
	output_pair(pair4);
	
	pair<string,string> pair5(string("java"),string("java大法好！"));
	output_pair(pair5);
	
	#if 0
	[first]:        [second]: 0

	[first]: C      [second]: 学C保平安!

	[first]: C      [second]: 学C保平安!

	[first]: c++    [second]: c++穷一生!

	[first]: java   [second]: java大法好！

	#endif 
	
	
	pair<string,string> pair6;
	pair6.first = "python";
	pair6.second = "python富三代!";
	output_pair(pair6);
	
	#if 0
	[first]: python         [second]: python富三代!
	#endif
}





template <typename T1,typename T2,typename T3>
void outputmap(map<T1,T2,T3> &mp)
{
	for (auto itr = mp.begin();itr != mp.end();++itr)
	{
			cout << "[first]:" << itr->first << "	[second]:" << itr->second << endl;
	}
	cout<<endl;
}
	
map<string,int> dismap()
{
	map<string,int>tmpmp{{"first",1},{"second",2}};
	return tmpmp;
}

void init_map()
{
	map<string,int> mp1;
	outputmap(mp1);
	
	map<string,int,greater<string>> mp2{{"first",1},{"second",2}};
	outputmap(mp2);
	#if 0
	[first]:second  [second]:2
	[first]:first   [second]:1
	#endif 
	
	map<string,int,less<string>> mp3{make_pair("third",3),make_pair("four",4)};
	outputmap(mp3);
	#if 0
	[first]:four    [second]:4
	[first]:third   [second]:3
	#endif
	
	map<string,int>newmap(dismap());
	outputmap(newmap);
	#if 0
	[first]:first   [second]:1
	[first]:second  [second]:2
	#endif
	
	map<string,int>mp4(++mp2.begin(),mp2.end());
	outputmap(mp4);
	#if 0
	[first]:first   [second]:1
	#endif
	
	map<string,int>::iterator itr = mp4.find("first");
	if (itr != mp4.end())
	{
		cout<<itr->second<<endl;
	}
	
	//返回的是指向第一个键不小于 key 的键值对的迭代器；
	auto itr2 = mp4.lower_bound("first");
	if (itr2 != mp4.end())
	{
		cout<<itr2->second<<endl;
		//1
	}
	
	//返回的是指向第一个键大于 key 的键值对的迭代器;
	auto itr3 = mp2.upper_bound("second");
	if (itr3 != mp2.end())
	{
		cout<<itr3->second<<endl;
		//1
	}
}

void equal_range()
{
    //创建并初始化 map 容器
    std::map<string, string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                   {"C语言教程","http://c.biancheng.net/c/"},
                                   {"Java教程","http://c.biancheng.net/java/"} };
    //创建一个 pair 对象，来接收 equal_range() 的返回值
    pair <std::map<string, string>::iterator, std::map<string, string>::iterator> myPair = myMap.equal_range("C语言教程");
    
	//通过遍历，输出 myPair 指定范围内的键值对
    auto iter1 = myPair.first;
	auto iter2 = myPair.second;
	
	cout << iter1->first << " " << iter1->second << endl;
	cout << iter2->first << " " << iter2->second << endl;
}

void getmap_keysvalue()
{
	//1.[]
	map<string,int> mp;
	int cvalue = mp["C语言教程"];//创建个这个键值对
	
	for (auto m = mp.begin();m != mp.end();++m)
	{
		cout<<m->first<< " " <<m->second<<endl;
		//C语言教程 0
	}
	
	cout<<cvalue<<endl;
	//0
	
	#if 0
	mp.at("aa");
	
	terminate called after throwing an instance of 'std::out_of_range'
	  what():  map::at
	Aborted (core dumped)
	#endif 
	
}


int main()
{
	getmap_keysvalue();
	return 0;
}


















































