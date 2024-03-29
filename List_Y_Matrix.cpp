//
// Created by EG on 20/08/2019.
//

#include <iostream>
#include <string>
#include "NodeContent.cpp"
#pragma once
using namespace std;
class List_Y_Matrix {
public:
    NodeContent *first;
    NodeContent *last;
    List_Y_Matrix() {
        first = NULL;
        last = NULL;
    }
    void insertar(NodeContent *nuevo) {
        if (first==NULL) {
            first = last = nuevo;
        }
        else {
            if (nuevo->y<first->y) {
                first->arriba = nuevo;
                nuevo->abajo = first;
                first = first->arriba;
            }
            else if (nuevo->y>last->y) {
                last->abajo = nuevo;
                nuevo->arriba = last;
                last = last->abajo;
            }
            else {
                NodeContent *temp1;
                NodeContent *temp2;
                temp1 = first;
                while (temp1->y<nuevo->y)
                {

                    temp1 = temp1->abajo;
                }
                temp2 = temp1->arriba;
                temp2->abajo = nuevo;
                temp1->arriba = nuevo;
                nuevo->abajo = temp1;
                nuevo->arriba = temp2;
            }
        }
    }
};