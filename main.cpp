#include "matrice.h"
#include "Quest2.h"
#include "Quest4.h"
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
    int **NT;   // matrice contenant les nbtri triangles et leurs 3 sommets (nbtri3)
    nbtri=lectNbTriangles();
    NT=CreateMati(nbtri,3);
    lectTriangles(nbtri,NT);

    //Creation de la matrice NTV
    int **NTV;  //matrice contenant les 3 triangles voisins de chaque triangle (nbtri3)
    NTV=CreateMati(nbtri,3);
    initNTV(nbtri,NTV,NT);



    return 0;
}


