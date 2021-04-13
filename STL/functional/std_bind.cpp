#include <iostream>
#include <functional>
using namespace std;

int fn1(int firtst,int second,int third)
{
	return firtst + second + third;
}

int main1()
{
	//T1、T2、T3
	using namespace placeholders;
	int firtst = 200;
	auto f2 = bind(fn1,firtst,_1,_2);//告知程序依旧有两个变量未传递
	int second = 201;
	auto f3 = bind(f2,second,_1);
	int third = 300;
	int result = f3(third);
	cout << result << endl;

	return 0;
}

int fn(int first,int second,int third)
{
	cout<<"first: "<<first<<" second: "<<second<<" third: "<<third<<endl;
	return first + second + third;
}

int main2()
{
	//T1、T2、T3
	using namespace placeholders;
	int first = 200;
	auto f2 = bind(fn,_1,first,_2);//告知程序依旧有两个变量未传递
	int second = 201;
	auto f3 = bind(f2,second,_1);
	int third = 300;
	int result = f3(third);
	cout << result << endl;

	return 0;
}


int main()
{
	//T1、T2、T3
	using namespace placeholders;
	int first = 200;
	auto f2 = bind(fn,_1,_1,first);//告知程序依旧有两个变量未传递
	int second = 201;
	auto f3 = bind(f2,second,_1);
	int third = 300;
	int result = f3(third);
	cout << result << endl;

	return 0;
}


