#include<iostream>
using namespace std;

//class A
//{
//	int Num;
//public:
//	A(int num)
//	{
//		Num = num;
//	}
//};
//
//class B :public  A
//{
//public:
//	B(int num):A(num)
//	{
//
//	}
//};

//template<class T> class Foo {
//	T tVar;
//public:
//
//	Foo(T t) :tVar(t) {}
//	
//};
//
//template<class T> class FOODerived :public Foo<T>
//{
//
//
//public:
//	FOODerived(T cpp):Foo<T>::Foo(cpp)
//	{
//		
//	}
//};
//
//int main()
//{
//	//B d(3);
//	FOODerived<int> d(5);
//	return 0;
//}

class A
{
public:
	void foo()
	{
		cout << "1" << endl;
	}
	virtual void fun()
	{
		cout << "2" << endl;
	}
};

class B :public A
{
public:
	void foo()
	{
		cout << "3" << endl;
	}
	void fun()
	{
		cout << "4" << endl;
	}
};
//121212
int main()
{
	A a;
	B b;
	A *p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A *ptr = (A*)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}