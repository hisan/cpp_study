#include <iostream>
#include <algorithm>
#include <deque>
#include <array>
#include <vector>
#include <list>

using namespace std;


template<typename T>
void output_list(list<T> &lst)
{
	for (auto &l:lst)
	{
		cout<<l<<" ";
	}
	cout<<endl;
}

template<typename T>
void reout_list(list<T> &lst)
{
	//此处必须显式声明list<T>::reverse_iterator为类型
	for (typename list<T>::reverse_iterator itr = lst.rbegin(); itr != lst.rend();itr++)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;
}


void init_list()
{
	list<int> l1;
	list<int> l2(10);
	//0 0 0 0 0 0 0 0 0 0
	
	output_list(l2);
	list<int> l3(20,5);
	output_list(l3);
	//5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
	
	list<int> l4(l3);
	output_list(l4);
	//5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
	
	deque<int>dq1{1,2,3,4,5,6};
	deque<int>dq2(dq1);
	
	cout<<*(dq2.end())<<endl;
	//0

	list<int>l5(dq2.begin(),dq2.end());
	output_list(l5);
	//1 2 3 4 5 6
	
	
	list<int>l6{2,4,6,8,10};
	
	output_list(l4);
	
	list<int>::iterator ptr = l4.begin();
	ptr++;
	ptr++;
	ptr++;
	
	#if 0
	error list非空间上连续的容器，
	ptr+=2;
	
	#endif 
	
	l4.splice(ptr,l6);//,l6.end()-2);
	output_list(l4);
	//5 5 5 2 4 6 8 10 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
}


void iterator_list()
{
	list<string> l1{{"apple"},{"huawei"},{"xiaomi"},{"vivo"},{"oppo"}};
	reout_list(l1);
	
	list<int>l2;
	list<int>::iterator ptr = l2.begin();
	list<int>::iterator ptr1 = l2.end();
	
	cout<<&ptr<<endl;
	cout<<&ptr1<<endl;
	
	#if 0	
	0xbfe8d494
	0xbfe8d498
	#endif
	
	list<int> l3{10,9,8,7,6,5,4,3,2,1};
	l3.sort();
	output_list(l3);
	//1 2 3 4 5 6 7 8 9 10
	
}

int main()
{
	iterator_list();
	return 0;
}	
		
		
		
		
		
		
		
		
			
		
		
		
		
		
		
		
			
		
		
		
		
		
		
		
		
		
	