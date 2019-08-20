//
// Created by EG on 20/08/2019.
//
#include <iostream>
#include <string>
#include "List_Y_Matrix.cpp"
#include "List_X_Matrix.cpp"
#include "ListX.cpp"
#include "ListY.cpp"
#include "Node_X.cpp"
#include "Node_Y.cpp"
#include "NodeContent.cpp"
#pragma once
class SparceMatrix {
public:
    List_Y_Matrix *ver;
    Node_X *temp1;
    Node_Y *temp2;
    ListX *ejeX;
    ListY *ejeY;
    SparceMatrix() {
        ejeX = new ListX();
        ejeY = new ListY();
    }
    void add(int x, int y, int r, int g, int b) {
        NodeContent *nuevo = new NodeContent(x,y,r,g,b);
        if (ejeX->buscar(x)==false) {
            ejeX->insertar(new Node_X(x));
        }
        if (ejeY->buscar(y)==false) {
            ejeY->insertar(new Node_Y(y));
        }
        temp1 = ejeX->buscarNodo(x);
        temp2 = ejeY->buscarNodo(y);
        temp1->listaY->insertar(nuevo);
        temp2->listX->insertar(nuevo);
        cout << "Inserto " << r << " en " << x << " ," << y << endl;
    }

};
