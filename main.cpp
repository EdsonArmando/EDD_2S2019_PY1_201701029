#include <iostream>
#include "SparceMatrix.cpp"
#include "Node_Y.cpp"
#include "NodeContent.cpp"
#pragma once
using namespace std;

int main() {

    SparceMatrix *matrix = new SparceMatrix();
    matrix->insertar(15,10,255,229,204);
    matrix->insertar(3,6,255,229,204);
    matrix->insertar(5,2,255,229,204);
    matrix->insertar(16,11,255,229,204);
    matrix->insertar(4,1,255,229,204);
    matrix->insertar(1,1,255,229,204);
    matrix->insertar(2,2,255,229,204);
    matrix->insertar(2,3,255,229,204);
    matrix->insertar(15,1,255,229,204);
    matrix->insertar(15,2,255,229,204);
    matrix->insertar(15,3,255,229,204);
    Node_Y *temp= matrix->listlat->primero;


    return  0;
}
