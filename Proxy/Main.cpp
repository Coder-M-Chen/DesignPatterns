/* 代理模式：参考智能指针，将功能包装，可在应用场景中替换掉实体对象 */

#include <iostream>
#include <string>

using namespace std;

class File {
protected:
	File() {
		cout << "File::File()" << endl;
	}
	File(const File & file) {}

public:
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Status() = 0;
	virtual ~File() {
		cout << "File::~File()" << endl;
	}
};

class TxtFile :public File {
private:
	bool status;
	string filename;
public:
	TxtFile(string filename = "nullptr") {
		cout << "TxtFile::TxtFile()" << endl;
		status = false;
		filename = filename;
	}
	virtual void Open() {
		cout << "Open a Txt!" << endl;
		status = true;
	}
	virtual void Close() {
		cout << "Close a Txt!" << endl;
		status = false;
	}
	virtual void Status() {
		cout << (status == true ? "Txt is opened!" : "Txt is closed!") << endl;
	}
	virtual ~TxtFile() {
		cout << "TxtFile::~TxtFile()" << endl;
	}
};

class FileProxy :public File {
private:
	File * mFile;
	string filename;

public:
	FileProxy(string fn = "nullptr") :mFile(new TxtFile(fn)) {
		cout << "FileProxy::FileProxy()" << endl;
		filename = fn;
	}
	virtual void Open() {
		cout << "Open a file, file name is " << filename << ": ";
		mFile->Open();
	}
	virtual void Close() {
		cout << "Close a file, file name is " << filename << ": ";
		mFile->Close();
	}
	virtual void Status() {
		mFile->Status();
	}
	virtual ~FileProxy() {
		cout << "FileProxy::~FileProxy()" << endl;
		if (mFile != nullptr) delete mFile;
	}
};

int main() {
	{
		FileProxy fp("HelloWorld.txt");
		fp.Status();
		fp.Open();
		fp.Status();
		fp.Close();
		fp.Status();
	}

	system("pause");
	return 0;
}
