#include<iostream>
using namespace std;

/*
类模板  实现一个C++ STL里面的一个顺序容器  vector 向量容器
*/
//容器 空间配置器 allocator 做四件事情 内存开辟/内存释放  对象构造/对象析构

//定义容器的空间配置器，和C++标准库的allocator实现一样
template<typename T>
struct Allocator
{
	T* allocate(size_t size)//负责内存开辟
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//负责内存释放
	{
		free(p);
	}
	void construct(T* p, const T& val)//负责对象构造
	{
		new (p)T(val);//定位new
	}
	void destroy(T* p)//负责对象析构
	{
		p->~T();//~T()代表了T类型的析构函数
	}
};

//容器底层内存开辟，内存释放，对象构造和析构，都通过空间配置器

template<typename T,typename Alloc=Allocator<T>>
class vector
{
public:
	vector(int size = 10) 

	{
		//需要把内存开辟和对象构造分开处理
		//first = new T[size];
		first = allocator.allocate(size);
		last = first;
		end = first + size;
	}
	~vector()
	{
		//析构容器有效的元素，然后释放first指针指向的堆内存
		//delete[]first;
		for (T* p = first; p != last; ++p)
		{
			allocator.destroy(p);//把first指针指向的数组的有效元素进行析构操作
		}
		allocator.deallocate(first);//释放堆上的数组内存
		first = last = end = nullptr;
	}
	vector(const vector<T> &rhs)
	{
		int size = rhs.end - rhs.first;
		//first = new T[size];
		first = allocator.allocate(size);
		int len = rhs.last - rhs.first;
		for (int i = 0; i < len; ++i)
		{
			//first[i] = rhs.first[i];
			allocator.construct(first + i, rhs.first[i]);
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
	//	delete[] first;
		for (T* p = first; p != last; ++p)
		{
			allocator.destory(p);//把first指针指向的数组的有效元素进行析构操作
		}
		allocator.deallocate(first);//释放堆上的数组内存

		int size = rhs.end - rhs.first;

		//first = new T[size];
		first = allocator.allocate(size);
		int len = rhs.last - rhs.first;
		for (int i = 0; i < len; ++i)
		{
			//first[i] = rhs.first[i];
			allocator.construct(first + i, rhs.first[i]);
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
		//*last++ = val;  last指针指向的内存构造一个值为val的对象
		allocator.construct(last, val);
		last++;
	}
	void pop_back()
	{
		if (empty())
		{
			return;
		}
		//--last;  不仅要把last指针--，还需要析构删除的元素
		--last;
		allocator.destroy(last);
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
	Alloc allocator;//定义容器的空间

	void expand()
	{
		int size = end - first;
		//T* ptmp = new T[2 * size];
		T* ptmp = allocator.allocate(2 * size);
		for (int i = 0; i < size; ++i)
		{
			//ptmp[i] = first[i];
			allocator.construct(ptmp + i, first[i]);
		}
		//delete[]first;
		for (T* p = first; p != last; ++p)
		{
			allocator.destroy(p);
		}
		allocator.deallocate(first);
		first = ptmp;
		last = first + size;
		end = first + 2 * size;

	}
};

class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
	Test(const Test&)
	{
		cout << "Test(const Test&)" << endl;
	}

};
int  main()
{
	/*vector<int>vec;
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
	cout << endl;*/


	Test t1, t2, t3;
	cout << "-------------------" << endl;
	vector<Test>vec;
	vec.push_back(t1);
	vec.push_back(t2);
	vec.push_back(t3);
	cout << "---------------------" << endl;
	vec.pop_back();//需要析构对象，要把对象的析构和内存释放分离开来
	cout << "------------------------" << endl;
	return 0;
}
