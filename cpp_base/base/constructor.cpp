#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Sales_data 
{
public:
	Sales_data() = default;
	Sales_data(int arga) {a = arga;}
	Sales_data(string& pstr):str(pstr) {cout<<str<<endl;}

	Sales_data  &combine(const Sales_data &);
	
private:
	int a = 10;
	string str;
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
	
	string str("aaa");
	Sales_data sobj3(str);
	
	cout<<"sobj2 address: "<<(void *)&sobj2<<endl<<endl;
	sobj.combine(sobj2);
}


void class_assigment()
{
	string str("bbb");
	Sales_data sobj3(str);
	Sales_data sobj4;
	sobj4 = sobj3;
	cout<<sobj4.str<<endl;
}

int main()
{
	class_assigment();
	return 0;
}