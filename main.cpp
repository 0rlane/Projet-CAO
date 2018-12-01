#include "matrice.h"
#include "Quest2.h"
#include "quest3.h"
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
    cout<<"NT:"<<endl;


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

    // Creation de la matrice Omega
    double **Omega;  // matrice contenant les coordonnees x et y du centre du cercle inscrit pour chaque triangle (nbtri*2)
    Omega=CentreCercleInscrits(N,nbtri,points,NT);
    //createFichierOmega(Omega,nbtri);  // Creation d'un fichier "Omega.pts" qui contient la matrice Omega

    // Creation de la matrice NM
    double **NM; //Matrice contenant les coordonnees x et y des points M1 M2 et M3 pour chaque triangle (nbtri*3)
    NM=CreateMatd(nbtri,6);
    initNM(NT,NTV,points,NM,nbtri,Omega);
    //createFichierNM(NM,nbtri);  // Creation d'un fichier "NM.pts" qui contient la matrice NM




    FreeMat(NT,nbtri); FreeMat(points,N); FreeMat(NTV,nbtri); FreeMat(F,N); // FreeMAt(G);
    return 0;
}
