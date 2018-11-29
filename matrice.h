#ifndef MATRICE_H
#define MATRICE_H

#include <fstream>
#include <iostream>


double **CreateMatd(int nrow, int ncol);

int **CreateMati(int nrow, int ncol);

template<typename Type> Type AfficheMat(int nrow, int ncol, Type **A){
  // Affichage d'une matrice nrow*ncol

  for (int i=0; i<nrow; i++){
    for(int j=0; j<ncol;j++){
      std::cout<<A[i][j]<<" ";
    }
    std::cout<<std::endl;;
  }
}

template<typename Type> Type FreeMat(Type **A, int nrow){
    // Desalocaation memoire de la matrice A

    for (int i=0; i<nrow; i++) {
            delete [] (A[i]);
    }
    delete [] A;
}

#endif // MATRICE_H

