#include<iostream>
using namespace std;
//���� Pelple
class People{

private:
    char *m_name;
public:
    int m_age;
};

//������ Student
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