#include <iostream>
using namespace std;

class A{
public:
	void display();
protected:
    int a1;
    int a2;
};

void A::display()
{
	cout<<"this: "<<(void *)this<<endl;
	cout<<"a1: "<<&a1<<endl;
	cout<<"a2: "<<&a2<<endl;
	cout<<endl;
	cout<<endl;
}


class B: virtual public A{
public:
	void display();
protected:
    int b1;
    int b2;
};

void B::display()
{
	cout<<"this: "<<(void *)this<<endl;
	cout<<"a1: "<<&a1<<endl;
	cout<<"a2: "<<&a2<<endl;
	cout<<"b1: "<<&b1<<endl;
	cout<<"b2: "<<&b2<<endl;
	cout<<endl;
	cout<<endl;
}

class C: virtual public B{
public:
	void display();
protected:
    int c1;
    int c2;
};

void C::display()
{
	cout<<"this: "<<(void *)this<<endl;
	cout<<"a1: "<<&a1<<endl;
	cout<<"a2: "<<&a2<<endl;
	
	cout<<"b1: "<<&b1<<endl;
	cout<<"b2: "<<&b2<<endl;
	
	cout<<"c1: "<<&c1<<endl;
	cout<<"c2: "<<&c2<<endl;
	
	cout<<endl;
	cout<<endl;
}


class D: public C{
public:
	void display();
protected:
    int d1;
    int d2;
};


void D::display()
{
	cout<<"this: "<<(void *)this<<endl;
	cout<<"a1: "<<&a1<<endl;
	cout<<"a2: "<<&a2<<endl;
	cout<<"b1: "<<&b1<<endl;
	cout<<"b2: "<<&b2<<endl;
	cout<<"c1: "<<&c1<<endl;
	cout<<"c2: "<<&c2<<endl;
	cout<<"d1: "<<&d1<<endl;
	cout<<"d2: "<<&d2<<endl;
	
	cout<<endl;
	cout<<endl;
}


int main(){
    A obj_a;
    B obj_b;
    C obj_c;
    D obj_d;
	
	obj_a.display();
	obj_b.display();
	obj_c.display();
	obj_d.display();
	
    return 0;
}








