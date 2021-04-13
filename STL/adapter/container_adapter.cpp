#include <functional>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	//priority_queue<int,vector<int>,greater<int>> cstk;//(1)
    priority_queue<int,vector<int>,less<int>> cstk;//(2)
	cstk.push(100);
	cstk.push(30);
	cstk.push(400);
	cstk.push(129);
	cstk.push(540);
	
	while(!cstk.empty())
	{
		cout<<cstk.top()<<endl;
		cstk.pop();
	}

	return 0;
}