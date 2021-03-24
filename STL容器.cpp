#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

/*
标准容器-容器适配器 => 设计模式，就叫做适配器模式
怎么理解这个适配器？
1.适配器底层没有自己的数据结构，它是另外一个容器的封装，它的方法全部由底层依赖的容器进行实现的
2.没有实现自己的迭代器
template<typename T,typename Container=deque<T>>
class Stack
{
public:
	void push(const T& val) { con.push_back(val); }
	void pop() { con.pop_back(); }
	T top()const { return con.back(); }
private:
	Container con;
};
stack：push入栈  pop出栈 top查看栈顶元素  empty判断栈空  size返回元素个数
stack =>deque 为什么不依赖vector呢？
queue：push入队 pop出队 front查看队头元素 back查看队尾元素 empty判断队空 size返回元素个数
queue => deque 为什么不依赖vector呢？
1.vector的初始内存使用效率太低了！没有deque好
2.对于queue来说，需要支持尾部插入，头部删除，时间复杂度最好是O(1)，如果queue依赖vector，那么出队效率很低
3.vector需要大片的连续内存，deque只需要分段的内存，当存储大量数据时，显然deque对于内存的利用率更好一些
priority_queue：push入队 pop出队 top查看队顶元素 empty判断队空 size返回元素个数   默认：大根堆
priority_queue =>vector 为什么依赖vector?
1.底层默认把数据组成一个大根堆结构 在一个内存连续的数组上构建一个大根堆或者小根堆的
*/
int main()
{
	priority_queue<int>pque;
	for (int i = 0; i < 20; ++i)
	{
		pque.push(rand() % 100 + 1);
	}
	
	cout << pque.size() << endl;
	while (!pque.empty())
	{
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;
	
	
	queue<int>que;
	for (int i = 0; i < 20; ++i)
	{
		que.push(rand() % 100 + 1);
	}
	cout << que.size() << endl;
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;


	
	//push入栈  pop出栈 top查看栈顶元素  empty判断栈空  size返回元素个数
	stack<int>s1;
	for (int i = 0; i < 20; ++i)
	{
		s1.push(rand() % 100 + 1);
	}
	cout << s1.size() << endl;
	while (!s1.empty()) 
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	
	return 0;
}







#if 0
int main()
{
	vector<int>vec;
	//vec.reserve(20);//给vector容器预留空间
	vec.resize(20);
	cout << vec.empty() << endl;
	cout << vec.size() << endl;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100 + 1);
	}
	cout << vec.empty() << endl;
	cout << vec.size() << endl;

}

	//vector的operator[]运算符重载函数
	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	//把vec容器中所有的偶数全部删除
	auto it2 = vec.begin();
	while ( it2 != vec.end())
	{
		if (*it2 % 2 == 0)
		{
			it2 = vec.erase(it2);
		}
		else 
		{
			++it2;
		}
	}
	auto it1 = vec.begin();
	for (; it1 != vec.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	//给vector容器中所有的奇数前面都添加一个小于奇数1的偶数
	auto it3 = vec.begin();
	for (it3 = vec.begin(); it3 != vec.end(); ++it3)
	{
		if (*it3 % 2 != 0)
		{
			it3=vec.insert(it3, *it3 - 1);
			++it3;
		}
	}

	it1 = vec.begin();
	for (; it1 != vec.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	return 0;
}
#endif
