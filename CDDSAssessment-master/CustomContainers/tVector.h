#pragma once
#include<iostream>

//// check for memory leaks
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#ifdef _DEBUG
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW
//#endif

template <typename T>
class tVector
{
	const static size_t growthFactor = 2;
	T *arr; // pointer to underlying array
	size_t arrSize = 0; // stores the number of elements currently used
	size_t arrCapacity = 1; // stores the capacity of the underlying array

public:

	tVector() // initializes the vector's default values
	{
		arr = new T[arrCapacity];
	};

	~tVector() // destroys the underlying array
	{
		delete[] arr;
	};
	tVector(const tVector &vec) // copy constructor
	{
		T *temp = new T[vec.arrCapacity]; // create new array with the same capacity
		for (int i = 0; i < vec.arrSize; i++) { temp[i] = vec.arr[i]; } // assign the values over
		delete[] arr;
		arr = temp;
		arrCapacity = vec.arrCapacity;
		arrSize = vec.arrSize;
		return *this;
	};

	T *data() // returns a pointer to the underlying array
	{
		return arr;
	};

	void reserve(size_t newCapacity)    // resizes the vector to at least this many elements
	{
		//If my array size is zero, expand the capacity to include at least one element.
		if (newCapacity < 1) { newCapacity = 1; }
		while (arrCapacity < newCapacity)
			arrCapacity *= growthFactor;
		T * newArr = new T[arrCapacity];
		for (int i = 0; i < arrSize; i++)
		{
			newArr[i] = arr[i]; // Copy data from arr to temp
		};
		delete[] arr; // delete original array
		arr = newArr; // assign new array pointer to temp pointer
		arrCapacity = newCapacity;
	}

	void push_back(const T &value) // adds an element to the end of the vector
	{
		if (arrSize == arrCapacity) { reserve(arrSize + 1); }
		arr[arrSize] = value;
		arrSize++;
	};
	void pop_back() // drops the last element of the vector
	{
		if (arrSize > 0) arrSize--;
	};
	T& operator[] (size_t index) // subscript operator to access array element within class
	{
		return arr[index];
	}; 
	tVector& operator=(const tVector &vec)
	{
		arr = vec;
	};
	size_t size() const // returns current number of elements
	{
		return arrSize;
	};
	size_t capacity() const // returns maximum number of elements we can store
	{
		return arrCapacity;
	}
	bool empty() const // Returns true if the vector contains no elements.
	{
		return (!arrSize);
	};
	void resize(size_t size)  // Resizes the vector to contain the given number of elements.
	{
		if (size < arrSize)
		{
			reserve(size);
			//arrSize = size;
		}
		else
		{ 
			for (size_t i = 0; i < size - arrSize; i++)
			{ pop_back(); } 
}
	};
	void shrink_to_fit() // Resizes the vector's capacity to match its size.
	{
		if (arrSize == arrCapacity) { return; }
		T* temp = new T[arrSize];
		for (size_t i = 0; i < arrSize; i++) { temp[i] = arr[i]; }
		delete[] arr;
		arr = temp;
		arrSize = arrCapacity = arrSize;
	};
	void clear() // Empties the vector (all elements are destroyed in this process)
	{
		//for (int i = 0; i < arrSize; i++)
		//{
		//	pop_back();
		//}
		arrSize = 0;
	};
	void print()
	{
		std::cout << "Vector values: ";
		for (int i = 0; i < arrSize; i++)
			std::cout << "(" << arr[i] << ") ";
		std::cout << "\n";
	};
};