#include <iostream>
#include <initializer_list>

using namespace std;

void print_var(initializer_list<int> lst)
{
	cout<<(void *)&lst<<endl;
	
	cout<<lst.size()<<endl<<endl;
	
	for (auto a:lst)
	{
		cout<<a<<endl;
	}
}

void initializer_list_test()
{
	initializer_list<int> lst{1,2,3,4,5,6};	
	
	initializer_list<int> lst2{1,2,3,4,5,6,7,9,10,1,2,3,1234,123451234};	
	//print_var(lst);
	print_var(lst2);
}


int main()
{
	initializer_list_test();
	
	return 0;
}

