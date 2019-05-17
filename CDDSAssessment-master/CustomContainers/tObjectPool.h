#pragma once

template<typename T>
class tObjectPool
{
	T * pool;                            // all objects stored in the pool
	bool * free;                         // indicates whether an object is available
	size_t capacity;					 // capacity of the object pool

public:

	tObjectPool()                        // default initializes the object pool
	{
		capacity = 1;
		pool = new T[1];
		free = new bool[1];
		free[0] = true;
		pool[0] = T();
	}
	tObjectPool(size_t initialCapacity)  // initializes the pool to have a set number of objects
	{
		pool = new T[initialCapacity];
		free = new bool[initialCapacity];
		capacity = initialCapacity;
		for (int i = 0; i < capacity; i++)
		{
			free[i] = true;
			pool[i] = T();
		}
	}
	~tObjectPool()                       // destroys all objects
	{
		delete pool;
		delete free;
	}

	T * retrieve()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (free[i])
			{
				free[i] = false;
				return &pool[i];
			}
		}
		return nullptr;
	}
	void recycle(T obj)
	{
		for (int i = 0; i < capacity; i++)
			if (pool[i] == obj && !free[i])
			{
				free[i] = true;
			}
	}
	void empty()
	{
		for (int i = 0; i < capacity; i++)
			if (!free[i])
				return false;
		return true;
	}
	//void insertAt(int index, T value)
	//{
	//	if (free[index])
	//	{
	//		pool[index] = value;
	//		free[index] = false;
	//	}
	//}
};