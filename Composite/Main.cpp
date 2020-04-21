/* 组合模式，将最小单元打包成组合，组合能访问组合中的最小单元，类似于收纳箱里放多个小收纳箱，称重取大收纳箱的总重 */

#include <iostream>
#include <list>

using namespace std;

class BoxBase {
public:
	BoxBase() {}
	~BoxBase() {}
	virtual int Weight() { return 0; }
};

class Box :public BoxBase {
protected:
	list<BoxBase *> listBox;

public:
	Box() {
		listBox.clear();
	}
	virtual void AddSth(BoxBase * b) {
		listBox.push_back(b);
	}
	virtual void DelSth(BoxBase * b) {
		listBox.remove(b);
	}
	virtual int Weight() {
		int w = 0;
		for (list<BoxBase *>::iterator it = listBox.begin(); it != listBox.end(); it++) {
			w = w + (*it)->Weight();
		}
		return w;
	}
};

class Sth :public BoxBase {
private:
	int w;
public:
	Sth(int i = 1) { w = i; }
	virtual int Weight() {
		return w;
	}
};

int main() {
	{
		Box bRoot;
		Box bComposite;
		Sth s1(2);
		Sth s2(3);
		Sth s3(4);
		Sth s4(5);

		bRoot.AddSth(&s1);
		bRoot.AddSth(&s2);
		bComposite.AddSth(&s3);
		bComposite.AddSth(&s4);
		bRoot.AddSth(&bComposite);

		int w = bRoot.Weight();
		cout << w << endl;
	}

	system("pause");
	return 0;
}