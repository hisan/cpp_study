#include <iostream>
using namespace std;
int main()
{
	int num = 10;
	int &&rval = 10;
	
	rval = 30;
	cout<<rval<<endl;
	//30
	
	return 0;
}