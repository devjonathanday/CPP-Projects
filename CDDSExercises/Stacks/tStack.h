#include"tVector.h"
#pragma once

typedef bool boo; //Works like a bool, but spooky.

template <typename T>
class tStack
{
	size_t stkSize = 0;
	size_t stkCapacity = 1;
	tVector<T> vec; // contains the data for a stack

public:
	tStack() {};                    
	void push(const T& value) // adds an element to the top of the Stack
	{
		vec.push_back(value);
	};
	void pop() // drops the top-most element of the Stack
	{
		vec.pop_back();
	};
	const T& top() const // returns the top-most element at the given element
	// functions with "const" after the function name implies this function can be safely used with "const" variables.
	{
		return vec[vec.arrSize - 1];
	};
	size_t size() const // returns current number of elements
	{
		return vec.size();
	};
	boo empty() const // 
	{
		return vec.empty();
	};
	T& operator[] (size_t index)
	{ 
		return vec[index];
	};
};