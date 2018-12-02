
#include <fstream>
#include <iostream>

#include "classes.h"
#include "basic_function.h"
#include "quest1-5.h"

using namespace std;

int main(){

    int Npts = lectN("listri.dat");
    int** TRIANGLES = CreateMat<int>(Npts, 3);
    LecData("listri.dat", Npts, TRIANGLES);
    AfficheMat(Npts, 3, TRIANGLES);

	return 0;

}
