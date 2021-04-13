#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	// sequence container
	int arr[] = {100,20,300,45,55};
	int *begin = &arr[0];
	int *end = &arr[0] + (sizeof(arr)/sizeof(arr[0]));
	
	
	sort(begin,end);
	//iterator are similar to pointers...
	
	for (;begin != end;begin++)
	{
		cout<<"val: = > "<<*begin<<endl;
	}
	
	return 0;
}
