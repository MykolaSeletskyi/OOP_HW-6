#include "Vector.h"
int Vector::bad = 0;
void Vector::reserve(size_t capacity)
{
	int* temp = new int[capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		temp[i] = arr[i];
	}
	this->capacity = capacity;
	delete[]arr;
	arr = temp;
}

void Vector::reserve(const Vector& obj)
{
	int* arr = new int[obj.capacity];
	for (size_t i = 0; i < obj.capacity; i++)
	{
		arr[i] = obj.arr[i];
	}
	this->capacity = obj.capacity;
}

void Vector::pushBack(int elem)
{
	if (size == capacity)
	{
		reserve(size + START_CAPACITY);
	}
	arr[size] = elem;
	size++;
}

void Vector::popBack()
{
	if (size>0)
	{
		arr[size] = 0;
		size--;
	}
}

int& Vector::operator[](size_t number)
{
	if (number<=size)
	{
		return arr[number];
	}
	return bad;
}

void Vector::fill(int value)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}
