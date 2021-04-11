#include <iostream>
using namespace std;

class A
{
public:
	A(int a,int b);
	void display();
public:
	int m_a;
    int m_b;
};

A::A(int a,int b):m_a(a),m_b(b){ }
void A::display()
{
	cout<<"m_a= "<<m_a<<" m_b= "<<m_b<<endl;
	cout<<endl;
}

class B:public A
{
public:
	B(int a,int b,int c);
	void display();
public:
	int m_c;
};
B::B(int a,int b,int c):A(a,b),m_c(c){ }

void B::display()
{
	cout<<"m_a= "<<m_a<<" m_b= "<<m_b<<" m_c= "<<m_c<<endl;
	cout<<endl;
}

class C:public B
{
public:
	C(int a,int b,int c,int d);
	void display();
public:

	int m_b;
	int m_c;
	int m_d;
};

C::C(int a,int b,int c,int d):B(a,b,c),m_b(b),m_c(c),m_d(d){ }

void C::display(){
    printf("A::m_a=%d, A::m_b=%d, B::m_c=%d\n", m_a, A::m_b, B::m_c);
    printf("C::m_b=%d, C::m_c=%d, C::m_d=%d\n", m_b, m_c, m_d);
	printf("\n");
	printf("\n");
}

int main()
{
	A obj_a(2,22);
	obj_a.display();
	
	cout<<"obj_a: "<<&obj_a<<endl;
	cout<<"obj_a.m_a: "<<&obj_a.m_a<<endl;
	cout<<"obj_a.m_b: "<<&obj_a.m_b<<endl;
	cout<<endl;
	cout<<endl;
	
	B obj_b(3,33,333);
	obj_b.display();
	obj_b.A::display();
	
	cout<<"obj_a: "<<&obj_a<<endl;
	cout<<"obj_b: "<<&obj_b<<endl;
	cout<<"obj_b.m_a: "<<&obj_b.m_a<<endl;
	cout<<"obj_b.m_b: "<<&obj_b.m_b<<endl;
	cout<<"obj_b.m_c: "<<&obj_b.m_c<<endl;
	cout<<endl;
	cout<<endl;
	
	C obj_c(1,11,111,1111);
	obj_c.A::display();
	obj_c.B::display();
	obj_c.display();
	
	cout<<"obj_a: "<<&obj_a<<endl;
	cout<<"obj_b: "<<&obj_b<<endl;
	cout<<"obj_c: "<<&obj_c<<endl;
	cout<<"obj_c.m_a: "<<&obj_c.m_a<<endl;
	cout<<"obj_c.m_b: "<<&obj_c.m_b<<endl;
	cout<<"obj_c.m_c: "<<&obj_c.m_c<<endl;
	cout<<"obj_c.m_d: "<<&obj_c.m_d<<endl;
	cout<<endl;
	cout<<endl;
	
	cout<<"obj_c.A::m_b: "<<&obj_c.A::m_b<<endl;
	cout<<"obj_c.B::m_c: "<<&obj_c.B::m_c<<endl;
	cout<<endl;
	cout<<endl;
	return 0;
}

