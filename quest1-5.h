
#ifndef QUEST1_5_H
#define QUEST1_5_H

#include <fstream>
#include <iostream>
using namespace std;

///////////////////////////////////////////////// QUESTION 1 /////////////////////////////////////////////////

int lectN(const char* name);

template<typename Type> Type LecData(const char* name, int N, Type **Mat)
{
    ifstream fichier(name);
    string tmp;
    getline(fichier,tmp);
    for (int i=0; i<N; i++){
        for (int j=0; j<3; j++){
            fichier >> Mat[i][j];
        }
    }
}

///////////////////////////////////////////////// QUESTION 1 /////////////////////////////////////////////////

#endif