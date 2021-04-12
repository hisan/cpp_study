#include <iostream>
#include <cstring>

using namespace std;

class complex{
public:
	complex(double real = 0.0,double imag = 0.0):m_real(real),m_imag(imag){}
	void display(){cout<<"m_real: "<<m_real<<" m_imag: "<<m_imag<<endl;}
	
public:
	friend complex operator+(const complex &A,const complex &B);
	
	friend istream & operator>>(istream & in, const complex &A);
	friend ostream & operator<<(ostream & out, const complex &A);
	
public:
	double m_real;
	double m_imag;
};



complex operator+(const complex &A,const complex &B)
{
	complex C;
	C.m_real = A.m_real + B.m_real;
	C.m_imag = A.m_imag + B.m_imag;
	
	return C;
}

istream & operator>>(istream & in, const complex &A)
{
	in>>A.m_real >> A.m_imag;
	return in;
}

ostream & operator<<(ostream & out, const complex &A)
{
	out<<A.m_real <<" "<< A.m_imag;
	return out;
}

int main()
{
	complex c1(12,23);
	complex c2(56,78);
	complex c3 = c1 + c2;
	c3.display();
	
	cout<<c3<<endl;
	
	return 0;
}




