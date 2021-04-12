#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 1. 完成这个类的编写
class ValidIpWrapper {
public:
	ValidIpWrapper();//默认构造函数

	explicit ValidIpWrapper(const char* input) 
	{
		size_t size = strlen(input);
		content_ = new char[size + 1];
		content_[size] = '\0';
		memcpy(content_, input, size);
	}

	ValidIpWrapper(const ValidIpWrapper &SrcClass);//拷贝构造函数

	void operator=(const ValidIpWrapper &SrcClass);//赋值构造函数

	~ValidIpWrapper();//析沟函数

	bool IsAValid_Ipv4_Unit(char *ip4unit) const;//判断一个ip地址的一段是否合法

	// 说明：如果content_ 是一个合法的IPV4则返回 true，否则返回 false
	bool IsAValidIpv4() const;

private:
	char* content_ = nullptr;
  
};

//默认构造函数
ValidIpWrapper::ValidIpWrapper()
{
	content_ = new char[1];
	content_[0] = '\0';
}

//拷贝构造函数
ValidIpWrapper::ValidIpWrapper(const ValidIpWrapper &SrcClass)
{	
	size_t size = strlen(SrcClass.content_);
	content_ = new char[size + 1];
	content_[size] = '\0';
	memcpy(content_, SrcClass.content_, size);
}

//赋值构造函数
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

//析沟函数
ValidIpWrapper::~ValidIpWrapper()
{
	if (content_ != nullptr)
	{
		delete [] content_;
		content_ = nullptr;
	}
}

//判断ip地址的某一段是否合法
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

//判断一个ip地址是否合法
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
	
	while (content_[idx] != '\0')//提取ip字符串
	{
		if (content_[idx] == '.')
		{
			seq++;
			if (seq > 3)//避免出现x.x.x.x.x.x
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
			
			if (tmpindex > 2)//避免出现2222.x.x.x这种情况
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
		if (false == IsAValid_Ipv4_Unit(arrary[i]))//只要其中一段不合法,整个IP地址就不合法
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	while (1)
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
	}
	
	return 0;
}

