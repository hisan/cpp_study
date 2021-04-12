#include <iostream>

using namespace std;

char get_char()
{
	return 'a';
}

int main()
{
	decltype(get_char()) character;
	cout<<"value:"<<character<<endl;
	cout<<"size:"<<sizeof(character)<<endl;
	return 0;
}