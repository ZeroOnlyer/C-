#include<iostream>
#include<queue>
#include<set>
using namespace std;

int main()
{
	priority_queue<int> que1;
	for (int i = 0; i < 10; ++i)
	{
		que1.push(rand() % 100);
	}
	while (!que1.empty())
	{
		cout << que1.top() << " ";
		que1.pop();
	}
	cout << endl;

	using MinHeap = priority_queue<int, vector<int>, greater<int>>;
	MinHeap que2;
	for (int i = 0; i < 10; ++i)
	{
		que2.push(rand() % 100);
	}
	while (!que2.empty())
	{
		cout << que2.top() << " ";
		que2.pop();
	}
	cout << endl;



	return 0;
}







#if 0
/*
函数对象  =>c语言里面的函数指针


//使用c的函数指针解决方案
template<typename T>
bool mygreater(T a, T b)
{
	return a > b;
}

template<typename T>
bool myless(T a, T b)
{
	return a < b;
}



1.通过函数对象调用operator（），可以省略函数的调用开销，比通过函数指针调用函数（不能够inline内联调用）效率高
2.因为函数对象是用类生成的，所以可以添加相关的成员变量，用来记录函数对象使用时更多的信息

*/
//C++函数对象的版本实现
template<typename T>
class mygreater
{
public:
	bool operator()(T a, T b)
	{
		return a > b;
	}
};

template<typename T>
class myless
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
};


template<typename T,typename Compare>
bool compare(T a, T b,Compare comp)
{  //operator()(a,b);
	return comp(a, b);//通过函数指针调用函数，是没有办法内联的，效率很低，因为有函数调用开销
}
int main()
{
	cout << compare(10, 20,mygreater<int>()) << endl;
	cout << compare('b', 'y',myless<int>()) << endl;

	return 0;
}
#endif
