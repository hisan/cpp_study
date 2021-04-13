#include <iostream>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;


//Functional Programing with Map(),Filter() &Reduce()
int main()
{
	//map - transform 
	vector<int> v {1,2,3,4,5,6,7};
	vector<int> vout;
	
	//map
	transform(v.begin(),v.end(),back_inserter(vout),[](int & value){return value * 3;});

	
	//filter
	vector<int>::iterator endfilter = remove_if(vout.begin(),vout.end(),[](int &value){
		if (value % 2 == 0){
			return true;
		}else {
			return false;
		}
	});
	
	for (auto itr = vout.begin();itr != endfilter;itr++)
	{
		cout<<*itr<<endl;
	}
	
	//reduce
	int finaval = accumulate(vout.begin(),endfilter,0,[](int first,int second){ return first + second;});
	cout<<"Finaval value: "<<finaval<<endl;
	
	return 0;
}

