/* 备忘录模式，保存对象状态且不破坏封装性，以便对象回退 */

#include <iostream>
#include <vector>

using namespace std;

class Memento {
private:
	vector<int> vecStep;
public:
	Memento() {}
	~Memento() {}
	int GetLast() {
		if (vecStep.size() == 0)return 0;
		int i = vecStep.at(vecStep.size() - 1);
		vecStep.pop_back();
		return i;
	}
	void AddSave(int i) {
		vecStep.push_back(i);
	}
};

class Originator {
private:
	int step;
public:
	Originator() {
		step = 0;
	}
	~Originator() {}

	void Save(Memento * m) {
		cout << "Originator::Save(), step = " << step << endl;
		m->AddSave(step++);
	}
	void RollBack(Memento * m) {
		step = m->GetLast();
		cout << "Originator::RollBack(), step = " << step << endl;
	}
};

int main() {
	{
		Originator o;
		Memento m;

		o.Save(&m);
		o.Save(&m);
		o.Save(&m);
		o.RollBack(&m);
		o.Save(&m);
		o.Save(&m);
		o.RollBack(&m);
		o.RollBack(&m);
	}

	system("pause");
	return 0;
}
