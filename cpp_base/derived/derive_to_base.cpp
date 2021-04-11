#include <iostream>
using namespace std;

//基类A
class A{
public:
    A(int a);
public:
    virtual void display();
protected:
    int m_a;
};
A::A(int a): m_a(a){ }
void A::display(){
    cout<<"Class A: m_a="<<m_a<<endl;
}

//中间派生类B
class B: public A{
public:
    B(int a, int b);
public:
    //void display();
protected:
    int m_b;
};

B::B(int a, int b): A(a), m_b(b){ }

// void B::display(){
    // cout<<"Class B: m_a="<<m_a<<", m_b="<<m_b<<endl;
// }


int main(){
    A *pa = new A(1);
    B *pb = new B(2, 20);
	
	pa = pb;
	pa->display();
	
    cout<<"-----------------------"<<endl;
    cout<<"pa="<<pa<<endl;
    cout<<"pb="<<pb<<endl;
	
    return 0;
}

















































