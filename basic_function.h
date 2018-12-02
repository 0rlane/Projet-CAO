
#ifndef BASIC_FUNCTION_H
#define BASIC_FUNCTION_H


#include <fstream>
#include <iostream>
using namespace std;

//int** Mat = CreateMat<int>(4,2);
template<typename Type> Type** CreateMat(int nrow, int ncol)
{
	Type** Mat = new Type*[nrow];
    for (int i = 0; i < nrow; ++i)
    {
    	Mat[i] = new Type[ncol];
    }
    return Mat;
}

//CreateFile("test.dat", 4, 2, Mat);
template<typename Type> Type CreateFile(const char* name, int nrow, int ncol, Type **A)
{

	ofstream fichier(name);
    for (int i = 0; i < nrow; ++i)
    {
    	for (int j = 0; j < ncol; ++j)
    	{
    		fichier << A[i][j] << " ";
    	}
        fichier << endl;
    }
    fichier.close();
}

//AfficheMat<int>(4, 2, Mat);
template<typename Type> Type AfficheMat(int nrow, int ncol, Type **A){
  // Affichage d'une matrice nrow*ncol

  for (int i=0; i<nrow; i++){
    for(int j=0; j<ncol;j++){
      cout << A[i][j] << " ";
    }
    cout<<endl;
  }
}

template<typename Type> Type FreeMat(Type **A, int nrow){
    // Desalocaation memoire de la matrice A

    for (int i=0; i<nrow; i++) {
            delete [] (A[i]);
    }
    delete [] A;
}


#endif