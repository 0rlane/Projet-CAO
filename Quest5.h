#ifndef QUEST5_H
#define QUEST5_H

#include <fstream>
#include <iostream>

double f(double x, double y);

double fpx(double x, double y);

double fpy(double x, double y);

double g(double x, double y);

double gpx(double x, double y);

double gpy(double x, double y);

void initF(int N, double **points, double **F);

void initG(int N, double **points, double **G);


#endif // QUEST5_H

