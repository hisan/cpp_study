#include <iostream>
using namespace std;


class Screen 
{
public:
	Screen(int count) {access_cstr = count;}
	void some_member() const;
	
private:
	mutable size_t access_cstr;
	int a = 10;
};

void Screen::some_member() const
{
	access_cstr++;
	//a++;				//error
	cout<<access_cstr<<endl;
}


void  mutable_test()
{
	Screen sc(100);
	sc.some_member();	
}

class empty
{
	
};

int main()
{
	cout<<sizeof(empty)<<endl;	
	return 0;
}