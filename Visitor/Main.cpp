/* ������ģʽ���Ժ㶨�������չ�������������������Ժ�Ů�Ե�ϲ����ʱ���仯 */

#include <iostream>

using namespace std;

class Person;

class Interests {
public:
	virtual ~Interests() {}
	virtual void HobbyOfWomen(Person * p) = 0;
	virtual void HobbyOfMen(Person * p) = 0;
};

class Person{
public:
	virtual ~Person() {}
	virtual void Sex() = 0;
	virtual void Hobby(Interests * i) = 0;
};

class Women :public Person{
public:
	virtual ~Women() {}
	virtual void Sex() {
		cout << "I'm a woman!" << endl;
	}
	virtual void Hobby(Interests * i) {
		i->HobbyOfWomen(this);
	}
};
class Men :public Person {
public:
	virtual ~Men() {}
	virtual void Sex() {
		cout << "I'm a man!" << endl;
	}
	virtual void Hobby(Interests * i) {
		i->HobbyOfMen(this);
	}
};

/* �·�Ϊ����չ�Ĳ��� */

class InterestsOf1990 :public Interests {
public:
	virtual ~InterestsOf1990() {}
	virtual void HobbyOfWomen(Person * p) {
		p->Sex();
		cout << "In 1990, I like movie!" << endl;
	}
	virtual void HobbyOfMen(Person * p) {
		p->Sex();
		cout << "In 1990, I like music!" << endl;
	}
};

class InterestsOf2000 :public Interests {
public:
	virtual ~InterestsOf2000() {}
	virtual void HobbyOfWomen(Person * p) {
		p->Sex();
		cout << "In 2000, I like QiongYao!" << endl;
	}
	virtual void HobbyOfMen(Person * p) {
		p->Sex();
		cout << "In 2000, I like JinYong!" << endl;
	}
};

class InterestsOf2010 :public Interests {
public:
	virtual ~InterestsOf2010() {}
	virtual void HobbyOfWomen(Person * p) {
		p->Sex();
		cout << "In 2010, I like DouYin!" << endl;
	}
	virtual void HobbyOfMen(Person * p) {
		p->Sex();
		cout << "In 2010, I like Bilibili!" << endl;
	}
};

int main() {
	{
		InterestsOf2010 i2010;
		Women w;
		w.Hobby(&i2010);
		Men m;

		m.Hobby(&i2010);

		InterestsOf2000 i2000;
		m.Hobby(&i2000);
	}

	system("pause");
	return 0;
}
