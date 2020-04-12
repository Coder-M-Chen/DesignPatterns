#include <iostream>

using namespace std;

class Strategy {
public:
	virtual int Caculate() = 0;  /* ���ඨ����Խӿ� */
};

class ConcreteStrategyA :public Strategy {  /* ����ʵ�ֲ���ϸ��(֧����չ) */
public:
	int Caculate() { cout << "ConcreteStrategyA::Caculate()!" << endl; return 1; }
};

class ConcreteStrategyB :public Strategy {
	int Caculate() { cout << "ConcreteStrategyB::Caculate()!" << endl; return 2; }
};

class ConcreteStrategyC :public Strategy {
	int Caculate() { cout << "ConcreteStrategyC::Caculate()!" << endl; return 3; }
};

class Context {
private:
	Strategy * pStrategy;

public:
	Context() { pStrategy = 0x00; }
	Context(char ch = 'A') {
		switch (ch) {  /* ����ģʽ�����������Է��� */
		case 'a':
		case 'A':
			pStrategy = new ConcreteStrategyA();
			break;
		case 'b':
		case 'B':
			pStrategy = new ConcreteStrategyB();
			break;
		case 'c':
		case 'C':
			pStrategy = new ConcreteStrategyC();
			break;
		default:
			pStrategy = 0x00;
		}
	}
	void Run() {
		if (pStrategy == 0x00) cout << "pStrategy = NULL!" << endl;
		else cout << "Context::Run()! Caculate() = " << pStrategy->Caculate() << endl;
	}
};

int main() {
	Context a('a');
	Context b('B');
	Context c('c');
	a.Run();
	cout << endl;
	b.Run();
	cout << endl;
	c.Run();

	system("pause");
	return 0;
}