#include <fstream>
#include <iostream>
#include <cmath>

#include "quest3.h"

using namespace std;


void CalculCoeff(double &a1, double &b1, double &c1, double Xa, double Ya, double Xb, double Yb)
{
    b1 = Xb - Xa;
    a1 = Ya - Yb;
    c1 = -Ya*b1 - Xa*a1;
}


int sign(double A1, double B1, double A2, double B2)
{
    // retourne le signe du determinant de la matrice carrée :
    //         | a1 b1 |
    //         | a2 b2 |
    double tmp = (A1*B2 - A2*B1);
    if (tmp==0) {cout << "erreur de signe" << endl;}
    return ((tmp>0.) - (tmp<0.));
}

void IntersectionDroites(double &X, double &Y, double a1, double a2, double b1, double b2, double c1, double c2)
{
    // calcule les corrdonnées X et Y d'intersection des deux droites de coeff a,b,c
    if (b1!=0. && b2!=0.)
    {
        X = (((c1/b1)-(c2/b2)) / ((a2/b2)-(a1/b1)));
        Y = (-a1/b1)*X-c1/b1
    }
    else if (b1==0.) // droite 1 est verticale
    {
        X = a1;
        Y = (-a2/b2)*X-c2/b2;
    }
    else if (b2==0.) // droite 2 est verticale
    {
        X = a2;
        Y = (-a1/b1)*X-c1/b1;
    }
    else // b1 et b2 ne sont pas sensé etre nuls tous les deux
    cout << "erreur dans IntersectionDroites" << endl;
}

double** CentreCercleInscrits(int N_points, int N_triangles, double** POINTS, int** TRIANGLES)
{
    // Initialisation
    double** RESULTS = new double*[N_triangles];
    for (int i = 0; i < N_triangles; ++i) { RESULTS[i] = new double[2]; }

    // boucle sur chaque triangle
    //for (int i = 0; i < N_triangles; ++i)
    //{
        // doit retourner les coefficients a,b,c ou coeff direc et ord origine

        int i =0;

        double Xa = POINTS[TRIANGLES[i][0]-1][1];
        double Ya = POINTS[TRIANGLES[i][0]-1][2];

        double Xb = POINTS[TRIANGLES[i][1]-1][1];
        double Yb = POINTS[TRIANGLES[i][1]-1][2];

        double Xc = POINTS[TRIANGLES[i][2]-1][1];
        double Yc = POINTS[TRIANGLES[i][2]-1][2];

        cout << "Xa Ya : " << Xa << " " << Ya << endl;
        cout << "Xb Yb : " << Xb << " " << Yb << endl;

        //calcul des coefficients a1,b1 etc de l'expression cartesienne
        double a1,b1,c1;
        double a2,b2,c2;
        double a3,b3,c3;

        CalculCoeff(a1,b1,c1,Xa,Ya,Xb,Yb); // droite AB
        CalculCoeff(a2,b2,c2,Xa,Ya,Xc,Yc); // droite AC
        CalculCoeff(a3,b3,c3,Xb,Yb,Xc,Yc); // droite BC

        cout << "a b c : " << a1 << " " << b1 << " " << c1 << endl;
        cout << "a b c : " << a2 << " " << b2 << " " << c2 << endl;
        cout << "a b c : " << a3 << " " << b3 << " " << c3 << endl;

        // pour la bissectrice sortant de A
        int sign1 = sign(a3, b3, a1, b1);
        int sign2 = sign(a3, b3, a2, b2);

        cout << "signes : " << sign1 << " " << sign2 << endl;

        double denom1 = sqrt(a1*a1+b1*b1);
        double denom2 = sqrt(a2*a2+b2*b2);
        double ab1 = (sign1/denom1)*a1 + (sign2/denom2)*a2; //bissec(sign1,sign2,denom1,denom2,a1,a2);
        double bb1 = (sign1/denom1)*b1 + (sign2/denom2)*b2;
        double cb1 = (sign1/denom1)*c1 + (sign2/denom2)*c2;

        // pour la bissectrice sortant de C
        sign1 = sign(a1, b1, a2, b2);
        sign2 = sign(a1, b1, a3, b3);
        denom1 = sqrt(a2*a2+b2*b2);
        denom2 = sqrt(a3*a3+b3*b3);
        double ab2 = (sign1/denom1)*a2 + (sign2/denom2)*a3;
        double bb2 = (sign1/denom1)*b2 + (sign2/denom2)*b3;
        double cb2 = (sign1/denom1)*c2 + (sign2/denom2)*c3;

        cout << "intersection A : " <<  << " " <<  << endl;

        // coordonnée du centre de cercle inscrit au triangle i
        RESULTS[i][0] = (((cb2/bb2)-(cb1/bb1)) / ((ab1/cb1)-(ab2/cb2))); // X
        RESULTS[i][1] = -ab1/bb1*RESULTS[i][0]-cb1/bb1;  // Y

        cout << "valeurs a,b,c des deux bissectrices : " << ab1 << " " << bb1 << " " << cb1 << " " << ab2 << " " << bb2 << " " << cb2 << endl;
        cout << "triangle " << i << " : X=" << RESULTS[i][0] << " Y=" << RESULTS[i][1] << endl;
    //}

    return RESULTS;
}