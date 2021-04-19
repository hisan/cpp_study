#include <iostream>
using namespace std;

class first
{
public:
	first():num(new int(0))
	{
		cout<<"first construct!"<<endl;
	}
	
	first(first &&d):num(d.num)
	{
		d.num = NULL;
		cout<<"first move constructor!"<<endl;
	}
	
public:
	int *num;
};

class second
{
public:
	second():fir()
	{
		cout<<"second construct!"<<endl;
	}
	
	second(second && sec):fir(move(sec.fir))
	{
		cout<<"second move construct!"<<endl;
	}
public:
	first fir;
};

int main()
{	
	second oth;
	second oth2 = move(oth);
    return 0;
}

#if 0
	first construct!
	second construct!
	first move constructor!
	second move construct!
#endif
