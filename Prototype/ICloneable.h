#pragma once


#define CLONE_TYPE DEEP_CLONE
class ICloneable
{
public:
	virtual ~ICloneable() = default;

	virtual ICloneable* CloneObject() = 0;

	template<class T>T* Clone();
};

template<class T>T* ICloneable::Clone()
{
	return static_cast<T*>(CloneObject());
}