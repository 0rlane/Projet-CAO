#include "Quest5.h"
#include <math.h>
#include <fstream>
#include <iostream>

using namespace std;

double f(double x, double y){
    // Focntion f(x,y)
    return exp(x+y);
}

double fpx(double x, double y){
    // Derive en x de la fonction f(x,y)
    return exp(x+y);
}

double fpy(double x, double y){
    // Derive en y de la fonction f(x,y)
    return exp(x+y);
}

double g(double x, double y){
    // Fonction g(x,y)
    return y*y*y-2*x*y*y-5*x*x*y+10*x*y+1;
}

double gpx(double x, double y){
    // Derive en x de la fonction g(x,y)
    return -2*y*y-10*x*y+10*y;
}

double gpy(double x, double y){
    // Derive en y de la fonction g(x,y)
    return 3*y*y-4*x*y-5*x*x+10*x;
}


void initF(int N, double **points, double **F){
    // Initialisation de la matrice F (N*3)

    for (int i=0; i<N; i++){
        F[i][0]=f(points[i][1],points[i][2]);  //La premiere colonne contient f(x,y)
        F[i][1]=fpx(points[i][1],points[i][2]);  // La seconde colonne contient la derive de f en x
        F[i][2]=fpy(points[i][1],points[i][2]);  // La seconde colonne contient la derive de f en y
    }
}

void initG(int N, double **points, double **G){
    // Initialisation de la matrice F (N*3)

    for (int i=0; i<N; i++){
        G[i][0]=g(points[i][1],points[i][2]);  //La premiere colonne contient g(x,y)
        G[i][1]=gpx(points[i][1],points[i][2]);  // La seconde colonne contient la derive de g en x
        G[i][2]=gpy(points[i][1],points[i][2]);  // La seconde colonne contient la derive de g en y
    }
}
