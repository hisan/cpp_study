#include <iostream>
#include <map>
using namespace std;

typedef std::map<std::string,int> map_int_t;

void outputmap(map_int_t& mi)
{
	for (auto mitr = mi.begin();mitr != mi.end();mitr++)
	{
		cout<<"[fisrst]: "<<mitr->first<<"   [second]: "<<mitr->second<<endl;
	}
}

void map_test()
{
	map_int_t m_i;
	
	m_i["a"] = 1;
	m_i["b"] = 1;
	m_i["c"] = 1;
	outputmap(m_i);
	
	#if 0
	[fisrst]: a   [second]: 1
	[fisrst]: b   [second]: 1
	[fisrst]: c   [second]: 1
	#endif
}

void constexpr_test()
{
	int num = 10;
	int array[num] = {0};
}

int main()
{
	
	return 0;
}