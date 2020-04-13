#include <iostream>
using namespace std;

/* �������������м�״̬��������޷�ֱ��ʹ�ù��캯����ɸ�״̬����Ĵ��� */
class Prototype {
protected:
	bool mStatus;
public:
	Prototype() { mStatus = false; }
	Prototype(const Prototype & t) {
		mStatus = t.mStatus;
	}
	virtual Prototype * clone() { return new Prototype(*this); }
	virtual void status() {
		if (mStatus) cout << "Prototype! I'm ready!" << endl;
		else cout << "Prototype! I neet some time!" << endl;
	}
	virtual void change() { mStatus = !mStatus; }
	virtual ~Prototype() {}
};

class ConcretePrototypeA :public Prototype {
public:
	ConcretePrototypeA() :Prototype() {}
	ConcretePrototypeA(const ConcretePrototypeA & t) { mStatus = t.mStatus; }
	virtual Prototype * clone() { return new ConcretePrototypeA(*this); }
	virtual void status() {
		if (mStatus) cout << "ConcretePrototypeA! I'm ready!" << endl;
		else cout << "ConcretePrototypeA! I need some time!" << endl;
	}
	virtual ~ConcretePrototypeA() {}
};

class ConcretePrototypeB :public Prototype {
public:
	ConcretePrototypeB() :Prototype() {}
	ConcretePrototypeB(const ConcretePrototypeB & t) { mStatus = t.mStatus; }
	virtual Prototype * clone() { return new ConcretePrototypeB(*this); }
	virtual void status() {
		if (mStatus) cout << "ConcratePrototypeB! I'm ready!" << endl;
		else cout << "ConcretePrototypeB! I need some time!" << endl;
	}
};

int main() {
	Prototype * pp = new ConcretePrototypeA();
	pp->status();

	cout << "clone:" << endl;
	Prototype * pt = pp->clone();
	pt->status();
	pt->change();
	pt->status();

	cout << "Prototype:" << endl;
	pp->status();

	system("pause");
	return 0;
}