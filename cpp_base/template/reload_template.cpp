#include <iostream>
using namespace std;

template<class T>void Swap(T &a,T &b);
template<typename T>void Swap(T a[],T b[],int len);

void printArray(int *arr, int size);


int main()
{
	int m = 10,n = 99;
	Swap(m,n);
	cout<<m<<", "<<n<<endl;
	
	int a[5] = {1,2,3,4,5};
	int b[5] = {10,20,30,40,50};
	
	int len = sizeof(a)/sizeof(a[0]);
	Swap(a,b,len);
	printArray(a,len);
	printArray(b,len);
}

template<class T>void Swap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>void Swap(T a[],T b[],int len)
{
	T temp;
    for(int i=0; i<len; i++)
	{
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        if(i == size-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<", ";
        }
    }
}