#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	Vector a;
	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);//delete
	//33
	a.pushBack(4);
	a.pushBack(5);
	a.pushBack(6);
	a.pushIndex(33,3);
	a.popIndex(2);
	Vector b(a);
	for (size_t i = 0; i < b.getSize(); i++)
	{
		cout << b[i]<<endl;

	}
	return 0;
}