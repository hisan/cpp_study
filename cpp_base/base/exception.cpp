#include <iostream>
#include <initializer_list>
using namespace std;

void str_test(int idx)
{
	char ch2 = 0;
	string str("www.baidu.com");
	ch2 = str.at(idx);
	cout<<ch2<<endl;
}

void test1()
{
	str_test(100);
}

void test2()
{
	test1();
}

void test3()
{
	test2();
}

void try_pos()
{
	try{
		throw "unknow Exception";
		test3();
	}catch(const char* &e){
		cout<<e<<endl;
	}
}

int main()
{
	try_pos();
	return 0;
}

