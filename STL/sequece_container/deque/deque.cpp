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
	OutPut(d);
	#if 0
	1 2 3
	#endif
	
	cout<<d.front()<<endl;
	//1
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

void visit_error()
{
	deque<int> dp1(1);
	cout<<dp1[1]<<endl;
	dp1[1] = 5;
	cout<<dp1[1]<<endl;
	#if 0
	2
	5
	#endif 
	
	dp1.at(0) = 20;
	cout<<dp1.at(0)<<endl;
	#if 0
	20
	#endif 
	
	#if 0
	dp1.at(n)返回dp1容器的第n个元素的引用
	cout<<dp1.at(3)<<endl;
	terminate called after throwing an instance of 'std::out_of_range'
	what():  deque::_M_range_check: __n (which is 3)>= this->size() (which is 1)
	Aborted (core dumped)
	#endif	
	
	deque<int> dq2{1,2,3,5,7,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19,8,9,10,11,12,13,14,15,16,217,19};
	cout<<"dp1 size: "<<sizeof(dp1)<<endl;
	cout<<"dq2 size: "<<sizeof(dq2)<<endl;
	 
	#if 0
	dq2.front()和dq2.back()返回元素引用
	#endif
	
	cout<<dq2.front()<<endl;
	//1
	dq2.front() = 5;
	cout<<dq2.front()<<endl;
	//5
	
	cout<<dq2.back()<<endl;
	//19
	dq2.front() = 10;
	cout<<dq2.front()<<endl;
	//10
	
	
	cout<<"end:   "<<&dq2.back()<<endl;
	cout<<"start: "<<&dq2.front()<<endl;
	#if 0
	end:   0x83b9854
	start: 0x83b9070
	#endif
	
	int tmp1 = (int)&dq2.back();
	int tmp2 = (int)&dq2.front();
	
	cout<<"dist: "<<(tmp1 - tmp2)/4<<endl;
	//505
	cout<<"size: "<<dq2.size()<<endl;
	//500
	
	#if 0
	这多出来的5*4 = 20字节字节，应该是deque用于维护内存空间的成员所占的空间
	#endif
	
	
	deque<int> dq3{1,3,5,7,9};
	cout<<endl;
	
	vector<int> vec{10,20,30,40,50,60,70,80};
	
	for (vector<int>::iterator itr = vec.begin();itr != vec.end();itr++)
	{
		if ((*itr/10)%2 == 0)
		{
			dq3.push_front(*itr);
		}
		else 
		{
			dq3.push_back(*itr);
		}
	}
	cout<<endl;
	for (auto vd:dq3)
	{
		cout<<vd<<" ";
	}
	cout<<endl;
	#if 0
	80 60 40 20 1 3 5 7 9 10 30 50 70
	#endif
}


void all_test()
{
	deque<int> d;
	d.push_back(2);
	d.pop_back();
	
	d.push_front(2);
	d.pop_front();
	
	d.emplace_back(2);
	d.emplace_front(3);
	
	d.emplace(d.begin() + 1,4);
	
	for (auto i:d)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	#if 0
	3 4 2
	#endif
	
	d.erase(d.begin());
	d.erase(d.begin(),d.end());
}

void insert_deque()
{
	deque<int>d{1,2,3};
	d.insert(d.begin()+1,3);
	
	#if 0
	insert(pos,num,value)
	#endif
	d.insert(d.end(),2,5);
	

	array<int,3> test{7,8,9};
	d.insert(d.end(),test.begin(),test.end());
	
	d.insert(d.end(),{10,11});
	
	OutPut(d);
	#if 0
	1 3 2 3 5 5 7 8 9 10 11
	#endif
}

int main()
{
	insert_deque();
	return 0;
}