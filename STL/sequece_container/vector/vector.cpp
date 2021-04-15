#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void OutPutVector(vector<T> &vec)
{
	for (auto v:vec)
	{
		cout<<v<<" ";
	}
	cout<<endl<<endl;
}

int vector_operator()
{
	vector<int> val1;
	val1.reserve(30);
	
	cout<<val1.size()<<endl;//返回元素实际个数
	//0
	
	cout<<val1.capacity()<<endl;//返回容器vector的当前容量
	//30
	
	cout<<val1.max_size()<<endl;
	//1073741823 == 2^30-1
	
	val1.shrink_to_fit();//将内存减等于当前元素实际所使用的大小
	cout<<val1.capacity()<<endl;//返回元素实际个数
	//0
	
	vector<int> val2 {1,3,5,7,9,11};
	OutPutVector(val2);
	//1 3 5 7 9 1
	
	cout<<"front: "<<val2.front()<<endl;//返回头元素
	//1
	
	cout<<"back: "<<val2.back()<<endl;//返回尾元素
	//11
	
	val2[3] = 222;
	val2.insert(val2.begin(),1000);
	OutPutVector(val2);
	//1000 1 3 5 7 9 11
	
	#if 0
	这样使用是错误的，因为运算符"[]"由vector重载的,和系统内定的不一样，它返回val2的第几个元素的引用，而不是内存地址
	
	val2.insert(&val2[5],1000);
	#endif
	
	vector<int> val3(20);//默认初始值为0
	OutPutVector(val3);
	//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
	
	vector<int> val4(20,1);//指定初始值
	OutPutVector(val4);
	//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
	
	int num = 10;
	double tmpvalues = 0.3;
	vector<double> val5(num,tmpvalues);//()用的参数还可以是变量
	OutPutVector(val5);
	//10 0.3
	//0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3
	
	
	cout<<"cap: "<<val5.capacity()<<" size: "<<val5.size()<<endl;
	//cap: 10 size: 10
	
	val5.push_back(1.111);
	
	cout<<"cap: "<<val5.capacity()<<" size: "<<val5.size()<<endl;
	//cap: 10 size: 10
	#if 0
	由上的内存变化也可以，当插入时内存不够后,vector扩容为当前容量的2倍
	#endif
	
	OutPutVector(val5);
	//0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3 0.3 1.111
	
	val5.pop_back();
	val5.pop_back();
	val5.pop_back();
	val5.pop_back();
	val5.pop_back();
	val5.pop_back();
	val5.pop_back();
	OutPutVector(val5);
	cout<<"cap: "<<val5.capacity()<<" size: "<<val5.size()<<endl;
	
	
	vector<int> val6(3);
	cout<<"cap: "<<val6.capacity()<<" size: "<<val6.size()<<endl;
	//cap: 3 size: 3
	
	
	val6.push_back(10);
	cout<<"cap: "<<val6.capacity()<<" size: "<<val6.size()<<endl;
	//cap: 6 size: 4
	
	
	cout<<"cap: "<<val4.capacity()<<" size: "<<val4.size()<<endl;
	//cap: 20 size: 20
	
	val6.assign(val4.begin(),val4.end());//用新元素替换原有内容，且不存在的也会替换过来。
	OutPutVector(val6);
	//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
	
	cout<<"cap: "<<val6.capacity()<<" size: "<<val6.size()<<endl;
	//cap: 20 size: 20
	
	val6.erase(val6.begin(),val6.begin()+3);// erase(const_iterator __position)
	OutPutVector(val6);
	//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
	
	for (vector<int>::iterator itr = val6.begin();itr != val6.end();/* itr++ */)
	{
		if (*itr == 1)
		{
			itr = val6.erase(itr);
		}
	}
	
	#if 0
	为什么屏蔽itr++? 因为当删除一个vector的元素以后,它的迭代器会变化或者说全部失效
	#endif 

	val6.insert(val6.begin(),{12,23,34});
	OutPutVector(val6);
	//12 23 34
	cout<<"cap: "<<val6.capacity()<<" size: "<<val6.size()<<endl;
	//cap: 20 size: 3
	val6.emplace(val6.begin());
	OutPutVector(val6);
	//0 12 23 34
	
	val6.emplace_back(20);
	//在容器末尾插入一个元素，值为20，如果这个值不填的话，就默认为0
	OutPutVector(val6);	
	return 0;
}

void iterator_vec()
{
	vector<int> val1({2,3,4});
	for (vector<int>::reverse_iterator itr = val1.rbegin();itr != val1.rend();itr++)
	{
		#if 0
		++才符合逻辑，服了
		#endif
		cout<<*itr<<" ";
	}
	cout<<endl;
}

void get_vector_elem()
{
	vector<int> values{1,2,3,4,5};
	cout<<values[0]<<endl;
	
	values[0] = values[1];
	cout<<values[0]<<endl;
	
	OutPutVector(values);
	//2 2 3 4 5
	
	try
	{
		int val = values.at(3);
		//异常是一旦检测到，后续的指令就不会再执行，所以不会发生段错误。
		cout<<val<<endl;
		
	}catch(out_of_range)
	{
		cout<<"error index"<<endl;
		//error index
	}
	
	values.reserve(10);
	
	for (int i = 0; i < values.capacity();i++)
	{
		cout<<values[i]<<" ";
		//2 2 3 4 5 0 0 0 0 0
	}
	
	cout<<endl<<values.capacity()<<endl;
	//10
}


typedef struct 
{
	int a;
	int b;
	char c;
}node;

void del_vector()
{
	cout<<"node:"<<sizeof(node)<<endl;
	int a = 10;
	int b = 20;
	char c = 'a';
	
	vector<node> nvec{{a++,b++,c++},{a++,b++,c++},{a++,b++,c++},{a++,b++,c++}};
	
	cout<<endl;
	for (auto &nd:nvec)
	{
		cout<<"a:"<<nd.a<<" b:"<<nd.b<<" char:"<<nd.c<<endl;
	}
	cout<<endl;
	
	#if 0
	node:12
	a:10 b:20 char:a
	a:11 b:21 char:b
	a:12 b:22 char:c
	a:13 b:23 char:d
	#endif

	
	nvec.pop_back();
	cout<<endl;
	for (auto &nd:nvec)
	{
		cout<<"a:"<<nd.a<<" b:"<<nd.b<<" char:"<<nd.c<<endl;
	}
	cout<<endl;
	
	#if 0
	a:10 b:20 char:a
	a:11 b:21 char:b
	a:12 b:22 char:c
	#endif
	
	vector<node>::iterator nitr = nvec.begin();
	
	nvec.erase(nitr);
	cout<<endl;
	for (auto &nd:nvec)
	{
		cout<<"a:"<<nd.a<<" b:"<<nd.b<<" char:"<<nd.c<<endl;
	}
	cout<<endl;
	
	#if 0
	a:11 b:21 char:b
	a:12 b:22 char:c
	#endif
	
	vector<node> ntmp{{111,222,'A'}};
	
	
	ntmp.swap(nvec);
	cout<<endl;
	for (auto &nd:nvec)
	{
		cout<<"a:"<<nd.a<<" b:"<<nd.b<<" char:"<<nd.c<<endl;
	}
	cout<<endl;
	
	#if 0
	a:111 b:222 char:A
	#endif
	
	cout<<endl;
	for (auto &nd:ntmp)
	{
		cout<<"a:"<<nd.a<<" b:"<<nd.b<<" char:"<<nd.c<<endl;
	}
	cout<<endl;
	
	#if 0
	a:11 b:21 char:b
	a:12 b:22 char:c
	#endif
	
	ntmp.clear();
	cout<<endl;
	
	cout<<"ntmp.size: "<<ntmp.size()<<endl;
	cout<<endl;
	
	#if 0
	ntmp.size: 0
	#endif
}

void bool_vec()
{
	vector<bool> bvec{0,1};
	bool *bp = &bvec[0];
	
	#if 0
	error1: taking address of temporary
	error2: cannot convert ‘std::vector<bool>::reference* {aka std::_Bit_reference*}’ to ‘bool*’ in initialization
	#endif
	
}

int main()
{
	bool_vec();
	return 0;
}