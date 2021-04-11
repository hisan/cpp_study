#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

void print_pointer()
{
	char *p1 = "abcdefghi";
	string p2 = "abcdefghi";
	char *p3 = "abcdefghi";
	
	cout<<(void *)p1<<endl;
	cout<<&p2<<endl;
	cout<<(void *)p3<<endl;
	
	cout<<endl<<endl;
	
	printf("0x%x\n",p1);
	printf("0x%x\n",&p2);
	printf("0x%x\n",p3);
}

void print_string(string &str)
{
	cout<<(void *)&str<<endl;
	cout<<endl;
	
	for (auto &c:str)//c为引用
	{
		cout<<(void *)&c<<endl;
	}
	
	cout<<endl<<endl;
	
	for (auto d:str)//d为变量
	{
		cout<<(void *)&d<<endl;
	}
}

int main()
{
	string str = "abcdefghi";
	print_string(str);
	return 0;
}