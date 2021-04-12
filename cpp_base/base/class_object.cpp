#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Sales_data 
{
public:
	Sales_data(int arga){a = arga;}
	int a;
	Sales_data  &combine(const Sales_data &);
};

Sales_data  &Sales_data::combine(const Sales_data &rhs)
{
	a += rhs.a;
	cout<<"this :"<<this<<endl;
	return *this;
}

void class_test()
{
	Sales_data sobj(0);
	cout<<"sobj address: "<<(void *)&sobj<<endl<<endl;
	Sales_data sobj2(5);
	cout<<"sobj2 address: "<<(void *)&sobj2<<endl<<endl;
	sobj.combine(sobj2);
}

int main()
{
	class_test();
	return 0;
}