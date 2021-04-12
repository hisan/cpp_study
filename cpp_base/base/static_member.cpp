#include <iostream>
using namespace std;

class static_t
{
public:

private:

	static int a;
};


void size_static_test()
{
	cout<<sizeof(static_t)<<endl;
}

int main()
{
	size_static_test();
	return 0;
}






















