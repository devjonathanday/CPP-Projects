#include <cassert>

#include"tVector.h"
#include"tStack.h"
#include"tQueue.h"
#include"tLinkedList.h"
#include"tObjectPool.h"
#include<iostream>

using std::cout;
using std::endl;

//// check for memory leaks
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#ifdef _DEBUG
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW
//#endif

int main()
{
	{
		//VECTOR
		cout << "Initializing 'myVector'" << endl;
		tVector<int> myVector;
		cout << "Pushing back a '1':" << endl; myVector.push_back(1);
		myVector.print();
		cout << "Pushing back a '2':" << endl; myVector.push_back(2);
		myVector.print();
		cout << "Pushing back a '3':" << endl; myVector.push_back(3);
		myVector.print();
		cout << "Pushing back a '4':" << endl; myVector.push_back(4);
		myVector.print();
		cout << "Popping off the back of the list:" << endl; myVector.pop_back();
		myVector.print();
		cout << "Clearing the array:" << endl; myVector.clear();
		myVector.print();
		system("pause");

		//STACK
		system("cls");
		cout << "Initializing 'myStack'" << endl;
		tStack<int> myStack;
		cout << "Pushing back a '1':" << endl; myStack.push(1);
		myStack.print();
		cout << "Pushing back a '2':" << endl; myStack.push(2);
		myStack.print();
		cout << "Pushing back a '3':" << endl; myStack.push(3);
		myStack.print();
		cout << "Pushing back a '4':" << endl; myStack.push(4);
		myStack.print();
		cout << "Popping off the back of the list:" << endl; myStack.pop();
		myStack.print();
		system("pause");

		//QUEUE
		system("cls");
		cout << "Initializing 'myQueue'" << endl;
		tQueue<int> myQueue;
		cout << "Pushing back a '1':" << endl; myQueue.push_back(1);
		myQueue.print();
		cout << "Pushing back a '2':" << endl; myQueue.push_back(2);
		myQueue.print();
		cout << "Pushing back a '3':" << endl; myQueue.push_back(3);
		myQueue.print();
		cout << "Popping off the front of the list:" << endl; myQueue.pop_front();
		myQueue.print();
		cout << "Popping off the back of the list:" << endl; myQueue.pop_back();
		myQueue.print();
		cout << "Pushing a '4' to the front:" << endl; myQueue.push_front(4);
		myQueue.print();
		system("pause");

		//LINKED LIST
		system("cls");
		cout << "Initializing 'myList'" << endl;
		tForwardList<int> myList;
		//cout << "Pushing a '1' to the front:" << endl;
		myList.push_front(2);
		myList.push_front(5);
		myList.push_front(7);
		myList.push_front(14);
		myList.push_front(4);
		myList.push_front(3);
		myList.push_front(9);
		myList.resize(4);
		//tForwardList<int> testList;
		//testList = myList;

		cout << "Look at Visual Studio to see complete functionality." << endl;
		system("pause");

		//OBJECT POOL
		system("cls");
		cout << "Initializing 'myPool' of ints (capacity of 1)" << endl;
		tObjectPool<int> myPool(10);
		cout << "Inserting a '5' at index 2 of the pool" << endl;
		//myPool.insertAt(2, 5);
		cout << "Memory address of the next available position in the object pool:" << endl;
		cout << myPool.retrieve() << endl;
		cout << "Recycling the value of 5, then setting its index to be free." << endl;
		myPool.recycle(5);
		cout << "Expected result should be: (0) (0) (5) (0) (0) (0) (0) (0) (0) (0)" << endl;
		cout << "Available positions:       (F) (F) (F) (F) (F) (F) (F) (F) (F) (F)" << endl;
		cout << "Look at Visual Studio to see complete functionality." << endl;
		system("pause");
	}

	//_CrtDumpMemoryLeaks();

	return 0;
}