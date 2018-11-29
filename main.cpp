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
    for (int i=0; i<nbtri; i++){
        for (int j=0; j<3; j++){
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
            if ((NT[i][0]==S1 || NT[i][1]==S1 || NT[i][2]==S1) && (NT[i][0]==S2 || NT[i][1]==S2 || NT[i][2]==S2)){
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
        NTV[k][0]=trianglevoisin(nbtri,NT[k][0],NT[k][1],k,NT);
        NTV[k][1]=trianglevoisin(nbtri,NT[k][0],NT[k][2],k,NT);
        NTV[k][2]=trianglevoisin(nbtri,NT[k][2],NT[k][1],k,NT);
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
    NT=CreateMati(nbtri,3);
    lectTriangles(nbtri,NT);

    //Creation de la matrice NTV
    int **NTV;  //matrice contenant les 3 triangles voisins de chaque triangle
    NTV=CreateMati(nbtri,3);
    initNTV(nbtri,NTV,NT);



    return 0;
}


