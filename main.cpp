#include <fstream>
#include <iostream>

using namespace std;

double **CreateMatd(int nrow, int ncol){
  // Creation d'une matrice nrow*ncol
    double **mat;
    mat = new double *[nrow];
    for (int i=0; i<nrow ; i++){
        mat[i] = new double[ncol];
    }

  return mat;
}

int **CreateMati(int nrow, int ncol){
  // Creation d'une matrice nrow*ncol
    int **mat;
    mat = new int *[nrow];
    for (int i=0; i<nrow ; i++){
        mat[i] = new int[ncol];
    }

  return mat;
}

template<typename Type> Type AfficheMat(int nrow, int ncol, Type **A){
  // Affichage d'une matrice nrow*ncol

  for (int i=0; i<nrow; i++){
    for(int j=0; j<ncol;j++){
      cout<<A[i][j]<<" ";
    }
    cout<<endl;;
  }
}

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
    for (int j=0; j<nbtri; j++){
        for (int i=0; i<3; i++){
            ftriangles>>triangles[i][j];
        }
    }
}

int trianglevoisin(int nbtri, int S1, int S2, int k, int **NT){
    // Recherche du traingle voisin du triangle K pour les sommets S1 et S2
    int voisin(-1);
    int i(0);
    while (i<nbtri && voisin==-1){
        if (i!=k){
            if ((NT[0][i]==S1 || NT[1][i]==S1 || NT[2][i]==S1) && (NT[0][i]==S2 || NT[1][i]==S2 || NT[2][i]==S2)){
                // Le triangle i est voisin du triangle k
                voisin=i;
            }
        }
    i++;
    }
    return voisin;
}

void initNTV(int nbtri, int **NTV, int **NT){
    // Initialisation de la matrice NTV
    for(int k=0; k<nbtri; k++){
        NTV[0][k]=trianglevoisin(nbtri,NT[0][k],NT[1][k],k,NT);
        NTV[1][k]=trianglevoisin(nbtri,NT[0][k],NT[2][k],k,NT);
        NTV[2][k]=trianglevoisin(nbtri,NT[2][k],NT[1][k],k,NT);
    }
}



int main(){
    // Lecture du fichier ps.pts
    int N;  //nombre de points
    double **points; // matrice contenant les N points et leurs coordonnees x et y
    N=lectN();
    points=CreateMatd(N,3);
    lectPoints(N,points);

    //Lecture du fichier listri.dat
    int nbtri;  //nombre de triangles dans le domaine D
    int **NT;   // matrice contenant les nbtri triangles et leurs 3 sommets
    nbtri=lectNbTriangles();
    NT=CreateMati(3,nbtri);
    lectTriangles(nbtri, NT);

    //Creation de la matrice NTV
    int **NTV;  //matrice contenant les 3 triangles voisins de chaque triangle
    NTV=CreateMati(3,nbtri);
    initNTV(nbtri,NTV,NT);



    return 0;
}


