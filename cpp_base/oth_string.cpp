#include <iostream>
#include <cstring>

using namespace std;

class String{
public:
    // Ĭ�Ϲ��캯��
    String(const char *str = nullptr);
    // �������캯��
    String(const String &str);
    // ��������
    ~String();
    // �ַ�����ֵ����
    String& operator=(const String &str);
    char *m_data;
    int m_size;
};

// ���캯��
String::String(const char *str)
{
    if(str == nullptr)  // �ӷֵ㣺��m_data��NULL �ж�
    {
        m_data = new char[1];   // �÷ֵ㣺�Կ��ַ����Զ������Ž�����־'\0'��
        m_data[0] = '\0';
        m_size = 0;
    }
    else
    {
        m_size = strlen(str);
        m_data = new char[m_size + 1];
        strcpy(m_data, str);
    }
}

int count=0;

// �������캯��
String::String(const String &str)   // �÷ֵ㣺�������Ϊconst��
{
	cout<<"operator:"<<count++<<endl;
	
    m_size = str.m_size;
    m_data = new char[m_size + 1];  //�ӷֵ㣺��m_data��NULL �ж�
    strcpy(m_data, str.m_data);
}

// ��������
String::~String()
{
    delete[] m_data;
}


// �ַ�����ֵ�������Ƽ�ʹ�ã�
// ��֤���쳣��ȫ��
String& String::operator=(const String &str)
{
	cout<<"operator"<<endl;
    if(this != &str)
    {
        String strTemp(str);

        char* pTemp = strTemp.m_data;
        strTemp.m_data = m_data;
        m_data = pTemp;
    }
    return *this;
}



int main()
{
	String str = "abcdefghijklmnopqrstuvwxyz";
	String str2(str);
	
	String str3 = str2;
	printf("%s\n",str3.m_data);
	
	return 0;
}