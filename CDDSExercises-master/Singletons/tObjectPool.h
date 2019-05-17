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

	}
	tObjectPool(size_t initialCapacity)  // initializes the pool to have a set number of objects
	{
		pool = new T[initialCapacity];
		free = new bool[initialCapacity];
		capacity = initialCapacity;
	}
	~tObjectPool()                       // destroys all objects
	{
		for (int i = 0; i < capacity; i++)
			delete pool[i];
		delete * pool;
	}

	T * retrieve()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (free[i])
				return pool[i]
		}
		return nullptr;
	}
	void recycle(T * obj)
	{
		for (int i = 0; i < capacity; i++)
			if (free[i])
			{
				pool[i] = obj;
				free[i] = false;
			}
		return null;
		
	}
	size_t getCapacity()                 // returns the total number of objects that this pool can provide
	{
		return capacity;
	}
};



//#include<vector>
//#pragma once
//
//template<typename T>
//class tObjectPool
//{
//	std::vector<T> objectList;
//
//	ObjectPool() {}                       // default initializes the object pool
//	ObjectPool(size_t initialCapacity)   // initializes the pool to have a set number of objects
//	{
//
//	}
//	~ObjectPool()                      // destroys all objects
//	{
//		/*for (auto i = used; i != free; i++)
//		{
//
//		}*/
//	}
//
//	T * free;                            // pointers to objects that can be reused
//	T * used;                            // pointers to objects that are currently in use
//	size_t freeCount;                   // number of objects that are free to use
//	size_t usedCount;                   // number of objects that are in use
//
//	T * retrieve()                      // returns a pointer to an object that will be used (returns null if none available)
//	{
//		if (freeCount == 0)
//			return null;
//		else
//			return free;
//	}
//	void recycle(T * obj)               // accepts a pointer that can be used in the future
//	{
//		*retrieve() = obj;
//	}
//
//	size_t capacity()                  // returns the total number of objects that this pool can provide
//	{
//		return objectList.size;
//	}
//};