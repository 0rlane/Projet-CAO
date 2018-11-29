#include "matrice.h"
#include "Quest2.h"
#include "Quest4.h"
#include "Quest5.h"
#include <fstream>
#include <iostream>

using namespace std;



int main(){
    // Lecture du fichier ps.pts
    int N;  //nombre de points
    double **points; // matrice contenant les N points et leurs coordonnees x et y (N*3)
    N=lectN();
    points=CreateMatd(N,3);
    lectPoints(N,points);

    //Lecture du fichier listri.dat
    int nbtri;  //nombre de triangles dans le domaine D
    int **NT;   // matrice contenant les nbtri triangles et leurs 3 sommets (nbtri*3)
    nbtri=lectNbTriangles();
    NT=CreateMati(nbtri,3);
    lectTriangles(nbtri,NT);

    //Creation de la matrice NTV
    int **NTV;  //matrice contenant les 3 triangles voisins de chaque triangle (nbtri*3)
    NTV=CreateMati(nbtri,3);
    initNTV(nbtri,NTV,NT);

    // Creation de la matrice F
    double **F;  //matrice contenant la valeur de f(x,y) de la derive de f en x et de la derive de f en y pour chaque point (N*3)
    F=CreateMatd(N,3);
    initF(N,points,F);

    // Creation de la matrice G
    /*double **G;  //matrice contenant la valeur de g(x,y) de la derive de g en x et de la derive de g en y pour chaque point (N*3)
    G=CreateMatd(N,3);
    initF(N,points,G);*/


    FreeMat(NT,nbtri); FreeMat(points,N); FreeMat(NTV,nbtri); FreeMat(F,N); // FreeMAt(G);
    return 0;
}
