#include"tVector.h"
#pragma once

template <typename T>
class tStack
{
	size_t stkSize = 0;
	size_t stkCapacity = 1;
	tVector<T> vec; // contains the data for a stack

public:

	tStack() {};
	~tStack() {}; //the underlying vector deallocates itself in its deconstructor

	void push(const T& value) // adds an element to the top of the Stack
	{
		vec.push_back(value);
		stkSize = vec.size();
		stkCapacity = vec.capacity();
	};

	void pop() // drops the top-most element of the Stack
	{
		vec.pop_back();
		stkSize = vec.size();
		stkCapacity = vec.capacity();
	};

	const T& top() const // returns the top-most element at the given element
	{
		return vec[vec.arrSize - 1];
	};
	size_t size() const // returns current number of elements
	{
		return vec.size();
	};
	bool empty() const // checks if the vector containing the data is empty
	{
		return vec.empty();
	};
	//T& operator[] (size_t index)
	//{
	//	return vec[index];
	//};
	void print()
	{
		std::cout << "Stack values: ";
		for (int i = 0; i < stkSize; i++)
			std::cout << "(" << vec[i] << ") ";
		std::cout << "\n";
	};
};