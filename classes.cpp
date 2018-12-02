

#include "classes.h"
#include <iostream>
using namespace std;

/////////////////////////////////////////////// FONCTION POINT /////////////////////////////////////////////////

Point::Point( double xi, double yi)
{
  X = xi;
  Y = yi;
}

Point::~Point() {}

///////////////////////////////////////////// FONCTION TRIANGLE //////////////////////////////////////////////////

Triangle::~Triangle() 
{
	cout << "destructeur de triangle : " << this->coord << endl;
	delete[] this->coord;
}

void Triangle::affiche()
{
	cout << "triangle " << this->coord;
	for (int i = 0; i < 3; ++i)
	{
		cout << this->coord[i] << " ";
	}
	cout << endl;
}
