#include <iostream>
#include "SparseMatrix.cpp"
#include "Node_Y.cpp"
#include "NodeContent.cpp"
#pragma once
using namespace std;

int main() {

    SparseMatrix *matrix = new SparseMatrix();
    matrix->add(15,10,255,229,204);
    matrix->add(3,6,255,229,204);
    matrix->add(5,2,255,229,204);
    matrix->add(16,11,255,229,204);
    matrix->add(4,1,255,229,204);
    matrix->add(1,1,255,229,204);
    matrix->add(2,2,255,229,204);
    matrix->add(2,3,255,229,204);
    matrix->add(15,1,255,229,204);
    matrix->add(15,2,255,229,204);
    matrix->add(15,3,255,229,204);
    Node_Y *temp= matrix->ejeY->primero;
    matrix->imageSpaseMatrix();
    return  0;
}
