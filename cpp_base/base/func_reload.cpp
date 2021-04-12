#include <iostream>
using namespace std;

void printstr(char *p)
{
	cout<<"arg type: char *"<<endl;
	cout<<p<<endl<<endl;
}

void printstr(string *p)
{
	cout<<"arg type: string &"<<endl;
	cout<<p<<endl<<endl;
}

void printstr(const string *const p)
{
	cout<<"arg type: string &"<<endl;
	cout<<p<<endl<<endl;
}

void load_test()
{
	string a("asdknvcaslkcmasc");
	printstr("abcd");
	printstr(&a);
}


//这两函数也是重载，一个参数类型是const string ,一个是string的
const string &shorterString(const string &s1,const string &s2)
{
	return s1.size() <= s2.size()?s1:s2;
}

string &shorterString(string &s1,string &s2)
{
	auto &r = shorterString(s1,s2);
	return const_cast<string &>(r);
}

int main()
{
	// string &s1 = const_cast<string &>("abc");//error
	// string &s2 = const_cast<string &>("def");//error
	
	string &s1 = static_cast<string &>("abc");//error
	string &s2 = static_cast<string &>("def");//error
	
	cout<<shorterString(s1,s2)<<endl;
    
	return 0;
}	

	
		
		
		
		
		
		
		
		
			
		
	