#include<iostream>
using namespace std;
/*
class CDate
{
public:
	CDate(int y,int m, int d)//自定义一个构造函数，编译器就不会再产生默认构造函数
	{
		_year = y;
		_month = m;
		_day = d;
	}
	void show()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//构造函数的初始化列表:可以指定当前对象成员变量的初始化方式
class CGoods
{
public:
	CGoods(const char* n, int a, double p, int y, int m, int d)
		:_date(y, m, d)//CDate _date(y,m,d);
		,_amount(a)//相当于 int  _amount = a;
		, _price(p)//1.构造函数的初始化列表，先执行
	{
		//2当前类类型构造函数体，后执行
		strcpy(_name, n);
		//_amount = a;//相当于int _amount;   _amount=a;
	}
	void show()
	{
		cout << "name:" << _name <<endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	}
private:
	char _name[20];
	int _amount;
	double _price;
	CDate _date;//成员对象    1.分配内存  2.调用构造函数
};
int main()
{
	CGoods   good("商品",200,65.00,2021,1,1);
	good.show();
	return 0;
}
*/
class Test
{
public:
	Test(int data = 10) :mb(data), ma(mb) {}
	void show()
	{
		cout << "ma:" << ma << "   mb:" << mb << endl;
	}
private:
	//成员变量的初始化和它们定义的顺序有关，和构造函数初始化列表中出现的先后顺序无关！
	int ma;
	int mb;
};

int main()
{
	Test t;
	t.show();
	return 0;
}
