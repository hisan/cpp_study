#include <iostream>
#include <string>
using namespace std;

typedef string::size_type sz;

void screen(sz ht = 24,sz wid = 80,char backgrnd = ' ')
{
	cout<<"ht:"<<ht<<" wid:"<<wid<<" backgrnd:"<<backgrnd<<endl;
}


void real_arg_t()
{
	//screen();//ok
	
	//screen(,,'a');//error
	
	screen('a');//ok,����û�дﵽĿ��
	
	
}

int main()
{
	real_arg_t();
	return 0;
}	

