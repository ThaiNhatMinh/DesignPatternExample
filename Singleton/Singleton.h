#pragma once

#define SINGLETON_TYPE 3

template <class T>
class Singleton
{
public:
	static T * Get()
	{
#if defined(SINGLETON_TYPE) && (SINGLETON_TYPE==2)
		if (!instance) instance = new T();
#elif defined(SINGLETON_TYPE) && (SINGLETON_TYPE == 3)
		std::lock_guard<std::mutex> myLock(myMutex);
		if (!instance) {
			instance = new T();
		}
#endif
		return instance;
	}
	static void Release()
	{
		if (instance) delete instance;
	}
private:
	
	
	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;
protected:
	Singleton() = default;
	virtual ~Singleton() = default;
private:
	static T* instance;
#if defined(SINGLETON_TYPE) && (SINGLETON_TYPE==3)
	static std::mutex myMutex;
#endif
};

#if defined(SINGLETON_TYPE) && (SINGLETON_TYPE==1)
template<class T>T* Singleton<T>::instance = new T();
#elif defined(SINGLETON_TYPE) && (SINGLETON_TYPE==2)
template<class T>T* Singleton<T>::instance =nullptr;
#elif defined(SINGLETON_TYPE) && (SINGLETON_TYPE==3)
template<class T>T* Singleton<T>::instance = nullptr;
template<class T>std::mutex Singleton<T>::myMutex;
#endif