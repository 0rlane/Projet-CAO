// definition des classes utilisées

#ifndef CLASSES_H
#define CLASSES_H

class Point
{
private:

public:
	// données
	double X, Y;

	// constructeur & destructeur
	Point() { X = Y = -1.; }
	Point( double xi, double yi);
	~Point();

	// fonctions

};

class Triangle
{
private:

public:
	// données
	int* IndexPoints = new int[3];
	Point* coord = new Point[3];
	Point CentreCercleInscrit;

	// constructeur & destructeur
	Triangle( double xi, double yi); // a faire
	~Triangle();

	// fonctions
	void affiche(void);

};



#endif