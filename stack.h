#pragma once

#include "clsqueue.h"


template<class T>
class clsMystack : public clsqueue<T>
{
public:

	void push(T val)
	{
		clsqueue<T>::_MyList.insertatbeginning(val);
	}

	T top()
	{
		return clsqueue<T>::front();
	}

	T bottom()
	{
		return clsqueue<T>::back();
	}
};
