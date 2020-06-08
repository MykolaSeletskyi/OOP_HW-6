#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	Vector a;
	a.pushBack(100);
	cout << a.front();
	return 0;
}