#include <iostream>
#include <string>
using namespace std;

typedef struct 
{
	string name;
	int age;
	float score;
}STU;


template<class T>const T& Max(const T& a,const T& b);


1. Max<STU>中的STU表明了要将类型参数 T 具体化为 STU 类型,原来使用 T 的位置都应该使用 STU 替换，包括返回值类型、形参类型、局部变量的类型。
template<> const STU& Max<STU>(const STU& a,const STU& b);


ostream &operator<<(ostream &out,const STU &stu);


int main()
{
	int a = 10;
	int b = 20;
	cout<<Max(a,b)<<endl;
	
	STU stu1 = { "王明", 16, 95.5};
    STU stu2 = { "徐亮", 17, 90.0};
    cout<<Max(stu1, stu2)<<endl;
    return 0;
}

template<class T>const T& Max(const T& a,const T& b)
{
	return a>b?a:b;
}

template<> const STU& Max<STU>(const STU& a,const STU& b)
{
	return a.score > b.score?a:b;
}

ostream &operator<<(ostream &out,const STU &stu)
{
	out<<stu.name<<" , "<<stu.age<<" , "<<stu.score;
	return out;
}