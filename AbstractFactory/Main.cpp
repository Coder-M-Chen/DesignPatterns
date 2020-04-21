#include <iostream>

using namespace std;

class Jacket{
public:
	virtual void show() = 0;
	virtual ~Jacket() {}
};
class SportJacket :public Jacket {
public:
	virtual void show() {
		cout << "Jacket for sports!" << endl;
	}
	virtual ~SportJacket() {}
};
class WorkJacket :public Jacket {
public:
	virtual void show() {
		cout << "Jacket for work!" << endl;
	}
	virtual ~WorkJacket() {}
};

class Trousers {
public:
	virtual void show() = 0;
	virtual ~Trousers() {}
};
class SportTrousers :public Trousers {
public:
	virtual void show() {
		cout << "Trousers for sports!" << endl;
	}
	virtual ~SportTrousers() {}
};
class WorkTrousers :public Trousers {
public:
	virtual void show() {
		cout << "Trousers for work!" << endl;
	}
	virtual ~WorkTrousers() {}
};

class Shoes {
public:
	virtual void show() = 0;
	virtual ~Shoes() {}
};
class SportShoes :public Shoes {
public:
	virtual void show() {
		cout << "Shoes for sports!" << endl;
	}
	virtual ~SportShoes() {}
};
class WorkShoes :public Shoes {
public:
	virtual void show() {
		cout << "Shoes for work!" << endl;
	}
	virtual ~WorkShoes() {}
};

/* 创建一系列相关的对象 */
class ClothesFactory {
public:
	virtual Jacket * createJacket() = 0;
	virtual Trousers * createTrousers() = 0;
	virtual Shoes * createShoes() = 0;
	virtual ~ClothesFactory() {}
};

class SportClothesFactory :public ClothesFactory{
public:
	virtual Jacket * createJacket() {
		return new SportJacket();
	}
	virtual Trousers * createTrousers() {
		return new SportTrousers();
	}
	virtual Shoes * createShoes() {
		return new SportShoes();
	}
	virtual ~SportClothesFactory() {}
};

class WorkClothesFactory :public ClothesFactory {
public:
	virtual Jacket * createJacket() {
		return new WorkJacket();
	}
	virtual Trousers * createTrousers() {
		return new WorkTrousers();
	}
	virtual Shoes * createShoes() {
		return new WorkShoes();
	}
	virtual ~WorkClothesFactory() {}
};

class ClothesShop {
	ClothesFactory * mClothesFactory;
	Jacket * mJacket;
	Trousers * mTrousers;
	Shoes * mShoes;
public:
	ClothesShop(ClothesFactory * pClothesFactory){
		mClothesFactory = pClothesFactory;  /* 多态绑定抽象工厂 */
		mJacket = nullptr;
		mTrousers = nullptr;
		mShoes = nullptr;
	}
	void getClothes() {
		if (mJacket == nullptr) mJacket = mClothesFactory->createJacket();
		if (mTrousers == nullptr) mTrousers = mClothesFactory->createTrousers();
		if (mShoes == nullptr)mShoes = mClothesFactory->createShoes();
	}
	void show() {
		cout << "There are some clothes." << endl;
		mJacket->show();
		mTrousers->show();
		mShoes->show();
	}
};
int main() {
	{
		ClothesFactory * workFacktor = new WorkClothesFactory();
		ClothesShop csw(workFacktor);
		csw.getClothes();
		csw.show();

		ClothesFactory * sportFactory = new SportClothesFactory();
		ClothesShop css(sportFactory);
		css.getClothes();
		css.show();
	}

	system("pause");
	return 0;
}