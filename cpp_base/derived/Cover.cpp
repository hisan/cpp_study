#include <iostream>

using namespace std;

class Base
{
public:
	void func();
	void func(int);
};

void Base::func(){cout<<"Base::func()"<<endl;}
void Base::func(int a){cout<<"Base::func(int)"<<endl;}

class Derived:public Base
{
public:
	void func();
	void func(bool);
};

void Derived::func(){cout<<"Derived::func()"<<endl;}
void Derived::func(bool flag){cout<<"Derived::func(bool)"<<endl;}

int main()
{
    Derived d;
	d.func();
    d.func("c.biancheng.net");
    d.func(true);
    //d.func();  //compile error
    //d.func(10);  //compile error
    d.Base::func();
    d.Base::func(100);
	
	return 0;
}