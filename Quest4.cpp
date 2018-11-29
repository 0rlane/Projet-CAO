#include "Quest4.h"
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
        NTV[k][0]=trianglevoisin(nbtri,NT[k][0],NT[k][1],k,NT);
        NTV[k][1]=trianglevoisin(nbtri,NT[k][0],NT[k][2],k,NT);
        NTV[k][2]=trianglevoisin(nbtri,NT[k][2],NT[k][1],k,NT);
    }
}

