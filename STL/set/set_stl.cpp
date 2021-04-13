#include <iostream>
#include <map>
#include <set>

using namespace std;

template <typename type>
struct mycomp{
	bool operator()(const type & first,const type & second) const {
		return first.second > second.second;
	}
};

int main()
{
	//set<pair<int,int>> myset;
	//set<pair<int,int>,greater<pair<int,int>>> myset;
	set<pair<int,int>,mycomp<pair<int,int>>> myset;
	
	myset.insert({40,10}),myset.insert({20,100}),myset.insert({30,250});
	
	for (auto &elem:myset)
	{
		cout<<elem.first<<" - "<<elem.second<<endl;
	}
	
	return 0;
}
