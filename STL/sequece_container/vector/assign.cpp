#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> first;
	vector<int> second;
	vector<int> third;
	
	first.assign(7,100);
	vector<int>::iterator it;
	
	it = first.begin()+1;
	second.assign(it,first.end()-1);
	
	int myints[] = {1776,7,4};
	third.assign(myints,myints+3);
	
	cout<<"size of first: "<< int (first.size())<<'\n';
	cout<<"size of second: "<< int (second.size())<<'\n';
	cout<<"size of third: "<< int (third.size())<<'\n';
}