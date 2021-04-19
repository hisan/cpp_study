#include <iostream>
using namespace std;

void oth(int &t)
{
	cout<<"lvalue\n";
}

void oth(const int &t)
{
	cout<<"rvalue\n";
}

template <typename T>
void function(const T& t)
{
	oth(t);
}

template <typename T>
void function(T& t)
{
	oth(t);
}

int main()
{
	function(5);
	int x = 1;
	function(x);
	
	#if 0
	rvalue
	lvalue
	#endif 
	
	return 0;
}
