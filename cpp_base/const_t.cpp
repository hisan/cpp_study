#include <iostream>
using namespace std;

void top_const_test()
{
	int i =10;
	int *const p = &i;
	
	cout<<*p<<endl;	
	
	//p = 20;//error
	*p = 20;//ok
	
	//����const,�����ڱ���p��p���ɱ䣬���������õĶ����const���Կɱ�
	
	cout<<*p<<endl;	
}


void const_const_t()
{
	int const a = 100;
	
	#if 0
	int *const p = &a;
	

	 error: invalid conversion from ��const int*�� to ��int*�� [-fpermissive]
	int *const p = &a;
	p��const�ģ�����const pָ���int�Ƿ�const�ģ����Բ��ܽ�һ��const int����p
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
	cout<<b<<endl;//���������20��˵����constͨ��const_castת��Ϊ��const�󣬶����޸���δ����ġ�
	
	//int *const p2 = &b;//error�� p2�ǳ�������p2ָ���int�Ƿǳ�����b�ǳ���
	//����ȼ���: int *p = &b;//error
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






















