#include <iostream>
using namespace std;

class A
{
public:
	A(int a):m_a(a){cout<<"A()"<<endl;}
	void display()
	{
		cout<<"m_a= "<<m_a<<endl;
		cout<<endl;
	}

public:
	int m_a;
};


class B:virtual public A
{
public:
	B(int a,int b):A(a),m_b(b){}
	void display()
	{
		cout<<"m_a= "<<m_a<<endl;
		cout<<"m_b= "<<m_b<<endl;
		cout<<endl;
	}
public:
	int m_b;
};


class C:virtual public A
{
public:
	C(int a,int c):A(a),m_c(c){ }
	void display()
	{
		cout<<"m_a= "<<m_a<<endl;
		cout<<"m_c= "<<m_c<<endl;
		cout<<endl;
	}
	
public:
	int m_c;
};


class D:public B,public C
{
public:
	D(int a,int b,int c,int d):A(a),B(a,b),C(a,c),m_d(d){ }
	void display()
	{
		cout<<"m_a= "<<m_a<<endl;
		cout<<"m_b= "<<m_b<<endl;
		cout<<"m_c= "<<m_c<<endl;	
		cout<<"m_d= "<<m_d<<endl;
		cout<<endl;
	}
	
public:
	int m_d;
};

int main()
{
	D(5,6,7,8);
	return 0;
}

