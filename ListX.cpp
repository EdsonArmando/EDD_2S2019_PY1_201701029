//
// Created by EG on 20/08/2019.
//
#include <iostream>
#include <string>
#include "Node_X.cpp"
#pragma once
class ListX {
public:
    Node_X *first;
    Node_X *last;
    ListX() {
        first = NULL;
        last = NULL;
    }

    void insertar(Node_X *nuevo) {
        if (first==NULL) {
            first = last = nuevo;
        }
        else {
            if (nuevo->x < first->x) {
                first->anterior = nuevo;
                nuevo->siguiente = first;
                first = first->anterior;
            }
            else if (nuevo->x > last->x) {
                last->siguiente = nuevo;
                nuevo->anterior = last;
                last = last->siguiente;
            }
            else {
                Node_X *temp1;
                Node_X *temp2;
                temp1 = first;
                while (temp1->x < nuevo->x)
                {

                    temp1 = temp1->siguiente;
                }
                temp2 = temp1->anterior;
                temp2->siguiente = nuevo;
                temp1->anterior = nuevo;
                nuevo->siguiente = temp1;
                nuevo->anterior = temp2;
            }
        }
    }
    bool buscar(int x) {
        if (first==NULL) {
            return false;
        }
        else {
            Node_X *temp=first;
            while (temp!=NULL)
            {
                if (temp->x==x) {

                    return true;
                }
                else if (temp->siguiente==NULL) {

                    return false;
                }
                temp = temp->siguiente;
            }
        }
    }
    int retorPrimer() {
        return first->x;
    }
    Node_X* buscarNodo(int x) {
        Node_X *temp=first;
        while (temp!=NULL)
        {
            if (temp->x==x) {
                return temp;
            }
            else {

            }
            temp = temp->siguiente;
        }
        return (new Node_X(-1));
    }
};