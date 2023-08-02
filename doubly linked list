#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;



template<class T>
class clsDblLinkedList;

template<class T>
class Node
{
private:
	T val;
	Node* next;
	Node* prev;

	friend class clsDblLinkedList<T>;

public:

	Node(T val, Node<T>* next , Node<T>* prev )
	{
		this->val = val;
		this->next = next;
		this->prev = prev;

	}

	T getval() { return val; }

};


template<class T>
class clsDblLinkedList
{
private:

	Node<T>* head;
	Node<T>* tail;
	int size;

public:




	clsDblLinkedList(); //copy constructor

	~clsDblLinkedList();

	void insertatbeginning(T);
	void insertafter(Node<T>*, T);
	void insertatend(T);

	void deletenode(Node<T>*);
	Node<T>* find(T);
	bool is_empty();

	void printlist();

	void deletefirstnode();
	void deletelastnode();

	void clear();
	int gsize();
	void reverse();
	Node<T>* getnode(int);
	T getitem(int);

	void updateitem(int, T);
	void insertafter(int, T);
};


template<class T>
clsDblLinkedList<T>::~clsDblLinkedList()
{
	clear();
	delete head;
	delete tail;
}


template<class T>
void clsDblLinkedList<T>::clear()
{
	while (size) deletefirstnode();
}


template<class T>
clsDblLinkedList<T>::clsDblLinkedList()
{
	head = tail = nullptr; size = 0;
}

template<class T>
bool clsDblLinkedList<T>::is_empty()
{
	return !size;
}

template<class T>
void clsDblLinkedList<T>::insertatbeginning(T val)
{
	size++;
	Node<T>* newnode = new Node<T>(val, head, nullptr);
	if (head) head->prev = newnode;
	head = newnode;
	if (!tail) tail = head;
}

template<class T>
void clsDblLinkedList<T>::insertatend(T val)
{
	size++;
	Node<T>* newnode = new Node<T>(val, nullptr, tail);
	if (tail) tail->next = newnode;
	tail = newnode;
	if (!head) head = tail;
}

template<class T>
Node<T>* clsDblLinkedList<T>::find(T val)
{
	Node<T>* curr = head;
	
	while (curr)
	{
		if (curr->val == val) return curr;
		curr = curr->next;
	}
	return nullptr;
}

template<class T>
void clsDblLinkedList<T>::insertafter(Node<T>* node, T val)
{
	if (node == tail) insertatend(val);
	else if (node == head) insertatbeginning(val);
	else
	{
		Node<T>* newnode = new Node<T>(val, node->next, node);

		node->next->prev = newnode;
		node->next = newnode;
		size++;
		return;
	}
}



template<class T>
void clsDblLinkedList<T>::deletenode(Node<T>* node)
{
	if (!node) return;


	if (node == head) deletefirstnode();
	else if (node == tail) deletelastnode();

	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		size--;
		delete node;
	}
	
	return;
}



template<class T>
void clsDblLinkedList<T>::printlist()
{
	Node<T>* curr = head;

	while (curr)
	{
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}



template<class T>
void clsDblLinkedList<T>::deletefirstnode()
{
	Node<T>* delnode = head;

	if (!head) return;

	else if (head == tail)
	{
		head = tail = nullptr;
	}

	else
	{
		head = head->next;
		head->prev = nullptr;
	}
	size--;
	delete delnode;
}


template<class T>
void clsDblLinkedList<T>::deletelastnode() 
{
	Node<T>* delnode = tail;

	if (!tail) return;

	else if (head == tail)
	{
		head = tail = nullptr;
	}

	else
	{
		tail = tail->prev;
		tail->next = nullptr;
	}
	size--;
	delete delnode;
}

template<class T>
int clsDblLinkedList<T>::gsize()
{
	return size;
}

template<class T>
void clsDblLinkedList<T>::reverse()
{
	Node<T>* curr = head;
	while (curr)
	{
		swap(curr->next, curr->prev);
		curr = curr->prev;
	}
	swap(head, tail);
}

template<class T>
Node<T>* clsDblLinkedList<T>::getnode(int index)
{
	if (index < 0 or index >= size) throw string("index out of range");
	Node<T>* curr = head;
	while (index--) curr = curr->next;

	return curr;
}

template<class T>
T clsDblLinkedList<T>::getitem(int index)
{
	return getnode(index)->val;
}


template<class T>
void clsDblLinkedList<T>::updateitem(int index, T val)
{
	Node<T>* curr = getnode(index);
	curr->val = val;
}


template<class T>
void clsDblLinkedList<T>::insertafter(int index, T val)
{
	Node<T>* curr = getnode(index);
	insertafter(curr, val);
	return;
}
