#pragma once
#include "tVector.h"

template <typename T>
class tQueue
{
	tVector<T> vec;                       // contains the data for a queue

public:
	tQueue() {}; // default initializes the queue
	~tQueue() {}; // deconstructs (the underlying vector deallocates itself in its deconstructor)
	tQueue(size_t count, const T& value) // constructs a queue with the given number of elements
	// each element is initialized by copying the given value
	{
		vec.resize(count);
		for (int i = 0; i < count; i++)
		{
			vec[i] = value;
		}
	};
	void push_front(const T& value) // adds an element to the beginning of the Queue
	{
		vec.push_back(vec[vec.size()]); //duplicates the last value and increases array size

		for (size_t i = vec.size() - 1; i > 0; i--)
		{
			vec[i] = vec[i - 1];
		}
		vec[0] = value;
	};
	void push_back(const T& value) // adds an element to the top of the Queue
	{
		vec.push_back(value);
	};
	void pop_front() // drops the bottom-most element of the Queue
	{
		if (vec.size() > 0)
		{
			for (int i = 0; i < size() - 1; i++) { vec[i] = vec[i + 1]; }
			pop_back();
		}
	};
	void pop_back() // drops the bottom-most element of the Queue
	{
		vec.pop_back();
	};
	T& front()// returns the front-most element
	{
		return vec[0];
	};
	T& back() // returns the back-most element
	{
		return vec[vec.size() - 1];
	};
	size_t size() const // returns current number of elements
	{
		return vec.size();
	};
	//T& operator[] (size_t index)
	//{
	//	return vec[index];
	//};
	void print()
	{
		std::cout << "Queue values: ";
		for (int i = 0; i < vec.size(); i++)
			std::cout << "(" << vec[i] << ") ";
		std::cout << "\n";
	};
};