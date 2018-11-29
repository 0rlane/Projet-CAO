#include "matrice.h"
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



