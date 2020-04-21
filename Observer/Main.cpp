/* 观察者模式，订阅发布 */

#include <iostream>
#include <vector>

using namespace std;

class Observer {
public:
	virtual void Update(int x) = 0;
};

class ConcreteObserver1 :public Observer {
public:
	void Update(int x) {
		cout << "ConcreteObserver1: " << x << endl;
		for (int i = 0; i < 100; i++) {
			if (i < x)cout << "+";
			else cout << ".";
		}
		cout << endl;
	}
};

class ConcreteObserver2 :public Observer {
public:
	void Update(int x) {
		cout << "ConcreteObserver2: " << x << endl;
		for (int i = 0; i < 100; i++) {
			if (i < x) cout << "-";
			else cout << ".";
		}
		cout << endl;
	}
};

class Doing {
private:
	vector<Observer *> vecObserver;
public:
	bool AddObserver(Observer * pObserver) {  /* 添加观察者列表 */
		vecObserver.push_back(pObserver);
		return true;
	}
	void SetProgress(int x) {  /* 更新状态 */
		cout << "SetProgress(" << x << "):" << endl;
		for (vector<Observer *>::iterator iter = vecObserver.begin(); iter != vecObserver.end(); iter++) {
			(*iter)->Update(x);
		}
	}
};

int main() {
	{
		Doing d;
		ConcreteObserver1 ob1;
		ConcreteObserver2 ob2;
		d.AddObserver(&ob1);
		d.AddObserver(&ob2);

		d.SetProgress(5);
		d.SetProgress(14);
		d.SetProgress(55);
		d.SetProgress(87);
		d.SetProgress(100);
	}

	system("pause");
	return 0;
}