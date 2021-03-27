#include<iostream>
using namespace std;


//装饰器：主要增加现有类的功能，
//但是增加现有类的功能还有一个方法，就是新增加一个子类(但是代码中有太多的子类添加进来)

class Car
{
public:
	virtual void show() = 0;
};

class Bm :public Car
{
public:
	void show()
	{
		cout << "宝马汽车";
	}
};

class Ad :public Car
{
public:
	void show()
	{
		cout << "奥迪汽车" ;
	}
};

class Bc :public Car
{
public:
	void show()
	{
		cout << "奔驰汽车" ;
	}
};

//装饰器1
class ConcreteDecorator01 :public Car
{
public:
	ConcreteDecorator01(Car *p):pCar(p){}
	void show()
	{
		pCar->show();
		cout << "，定速巡航" << endl;
	}
private:
	Car* pCar;
};

//装饰器2
class ConcreteDecorator02 :public Car
{
public:
	ConcreteDecorator02(Car* p) :pCar(p) {}
	void show()
	{
		pCar->show();
		cout << "，自动刹车" << endl;
	}
private:
	Car* pCar;
};

//装饰器3
class ConcreteDecorator03 :public Car
{
public:
	ConcreteDecorator03(Car* p) :pCar(p) {}
	void show()
	{
		pCar->show();
		cout << "，车道偏离" << endl;
	}
private:
	Car* pCar;
};



int main()
{
	Car* p1 = new ConcreteDecorator01(new Bm());
	p1->show();
	Car* p2 = new ConcreteDecorator02(new  Ad());
	p2->show();
	Car* p3 = new ConcreteDecorator03(new  Bc());
	p3->show();
}
