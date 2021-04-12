#include <iostream>
#include <string>
using namespace std;

int sequence = 1;

class Sales_data{
public:
	Sales_data(string s,unsigned cnt,double price):bookNo(s),units_sold(cnt),revenue(cnt*price){cout<<"Sales_data(string s,unsigned cnt,double price):bookNo(s),units_sold(cnt),revenue(cnt*price) sequence:"<<sequence++<<endl;}
	
	Sales_data():Sales_data("",0,0){cout<<"Sales_data() sequence:"<<sequence++<<endl;}
	
	Sales_data(string s):Sales_data(s,0,0){cout<<"Sales_data(string s) sequence:"<<sequence++<<endl;}
	
	Sales_data(istream &is):Sales_data(){cout<<"Sales_data(istream &is) sequence:"<<sequence++<<endl;}
private:
	string bookNo;
	unsigned units_sold;
	double revenue;
};


int main()
{
	string str("aaa");
	Sales_data sdata(str);
	return 0;
}	

