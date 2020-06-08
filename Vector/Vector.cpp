#include "Vector.h"
int Vector::bad = 0;
void Vector::reserve(size_t capacity)
{
	if (this->capacity >= capacity)
	{
		return;
	}
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
	if (arr!=nullptr)
	{
	delete[]arr;
	}
	reserve(obj.size);
	size = obj.size;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	for (size_t i = size; i < capacity; i++)
	{
		arr[i] = 0;
	}
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

void Vector::insert(int elem, size_t index)
{
	if (index <= size)
	{
		if (size == capacity)
		{
			reserve(size + START_CAPACITY);
		}
		int* temp = new int[++size];
		for (size_t i = 0; i < size; i++)
		{
			if (i < index)
			{
				temp[i] = arr[i];
			}
			else if (i > index)
			{
				temp[i] = arr[i-1];
			}
		}
		temp[index] = elem;
		delete[]arr;
		arr = temp;
	}
}

void Vector::popIndex(size_t index)
{
	if (index <= size)
	{
		int* temp = new int[--size];
		for (size_t i = 0; i < size; i++)
		{
			if (i < index)
			{
				temp[i] = arr[i];
			}
			else if (i >= index)
			{
				temp[i] = arr[i+1];
			}
		}
		delete[]arr;
		arr = temp;
	}
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

Vector& Vector::operator=(const Vector& obj)
{
	if (this != &obj)
	{
		reserve(obj);
	}
	return *this;
}


Vector Vector::operator*(int number) const
{
	Vector result(*this);
	for (size_t i = 0; i < size; i++)
	{
		result.arr[i]*=number;
	}
	return result;
}

Vector Vector::operator/(const Vector& obj) const
{
	return Vector();
}

Vector& Vector::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i]++;
	}
	return *this;
}

Vector Vector::operator++(int)
{
	Vector temp(*this);
	this->operator++();
	return temp;
}
