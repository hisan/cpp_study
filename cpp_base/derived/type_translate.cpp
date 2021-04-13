#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0,double imag = 0.0):m_real(real),m_imag(imag){}

public:
	friend ostream &operator<<(ostream &out,Complex &c);
	friend Complex operator+(const Complex &c1,const Complex &c2);
	operator double() const {return m_real;}//类型转换函数
private:
	double m_real;
	double m_imag;
};


ostream &operator<<(ostream &out,Complex &c)
{
	out<<c.m_real<<" + "<<c.m_imag<<"i";
	return out;
}

Complex operator+(const Complex &c1,const Complex &c2)
{
	Complex c;
	c.m_real = c1.m_real + c2.m_real;
	c.m_imag = c1.m_imag + c2.m_imag;
	
	return c;
}


int main()
{
	Complex c1(24.6,100);
	double f = c1;
	c1 = 78.4;
	f = 12.5 + c1;
	
	#if 0
	即可以对12.5调用转换构造函数，也可以对c1执行类型转换函数，所以造成了二义性
	#endif
	
	Complex c2 = c1 + 46.7;	
	return 0;
}