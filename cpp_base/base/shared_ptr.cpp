#include <iostream>
#include <memory>

using namespace std;

int main()
{
	//shared_ptr<T> 类型的空智能指针
	shared_ptr<int> p1;
	shared_ptr<int> p2(nullptr);
	
	//在构建 shared_ptr 智能指针，也可以明确其指向
	shared_ptr<int> p3(new int(10));
	shared_ptr<int> p4 = make_shared<int>(10);
	
	//通过拷贝构造函数
	shared_ptr<int> p5(p4);
	
	//通过移动构造函数
	shared_ptr<int> p6(move(p5));
	
	return 0;
}