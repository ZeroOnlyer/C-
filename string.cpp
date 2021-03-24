#include<iostream>
using namespace std;

class String 
{
public:
	String(const char* str =nullptr)
	{
		if (str != nullptr)
		{
			m_data = new char[strlen(str) + 1];
			strcpy(this->m_data, str);
		}
		else
		{
			m_data = new char[1];
			*m_data = '\0';
		}
	}
	String(const String& other)
	{
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
	}
	~String(void)
	{
		delete[]m_data;
		m_data = nullptr;
	}
	//String&是为了支持连续的operator=赋值操作
	String& operator = (const String& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[]m_data;
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
		return *this;
	}
private:
	char  *m_data;
};

int main()
{
	String str1;
	String str2("hello");
	String str3 = "world";
	String str4 = str3;
	String str5(str3);
	str1 = str2;
	return 0;
}
