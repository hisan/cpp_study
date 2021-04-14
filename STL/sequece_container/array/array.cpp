#include <iostream>
#include <array>
#include <cstring>

using namespace std;

int main()
{
	array<string,5> words{"one","two","three","four","five"};
	
	//1.get<n>  ��ȡ�������ĵ� n ��Ԫ��,n����Ϊһ�������ڼ�Ϳ���ȷ���ĳ���
	cout<<get<3>(words)<<endl;
	
	#if 0
	for (int i = 0;i < words.size();i++)
	{
		cout<<get<i>(words)<<endl;
	}
	
	array.cpp:15:13: error: the value of ��i�� is not usable in a constant expression
	#endif
	
	//2.at(i)
	int num = words.size();
	for (int i = 0;i < num;i++)
	{
		cout<<words.at(i)<<endl;
	}
	
	//3. data(): ͨ�����øú������Եõ�ָ�������׸�Ԫ�ص�ָ��
	auto ptr = words.data();
	while (ptr != words.end())
	{
		cout<<*ptr<<" ";
		ptr++;
	}
	cout<<endl;
	
	//4.��ʼ��
	int initvalue = 10;
	array<int,5> values1{};
	for (auto& val:values1)//ֻ��ʹ�����ò����޸���ֵ
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
	//swapֻ����������ͬ����С��ͬ������²���ʹ��
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
		//���Ϊ�գ���ʱa�ѽ���
	}
	
	a = b;
	cout<<&a[0]<<endl;
	
	array<char,51> c;
	
	#if 0
	error:���Ȳ�ͬ��array,���ܽ��и�ֵ
	c = b;
	
	error:���Ȳ�ͬ��array,���ܽ��бȽ�
	if (c < b)
	{
		cout<<&c[0]<<endl;
	}
	#endif
	
	return 0;
}