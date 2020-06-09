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
	a.pushBack(4);
	a.pushBack(5);
	a.pushBack(6); 
	
	Vector c = a(2,4);

	c=c * 2;
	c.print();
	cout << endl << c;
	return 0;
}