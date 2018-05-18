#pragma once

template<class Type>
class Singleton
{
protected:
	Singleton() = default;
	virtual ~Singleton() = default;
	Singleton& operator=(const Singleton& other) = delete;
	Singleton(const Singleton&) = delete;

private:
	static Type Instance;

public:
	static Type * Get()
	{
		return &Instance;

	}
};

template<class Type> Type Singleton<Type>::Instance;