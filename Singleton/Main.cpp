/* 单例模式，饿汉式、懒汉式，懒汉式须线程安全处理 */

#include <iostream>
#include <atomic>
#include <mutex>
using namespace std;

class Singleton{
private:
	Singleton() {};
	Singleton(Singleton & t) {};
	static std::mutex mMutex;
public:
	static std::atomic<Singleton *> mInstance;

	/* 懒汉式 双检查锁 */
	static Singleton * getInstance() {
		Singleton * tmp = mInstance.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);
		if (tmp == nullptr) {
			std::lock_guard<std::mutex> lock(mMutex);
			tmp = mInstance.load(std::memory_order_relaxed);
			if (tmp == nullptr) {
				tmp = new Singleton();
				std::_Atomic_thread_fence(std::memory_order_release);
				mInstance.store(tmp, std::memory_order_relaxed);
			}
		}
		return tmp;
	}

	/* 饿汉式 */
	static Singleton * getInstance1() {
		static Singleton instance;
		return &instance;
	}

	void func() {
		cout << "This is a function, address: " << (int)this << endl;
	}
};

int main() {
	{
		Singleton * pInstance = Singleton::getInstance();
		if (pInstance != nullptr) {
			pInstance->func();
		}
	}

	system("pause");
	return 0;
}