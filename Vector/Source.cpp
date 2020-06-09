#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	//не зробив не зрозумів для чого

	//Метод зміни фактичної довжини масиву 
	//void resize(size_t newSize, int value = 0), 
	//ємність масиву якщо потрібно - збільшується


	Vector v1(2); // фактичний розмір = 2, елементи нулі, buffer -> [0][0], 
		//buffer - може вказувати на більшу ділянку, якщо capacity більше(capcity = 4, то buffer -> [0][0][.][.])
	v1.pushBack(10);
	v1.pushBack(20);
	cout << "The size of v is " << v1.size() << endl; // 4
	cout << "The capacity of v is " << v1.capacity() << endl; // >=4, якась Ваша формула, н-д, якщо ємності не вистачає можна збільшувати ємність масиву з певним коефіціентом(1.5 чи 2)
	v1.print(); // 0 0 10 20
	if (!v1.empty())// якщо не пусто
		v1.popBack(); // вилучили останній
	v1.print(); // 0 0 10
	cout << "The size of v is " << v1.size() << endl; // 3
	v1.reserve(20); // capacity = 20, size = яке було(3)
	v1.front() = 1234; // перший елемент замінили на 1234
	v1.clear();
	cout << "The size of v after clearing is " << v1.size() << endl; // 0

	v1.pushBack(1);
	v1.pushBack(2);
	v1.pushBack(3);// v1:  1 2 3




	Vector v2(4, -1); // v2 : -1 -1 -1 -1
	v2[1] = 20; // v2 : -1 20 -1 -1

	Vector v3 = v1 + v2;  // v3:  1 2 3 -1 20 -1 -1 
	cout << "v3 is \t" << v3 << endl; // 

	v3 = v1 * 5;  // v3:  5 10 15
	cout << "v3 is \t" << v3 << endl; // 

	v2 *= 10;  // v2 : -10 200 -10 -10

	v2 += Vector(3, 5);  // // v2 : -10 200 -10 -10 5 5 5

	return 0;
}