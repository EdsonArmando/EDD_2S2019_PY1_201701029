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
    ListX *listaCab;
    ListY *listlat;
    SparceMatrix() {
        listaCab = new ListX();
        listlat = new ListY();
    }
    void insertar(int x, int y, int r, int g, int b) {
        NodeContent *nuevo = new NodeContent(x,y,r,g,b);
        if (listaCab->buscar(x)==false) {
            listaCab->insertar(new Node_X(x));
        }
        if (listlat->buscar(y)==false) {
            listlat->insertar(new Node_Y(y));
        }

        temp1 = listaCab->buscarNodo(x);
        temp2 = listlat->buscarNodo(y);
        temp1->listaY->insertar(nuevo);
        temp2->listX->insertar(nuevo);
        cout << "Inserto " << r << " en " << x << " ," << y << endl;
    }

};
