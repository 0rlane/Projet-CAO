#ifndef QUEST4_H
#define QUEST4_H

#include "Quest3.h"
#include <fstream>
#include <iostream>

int trianglevoisin(int nbtri, int S1, int S2, int k, int **NT);

void initNTV(int nbtri, int **NTV, int **NT);

void initNM(int **NT, int **NTV, double **points, double **NM, int nbtri,double **omega);

void createFichierNM(double **NM,int nbtri);

#endif // QUEST4_H

