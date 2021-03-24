#include<iostream>
using namespace std;

/*
类模板  实现一个C++ STL里面的一个顺序容器  vector 向量容器
*/
//容器 空间配置器

template<typename T>
class vector
{
public:
	vector(int size = 10) 
	{
		first = new T[size];
		last = first;
		end = first + size;
	}
	~vector()
	{
		delete[]first;
		first = last = end = nullptr;
	}
	vector(const vector<T> &rhs)
	{
		int size = rhs.end - rhs.first;
		first = new T[size];
		int len = rhs.last - rhs.first;
		for (int i = 0; i < len; ++i)
		{
			first[i] = rhs.first[i];
		}
		last = first + len;
		end = first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)
	{
		if (this == &rhs)
		{
			return this;
		}
		delete[] first;
		int size = rhs.end - rhs.first;
		first = new T[size];
		int len = rhs.last - rhs.first;
		for (int i = 0; i < len; ++i)
		{
			first[i] = rhs.first[i];
		}
		last = first + len;
		end = first + size;
		return *this;
	}
	void push_back(const T& val)
	{
		if (full())
		{
			expand();
		}
		*last++ = val;
	}
	void pop_back()
	{
		if (empty())
		{
			return;
		}
		--last;
	}
	T back()const
	{
		return *(last - 1);
	}
	bool full()const
	{
		return last == end;
	}
	bool empty()const
	{
		return first == last;
	}
	int size()const
	{
		return last - first;
	}
private:
	T* first;//指向数组起始的位置
	T* last;//指向数组中有效元素的后继位置
	T* end;//指向数组空间的后继位置

	void expand()
	{
		int size = end - first;
		T* ptmp = new T[2 * size];
		for (int i = 0; i < size; ++i)
		{
			ptmp[i] = first[i];
		}
		delete[]first;
		first = ptmp;
		last = first + size;
		end = first + 2 * size;

	}
};


int  main()
{
	vector<int>vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100);
	}
	vec.pop_back();
	while (!vec.empty())
	{
		cout << vec.back() << "  ";
		vec.pop_back();
	}
	cout << endl;
	return 0;
}
