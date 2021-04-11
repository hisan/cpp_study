#include <iostream>
using namespace std;

class A
{
public:
	A(int a,string &name);
	void display();
public:
	int m_a;
	string samename;
};

A::A(int a,string &name):m_a(a),samename(name){ }
void A::display()
{
	cout<<"m_a= "<<m_a<<endl;
	cout<<"name= "<<samename<<endl;
	cout<<endl;
}

class B
{
public:
	B(int b,string &name);
	void display();
public:
	int m_b;
	string samename;
};

B::B(int b,string &name):m_b(b),samename(name){ }

void B::display()
{
	cout<<"m_b= "<<m_b<<endl;
	cout<<"name= "<<samename<<endl;
	cout<<endl;
}

class C:public A,public B
{
public:
	C(int a,int b,int c,string &nameA,string& nameB);
	void display();
public:
	int m_c;
};

C::C(int a,int b,int c,string &nameA,string& nameB):A(a,nameA),B(b,nameB),m_c(c){ }

void C::display()
{
	cout<<"m_c= "<<m_c<<endl;
	cout<<endl;
}

int main()
{
	string nameA = "AAA";
	string nameB = "BBB";
	
	A obj_a(41,nameA);
	obj_a.display();
	cout<<"obj_a: "<<&obj_a<<endl;
	cout<<"obj_a.m_a: "<<&obj_a.m_a<<endl;
	cout<<"obj_a.samename: "<<&obj_a.samename<<endl;
	cout<<endl;
	cout<<endl;
	
	
	B obj_b(42,nameB);
	obj_b.display();
	cout<<"obj_b: "<<&obj_b<<endl;
	cout<<"obj_b.m_b: "<<&obj_b.m_b<<endl;
	cout<<"obj_b.samename: "<<&obj_b.samename<<endl;
	cout<<endl;
	cout<<endl;
	
	C obj_c(3,1,2,nameA,nameB);
	obj_c.display();
	cout<<"obj_c: "<<&obj_c<<endl;
	cout<<"obj_c.m_c: "<<&obj_c.m_c<<endl;
	cout<<endl;
	cout<<endl;
	
	cout<<"obj_c.m_a "<<&obj_c.m_a<<endl;
	cout<<"obj_c.m_b: "<<&obj_c.m_b<<endl;
	
	//cout<<"obj_c.samename: "<<&obj_c.samename<<endl;//error:request for member ¡®samename¡¯ is ambiguous
	cout<<"obj_c.A::samename: "<<obj_c.A::samename<<endl;
	cout<<"obj_c.B::samename: "<<obj_c.B::samename<<endl;
	
	cout<<"obj_c.A::samename: "<<&obj_c.A::samename<<endl;
	cout<<"obj_c.B::samename: "<<&obj_c.B::samename<<endl;
	
	
	return 0;
}

