/* 中介者模式，类似于操作系统中的总线、实例手机通讯转接 */
/**
 * 中介者模式特点
 * 各个手机端之间无法直接调用，均通过中介者接口实现端与端的通讯
 */

#include <iostream>
#include <map>
using namespace std;

class Mediator;

class Phone {
protected:
	int number;
	Mediator * mediator;
public:
	Phone(int num, Mediator * m) :number(num), mediator(m) {}
	virtual ~Phone() {}

	virtual void CallOther(int num) = 0;
	virtual int GetNum() = 0;
	virtual void CalledByOther() = 0;
};

class Mediator {
private:
	map<int, Phone *> myList;
public:
	Mediator() {
		myList.clear();
	}
	virtual ~Mediator() {
		cout << "MyList : " << myList.size() << endl;
		cout << "Mediator::~Mediator()" << endl;
		for (map<int, Phone *>::iterator it = myList.begin(); it != myList.end();) {
			myList.erase(it++);
		}
		cout << "MyList : " << myList.size() << endl;
	}

	virtual void CallOther(int num) {
		for (map<int, Phone *>::iterator it = myList.begin(); it != myList.end(); it++) {
			if (it->first == num) {
				it->second->CalledByOther();
				break;
			}
		}
	}
	virtual void AddPhone(Phone * phone) {
		myList[phone->GetNum()] = phone;
	}
};

class PhoneA :public Phone {
public:
	PhoneA(int num, Mediator * m) :Phone(num, m) {}
	virtual ~PhoneA() {}
	virtual void CallOther(int num) {
		cout << number << " call " << num << endl;
		mediator->CallOther(num);
	}
	virtual int GetNum() {
		return number;
	}
	virtual void CalledByOther() {
		cout << number << " is called!" << endl;
	}
};

class PhoneB :public Phone {
public:
	PhoneB(int num, Mediator * m) :Phone(num, m) {}
	virtual ~PhoneB() {}
	virtual void CallOther(int num) {
		cout << number << " call " << num << endl;
		mediator->CallOther(num);
	}
	virtual int GetNum() {
		return number;
	}
	virtual void CalledByOther() {
		cout << number << " is called!" << endl;
	}
};

class PhoneC :public Phone {
public:
	PhoneC(int num, Mediator * m) :Phone(num, m) {}
	virtual ~PhoneC() {}
	virtual void CallOther(int num) {
		cout << number << " call " << num << endl;
		mediator->CallOther(num);
	}
	virtual int GetNum() {
		return number;
	}
	virtual void CalledByOther() {
		cout << number << " is called!" << endl;
	}
};

int main() {
	{
		Mediator * m = new Mediator();
		PhoneA pa(1, m);
		m->AddPhone(&pa);
		PhoneB pb(2, m);
		m->AddPhone(&pb);
		PhoneC pc(3, m);
		m->AddPhone(&pc);

		cout << "main(), 1 call 2:" << endl;
		pa.CallOther(2);
		cout << "main(), 2 call 3:" << endl;
		pb.CallOther(3);
		cout << "main(), 3 call 1:" << endl;
		pc.CallOther(1);

		delete m;
	}

	system("pause");
	return 0;
}
