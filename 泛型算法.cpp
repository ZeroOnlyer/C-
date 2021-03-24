#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

/*
泛型算法=template+迭代器+函数对象
特点：
1.泛型算法的参数接收的都是迭代器
2.泛型算法的参数还可以接收函数对象（c函数指针）


绑定器+二元函数对象=>一元函数对象
bind1st：把二元函数对象的operator()的第一个形参绑定起来
bind2nd：把二元函数对象的operator()的第二个形参绑定起来

*/
int main()
{
	int arr[] = { 12,4,78,9,21,43,56,52,42,31 };
	vector<int>vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;

	//默认小到大的排序
	sort(vec.begin(), vec.end());

	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;

	//有序容器中进行二分查找
	if (binary_search(vec.begin(), vec.end(), 21))
	{
		cout << "21存在" << endl;
	}

	auto it1 = find(vec.begin(), vec.end(), 21);
	if (it1 != vec.end())
	{
		cout << "find 21存在" << endl;
	}

	//传入函数对象greater，改变容器元素排序时的比较方式 
	sort(vec.begin(), vec.end(), greater<int>());
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	//78 56 52 43 42 31 21 12 9 4
	//把48按序插入到vector容器当中,找第一个小于48的数字
	//find_if需要的是一个一元函数对象
	auto it2 = find_if(vec.begin(), vec.end(),
		//bind1st(greater<int>(),48));
		//bind2nd(less<int>(), 48));
		[](int val)->bool {return val < 48; });
	vec.insert(it2, 48);
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;

	//for_each可以遍历容器的所有元素，可以自行添加合适的函数对象对容器的元素进行过滤
	for_each (vec.begin(), vec.end(), [](int val)->void
		{
			if (val % 2 == 0)
			{
				cout << val << " ";
			}
		});
	cout << endl;
	return 0;
}
