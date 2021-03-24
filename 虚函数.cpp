#include<iostream>
using namespace std;

class Base
{
public:
	Base(int data = 10) :ma(data) {}
	virtual void show() { cout << "Base::show()" << endl; }
	virtual void show(int) { cout << "Base::show(int)" << endl; }
protected:
	int ma;
};

class Derive :public Base
{
public:
	Derive(int data=20):Base(data),mb(data){}
	void show() { cout << "Derive::show()" << endl; }
protected:
	int mb;
};

int main()
{
	Derive d(50);
	Base* pb = &d;
	
	//如果发现show是普通函数，就进行静态绑定
	//如果发现show是虚函数，就进行动态绑定了

	pb->show();//静态（编译时期）的绑定从（函数的调用）
	pb->show(10);

	cout << sizeof(Base) << endl;
	cout << sizeof(Derive) << endl;

	cout << typeid(pb).name() << endl;
	cout << typeid(*pb).name() << endl;


	return 0;
}
