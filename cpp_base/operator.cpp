#include <iostream>
#include <cstring>

using namespace std;

class complex{
public:
	complex();
	complex(double real,double imag);
	complex operator+(const complex &A) const;
	void operator=(const complex &A);
	void display() const;
private:
	double m_real;
	double m_imag;
};

complex::complex():m_real(0.0),m_imag(0.0){}

complex::complex(double real,double imag):m_real(real),m_imag(imag)
{
	cout<<"the model: "<<this<<endl;
	cout<<"real: "<<real<<" "<<"imag: "<<imag<<endl;
	cout<<endl;
}

#if 0
complex complex::operator+(const complex &A) const
{
	complex B;
	B.m_real = this->m_real + A.m_real;
	B.m_imag = this->m_imag + A.m_imag;
	
	return B;
}
#else
complex complex::operator+(const complex &A)const{
    return complex(this->m_real + A.m_real, this->m_imag + A.m_imag);
}

#endif

void complex::operator=(const complex &A)
{
	cout<<"operator=(const complex &A)"<<endl;
    this->m_real = A.m_real;
	this->m_imag = A.m_imag;
	return;
}

void complex::display() const 
{
	cout<<m_real<<" + "<<m_imag<<"i"<<endl;
}


int main()
{
	complex c1(4.3, 5.8);
	complex c2(2.4, 3.7);
	complex c3;
	c3 = c1 + c2;//<==> c1.operator+(c2);
	c3.display();
	cout<<"c1: "<<&c1<<endl;
	cout<<"c2: "<<&c2<<endl;
	cout<<"c3: "<<&c3<<endl;
	
	return 0;
}





