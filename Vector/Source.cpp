#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	//не зробив не зрозумів для чого
	//Метод зміни фактичної довжини масиву 
	//void resize(size_t newSize, int value = 0), 
	//ємність масиву якщо потрібно - збільшується


	 

	 
	Vector a;
	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);//delete
	//33
	Vector b;
	b.pushBack(4);
	b.pushBack(5);
	b.pushBack(6); 
	a += b;
	Vector c = (!b);//тут ок
	//c = (!c);// тут вилітає
	//b.clear();
	for (size_t i = 0; i < c.getSize(); i++)
	{
		cout << c[i]<<endl;

	}
	return 0;
}