#include<iostream>
#include<string>
#include<memory>
using namespace std;

//工厂模式：主要是封装了对象的创建
class Car
{
public:
	Car(string name) :name_(name) {}
	virtual void show() = 0;
protected:
	string name_;
};

class BM :public Car
{
public:
	BM(string name) :Car(name) {}
	void show()
	{
		cout << "baoma" << name_ << endl;
	}
};

class BL :public Car
{
public:
	BL(string name) :Car(name) {}
	void show()
	{
		cout << "bingli" << name_ << endl;
	}
};

class Light
{
public:
	virtual void show() = 0;

};

class BMLight :public Light
{
public:
	void show() { cout << "Bmlight" << endl; }
};

class BlLight :public Light
{
public:
	void show() { cout << "BlLight" << endl; }

};

/*简单工厂
把对象的创建封装在一个接口函数里面，通过传入不同的标识，返回创建的对象  客户不用自己负责new对象，不用了解对象的创建过程。
提供创建对象实例的接口函数不闭合，不能对修改关闭


工厂方法
工厂基类提供了一个纯虚函数（创建产品），定义派生类（具体产品的工厂）负责创建对应的产品，可以做到不同的产品在不同的工厂里面创建，能够对现有工厂及产品的修改关闭
但实际上很多产品是有关联关系的，属于一个产品簇，不应该放在不同的工厂里面创建，这样一是不符合实际的产品对象创建逻辑，二是工厂类太多了，不好维护

=》抽象工厂（对有一组关联关系的产品簇提供产品对象的统一创建）
把有关联关系的，属于一个产品簇的所有产品创建的接口函数，放在一个抽象工厂（基类）里面，派生类（具体产品的工厂）应该负责创建该产品簇里面所有的产品


*/
class AbstructFactory
{
public:
	virtual Car* creatCar(string name) = 0;
	virtual Light* creatLight() = 0;
};

/*
class Factory
{
public:
	virtual  Car* creatCar(string name) = 0;
};*/

class BMfactory :public AbstructFactory
{
public:
	Car* creatCar(string name)
	{
		return new BM(name);
	}
	Light* creatLight()
	{
		return new BMLight();
	}
};

class BLfactory :public AbstructFactory
{
public:
	Car* creatCar(string name)
	{
		return new BL(name);
	}
	Light* creatLight()
	{
		return new BlLight();
	}
};

int main()
{
	unique_ptr<AbstructFactory>bmfactory(new BMfactory());
	unique_ptr<AbstructFactory>blfactory(new BLfactory());
	unique_ptr<Car>p1(bmfactory->creatCar("x1"));
	unique_ptr<Car>p2(blfactory->creatCar("x2"));
	unique_ptr<Light>l1(bmfactory->creatLight());
	unique_ptr<Light>l2(blfactory->creatLight());
	p1->show();
	p2->show();
	l1->show();
	l2->show();
	return 0;

}
/*
//简单工厂
enum  CarType
{
	BMW,
	BLI
};
class SimpleFactory
{
public:
	Car* createCar(CarType ct)
	{
		switch (ct)
		{
		case BMW:
			return new BM("x1");
		case BLI:
			return new BL("x2");
		default:
			cout << "传入参数不正确" << endl;
			break;
		}
		return nullptr;
	}
};
int main()
{
	//Car* p = new BMW("X");
	//Car* q = new BLI("Y");
	unique_ptr< SimpleFactory> factory( new SimpleFactory());
	unique_ptr<Car> p1 ( factory->createCar(BMW));
	unique_ptr<Car> p2 (factory->createCar(BLI));
	p1->show();
	p2->show();

	return 0;
}*/
