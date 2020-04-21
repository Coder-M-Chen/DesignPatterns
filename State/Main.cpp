/* 状态模式，将每一种状态对应的操作封装成一个类 */

#include <iostream>
using namespace std;

class Person;
class MorningState;
class NoonState;
class NightState;

class State {
protected:
	State() {}
	virtual ~State() {}
public:
	virtual void ChangeState(Person * person) = 0;
	virtual void Eat(Person * person) = 0;
	virtual void Work(Person * person) = 0;
	virtual void Run(Person * person) = 0;
};

class MorningState :public State {
private:
	MorningState() {}
	MorningState(const MorningState & ms) {}
public:
	virtual void ChangeState(Person * person);
	virtual ~MorningState() {}
	static MorningState * Instance() {  /* 单一状态下的行为模式是共享的，单例模式 */
		static MorningState ms;
		return &ms;
	}
	virtual void Eat(Person * person) {
		cout << "MorningState::Eat()!" << endl;
		ChangeState(person);  /* 将状态的流转放在操作里 */
	}
	virtual void Work(Person * person) {
		cout << "MorningState::Work()!" << endl;
	}
	virtual void Run(Person * person) {
		cout << "MorningState::Run()!" << endl;
	}
};

class NoonState :public State {
private:
	NoonState() {}
	NoonState(const NoonState & as) {}
public:
	virtual void ChangeState(Person * person);
	virtual ~NoonState() {}
	static State * Instance() {
		static NoonState as;
		return &as;
	}
	virtual void Eat(Person * person) {
		cout << "NoonState::Eat()!" << endl;
	}
	virtual void Work(Person * person) {
		cout << "NoonState::Work()!" << endl;
		ChangeState(person);
	}
	virtual void Run(Person * person) {
		cout << "NoonState::Run()!" << endl;
	}
};

class NightState :public State {
private:
	NightState() {}
	NightState(const NightState & ns) {}
public:
	virtual void ChangeState(Person * person);
	virtual ~NightState() {}
	static State * Instance() {
		static NightState ns;
		return &ns;
	}
	virtual void Eat(Person * person) {
		cout << "NightState::Eat()!" << endl;
	}
	virtual void Work(Person * person) {
		cout << "NightState::Work()!" << endl;
	}
	virtual void Run(Person * person) {
		cout << "NightState::Run()!" << endl;
		ChangeState(person);
	}
};

class Person {
private:
	State * mState;
public:
	Person() {
		mState = MorningState::Instance();
	}
	~Person() {}

	void ChangeState(State * s) {
		mState = s;
	}
	virtual void Eat() {
		mState->Eat(this);
	}
	virtual void Work() {
		mState->Work(this);
	}
	virtual void Run() {
		mState->Run(this);
	}
};


void MorningState::ChangeState(Person * person) {
	cout << "MorningState::ChangeState()!" << endl;
	person->ChangeState(NoonState::Instance());
}

void NoonState::ChangeState(Person * person) {
	cout << "NoonState::ChangeState()!" << endl;
	person->ChangeState(NightState::Instance());
}

void NightState::ChangeState(Person * person) {
	cout << "NightState::ChangeState()!" << endl;
	person->ChangeState(MorningState::Instance());
}

int main() {
	{
		Person p;
		p.Work();
		p.Eat();
		p.Run();

		p.Eat();
		p.Run();
		p.Work();

		p.Eat();
		p.Work();
		p.Run();
	}

	system("pause");
	return 0;
}
