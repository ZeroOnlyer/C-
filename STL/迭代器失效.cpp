#include<iostream>
#include<vector>
using namespace std;

/*迭代器的失效问题
1.迭代器为什么会失效
2.当容器调用erase方法以后，当前位置到容器末尾元素的所有的迭代器全部失效了
3.当容器调用insert方法后，当前位置到容器末尾元素的所有迭代器全部失效了
4.对insert来说，如果引起容器内存扩容，原来容器的所有的迭代器就全部失效了
不同容器的迭代器是不能进行比较运算的
迭代器失效了以后，问题该怎么解决
*/

int main()
{
	vector<int>vec;
		for (int i = 0; i < 20; ++i)
		{
			vec.push_back(rand() % 100 + 1);
		}
		for (int v : vec)
		{
			cout << v <<" ";
		}
		cout << endl;

		//给vec容器中所有的偶数前面添加一个小于偶数值1的数字
		auto it = vec.begin();
		for (; it != vec.end(); ++it)
		{
			if (*it % 2 == 0)
			{
				//这里的迭代器在第一次insert之后，iterator就失效了
				it = vec.insert(it, *it - 1);
				++it;
			}
		}

	/*	//把vec容器中所有的偶数全部删除
		auto it = vec.begin();
		while( it != vec.end() )
		{
			if (*it % 2 == 0)
			{
				//迭代器失效的问题，第一次调用erase以后，迭代器it就失效了
				//vec.erase(it);
				it = vec.erase(it);
			}
			else {
				it++;
			}
		}*/
		for (int v : vec)
		{
			cout << v << " ";
		}
		cout << endl;

		return 0;
}
