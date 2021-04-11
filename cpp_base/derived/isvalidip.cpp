#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 1. ��������ı�д
class ValidIpWrapper {
public:
	ValidIpWrapper();//Ĭ�Ϲ��캯��

	explicit ValidIpWrapper(const char* input) 
	{
		size_t size = strlen(input);
		content_ = new char[size + 1];
		content_[size] = '\0';
		memcpy(content_, input, size);
	}

	ValidIpWrapper(const ValidIpWrapper &SrcClass);//�������캯��

	void operator=(const ValidIpWrapper &SrcClass);//��ֵ���캯��

	~ValidIpWrapper();//��������

	bool IsAValid_Ipv4_Unit(char *ip4unit) const;//�ж�һ��ip��ַ��һ���Ƿ�Ϸ�

	// ˵�������content_ ��һ���Ϸ���IPV4�򷵻� true�����򷵻� false
	bool IsAValidIpv4() const;

private:
	char* content_ = nullptr;
  
};

//Ĭ�Ϲ��캯��
ValidIpWrapper::ValidIpWrapper()
{
	content_ = new char[1];
	content_[0] = '\0';
}

//�������캯��
ValidIpWrapper::ValidIpWrapper(const ValidIpWrapper &SrcClass)
{	
	size_t size = strlen(SrcClass.content_);
	content_ = new char[size + 1];
	content_[size] = '\0';
	memcpy(content_, SrcClass.content_, size);
}

//��ֵ���캯��
void ValidIpWrapper::operator=(const ValidIpWrapper &SrcClass)
{
	int len = strlen(SrcClass.content_);
	if (content_ != nullptr)
	{
		delete [] content_;
	}
	
	content_ = new char[len+1];
	content_[len] = '\0';
    memcpy(content_, SrcClass.content_,len);
}

//��������
ValidIpWrapper::~ValidIpWrapper()
{
	if (content_ != nullptr)
	{
		delete [] content_;
		content_ = nullptr;
	}
}

//�ж�ip��ַ��ĳһ���Ƿ�Ϸ�
bool ValidIpWrapper::IsAValid_Ipv4_Unit(char *ip4unit) const
{
	if (ip4unit == nullptr)
	{
		return false;
	}
	
	int len = strlen(ip4unit);
	int num = 0;
	int res = 1;
	for (int i =len-1;i>=0;--i)
	{
		num += res*(ip4unit[i] - '0');
		res *=10;
	}
	
	if (num > 256)
	{
		return false;
	}
	
	return true;
}

//�ж�һ��ip��ַ�Ƿ�Ϸ�
bool ValidIpWrapper::IsAValidIpv4() const
{
	if (content_ == nullptr)
	{
		return false;
	}
	int seq = 0;
	int idx = 0;
	int tmpindex = 0;
	char arrary[4][4] = {0};
	
	while (content_[idx] != '\0')//��ȡip�ַ���
	{
		if (content_[idx] == '.')
		{
			seq++;
			if (seq > 3)//�������x.x.x.x.x.x
			{
				return false;
			}
			
			tmpindex = 0;
		}
		else 
		{
			if (content_[idx] < '0' || content_[idx] > '9')
			{
				return false;
			}
			
			if (tmpindex > 2)//�������2222.x.x.x�������
			{
				return false;
			}
			
			arrary[seq][tmpindex] = content_[idx];
			tmpindex++;
		}
		idx++;
	}
	
	if (seq != 3)
	{
		return false;
	}
	
	for (int i = 0;i <= seq;i++)
	{
		//cout<<arrary[i]<<endl;
		if (false == IsAValid_Ipv4_Unit(arrary[i]))//ֻҪ����һ�β��Ϸ�,����IP��ַ�Ͳ��Ϸ�
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	string ipstring;
	cin>>ipstring;
	
	ValidIpWrapper tmp1(ipstring.c_str());
	std::cout << (tmp1.IsAValidIpv4() ? "true" : "false") << std::endl;
	
	ValidIpWrapper tmp2 = tmp1;
	std::cout << (tmp2.IsAValidIpv4() ? "true" : "false") << std::endl;
	
	ValidIpWrapper tmp3;
	tmp3 = tmp1;
	std::cout << (tmp3.IsAValidIpv4() ? "true" : "false") << std::endl;
	
	return 0;
}

