#include <iostream>
#include <map>
#include <set>

using namespace std;
template <typename T>
void outputset(set<T>&mset)
{
	for (auto s:mset)
	{
		cout<<s<<endl;
	}
	cout<<endl;
}

template <typename type>
struct mycomp{
	bool operator()(const type & first,const type & second) const {
		return first.second > second.second;
	}
};


set<string> retSet()
{
	set<string> myset{"huawei","apple","xiaomi"};
	return myset;
}

void set_init()
{
	set<string>mset1;
	outputset(mset1);
	
	set<string>mset2{"first","second","third"};
	outputset(mset2);
	#if 0	
	first
	second
	third
	#endif 
	
	set<string>mset3(mset2);
	outputset(mset3);
	#if 0
	first
	second
	third
	#endif 
	
	set<string>mset4(retSet());
	outputset(mset4);
	#if 0
	apple
	huawei
	xiaomi
	#endif
	
	
}

int main()
{
	set_init();
	return 0;
}
