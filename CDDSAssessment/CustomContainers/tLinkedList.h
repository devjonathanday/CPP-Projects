#pragma once
#include<iostream>

template<typename T>
class tForwardList
{
	struct Node
	{
		T data = 0;                     // data for the element stored
		Node * next = nullptr;          // pointer to node following this node
	};
	Node * head;                    // pointer to head of linked list

public:
	tForwardList()                  // default constructor
	{
		head = nullptr;
	}
	~tForwardList() //destructor
	{
		clear();
	}
	void push_front(const T& val)   // adds element to front (i.e. head)
	{
		Node *newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		head = newNode;
	}
	void pop_front()                // removes element from front
	{
		if ((*head).next != nullptr)
		{
			Node * tempNode = head;
			head = (*head).next;
			delete tempNode;
		}
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
		(*this).head = other.head;
		Node * newTemp = (*this).head;

		for (Node * i = other.head; i->next != nullptr; i = i->next)
		{
			newTemp->next = i->next;
			newTemp = newTemp->next;
		}
		//delete newTemp;
	}
	tForwardList& operator=(const tForwardList& rhs)    // copy-assignment
	{
		//clear();
		tForwardList * newList = new tForwardList;
		Node newNode = { rhs.head->data, nullptr };
		//*head = new Node{ rhs.head->data, newNode };
		Node * newTemp = newList->head;

		for (Node * i = rhs.head; i->next != nullptr; i = i->next)
		{
			Node * newNode;
			newNode->data = i->next->data;
			// hi jonathan :)
			newTemp->next = newNode;
			newTemp = newTemp->next;
		}
		return * newList;
	}
	void empty() const              // Returns true if there are no elements
	{
		if (head == nullptr)
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
		/*while(head->next != nullptr)
		{
			pop_front();
		}
		head = nullptr;*/
		resize(1);
		delete head;
	}
	void resize(size_t newSize)     // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized
	{
		if (newSize > count())
		{
			Node * tempNode = head; //Make a new pointer at the beginning of the linked list
			for (int i = 0; i < newSize - 1; i++) //counter for the new size
			{
				if (tempNode->next == nullptr) //Check if we're at the end of the list
				{
					Node * newNode = new Node; //Make a new node with default values (val=0, next=nullptr)
					tempNode->next = newNode; //Make the last node in the list point to the new node
					newNode->next = nullptr; //Make the NEW last node point to a nullptr
					tempNode = tempNode->next; // Iterate the temp node
				}
				else
					tempNode = tempNode->next; //If we haven't reached the end of the list, just iterate to the next one
			}
		}
		else
		{
			Node * originalHead = head; //Save the original starting point of the list
			Node * tempNode = originalHead; //Make a new pointer at the beginning of the linked list
			for (int i = 0; i < newSize - 1; i++) //counter for the new size
				tempNode = tempNode->next; //Iterate through the list, stopping at the new size limit

			Node * newHead = tempNode->next; //Save the next node as a new pointer
			tempNode->next = nullptr; //Cut off the end of the original linked list by pointing to nullptr
			head = newHead; //Make the linked list start at the second half of the list
			while (head->next != nullptr)
				pop_front(); //pop off the front of the new list until there's nothing left
			
			head = originalHead; //resetting the head
		}
	}
	void print() //For demonstration, only works with values that can be passed into std::cout
	{
		/*if (head->next == nullptr)
			cout << (*head).data << " -> nullptr" << endl;
		else
		{
			for (Node * i = head; ; i = i->next)
			{
				if (i->next != nullptr)
					cout << (*i).data << " -> ";
				else
				{
					cout << (*i).data << " -> ";
					break;
				}
			}
			cout << "nullptr" << endl;
		}*/

		//if (head->next == nullptr)
		//{
		//	cout << (*head).data << " -> nullptr" << endl;
		//}
		//else
		//{
		//	Node * i = head;
		//	//cout << (*head).data << " -> ";
		//	while (true)
		//	{
		//		if(i->next != nullptr)
		//		{
		//			cout << (*i).data << " -> ";
		//			i = i->next;
		//		}
		//		else
		//		{
		//			cout << (*i).data << " -> nullptr" << endl;
		//			break;
		//		}
		//	}
		//	delete i;
		//}

		for (auto i = (*this).begin(); i != (*this).end(); ++i)
			std::cout << (*i).data << std::endl;
	}

	int count()
	{
		int counter = 0;
		for (auto i = begin(); i != end(); ++i)
			counter++;
		return counter;
	}

	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator() {}
		iterator(Node * start)
		{
			cur = start;
		}
		bool operator==(const iterator& rhs) const  // returns true if the iterator points to the same node
		{
			return cur == rhs.cur;
		};
		bool operator!=(const iterator& rhs) const  // returns false if the iterator does not point to the same node
		{
			return cur != rhs.cur;
		};
		T& operator*() const                        // returns a reference to the element pointed to by the current node
		{
			return cur->data;
		};
		iterator& operator++()                      // pre-increment (returns a reference to this iterator after it is incremented)
		{
			cur = cur->next;
			return (*this);
		};
		iterator operator++(int)                    // post-increment (returns an iterator to current node while incrementing the existing iterator)
		{
			iterator newIterator;
			newIterator.cur = cur;
			++cur;
			return newIterator;
		};
		//void goToBegin(Node* _head)
		//{
		//	cur = _head;
		//};
	};

	iterator begin()
	{
		return iterator(head);
	};
	iterator end()
	{
		return iterator(nullptr);
	};
};