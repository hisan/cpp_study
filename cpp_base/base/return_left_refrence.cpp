#include <iostream>

using namespace std;

char &get_val(string &str,int idx)
{
    return str[idx];
}

char *get_val_c(const char *p,int idx)
{
	return (char *)&p[idx];
}

int main()
{
    string s("a value");
    cout<<s<<endl;
    get_val(s,0) = 'A';
    cout<<s<<endl<<endl<<endl;
	
	get_val_c(s.c_str(),2) = 'B';
	
	#if 0
	return_left_refrence.cpp: In function ��int main()��:
	return_left_refrence.cpp:22:25: error: lvalue required as left operand of assignment
    get_val_c(s.c_str(),2) = 'B';
	#endif
	
	����˵�����õı��ʾ��������õı����ı�����
	cout<<s<<endl<<endl<<endl;
	
    return 0;
}