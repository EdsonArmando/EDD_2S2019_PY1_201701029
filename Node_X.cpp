//
// Created by EG on 20/08/2019.
//

#include <iostream>
#include <string>
#include "List_Y_Matrix.cpp"
#pragma once
using namespace std;
/*Nodos Cab*/
class Node_X {
public:
    int x;
    Node_X *siguiente;
    Node_X *anterior;
    List_Y_Matrix *listaY;
    Node_X(int x) {
        this->x = x;
        listaY = new List_Y_Matrix();
        siguiente = NULL;
        anterior = NULL;
    }
};