#include <iostream>
#include <cstring>
using namespace std;

class String 
{
public:
	String(const char *str=NULL);
	String& operator = (const String& Other);
	String(const String& Other);
	~String();
	
	char *m_data = NULL;
};

//Ĭ�Ϲ���
String::String(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else 
	{
		int len = strlen(str);
		m_data = new char[len+1];
		strncpy(m_data,str,len);
		m_data[len] = '\0';
	}
}

String::~String()
{
	if (m_data != NULL)
	{
		delete [] m_data;
	}
}

//��ֵ����
String& String::operator = (const String& Other)
{
	cout<<"��ֵ����:"<<endl;
	if (this == &Other)
	{
		return *this;
	}
	
	delete [] m_data;
	int len = strlen(Other.m_data);
	m_data = new char[len+1];
	strcpy(m_data,Other.m_data);
	return *this;
}


int count = 0;

//��������
String::String(const String& Other)
{
	cout<<"��������:"<<++count<<endl;
	if (this != &Other)
	{
		if (m_data)
		{
			delete [] m_data;
		}
		
		int len = strlen(Other.m_data);
		m_data = new char[len+1];
		strcpy(m_data,Other.m_data);
	}
	else//�Լ����Լ���ʼ��ʱҲҪ��ֹ��ʼ��ʧ��
	{
		if (Other.m_data == NULL)
		{
			m_data = new char[1];
			m_data[0] = '\0';
		}
	}
}


int main()
{
	String str("abcdefghijklmnopqrstuvwxyz");
	String str2 = str;
	
	String str3;
	str3 = str2;
	printf("%s\n",str3.m_data);
	
	return 0;
}

	