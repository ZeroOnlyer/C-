#include<iostream>
using namespace std;

/*
函数模板  看函数前面是否有template以及模板参数列表  ，是不进行编译的，因为类型不知道
模板的实例化   在函数调用点，编译器用用户指定的类型，从原模板实例化一份函数代码出来
模板函数 实例化后的模板函数  ，才是要被编译器所编译的
模板类型参数  typename/class，定义多个，用“，”隔开
模板非类型参数
模板的实参推演 =》 可以根据用户传入的实参类型，来推导出模板类型参数的具体类型
模板的特例化（专用化） 特殊（不是编译器提供的，而是用户提供的）的实例化
函数模板、模板的特例化，非模板函数的重载关系
模板代码是不能在一个文件中定义，在另一个文件中使用
模板代码调用之前，一定要看到模板定义的地方，
这样的话，模板才能够进行正常的实例化，产生能够被编译器编译的代码
所以，模板代码都是放在头文件当中，然后在源文件当中直接进行#include包含
*/


//函数模板
template<typename T>//定义一个模板参数列表
bool compare(T a, T b)//compare是一个函数模板
{
	cout << "template compare" << endl;
	return a > b;
}

//针对compare函数模板，提供const char*类型的特例化版本
template<>
bool compare<const char*>(const char* a, const char* b)
{
	cout << " compare<const char*>" << endl;
	return strcmp(a , b)>0;
}

//非模板函数  -  普通函数
bool compare(const char* a, const char* b)
{
	cout << " normal compare" << endl;
	return strcmp(a, b) > 0;
}

/*
在函数调用点，编译器用用户指定的类型，从原模板实例化一份函数代码出来
模板函数
bool compare<int>(int a,int b)
{
	return a>b;
}
bool compare<double>(double a,double b)
{
	return a>b;
}
bool compare<const char*>(const char* a,const char* b)//特例化
{
	return a>b;
}
*/

int main()
{
	//函数的调用点
	compare<int>(10, 20);
	compare<double>(10.5, 20.06);

//模板实参的推演
	compare(10, 20);
	compare<int>(30, 40.5);
	//模板实参的推演 T const char*
	//对于某些类型来说。依赖编译器默认实例化的模板代码，代码处理逻辑是错误的
	//编译器优先把compare处理成函数名字，没有的话，才去找compare模板
	compare("aaa", "bbb");
	compare<const char*>("aaa", "bbb");
	return 0;
}
