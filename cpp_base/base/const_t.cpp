#include <iostream>
using namespace std;

void top_const_test()
{
	int i =10;
	int *const p = &i;
	
	cout<<*p<<endl;	
	
	//p = 20;//error
	*p = 20;//ok
	
	//顶层const,作用于本身p，p不可变，但是其引用的对象非const所以可变
	
	cout<<*p<<endl;	
}


void const_const_t()
{
	int const a = 100;
	
	#if 0
	int *const p = &a;
	

	 error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
	int *const p = &a;
	p是const的，但是const p指向的int是非const的，所以不能将一个const int赋给p
	#endif 
	
}

void int_pointer_test()
{
	const int &a = 10;
	cout<<(void *)&a<<endl;
	
	printf("0x%x\n",&a);
	
	int b = 200;
	int *p = &b;
	
	cout<<p<<endl;
	cout<<(void *)&p<<endl;
}

void const_cast_t()
{
	int a = 10;
	const int b = 20;
	
	//int *p = &b;//error: const int * to int *
	
	const int *p1 = &b;//ok
	//p1 = &a;//ok
	
	int *p = const_cast<int *>(&b);//OK
	*p = 560;
	cout<<b<<endl;//输出依旧是20，说明将const通过const_cast转换为非const后，对其修改是未定义的。
	
	//int *const p2 = &b;//error： p2是常量，而p2指向的int是非常量，b是常量
	//这个等价于: int *p = &b;//error
}


void cast_const_t()
{
	;
}

int main()
{
	const_cast_t();
	return 0;
}






















