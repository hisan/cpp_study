#include <iostream>
using namespace std;

#if 0

template <typename T>
void Swap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

#else

template<class T> 
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif


int main()
{
	int a = 10, b = 20;
	
	Swap(a,b);
	
	cout<<"a: "<<a<<" b: "<<b<<endl;
	
	return 0;
}

