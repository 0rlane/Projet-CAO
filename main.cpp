#include <fstream>
#include <iostream>

using namespace std;

double **CreateMat(int nrow, int ncol){
  // Creation d'une matrice nrow*ncol
    double **mat;
    mat = new double *[nrow];
    for (int i=0; i<nrow ; i++){
        mat[i] = new double[ncol];
    }

  return mat;
}

void AfficheMat(int nrow, int ncol, double **A){
  // Affichage d'une matrice nrow*ncol

  for (int i=0; i<nrow; i++){
    for(int j=0; j<ncol;j++){
      cout<<A[i][j]<<" ";
    }
    cout<<endl;;
  }
}

int lectN(){
    // Lecture du fichier ps.pts et recuperation de la donnee N

    int N;
    ifstream fpoints("ps.pts");
    fpoints>>N;
    return N;
}

void lectPoints(int N, double **points){
    // Lecture du fichier ps.pts et recuperation des coordonnees des points

    ifstream fpoints("ps.pts");
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

void lectTriangles(int nbtri, double **triangles){
    //Lecture du fichier listri.dat et recuperation des sommets des triangles

    ifstream ftriangles("listri.dat");
    string tmp;
    getline(ftriangles,tmp);
    for (int j=0; j<nbtri; j++){
        for (int i=0; i<3; i++){
            ftriangles>>triangles[i][j];
        }
    }
}



int main(){
    // Lecture du fichier ps.pts
    int N;  //nombre de points
    double **points; // matrice contenant les N points et leurs coordonnees x et y
    N=lectN();
    points=CreateMat(N,3);
    lectPoints(N,points);

    //Lecture du fichier listri.dat
    int nbtri;  //nombre de triangles dans le domaine D
    double **NT;   // matrice contenant les nbtri triangles et leurs 3 sommets
    nbtri=lectNbTriangles();
    NT=CreateMat(3,nbtri);
    lectTriangles(nbtri, NT);


    return 0;
}
