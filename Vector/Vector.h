#pragma once
class Vector
{
	static const size_t START_CAPACITY = 5;
	int* arr = nullptr;
	size_t capacity;
	size_t size;
	void reserve(size_t capacity = START_CAPACITY);//мона поставити size + START_CAPACITY
	void reserve(const Vector& obj);
	static int bad;
public:
	Vector(size_t size=0) : Vector(size, 0) {                                                                   };
	Vector(size_t size, int value) {
		reserve(size + START_CAPACITY);
		this->size = size;
		fill(value);
	}
	Vector(const Vector& obj)
	{
		size = obj.size;
		reserve(obj);
	}
	Vector(Vector&& obj)
	{
		size = obj.size;
		arr = obj.arr;
		capacity = obj.capacity;
		obj.arr = nullptr;
		obj.size = 0;
	}
	size_t getSize()const
	{
		return size;
	}
	size_t getCapacity()const
	{
		return capacity;
	}
	void pushBack(int elem);
	void pushIndex(int elem, size_t index);
	void popIndex(size_t index);
	void popBack();
	int& front()
	{
		if (size==0)
		{
			return bad;
		}
		return arr[0];
	}
	int& back()
	{
		if (size == 0)
		{
			return bad;
		}
		return arr[size];
	}
	bool empty()const
	{
		return size == 0;
	}
	void setValue(size_t index, int value) 
	{
		if (index<size)
		{
			arr[index] = value;
		}
	}
	void fill(int value);
	void clear()
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
		size=0;
	}

	int &operator [](size_t number);
	~Vector()
	{
		delete[]arr;
		arr = nullptr;
		capacity = 0;
		size = 0;
	};
};

