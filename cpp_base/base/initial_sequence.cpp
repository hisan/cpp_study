#include <iostream>
#include <string>
using namespace std;

class sequence
{
public:
	sequence():a(a+1),str("bbb"){cout<<a<<endl;cout<<str<<endl;}
	
private:
	int a = 10;
	string str{"aaa"};
};

void initial_sequence_t()
{
	sequence sequence_t;
}

class third
{
	int a;
};


class ConstRef
{
public:
	ConstRef(int ii);	
private:
	int i;
	const int ci;
	int &ri;
	third ctf;
};

ConstRef::ConstRef(int ii):ci(ii),ri(ii)
{
	cout<<i<<endl;
}



void constref_t()
{
	ConstRef cref(10);
}


int main()
{
	constref_t();
	return 0;
}	

