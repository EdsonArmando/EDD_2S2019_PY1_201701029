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
    void insertar(NodeContent *nuevo) {
        if (first==NULL) {
            first = last = nuevo;
        }
        else {
            if (nuevo->x < first->x) {
                first->izqui = nuevo;
                nuevo->derech = first;
                first = first->izqui;
            }
            else if (nuevo->x > last->x) {
                last->derech = nuevo;
                nuevo->izqui = last;
                last = last->derech;
            }
            else {
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
        }
    }

};