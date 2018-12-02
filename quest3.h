//header quest3

#ifndef QUEST3_H
#define QUEST3_H


double DistEucl(double Xa, double Ya, double Xb, double Yb);
double ErreurBissectrice(double Xa, double Ya, double Xb, double Yb, double Xc, double Yc, double Xom, double Yom);
void IntersectionDroites(double &X, double &Y, double a1, double a2, double b1, double b2, double c1, double c2);
int sign(double A1, double B1, double A2, double B2);
void CalculCoeff(double &a1, double &b1, double &c1, double Xa, double Ya, double Xb, double Yb);
double** CentreCercleInscrits(int N_points, int N_triangles, double** POINTS, int** TRIANGLES);
void createFichierOmega(double **Omega,int nbtri);

#endif
