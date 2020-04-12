#include <iostream>

using namespace std;

/* 行为无法兼容，具有互斥性，可以用两个基类指针表示 */
class ActionImp {
public:
	virtual void start() = 0;
	virtual void hobby() = 0;
};

class Person {
protected:
	ActionImp * mAction1;
	ActionImp * mAction2;
public:
	Person(ActionImp * pAction1, ActionImp * pAction2) :mAction1(pAction1), mAction2(pAction2) {}
	virtual void introduce() {
		mAction1->hobby();
		mAction1->start();
		cout << "This is my second hobby!" << endl;
		mAction2->hobby();
		mAction2->start();
	}
	virtual ~Person() {
		if (mAction1 != nullptr) {
			delete mAction1;
			cout << "delete mAction1!" << endl;
		}
		if (mAction2 != nullptr) {
			delete mAction2;
			cout << "delete mAction2!" << endl;
		}
	}
};

class ActionSinger :public ActionImp {
public:
	virtual void start() {
		cout << "I'm singing!" << endl;
	}

	virtual void hobby() {
		cout << "I like singing!" << endl;
	}
};

class ActionRunner :public ActionImp {
public:
	virtual void start() {
		cout << "I'm running!" << endl;
	}
	virtual void hobby() {
		cout << "I like running!" << endl;
	}
};

class ActionDancer :public ActionImp {
public:
	virtual void start() {
		cout << "I'm dancing!" << endl;
	}
	virtual void hobby() {
		cout << "I like dancing!" << endl;
	}
};

class PersonBoy : public Person {
public:
	PersonBoy(ActionImp * pAction1, ActionImp * pAction2) :Person(pAction1, pAction2) {}
	virtual void introduce() {
		cout << "I'm a boy!" << endl;
		mAction1->hobby();
		mAction1->start();
		cout << "This is my second hobby!" << endl;
		mAction2->hobby();
		mAction2->start();
	}
};

class PersonGirl :public Person {
public:
	PersonGirl(ActionImp * pAction1, ActionImp * pAction2) :Person(pAction1, pAction2) {}
	virtual void introduce() {
		cout << "I'm a girl!" << endl;
		mAction1->hobby();
		mAction1->start();
		cout << "This is my second hobby!" << endl;
		mAction2->hobby();
		mAction2->start();
	}
};

int main() {
	{
		ActionImp * pActionSinger = new ActionSinger();
		ActionImp * pActionRunner = new ActionRunner();
		Person * pPersonGirl = new PersonGirl(pActionSinger, pActionRunner);
		pPersonGirl->introduce();

		delete pPersonGirl;
		cout << endl;

		pActionRunner = new ActionRunner();
		ActionImp * pActionDancer = new ActionDancer();
		Person * pPersonBoy = new PersonBoy(pActionRunner, pActionDancer);
		pPersonBoy->introduce();
	}
	system("pause");
	return 0;
}