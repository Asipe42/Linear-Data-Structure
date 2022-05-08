#pragma once
#include <iostream>
#include "DoubleLinkedList.h"

template <typename T>
class Stack
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
		list.addLast(elem);
	}

	T pop()
	{
		if (isEmpty())
		{
			cout << "Error";
			return NULL;
		}

		return list.removeLast();
	}

	T Peek()
	{
		if (isEmpty())
		{
			cout << "Error";
			return NULL;
		}

		return list.peekLast();
	}
};