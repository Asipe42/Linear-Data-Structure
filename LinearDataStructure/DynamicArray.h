#pragma once
#include <iostream>

using namespace std;

template <typename T>
class DynamicArray
{
private:
	T* arr;
	int length = 0; // this is using memory count
	int capacity = 0; // this is available memory count

public:
	DynamicArray()
	{
		capacity = 16; // number of 16 doesn't mean anything
		arr = new T[capacity]; // this memory is allocated heap area
	}

	DynamicArray(int capacity)
	{
		if (capacity < 0)
		{
			cout << "Exception\n";

			T = new T[16];
			return;
		}

		this->capacity = capacity;
		arr = new T[capacity];
	}

	int Size()
	{
		return length;
	}

	bool isEmpty()
	{
		return Size() == 0;
	}

	T get(int index)
	{
		if (index >= length || index < 0)
			return NULL;

		return arr[index];
	}

	void set(int index, T elem)
	{
		arr[index] = elem;
	}

	void Clear()
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = NULL;
		}

		length = 0;
	}

	void add(T elem)
	{
		if (length + 1 >= capacity) // memory is full
		{
			if (capacity == 0) // The reason why I use this condition is "0 * 2 == 0"
			{
				capacity = 1;
			}
			else
			{
				capacity *= 2;
			}

			T* newArr = new T[capacity];

			for (int i = 0; i < length; i++) // Migrate past data
			{
				newArr[i] = arr[i];
			}

			arr = newArr;
		}

		arr[length++] = elem;
	}

	T remove()
	{
		length--;

		T data = arr[length];

		arr[length] = NULL;

		return data;
	}
};