#include <iostream>
#include <cstring>

using namespace std;

class Complex{
public:
	Complex(): m_real(0.0),m_imag(0.0){ }
	Complex(double real,double imag):m_real(real),m_imag(imag){ }
	Complex(double real): m_real(real),m_imag(0.0){}

public:
	Complex operator+(const Complex &A);
	
public:
	double real() const { return m_real; }
	double imag() const { return m_imag; }
	
public:
	double m_real;
	double m_imag;
};


Complex Complex::operator+(const Complex &A)
{
	this->m_real += A.m_real;
	this->m_imag += A.m_imag;
	return *this;
}

int main()
{
	Complex c1(25, 35);
	//Complex c2 = c1 + 15.6;
	Complex c3 = 28.23 + c1;
	
	//cout<<c2.real()<<" + "<<c2.imag()<<"i"<<endl;
	cout<<c3.real()<<" + "<<c3.imag()<<"i"<<endl;
	
	return 0;
}