#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//����һ������ָ��
char *(*func)(int,char *);

char *getstring(int size,char *string)
{
	char *res = (char *)malloc(size+1);
	strncpy(res,string,size);
	res[size] = '\0';
	
	return res;
}

void func_test()
{
	func = getstring;//���ú���ָ�븳ֵ
	
	char *res = func(strlen("aaaaa"),"aaaaa");
	
	cout<<res<<endl;
	free(res);
}

int main()
{
	func_test();
	return 0;
}	

