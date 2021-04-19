#include <iostream>
using namespace std;
class demo{
public:
    demo():num(new int(0)){
        cout<<"construct!"<<endl;
    }

    demo(const demo &d):num(new int(*d.num)){
        cout<<"copy construct!"<<endl;
    }
    //添加移动构造函数
    demo(demo &&d):num(d.num){
        d.num = NULL;
        cout<<"move construct!"<<endl;
    }
    ~demo(){
        cout<<"class destruct!"<<endl;
    }
public:
    int *num;
};

demo get_demo(){
    return demo();
}


int main(){
    demo a;
	cout<<"a:\n"<<endl;
	demo b = demo();
	cout<<"b:\n"<<endl;
	cout<<*b.num<<endl<<endl;
	
	demo c = move(a);
	cout<<"c:\n"<<endl;
	
	cout<<*c.num<<endl<<endl;//ok
	
	#if 0
	交换而非深拷贝,交换以后a.num = NULL了。
	cout<<*a.num<<endl<<endl;
	Segmentation fault (core dumped)
	#endif 
	
    return 0;
}

#if 0
construct!
a:

construct!
b:

0

move construct!
c:

class destruct!
class destruct!
class destruct!

#endif