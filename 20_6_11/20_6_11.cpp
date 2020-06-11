#include<iostream>
using namespace std;


template<class T> class Foo {
	T tVar;
public:
	Foo(){}
	Foo(T t) :tVar(t) {}
};

template<class T> class FOODerived :public Foo<T>
{
	T TVar;

public:

	FOODerived(T c):TVar(c),tVar()
	{

	}
};

int main()
{
	FOODerived<int> d(5);
	return 0;
}