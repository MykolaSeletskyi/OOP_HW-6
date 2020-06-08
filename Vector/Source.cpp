#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	//не зробив не зрозумів для чого
	//Метод зміни фактичної довжини масиву 
	//void resize(size_t newSize, int value = 0), 
	//ємність масиву якщо потрібно - збільшується


	//я ще не доробив 
	 

	 
	Vector a;
	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);//delete
	//33
	a.pushBack(4);
	a.pushBack(5);
	a.pushBack(6);
	a.insert(33,3);
	a.popIndex(2);
	Vector b=a*2;
	//b.clear();
	for (size_t i = 0; i < b.getSize(); i++)
	{
		cout << b[i]<<endl;

	}
	return 0;
}