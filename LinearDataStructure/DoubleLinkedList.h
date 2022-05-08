#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
public:
	T data;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;

	Node<T>(T data, Node<T>* prev, Node<T>* next)
	{
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

template <typename T>
class DoubleLinkeList
{
private:
	int size = 0;
	Node<T>* head;
	Node<T>* tail;

	T remove(Node<T>* node)
	{
		if (node->prev == nullptr) // this node is first node
			return removeFirst();

		if (node->next == nullptr) // this node is last node
			return removeLast();

		node->next->prev = node->prev; // next node's prev pointer point to prev node
		node->prev->next = node->next; // prev node's next pointer point to next node

		T data = node->data;

		node->data = NULL;
		node = node->prev = node->next = nullptr;

		--size;

		return data;
	}

public:
	void Clear()
	{
		Node<T>* trav = head; // head ~ trail

		while (trav != nullptr) // when trav == nullptr, trav == tail's next
		{
			Node<T>* next = trav->next;
			trav->prev = trav->next = nullptr;
			trav->data == NULL;
			trav = next;
		}

		head = tail = trav = nullptr;
		size = 0;
	}

	int Size()
	{
		return size;
	}

	bool isEmpty()
	{
		return Size() == 0;
	}

	void addLast(T elem)
	{
		if (isEmpty()) // first node
		{
			head = tail = new Node<T>(elem, nullptr, nullptr);
		}
		else
		{
			tail->next = new Node<T>(elem, tail, nullptr); // data, prev, next
			tail = tail->next;
		}

		size++;
	}

	void addFirst(T elem)
	{
		if (isEmpty())
		{
			head = tail = new Node<T>(elem, nullptr, nullptr);
		}
		else
		{
			head->prev = new Node<T>(elem, nullptr, head);
			head = head->prev;
		}

		size++;
	}

	T peekFirst()
	{
		if (isEmpty())
		{
			cout << "Error";
			return NULL;
		}

		return head->data;
	}

	T peekLast()
	{
		if (isEmpty())
		{
			cout << "Error";
			return NULL;
		}

		return tail->data;
	}

	T removeFirst()
	{
		if (isEmpty())
		{
			cout << "Error";
			return NULL;
		}

		T data = head->data;

		head = head->next; // if delete first node, first node's next node be first node
		--size;

		if (isEmpty())
		{
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}

		return data;
	}

	T removeLast()
	{
		if (isEmpty())
		{
			cout << "Error";
			return NULL;
		}

		T data = tail->data;

		tail = tail->prev; // if delete last node, last node's previous node be last node
		--size;

		if (isEmpty())
		{
			head = nullptr;
		}
		else
		{
			tail->prev = nullptr;
		}

		return data;
	}

	T removeAt(int index)
	{
		if (index < 0 || index >= size)
		{
			cout << "Error";
			return NULL;
		}

		int i;
		Node<T>* trav;

		// binary Search
		if (index < size / 2)
		{
			for (i = 0, trav = head; i != index; i++)
			{
				trav = trav->next;
			}
		}
		else
		{
			for (i = size - 1, trav = tail; i != index; i--)
			{
				trav = trav->prev;
			}
		}

		return remove(trav);
	}
};