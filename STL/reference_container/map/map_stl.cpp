#include <iostream>
#include <map>

#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<int,int> mp;
	mp.insert(make_pair(4,400));
	mp[4] = 400;
	mp[3] = 300;
	
	mp.insert(make_pair(4,300));
	mp.insert(make_pair(10,700));
	mp.insert(make_pair(3,400));
	mp.insert(make_pair(21,9000));
	mp.insert(make_pair(11,1000));
	mp[10] = 900;
	
	
	//iterate 
	for (auto it = mp.begin();it != mp	.end();it++)
	{
		cout<<it->first<<"------"<<it->second<<endl;
	}
	
	return 0;
}