#include <iostream>
using namespace std;

//1.定义类模板
template<typename T1,typename T2>
class Point
{
public:
	Point(T1 x,T2 y):m_x(x),m_y(y){}
	
public:
	T1 getX() const;
	void setX(T1 x);
	T2 getY() const;
	void setY(T2 Y);
	
private:
	T1 m_x;
	T2 m_y;
};


//2.定义成员函数
template<typename T1,typename T2>
T1 Point<T1,T2>::getX() const 
{
	return m_x;
}

template<typename T1,typename T2>
void Point<T1,T2>::setX(T1 x) 
{
	m_x = x;
	return;
}


int main()
{
	//3.使用类模板创建对象
	Point<int,int> p1(10,100);
	Point<int,float> p2(10,15.5);
	Point<float,char*> p3(12.4,"东经180度");

	int a = (int)"http://c.biancheng.net";  //强制转换（得到字符串的地址） 
	cout<<a<<endl;
}

