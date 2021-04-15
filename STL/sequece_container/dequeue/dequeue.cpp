#include <iostream>
#include <deque>
#include <array>
#include <vector>

using namespace std;

template <typename T1>

void OutPut(deque<T1> &dq)
{
	for (auto v:dq)
	{
		cout<<v<<" ";
	}
	cout<<endl<<endl;
}

void create_dequeu()
{
	//1. 创建空队列
	deque<int>dq1;
	deque<int>dq2(10);
	OutPut(dq2);
	#if 0	
	0 0 0 0 0 0 0 0 0 0 
	说明初始化为0了
	#endif
	
	deque<int>dq3(10,5);
	OutPut(dq3);
	#if 0
	5 5 5 5 5 5 5 5 5 5
	#endif
	
	//通过拷贝容器创建新的容器
	deque<int>dq5(dq3);
	OutPut(dq5);
	#if 0
	5 5 5 5 5 5 5 5 5 5
	#endif
	
	int a[] = {1,2,3,4,5};
	deque<int>dq6(a,a+sizeof(a)/sizeof(a[0]));
	OutPut(dq6);
	#if 0
	1 2 3 4 5
	#endif 
	
	array<int,5>arr{11,12,13,14,15};
	deque<int>dq7(arr.begin()+2,arr.end());
	OutPut(dq7);
	#if 0
	13 14 15
	#endif
	
	cout<<"dq6.max_size: "<<dq6.max_size()<<endl;
	
	#if 0
	dq6.max_size: 1073741823
	#endif
	
	
}

void add_deque()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
}

int ite_error()
{
    deque<int>values;
    auto first = values.begin();
	cout<<(void *)&first<<endl;
    *first = 1;
	cout<<values.front()<<endl;
	#if 0
	1
	#endif
	
    return 0;
}

int main()
{
	ite_error();
	
	return 0;
}



























