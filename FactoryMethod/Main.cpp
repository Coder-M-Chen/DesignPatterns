#include <iostream>
using namespace std;

class Wps {
public:
	virtual void open() = 0;
	virtual void close() = 0;
	virtual ~Wps() {}
};

class FactoryMethod {
public:
	virtual Wps * create() = 0;
	virtual ~FactoryMethod() {}
};

class Word :public Wps {
public:
	virtual void open() {
		cout << "Opening a Word file!" << endl;
	}
	virtual void close() {
		cout << "Closing a Word file!" << endl;
	}
};

class WordFactoryMethod :public FactoryMethod {
public:
	virtual Wps * create() {
		return new Word();
	}
};

class Excel :public Wps {
public:
	virtual void open() {
		cout << "Opening a Excel file!" << endl;
	}
	virtual void close() {
		cout << "Closing a Excel file!" << endl;
	}
};

class ExcelFactoryMethod :public FactoryMethod {
public:
	virtual Wps * create() {
		return new Excel();
	}
};

class Ppt :public Wps {
public:
	virtual void open() {
		cout << "Opening a PPT file!" << endl;
	}
	virtual void close() {
		cout << "Closing a PPT file!" << endl;
	}
};

class PptFactoryMethod :public FactoryMethod {
public:
	virtual Wps * create() {
		return new Ppt();
	}
};

class WpsWindows {
	FactoryMethod * mFactory;
	Wps * mWpsFile;
public:
	/* 将具体实现的绑定关系交由调用时完成，死道友不死贫道 */
	WpsWindows(FactoryMethod * pFactory) :mFactory(pFactory) {
		mWpsFile = nullptr;
	}
	void CreateFile() {
		if (mWpsFile == nullptr) {
			mWpsFile = mFactory->create();
			cout << "Create file, finished!" << endl;
		}
		else {
			cout << "File is alive!" << endl;
		}
	}
	void open() {
		mWpsFile->open();
	}
	void close() {
		mWpsFile->close();
	}
	void delFile() {
		if (mWpsFile != nullptr) {
			delete mWpsFile;
			cout << "Delete file, finished!" << endl;
			mWpsFile = nullptr;
		}
		else {
			cout << "File is NULL!" << endl;
		}
	}
	~WpsWindows() {
		delFile();
	}
};

int main() {
	{
		FactoryMethod * pWordFactory = new WordFactoryMethod();

		WpsWindows ww(pWordFactory);  // 运行时绑定

		ww.CreateFile();
		ww.CreateFile();
		ww.open();
		ww.close();
		ww.open();
		ww.delFile();
	}

	system("pause");
	return 0;
}