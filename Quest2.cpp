#include "Quest2.h"
#include <fstream>
#include <iostream>

using namespace std;



int lectN(){
    // Lecture du fichier points.pts et recuperation de la donnee N

    int N;
    ifstream fpoints("points.pts");
    fpoints>>N;
    return N;
}

void lectPoints(int N, double **points){
    // Lecture du fichier points.pts et recuperation des coordonnees des points

    ifstream fpoints("points.pts");
    string tmp;
    getline(fpoints,tmp);
    for (int i=0; i<N; i++){
        for (int j=0; j<3; j++){
            fpoints>>points[i][j];
        }
    }
}

int lectNbTriangles(){
    // Lecture du fichier listri.dat et recuperation de la donnee nbtri

    int nbtri;
    ifstream ftriangles("listri.dat");
    ftriangles>>nbtri;
    return nbtri;
}

void lectTriangles(int nbtri, int **triangles){
    //Lecture du fichier listri.dat et recuperation des sommets des triangles

    ifstream ftriangles("listri.dat");
    string tmp;
    getline(ftriangles,tmp);
    for (int i=0; i<nbtri; i++){
        for (int j=0; j<3; j++){
            ftriangles>>triangles[i][j];
        }
    }
}

