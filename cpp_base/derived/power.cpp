#include <iostream>
#include <cstring>

using namespace std;

class People{
public:
	People(int age,char *name);//:m_age(age);
	void show();
	
protected:
    char *m_name = NULL;
    int m_age;
};

void People::show()
{
	cout<<m_name<<"'s age is: "<<m_age<<endl;
}


People::People(int age,char *name):m_age(age),m_name()
{
	int len = strlen(name);
	m_name = new char[len+1];
	strncpy(m_name,name,len);
	m_name[len] = '\0';
}

class Student: public People{
public:
	Student(int age,float score,char *name):People(age,name),m_score(score){}
public:
    float m_score;
	using People::m_name;
	using People::m_age;
private:
	using People::show;
};

int main()
{
    People humen(40,"michael");
	Student stu(20,99.9,"lee");	
	
	humen.show();
    stu.show();
	
	return 0;
}
