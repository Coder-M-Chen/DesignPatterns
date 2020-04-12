/* 数字、汉字、英文做加粗、斜体、下划线处理 */

#include <iostream>

using namespace std;

class Text {
public:
	virtual void GetText() { cout << "Text" << endl; }
	virtual ~Text() {}
};

class Number :public Text {
public:
	Number() { cout << "Number()" << endl; }
	virtual void GetText() { cout << "Number" << endl; }
};

class Chinese :public Text {
public:
	Chinese() { cout << "Chinese()" << endl; }
	virtual void GetText() { cout << "Chinese" << endl; }
};

class English :public Text {
public:
	English() { cout << "English()" << endl; }
	virtual void GetText() { cout << "English" << endl; }
};

/* 派生的样式可以兼容，即迭代构造可使多个样式并存 */
class Decorator :public Text {
protected:
	Text * mpText;
public:
	Decorator(Text * pText) :mpText(pText) {}
	virtual void GetText() { mpText->GetText(); }
};

class DealB :public Decorator {
public:
	DealB(Text * pText) :Decorator(pText) {
		cout << "Deal B!" << endl;
	}
	virtual void GetText() {
		cout << "加粗的";
		mpText->GetText();
	}
};

class DealI :public Decorator {
public:
	DealI(Text * pText) :Decorator(pText) {
		cout << "Deal I!" << endl;
	}

	virtual void GetText() {
		cout << "斜体的";
		mpText->GetText();
	}
};

class DealU :public Decorator {
public:
	DealU(Text * pText) :Decorator(pText) {
		cout << "Deal U!" << endl;
	}

	virtual void GetText() {
		cout << "带下划线的";
		mpText->GetText();
	}
};

int main() {
	Number * n = new Number();
	Chinese * c = new Chinese();
	English * e = new English();

	DealB * pDb = new DealB(n);
	pDb->GetText();

	DealI * pDi = new DealI(c);
	pDb->GetText();

	DealU * pDu = new DealU(e);
	pDu->GetText();

	DealU * pDu2 = new DealU(pDb);
	pDu2->GetText();

	system("pause");
	return 0;
}