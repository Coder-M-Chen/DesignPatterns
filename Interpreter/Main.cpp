/* 解析器模式 按特定语法解析输入参数 递归 定义公式，带入参数执行加减乘除四则运算 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> mLevel;

class Expression;
class NumExpression;
class CaculatorExpression;

class Expression {
public:
	virtual ~Expression() {}
	virtual int Interpreter(map<char, int> m) = 0;
	virtual int GetLevel() = 0;  /* 运算优先级 */
	virtual Expression * AddExpression(CaculatorExpression * ce) = 0;
};

class CaculatorExpression :public Expression {
protected:
	friend class NumExpression;
	Expression * l;
	Expression * r;

public:
	CaculatorExpression(Expression * left, Expression * right) {
		l = left;
		r = right;
	}
	virtual ~CaculatorExpression() {
		if (l != nullptr) delete l;
		if (r != nullptr) delete r;
	}
	virtual CaculatorExpression * AddExpression(CaculatorExpression * ce) {
		if (GetLevel() < ce->GetLevel()) {
			ce->l = this->r;
			this->r = ce;
			return this;
		}
		else {
			ce->l = this;
			return ce;
		}
	}
};

class NumExpression :public Expression {
private:
	char c;
public:
	NumExpression(char x = '\0') {
		c = x;
	}
	virtual ~NumExpression() {}
	virtual int Interpreter(map<char, int> m) {
		return m[c];
	}
	virtual int GetLevel() { return 9; }
	virtual CaculatorExpression * AddExpression(CaculatorExpression * ce) {
		ce->l = this;
		return ce;
	}
};

class AddCaculator :public CaculatorExpression {
public:
	AddCaculator(Expression * left, Expression * right) :CaculatorExpression(left, right) {}
	~AddCaculator() {}
	virtual int Interpreter(map<char, int> m) {
		return l->Interpreter(m) + r->Interpreter(m);
	}
	virtual int GetLevel() { return mLevel['+']; }
};

class SubCaculator :public CaculatorExpression {
public:
	SubCaculator(Expression * left, Expression * right) :CaculatorExpression(left, right) {}
	virtual ~SubCaculator() {}
	virtual int Interpreter(map<char, int> m) {
		return l->Interpreter(m) - r->Interpreter(m);
	}
	virtual int GetLevel() { return mLevel['-']; }
};

class MulCaculator :public CaculatorExpression {
public:
	MulCaculator(Expression * left, Expression * right) :CaculatorExpression(left, right) {}
	virtual ~MulCaculator() {}
	virtual int Interpreter(map<char, int> m) {
		return l->Interpreter(m) * r->Interpreter(m);
	}
	virtual int GetLevel() { return mLevel['*']; }
};

class DivCaculator :public CaculatorExpression {
public:
	DivCaculator(Expression * left, Expression * right) :CaculatorExpression(left, right) {}
	virtual ~DivCaculator() {}
	virtual int Interpreter(map<char, int> m) {
		return l->Interpreter(m) / r->Interpreter(m);
	}
	virtual int GetLevel() { return mLevel['/']; }
};

Expression * Analysis(string str) {
	Expression *root = nullptr;
	CaculatorExpression *p;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '\0') break;
		switch (str[i]) {
		case '+':
			root = new AddCaculator(root, new NumExpression(str[++i]));
			break;
		case '-':
			root = new SubCaculator(root, new NumExpression(str[++i]));
			break;
		case '*':
			p = new MulCaculator(nullptr, new NumExpression(str[++i]));
			root = root->AddExpression(p);
			break;
		case '/':
			p = new DivCaculator(nullptr, new NumExpression(str[++i]));
			root = root->AddExpression(p);
			break;
		default:
			root = new NumExpression(str[i]);
			break;
		}
	}
	return root;
}

int main() {
	mLevel['+'] = 0;
	mLevel['-'] = 0;
	mLevel['*'] = 1;
	mLevel['/'] = 1;

	string s = "a+b*c-d/e";

	Expression * e = Analysis(s);
	
	map<char, int> mKeyValue;
	mKeyValue['a'] = 3;
	mKeyValue['b'] = 2;
	mKeyValue['c'] = 4;
	mKeyValue['d'] = 6;
	mKeyValue['e'] = 3;

	int result = e->Interpreter(mKeyValue);
	cout << result << endl;

	system("pause");
	return 0;
}
