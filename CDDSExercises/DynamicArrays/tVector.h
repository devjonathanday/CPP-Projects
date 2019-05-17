#pragma once

template <typename T>
class tVector
{
	const static size_t growthFactor = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize = 0;    
	// stores the number of elements currently used
	//size_t ArrayDataThatIsAlreadyUsedButIsStillSmallerThanCapacityNotToBeConfusedWithActualArrayCapacity = 1;
	size_t arrCapacity = 1;                 // stores the capacity of the underlying array

public:
	tVector()                           // initializes the vector's default values
	{
		arr = new T[arrCapacity];
	};

	~tVector()                          // destroys the underlying array
	{
		delete[] arr;
		delete arr;
	};

	tVector(const tVector &vec)
	{
		arr = vec.arr;
	};

	T *data()                           // returns a pointer to the underlying array
	{
		return arr;
	};
	void reserve(size_t newCapacity)    // resizes the vector to at least this many elements
	{
		T * newArr = new T[newCapacity];
		//Copy data from arr to temp
		for (int i = 0; i < arrSize; i++)
		{
			newArr[i] = arr[i];
		}

		//delete original arr
		delete[] arr;

		//assign new arr pointer to temp pointer
		arr = newArr;
		arrCapacity = newCapacity;

		//delete newArr;
	}
	void push_back(const T &value)      // adds an element to the end of the vector
	{
		if (arrSize == arrCapacity)
		{
			reserve(arrSize + 1);
		}
		arr[arrSize] = value;
		arrSize++;
	}
	void pop_back()                     // drops the last element of the vector
	{
		arrSize--;
	}
	T& operator[] (size_t index) //subscript operator replaces vec.at();
	{
		return arr[index];
	};
	tVector& operator=(const tVector &vec)
	{
		T *temp = new T[vec.arrCapacity];

		for (int i = 0; i < vec.arrSize; i++)
		{
			temp[i] = vec.arr[i];
		}

		delete[] arr;
		arr = temp;
		arrCapacity = vec.arrCapacity;
		arrSize = vec.arrSize;
		return *this;
	};
	size_t size() const                 // returns current number of elements
	{
		return arrSize;
	};
	size_t capacity() const             // returns maximum number of elements we can store
	{
		return arrCapacity;
	}
	bool empty()         // Returns true if the vector contains no elements.
	{
		if (arrSize == 0)
		{
			return false;
		}
		return true;
	};
	void resize(size_t size)  // Resizes the vector to contain the given number of elements.
	{
		reserve(size);

		if (newSize < arrSize)
		{
			arrSize = size;
		}
		else 
		{
			for (size_t i = arrSize; i < size; i++)
			{
				pop_back(T());
			}
		}
	};
	void shrink_to_fit() // Resizes the vector's capacity to match its size.
	{
		if (arrSize == arrCapacity)
		{
			return;
		}
		T* temp = new T[arrSize];
		for (size_t i = 0; i < arrSize; i++)
		{
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
		arrSize = arrCapacity = arrSize;
	};
	void clear()         // Empties the vector (all elements are destroyed in this process)
	{
		for (int i = 0; i < arrSize; i++)
		{
			pop_back();
		}
	};
};