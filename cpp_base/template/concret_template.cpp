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


1. Max<STU>�е�STU������Ҫ�����Ͳ��� T ���廯Ϊ STU ����,ԭ��ʹ�� T ��λ�ö�Ӧ��ʹ�� STU �滻����������ֵ���͡��β����͡��ֲ����������͡�
template<> const STU& Max<STU>(const STU& a,const STU& b);


ostream &operator<<(ostream &out,const STU &stu);


int main()
{
	int a = 10;
	int b = 20;
	cout<<Max(a,b)<<endl;
	
	STU stu1 = { "����", 16, 95.5};
    STU stu2 = { "����", 17, 90.0};
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