#include <iostream>
#include <string>
#include <list>

using namespace std;

class SQL{
protected:
	string s;
public:
	SQL() { s = ""; }
	SQL(const string & str) :s(str) {}
	virtual ~SQL() {}
	virtual void Execute() = 0;
	virtual void Rollback() = 0;
};

class SelectSQL :public SQL {
public:
	SelectSQL() {}
	SelectSQL(const string & sql) :SQL(sql) {}
	virtual ~SelectSQL() {}
	virtual void Execute() {
		cout << "SelectSQL::Execute(), " << s << endl;
	}
	virtual void Rollback() {
		cout << "SelectSQL::Rollback(), " << s << endl;
	}
};

class UpdateSQL :public SQL {
public:
	UpdateSQL() {}
	UpdateSQL(const string & sql) :SQL(sql) {}
	virtual ~UpdateSQL() {}
	virtual void Execute() {
		cout << "UpdateSQL::Execute(), " << s << endl;
	}
	virtual void Rollback() {
		cout << "UpdateSQL::Rollback(), " << s << endl;
	}
};

class DeleteSQL :public SQL {
public:
	DeleteSQL() {}
	DeleteSQL(const string & sql) :SQL(sql) {}
	virtual ~DeleteSQL() {}
	virtual void Execute() {
		cout << "DeleteSQL::Execute(), " << s << endl;
	}
	virtual void Rollback() {
		cout << "DeleteSQL::Rollback(), " << s << endl;
	}
};

class SqlFile :public SQL {
private:
	list<SQL *> listSQL;
public:
	SqlFile() {}
	virtual ~SqlFile() {}
	virtual void Execute() {
		for (list<SQL *>::iterator it = listSQL.begin(); it != listSQL.end(); it++) {
			(*it)->Execute();
		}
	}
	virtual void Rollback() {
		for (list<SQL *>::reverse_iterator it = listSQL.rbegin(); it != listSQL.rend(); it++) {
			(*it)->Rollback();
		}
	}

	virtual void AddSQL(SQL * s) {
		listSQL.push_back(s);
	}
	virtual void Remove(SQL * s) {
		listSQL.remove(s);
	}
};


int main() {
	{
		SelectSQL ss("select ... from ... where ...;");
		UpdateSQL us("update ... set ... where ...;");
		DeleteSQL ds("delete from ... where ...;");

		SqlFile sf;
		sf.AddSQL(&ss);
		sf.AddSQL(&us);
		sf.AddSQL(&ds);

		sf.Execute();
		sf.Rollback();
	}

	system("pause");
	return 0;
}
