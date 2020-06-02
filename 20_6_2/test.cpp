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

};

class B :public A {
public:
	virtual void func1()
	{
		cout << "B::func1" << endl;
	}
	virtual void func2()
	{
		cout << "B::func2" << endl;
	}
	virtual void func3()
	{
		cout << "B::func3" << endl;
	}
};

typedef void(*vfptr)();

void printfvf(vfptr* vf)
{
	cout << "Ðé±íµØÖ·£º" << vf << endl;
	while (*vf != nullptr)
	{
		vfptr f = *vf;
		f();
		vf++;
	}
}

int main()
{
	A a;
	B b;
	vfptr* vf = (vfptr*)(*(int*)&a);
	printfvf(vf);

	system("pause");
	return 0;
}