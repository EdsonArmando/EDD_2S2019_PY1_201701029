
#include <iostream>
#include <string>
#include <fstream>
#include "Node_Y.cpp"
#pragma once
using namespace std;
class ListY {
public:
    Node_Y *primero;
    Node_Y *ultimo;
    ListY() {
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
    void insertar(Node_Y *nuevo) {
        if (esVacia()) {
            primero = ultimo = nuevo;
        }
        else {
            if (nuevo->y < primero->y) {
                insertarAlInicio(nuevo);
            }
            else if (nuevo->y > ultimo->y) {
                insertarAlFinal(nuevo);
            }
            else {
                insertarMedio(nuevo);
            }
        }
    }
    void insertarAlInicio(Node_Y *nuevo) {
        primero->anterior = nuevo;
        nuevo->siguiente = primero;
        primero = primero->anterior;
    }
    void insertarAlFinal(Node_Y *nuevo) {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = ultimo->siguiente;
    }
    void insertarMedio(Node_Y *nuevo) {
        Node_Y *temp1;
        Node_Y *temp2;
        temp1 = primero;
        while (temp1->y < nuevo->y)
        {

            temp1 = temp1->siguiente;
        }
        temp2 = temp1->anterior;
        temp2->siguiente = nuevo;
        temp1->anterior = nuevo;
        nuevo->siguiente = temp1;
        nuevo->anterior = temp2;
    }
    void mostrarDatos() {
        if (!esVacia()) {
            Node_Y *temp = primero;
            while (temp != NULL)
            {

                temp = temp->siguiente;
            }
        }

    }
    vector<int> retListaFila() {
        vector<int> y;
        if (!esVacia()) {
            Node_Y *temp = primero;
            while (temp != NULL)
            {
                y.push_back(temp->y);

                temp = temp->siguiente;
            }
            return y;
        }

    }

    bool buscar(int y) {
        if (esVacia()) {

            return false;
        }
        else {
            Node_Y *temp = primero;
            while (temp != NULL)
            {
                if (temp->y == y) {

                    return true;
                }
                else if (temp->siguiente == NULL) {

                    return false;
                }
                temp = temp->siguiente;
            }
        }
    }
    Node_Y* buscarNodo(int y) {
        Node_Y *temp = primero;
        while (temp != NULL)
        {
            if (temp->y == y) {
                return temp;
            }
            else {

            }
            temp = temp->siguiente;
        }

        return (new Node_Y(-1));
    }
};