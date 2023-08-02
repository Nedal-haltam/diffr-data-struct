#pragma once

#include "clsDblLinkedList.h"


template<class T>
class clsqueue
{
private:
	clsDblLinkedList<T> _MyList;
public:


		void push(T Item)
		{
			_MyList.insertatend(Item);
		}


		void pop()
		{
			_MyList.deletefirstnode();
		}

		void Print()
		{
			_MyList.printlist();
		}

		int Size()
		{
			return _MyList.gsize();
		}

		bool IsEmpty()
		{
			return _MyList.is_empty();
		}

		T front()
		{
			return _MyList.getitem(0);
		}

		T back()
		{
			return _MyList.getitem(Size() - 1);
		}

		T GetItem(int Index)
		{
			return _MyList.getitem(Index);

		}

		void Reverse()
		{

			_MyList.reverse();

		}

		void UpdateItem(int Index, T NewValue)
		{
			_MyList.updateitem(Index, NewValue);

		}

		void InsertAfter(int Index, T NewValue)
		{
			_MyList.insertafter(Index, NewValue);
		}


		void InsertAtFront(T Value)
		{
			_MyList.insertatbeginning(Value);

		}

		void InsertAtBack(T Value)
		{
			_MyList.insertatend(Value);


		}


		void Clear()
		{
			_MyList.clear();
		}



};
