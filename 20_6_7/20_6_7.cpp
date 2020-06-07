#include<iostream>
using namespace std;

class A {
public:
	virtual void func1()
	{
		cout << "A::func1" << endl;
	}
	virtual void func2()
	{
		cout << "A::func2" << endl;
	}
private:
	int a;
};

class B :public A {
public:
	B(int c)
	{
		func1();
		b = c;

	}
	void func1()
	{
		cout << "B::func1" << endl;
	}
private:
	int b;
};



int main()
{
//	A a;
	B b(1);

	system("pause");
	return 0;
}