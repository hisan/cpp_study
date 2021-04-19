#include <iostream>
#include <cstring>

using namespace std;


void modifyrvalue(int&& b)
{
	b = 30;
}

void rvalue()
{
	int && a = 10;
	modifyrvalue(10);
	
	cout<<a<<endl;
}

char *test(char *s)
{
	cout<<"S_addr: "<<(void *)&(s[0])<<endl;
	return &s[0];
}

int main()
{
	//rvalue();
	char *p = test("aaa");
	cout<<(void *)p<<endl;
	
	char *p1 = "aan";
	cout<<(void *)p1<<endl;	
	return 0;
}
