#include "Quest4.h"
#include <math.h>
#include <fstream>
#include <iostream>

using namespace std;


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
    // Initialisation de la matrice NTV 32*3
    for(int k=0; k<nbtri; k++){
        NTV[k][0]=trianglevoisin(nbtri,NT[k][1],NT[k][2],k,NT);  // triangle voisin des sommets A2A3
        NTV[k][1]=trianglevoisin(nbtri,NT[k][0],NT[k][2],k,NT);  // triangle voisin des sommets A1A3
        NTV[k][2]=trianglevoisin(nbtri,NT[k][0],NT[k][1],k,NT);  // triangle voisin des sommets A1A2
    }
}

void initNM(int **NT, int **NTV, double **points, double **NM, int nbtri,double **omega){
    /*Initilisationde la matrice NM (nbtriangles*6) qui contient les coordonnees x et y des trois points Mi du triangle k
    NT=matrice (nb_triangles*3) qui contient les 3 sommets pour chaque traingle
    NTV= matrice (nb_triangles*3) qui contient le numero des 3 triangles voisins pour chaque triangle (-1 si il n'y a pas de traingle voisin)
    points=matrice (nb_points*3) qui contient les numero du point et ses coordonnees x et y associees
    nbtri= nombre de triangles dans le domaine
    omega= matrice (nb_trinagles*2) qui contient les coefficients x et y du centre du cercle inscrit de chaque triangle */

    for (int k=0; k<nbtri; k++){
        double a1, b1, c1;
        double a2, b2, c2;

        int j(0);
        for (int i=0; i<3; i++){
            if (NTV[k][i]!=-1){
                CalculCoeff(a1,b1,c1,points[NT[k][(i+1)%3]-1][1],points[NT[k][(i+1)%3]-1][2],points[NT[k][(i+2)%3]-1][1],points[NT[k][(i+2)%3]-1][2]);  // Coefficients de la droite (D1): a1*x+b1*y+c1=0 qui passe par les sommets A2 et A3
                CalculCoeff(a2,b2,c2,omega[k][0],omega[k][1],omega[NTV[k][i]][0],omega[NTV[k][i]][1]);   // Coefficients de la droite (D2): a2*x+b2*y+c2=0 qui passe par les sommets le centre du cercle inscrit du triangle k et par le centre du cercle inscrit du triangle voisin de k par les sommets A2 et A3
                IntersectionDroites(NM[k][j],NM[k][j+1],a1,a2,b1,b2,c1,c2);

            }else {
                NM[k][j]=fabs(points[NT[k][(i+1)%3]-1][1]-points[NT[k][(i+2)%3]-1][1])/2+min(points[NT[k][(i+1)%3]-1][1],points[NT[k][(i+2)%3]-1][1]);
                NM[k][j+1]=fabs(points[NT[k][(i+1)%3]-1][2]-points[NT[k][(i+2)%3]-1][2])/2+min(points[NT[k][(i+1)%3]-1][2],points[NT[k][(i+2)%3]-1][2]);
            }
            j+=2;
        }
    }
}

void createFichierNM(double **NM,int nbtri){
    ofstream fNM("NM.pts");
    for (int i=0; i<nbtri; i++){
        for(int j=0; j<6;j++){
            fNM<<NM[i][j]<<" ";
        }
        fNM<<endl;;
    }
    fNM.close();
}
