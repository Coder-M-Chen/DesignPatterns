// ģ�巽��
// ����̶����̣�����ʵ��ϸ��

#include <iostream>
using namespace std;

class A {
public:
	~A() {}

	void Step1() { cout << "A::Step1()" << endl; }
	virtual void Step2() { cout << "virtual A::Step2()" << endl; }
	void Step3() { cout << "A::Step3()" << endl; }
	virtual void Step4() { cout << "virtual A::Step4()" << endl; }
	void Step5() { cout << "A::step5()" << endl; }
	void Run() {  /* ����ȶ��ĵ������̣������ִ��ϸ����������ʵ�ֱ仯 */
		cout << "A::Run() begin!" << endl;
		Step1();
		Step2();
		Step3();
		Step4();
		Step5();
		cout << "A::Run() end!" << endl;
	}
};

class B :public A {
public:
	virtual void Step2() { cout << "B::Step2()" << endl; }
	virtual void Step4() { cout << "B::Step4()" << endl; }
};

int main() {
	A * p = new B();
	p->Run();
}
