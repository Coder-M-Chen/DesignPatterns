#include <iostream>
#include <map>
#include <string>

using namespace std;

class Flyweight {
private:
	string str;
public:
	Flyweight(char c) {
		if (c != '\0')str = string(3, c);
		else str = "NULL";
	}
	string get() {
		return str;
	}
};

class FlyweightFactory {
private:
	map<char, Flyweight *> mC2S;  /* ����أ������Ϊֻ��ģʽ���� */

public:
	Flyweight * getFlyweight(char c) {
		if (c >= 'a'&&c <= 'z') c = c + 'A' - 'a';
		map<char, Flyweight *>::iterator it = mC2S.find(c);
		if (it != mC2S.end()) {
			return it->second;
		} else {
			Flyweight * f = new Flyweight(c);
			mC2S[c] = f;
			return f;
		}
	}
	~FlyweightFactory() {
		cout << "sizeof map:" << mC2S.size() << endl;
		for (map<char, Flyweight *>::iterator it = mC2S.begin(); it != mC2S.end(); ) {
			delete it->second;
			it->second = nullptr;
			mC2S.erase(it++);  /* ɾ�� map �еĵ�ǰ������Ԫ�أ��ұ��������ʧЧ */
		}
		cout << "sizeof map:" << mC2S.size() << endl;
	}
};

int main() {
	{
		char str[10] = "asdfghjkl";
		FlyweightFactory ff;
		Flyweight * p = nullptr;
		for (int i = 0; i < 10; i++) {
			p = ff.getFlyweight(str[i]);
			cout << p->get() << endl;
		}

		cout << "Delete FlyweightFactory!" << endl;
	}

	system("pause");
	return 0;
}
