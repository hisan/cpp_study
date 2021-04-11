#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> process_1()
{
	vector<string> str1 = {"watermelon"};
	cout<<(void *)&str1<<endl;
	
	vector<string> str2 = {"banana"};
	cout<<(void *)&str2<<endl;
	
	vector<string> str3 = {"apple"};
	cout<<(void *)&str3<<endl;
	
	return {str1,str2,str3};
}

vector<string> process_2()		//OK
{
	return {"watermelon","banana","apple"};
}

int main()
{
	//vector<string> vstr = process_2();
	vector<vector<string>> vstr = process_1();
	cout<<vstr.size()<<endl<<endl<<endl;
	
	for (auto v:vstr)
	{
		cout<<v[0]<<endl;
		
		cout<<(void *)&v<<endl;
	}
	
    return 0;
}