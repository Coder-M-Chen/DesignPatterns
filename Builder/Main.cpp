#include <iostream>
using namespace std;

class Lessons {
public:
	enum Subject { YuWen, ShuXue, YingYu };

private:
	Subject sub[4];
public:
	Lessons() {
		for (int i = 0; i < 4; i++) {
			sub[i] = Subject::YuWen;
		}
	}
	virtual void show() {
		for (int i = 0; i < 4; i++) {
			cout << "s[" << i + 1 << "]: " << (sub[i] == Subject::YuWen ? "YuWen" : (sub[i] == Subject::ShuXue ? "ShuXue" : "YingYu")) << endl;
		}
	}
	virtual void setLesson(int i, Subject t) { sub[i - 1] = t; }
};

class LessonsList {
protected:
	Lessons * lessons;

public:
	LessonsList() { lessons = new Lessons(); }
	virtual void Lessons1() = 0;
	virtual void Lessons2() = 0;
	virtual void Lessons3() = 0;
	virtual void Lessons4() = 0;
	virtual Lessons * GetList() = 0;
	virtual ~LessonsList() { if (lessons != nullptr) delete lessons; }
};

class LessonsListMonday :public LessonsList {
public:
	virtual void Lessons1() {
		lessons->setLesson(1, Lessons::Subject::YuWen);
	}
	virtual void Lessons2() {
		lessons->setLesson(2, Lessons::Subject::YingYu);
	}
	virtual void Lessons3() {
		lessons->setLesson(3, Lessons::Subject::ShuXue);
	}
	virtual void Lessons4() {
		lessons->setLesson(4, Lessons::Subject::ShuXue);
	}
	virtual Lessons * GetList() { return lessons; }
	virtual ~LessonsListMonday() {}
};

class LessonsListTuesday :public LessonsList {
public:
	virtual void Lessons1() {
		lessons->setLesson(1, Lessons::Subject::ShuXue);
	}
	virtual void Lessons2() {
		lessons->setLesson(2, Lessons::Subject::YingYu);
	}
	virtual void Lessons3() {
		lessons->setLesson(3, Lessons::Subject::YuWen);
	}
	virtual void Lessons4() {
		lessons->setLesson(4, Lessons::Subject::YingYu);
	}
	virtual Lessons * GetList() { return lessons; }
	virtual ~LessonsListTuesday() {}
};

class LessonsListWednesday :public LessonsList {
public:
	virtual void Lessons1() {
		lessons->setLesson(1, Lessons::Subject::ShuXue);
	}
	virtual void Lessons2() {
		lessons->setLesson(2, Lessons::Subject::ShuXue);
	}
	virtual void Lessons3() {
		lessons->setLesson(3, Lessons::Subject::YingYu);
	}
	virtual void Lessons4() {
		lessons->setLesson(4, Lessons::Subject::YuWen);
	}
	virtual Lessons * GetList() { return lessons; }
	virtual ~LessonsListWednesday() {}
};

class Director {
private:
	LessonsList * lesslist;
public:
	Director(LessonsList * list) :lesslist(list) {}
	/* 构造过程提取出来，独立于实现部分 */
	Lessons * Construct() {
		lesslist->Lessons1();
		lesslist->Lessons2();
		lesslist->Lessons3();
		lesslist->Lessons4();
		return lesslist->GetList();
	}
};

int main() {
	cout << "Monday, Lessons list:" << endl;
	LessonsList * listMon = new LessonsListMonday();
	Director dm(listMon);
	Lessons * lm = dm.Construct();
	lm->show();

	cout << "Tuesday, Lessons list:" << endl;
	LessonsList * listTue = new LessonsListTuesday();
	Director dt(listTue);
	Lessons * lt = dt.Construct();
	lt->show();

	system("pause");
	return 0;
}