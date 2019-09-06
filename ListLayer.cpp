//
// Created by EG on 4/09/2019.
//


#include <stdlib.h>
#include <iostream>
#include <string>
using  namespace std;
#pragma once
class NodeConfig{
public:
    string attribute;
    int size;
    NodeConfig *siguiente;
    NodeConfig *anterior;
    NodeConfig(string atribute, int size ){
        this->attribute = atribute;
        this->size = size;
        siguiente = NULL;
        anterior = NULL;
    }
};
class LinkedLiyer{
public:
    NodeConfig *primero;
    NodeConfig *ultimo;
    LinkedLiyer() {
        primero = NULL;
        ultimo = NULL;
    }
    bool esVacia() {
        if (primero == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    void addConfig(NodeConfig *nuevo) {
        if (esVacia()) {
            primero = nuevo;
            primero->siguiente = primero;
            primero->anterior = primero;
            ultimo = nuevo;
        }
        else {
            primero->siguiente = nuevo;
            nuevo->anterior = primero;
            nuevo->siguiente = ultimo;
            ultimo->anterior = nuevo;
            primero = nuevo;
        }
    }
};