#include <iostream>
#include <array>
#include <cstring>

using namespace std;

int main()
{
	array<string,5> words{"one","two","three","four","five"};
	
	//1.get<n>  获取到容器的第 n 个元素,n必须为一个编译期间就可以确定的常量
	cout<<get<3>(words)<<endl;
	
	#if 0
	for (int i = 0;i < words.size();i++)
	{
		cout<<get<i>(words)<<endl;
	}
	
	array.cpp:15:13: error: the value of ‘i’ is not usable in a constant expression
	#endif
	
	//2.at(i)
	int num = words.size();
	for (int i = 0;i < num;i++)
	{
		cout<<words.at(i)<<endl;
	}
	
	//3. data(): 通过调用该函数可以得到指向容器首个元素的指针
	auto ptr = words.data();
	while (ptr != words.end())
	{
		cout<<*ptr<<" ";
		ptr++;
	}
	cout<<endl;
	
	//4.初始化
	int initvalue = 10;
	array<int,5> values1{};
	for (auto& val:values1)//只有使用引用才能修改其值
	{
		val = initvalue;
		initvalue++;
		cout<<initvalue-10<<": "<<val<<endl;
	}
	
	for (auto val:values1)
	{
		cout<<initvalue-10<<": "<<val<<endl;
	}
	
	
	cout<<endl;
	cout<<endl;
	
	array<char,50> a{0x41,0x42,0x43};
	cout<<a[0]<<endl;
	cout<<a[1]<<endl;
	cout<<a[2]<<endl;
	
	//strcpy(&a[3], "http://c.biancheng.net/stl");
	
	strcpy(a.begin(), "http://c.biancheng.net/stl");
	
	cout<<&a[0]<<endl;
	
	
	array<char,50> b{};
	//swap只有在类型相同，大小相同的情况下才能使用
	b.swap(a);
	cout<<&b[0]<<endl;
	
	int len = strlen(&b[0]);
	cout<<len<<endl;
	
	strcpy(&b[len],"/next");
	cout<<&b[0]<<endl;
	
	if (b > a)
	{
		cout<<b.begin()<<endl;
	}
	else 
	{
		cout<<a.begin()<<endl;
		//输出为空，此时a已交换
	}
	
	a = b;
	cout<<&a[0]<<endl;
	
	array<char,51> c;
	
	#if 0
	error:长度不同的array,不能进行赋值
	c = b;
	
	error:长度不同的array,不能进行比较
	if (c < b)
	{
		cout<<&c[0]<<endl;
	}
	#endif
	
	return 0;
}