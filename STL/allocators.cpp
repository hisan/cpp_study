#include <cstddef>
#include <iostream>
#include <vector>
#include <new>

using namespace std;

template<typename type>
struct MyAlloc : allocator<type> {
	
	template<typename U>
    struct rebind
    {
        typedef Allocator<U> other;
    };
	
	type * allocate(size_t size){
		cout<<" Allocation request size ==> "<<size<<endl;
		return new type[size];
	}
	
	void deallocation(type &ptr,size_t size){
		cout<<"Deallocation size ==> "<<size<<endl;
		delete [] ptr;
	}
};

int main()
{
	vector<int, MyAlloc<int> > v1;
	v1.push_back(10);
	
	cout<<"size: "<<v1.size()<<endl;
	
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	
	cout<<"size: "<<v1.size()<<endl;
	
	for (auto &val : v1)
	{
		cout<<val<<endl;
	}
	
	return 0;
}



