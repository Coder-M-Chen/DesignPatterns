/* ������ģʽ�����ӿ���ϳ�����Ľṹ���������ʹ������ͷ���������ҵ������������ִ�� */

#include <iostream>

using namespace std;

class Convert {
protected:
	Convert * mConvert;
public:
	Convert() {
		mConvert = nullptr;
	}
	virtual ~Convert() {}
	virtual void AddList(Convert * convert) {
		mConvert = convert;
	}
	virtual void ConvertChar(char c) = 0;
};

class Convert_atoA :public Convert {
public:
	virtual ~Convert_atoA() {}
	virtual void ConvertChar(char c) {
		if ('a' <= c&&c <= 'z') {
			cout << "Convert_atoA::ConvertChar(" << c << "): " << (char)(c + 'A' - 'a') << endl;
		}
		else {
			mConvert->ConvertChar(c);
		}
	}
};

class Convert_Atoa :public Convert {
public:
	virtual ~Convert_Atoa() {}
	virtual void ConvertChar(char c) {
		if ('A' <= c&&c <= 'Z') {
			cout << "Convert_Atoa::ConvertChar(" << c << "): " << (char)(c + 'a' - 'A') << endl;
		}
		else {
			mConvert->ConvertChar(c);
		}
	}
};

class Convert_default :public Convert {
public:
	virtual ~Convert_default() {}
	virtual void ConvertChar(char c) {
		cout << "Convert_default::ConvertChar(" << c << ")!" << endl;
	}
};

int main() {
	Convert_Atoa cA;
	Convert_atoA ca;
	Convert_default cd;
	ca.AddList(&cd);
	cA.AddList(&ca);

	cA.ConvertChar('a');
	cA.ConvertChar('A');

	system("pause");
	return 0;
}
