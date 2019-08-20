//
// Created by EG on 20/08/2019.
//

#include <iostream>
#include <string>
#include "List_X_Matrix.cpp"
#pragma once
using namespace std;
class Node_Y {
public:
    int y;
    Node_Y *siguiente;
    Node_Y *anterior;
    List_X_Matrix *listX;
    Node_Y(int y) {
        this->y = y;
        listX = new List_X_Matrix();
        siguiente = NULL;
        anterior = NULL;
    }
};