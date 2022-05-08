#pragma once
#include <iostream>
#include "DoubleLinkedList.h"

template <typename T>
class Queue
{
private:
	DoubleLinkeList<T> list;

public:
	int Size()
	{
		return list.Size();
	}

	bool isEmpty()
	{
		return Size() == 0;
	}

	void push(T elem)
	{
		list.addFirst(elem);
	}

	T pop()
	{
		if (isEmpty())
		{
			cout << "Error";
			return NULL;
		}

		return list.removeFirst();
	}

	T front()
	{
		if (isEmpty())
		{
			cout << "Error";
			return NULL;
		}

		return list.peekFirst();
	}
};