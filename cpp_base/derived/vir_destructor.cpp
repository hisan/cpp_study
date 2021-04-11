#include <iostream>
using namespace std;

class A
{
public:
	A();
	~A();
private:
	char *str;	
};


A::A()
{
	str = new char[100];
	cout<<"constructor::A"<<endl;
}

A::~A()
{
	delete [] str;
	cout<<"destructor::~A"<<endl;
}

class B:public A
{
public:
	B();
	~B();
private:
	char *name;	
};


B::B()
{
	name = new char[100];
	cout<<"constructor::B"<<endl;
}

B::~B()
{
	delete [] name;
	cout<<"destructor::~B"<<endl;
}

int main()
{
	A *pa = new B();
	delete pa;
	cout<<"---------------------"<<endl;
	B *pd = new B();
	delete pd;
	
	return 0;
}