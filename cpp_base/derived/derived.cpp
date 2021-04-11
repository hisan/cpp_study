#include<iostream>
using namespace std;
//基类 Pelple
class People{

private:
    char *m_name;
public:
    int m_age;
};

//派生类 Student
class Student: public People{
public:
  
private:
    float m_score;
};


int main()
{
    People humen;
	Student stu;	
	cout<<"People: "<<sizeof(humen)<<" student: "<<sizeof(stu)<<endl;
	
	cout<<stu.m_age<<endl;
    return 0;
}