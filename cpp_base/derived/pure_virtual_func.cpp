#include <iostream>
using namespace std;

class Line
{
public:
	Line::Line(float len):m_len(len){}
	virtual float area()=0;
	virtual float volume()=0;
protected:
	float m_len;
};

class Rect:public Line
{
public:
	Rect::Rect(float len，float width):Line(len),m_width(width){}
	virtual float area()=0;
	virtual float volume()=0;
protected:
	float m_len;
};

int main()
{
	A *pa = new B();
	delete pa;
	cout<<"---------------------"<<endl;
	B *pd = new B();
	delete pd;
	
	return 0;
}
