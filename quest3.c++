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
        Y = (-a1/b1)*X-c1/b1;
    }
    else if (b1==0.) // droite 1 est verticale
    {
        X = -c1/a1;
        Y = (-a2/b2)*X-c2/b2;
    }
    else if (b2==0.) // droite 2 est verticale
    {
        X = -c2/a2;
        Y = (-a1/b1)*X-c1/b1;
    }
    else // b1 et b2 ne sont pas sensé etre nuls tous les deux
    cout << "erreur dans IntersectionDroites" << endl;
}

// distance entre deux points A et B
double DistEucl(double Xa, double Ya, double Xb, double Yb)
{
    return ( sqrt( (Xa-Xb)*(Xa-Xb)+(Ya-Yb)*(Ya-Yb) ) );
}

// calcule la différence entre les angles de chaque coté de la bissectrice de sortant de B
double ErreurBissectrice(double Xa, double Ya, double Xb, double Yb, double Xc, double Yc, double Xom, double Yom)
{
    double a1 = DistEucl(Xb,Yb,Xom,Yom);
    double a2 = DistEucl(Xa,Ya,Xc,Yc); 

    double b1 = DistEucl(Xa,Ya,Xb,Yb);
    double c1 = DistEucl(Xa,Ya,Xom,Yom);

    double b2 = DistEucl(Xc,Yc,Xb,Yb);
    double c2 = DistEucl(Xc,Yc,Xom,Yom);

    //calcul angle A_B_Omega
    double angle1 = fabs( acos((-c1*c1+a1*a1+b1*b1)/(2*a1*b1)) );
    //calcul angle C_B_Omega
    double angle2 = fabs( acos((-c2*c2+a1*a1+b2*b2)/(2*a1*b2)) );
    //erreur sur la 1ere bissectrice
    double error = fabs(angle1-angle2);

    //calcul angle B_C_Omega
    angle1 = fabs( acos((-a1*a1+b2*b2+c2*c2)/(2*b2*c2)) );
    //calcul angle A_C_Omega
    angle2 = fabs( acos((-c1*c1+a2*a2+c2*c2)/(2*a2*c2)) );
    
    //erreur sur la 2ere bissectrice
    error = max(error,fabs(angle1-angle2));

    return (error);
}

double** CentreCercleInscrits(int N_points, int N_triangles, double** POINTS, int** TRIANGLES)
{
    // Initialisation
    double** RESULTS = new double*[N_triangles];
    for (int i = 0; i < N_triangles; ++i) { RESULTS[i] = new double[2]; }

    double ERREUR_MAX = 0.;

    // boucle sur chaque triangle
    for (int i = 0; i < N_triangles; ++i)
    {
        // Initialisation des coordonées des points A,B,C du triangle i
        double Xa = POINTS[TRIANGLES[i][0]-1][1];
        double Ya = POINTS[TRIANGLES[i][0]-1][2];

        double Xb = POINTS[TRIANGLES[i][1]-1][1];
        double Yb = POINTS[TRIANGLES[i][1]-1][2];

        double Xc = POINTS[TRIANGLES[i][2]-1][1];
        double Yc = POINTS[TRIANGLES[i][2]-1][2];

        //calcul des coefficients a1,b1 etc de l'expression cartesienne de chaque droite
        double a1,b1,c1;
        double a2,b2,c2;
        double a3,b3,c3;

        CalculCoeff(a1,b1,c1,Xa,Ya,Xb,Yb); // droite AB
        CalculCoeff(a2,b2,c2,Xa,Ya,Xc,Yc); // droite AC
        CalculCoeff(a3,b3,c3,Xb,Yb,Xc,Yc); // droite BC

        // pour la bissectrice sortant de A
        double T1 = sign(a3, b3, a1, b1) / sqrt(a1*a1+b1*b1);
        double T2 = sign(a3, b3, a2, b2) / sqrt(a2*a2+b2*b2);
        double ab1 = T1*a1 + T2*a2;
        double bb1 = T1*b1 + T2*b2;
        double cb1 = T1*c1 + T2*c2;

        // pour la bissectrice sortant de C
        T1 = sign(a1, b1, a2, b2) / sqrt(a2*a2+b2*b2);
        T2 = sign(a1, b1, a3, b3) / sqrt(a3*a3+b3*b3);
        double ab2 = T1*a2 + T2*a3;
        double bb2 = T1*b2 + T2*b3;
        double cb2 = T1*c2 + T2*c3;

        IntersectionDroites(RESULTS[i][0], RESULTS[i][1], ab1, ab2, bb1, bb2, cb1, cb2);

        ERREUR_MAX = max(ERREUR_MAX,ErreurBissectrice(Xa, Ya, Xb, Yb, Xc, Yc, RESULTS[i][0], RESULTS[i][1]));
        
    }

    cout << "Erreur max d'angle des bissectrices : " << ERREUR_MAX << endl;

    return RESULTS;
}