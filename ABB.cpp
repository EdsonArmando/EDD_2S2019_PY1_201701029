//
// Created by EG on 27/08/2019.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include "NodeImage.cpp"
using  namespace std;
static NodeImage *raiz;
class ABB {
public:
    void insertarNodo(NodeImage *&raiz,string n) {
        if (raiz ==NULL) {
            NodeImage *nuevo = new NodeImage(n);
            raiz = nuevo;
            raiz->izq = NULL;
            raiz->dere = NULL;
        }else if (n < raiz->valor)
            insertarNodo(raiz->izq, n);

        else if (n > raiz->valor)
            insertarNodo(raiz->dere, n);
    }
};