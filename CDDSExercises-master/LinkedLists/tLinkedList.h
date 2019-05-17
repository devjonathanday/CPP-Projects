#pragma once
#include<iostream>

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList()                  // default constructor
	{
		head = nullptr;
	}
	~tForwardList()                 // destructor
	{

	}
	void push_front(const T& val)   // adds element to front (i.e. head)
	{
		Node *newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		head = newNode;

		//if (head == NULL)
		//{
		//	//head->next = new Node;
		//	head = new Node;
		//	head->data = val;
		//}
		//else
		//{
		//	Node * newNode = new Node{ val, head };
		//	head = newNode;
		//}
	}
	void pop_front()                // removes element from front
	{
		Node * tempNode = head;
		head = (*head).next;
		delete tempNode;
	}
	T& front()                      // returns the element at the head
	{
		return (*head).data;
	}
	const T& front() const          // returns the element at the head (const)
	{
		return (*head).data;
	}
	void remove(const T& val)       // removes all elements equal to the given value
	{
		while (head->data == val) {
			pop_front();
			if (head == nullptr) {
				return;
			}
		}
		Node * lastKnownGood = head;
		for (Node * it = lastKnownGood->next; it != nullptr;)
		{
			// always be safe to access next
			if (it->data == val)
			{
				auto next = it->next;
				delete it;
				it = next;
				continue;
			}
			lastKnownGood->next = it;
			lastKnownGood = it;
			it = it->next;
		}
		lastKnownGood->next = nullptr;
	}
	tForwardList(const tForwardList& other)             // copy-constructor
	{

	}
	tForwardList& operator=(const tForwardList &rhs)    // copy-assignment
	{

	}
	void empty() const              // Returns true if there are no elements
	{
		if (head == NULL)
			return true;
		else
		{
			if (head->data == NULL)
			{
				return true;
			}
		}
		return false;
	}
	void clear()                    // Destroys every single node in the linked list
	{
		for (Node * it = head; it != nullptr;)
		{
			pop_front();
		}
	}
	void resize(size_t newSize)     // Resizes the linked list to contain the given number of elements
	// New elements are default-initialized
	{

	}
};