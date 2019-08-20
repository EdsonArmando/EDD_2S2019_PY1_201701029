//
// Created by EG on 20/08/2019.
//

#include <iostream>
#include <string>
#include <vector>
#include "NodeContent.cpp"
#pragma once
using namespace std;
class List_X_Matrix {
public:
    NodeContent *first;
    NodeContent *last;
    List_X_Matrix() {
        first = NULL;
        last = NULL;
    }
    bool esVacia() {
        if (first == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    void insertar(NodeContent *nuevo) {
        if (esVacia()) {
            first = last = nuevo;
        }
        else {
            if (nuevo->x < first->x) {
                insertarAlInicio(nuevo);
            }
            else if (nuevo->x > last->x) {
                insertarAlFinal(nuevo);
            }
            else {
                insertarMedio(nuevo);
            }
        }
    }
    void insertarAlInicio(NodeContent *nuevo) {
        first->izqui = nuevo;
        nuevo->derech = first;
        first = first->izqui;
    }
    void insertarAlFinal(NodeContent *nuevo) {
        last->derech = nuevo;
        nuevo->izqui = last;
        last = last->derech;
    }
    void insertarMedio(NodeContent *nuevo) {
        NodeContent *temp1;
        NodeContent *temp2;
        temp1 = first;
        while (temp1->x < nuevo->x)
        {

            temp1 = temp1->derech;
        }
        temp2 = temp1->izqui;
        temp2->derech = nuevo;
        temp1->izqui = nuevo;
        nuevo->derech = temp1;
        nuevo->izqui = temp2;
    }
    void mostrarDatos() {
        if (!esVacia()) {

            NodeContent *temp = first;
            while (temp != NULL)
            {

                temp = temp->derech;
            }
        }

    }

    vector<int> retorX() {
        vector<int> x;
        if (!esVacia()) {

            NodeContent *temp = first;
            while (temp != NULL)
            {

                x.push_back(temp->x);
                temp = temp->derech;
            }
        }
        return x;
    }
};