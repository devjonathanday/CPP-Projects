#include"tLinkedList.h"
#include<iostream>

using std::cout;
using std::endl;

int main()
{
	tForwardList<int> testList;

	testList.push_front(4);
	testList.push_front(4);
	testList.push_front(7);
	testList.push_front(4);
	testList.push_front(4);
	testList.push_front(3);
	testList.push_front(4);
	testList.push_front(4);
	//testList.remove(4);

	testList.clear();

	//cout << testList.front() << endl;


	return 0;
}