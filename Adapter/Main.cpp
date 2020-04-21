/* ������ģʽ�����������»����������Ͻӿڣ����Ͻӿڰ�װ���� */

#include <iostream>

using namespace std;

class CharCap {
public:
	virtual char get(int i) = 0;
	virtual ~CharCap() {}
};

class CharLow {
private:
	char mC[26];
public:
	CharLow() {
		for (int i = 'a'; i <= 'z'; i++)mC[i - 'a'] = i;
	}
	char get(int i) {
		if (i > 0 && i <= 26) return mC[i - 1];
		else return '\0';
	}
};

class CharAdapterLow2Cap :public CharCap {
private:
	CharLow * mCharLow;
public:
	CharAdapterLow2Cap(CharLow * cl) {
		mCharLow = cl;
	}
	virtual char get(int i) {
		return 'A' - 'a' + mCharLow->get(i);  /* ͨ��ת�����Ͻӿ�ʵ���½ӿڵĹ��� */
	}
	virtual ~CharAdapterLow2Cap() {
		if (mCharLow != nullptr)delete mCharLow;
	}
};

int main() {
	{
		CharLow * cl = new CharLow();
		CharAdapterLow2Cap cAdapter(cl);
		cout << "CharAdapterLow2Cap::get():" << endl;
		for (int i = 1; i <= 26; i++) {
			cout << " " << cAdapter.get(i);
			if (i % 4 == 0)cout << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
