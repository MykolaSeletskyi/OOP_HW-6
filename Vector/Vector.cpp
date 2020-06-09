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

void Vector::copy(const Vector& obj)
{
	reserve(obj.capacity);
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

void Vector::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
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

int& Vector::operator[](size_t number)const
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
		copy(obj);
	}
	return *this;
}

Vector Vector::operator()(size_t start, size_t len)
{
	if (start >=  size)
	{
		return bad;
	}
	if (len>size)
	{
		len = size- start;
	}
	Vector result(len);
	for (size_t i = 0; i <= len; i++)
	{
		result[i] = arr[i + start];
	}
	return result;
}

Vector::operator int() const
{
	int result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result += arr[i];
	}
	return result;
}

Vector operator!(const Vector& obj)
{
	Vector result (obj);

	int temp = result[0];
	for (int i = 0; i < obj.getSize() / 2; ++i)
	{
		result[i] = temp;
		temp = result[obj.getSize() - i - 1];
		result[obj.getSize() - i - 1] = result[i];
		result[i] = temp;
	}
	return result;
}

bool operator==(const Vector& left, const Vector& right)
{
	if (left.getSize()!=right.getSize())
	{
	return false;
	}
	for (size_t i = 0; i < left.getSize(); i++)
	{
		if (left[i]!=right[i])
		{
			return false;
		}			
	}
	return true;
}

bool operator!=(const Vector& left, const Vector& right)
{
	return !(left== right);
}

Vector& operator+=( Vector& left, const Vector& right)
{
	for (size_t i = 0; i < right.getSize(); i++)
	{
		left.pushBack(right[i]);
	}
	return left;
}

Vector operator+(const Vector& left, const Vector& right)
{
	Vector result(left);
	for (size_t i = 0; i < right.getSize(); i++)
	{
		result.pushBack(right[i]);
	}
	return result;
}

Vector operator++(Vector& obj, int)
{
	Vector temp(obj);
	++obj;
	return temp;
}

Vector& operator++(Vector& obj)
{
	for (size_t i = 0; i < obj.getSize(); i++)
	{
		obj[i];
	}
	return obj;
}

Vector& operator*=(Vector& obj, const int number)
{
	return (obj = obj * number);
}

Vector operator*(const Vector& obj, int number)
{
	Vector result(obj);
	for (size_t i = 0; i < result.getSize(); i++)
	{
		result[i] *= number;
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const Vector& obj)
{
	for (size_t i = 0; i < obj.getSize(); i++)
	{
		out << obj[i] << "\t";
	}
	return out;
}
