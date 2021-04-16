#include <iostream>
#include <map>
#include <string>

using namespace std;


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

int main()
{
	map_test();
	return 0;
}