//
// Created by EG on 13/09/2019.
//
#include <string>
#include "LinkedList.cpp"
#include "ListLayer.cpp"
#pragma once
using namespace std;
class NodeFilter {
public:
    string valor;
    LinkedLiyer *listConfig;
    LinkesList *list;
    NodeFilter *siguiente;
    NodeFilter *anterior;
    NodeFilter(string name) {
        this->valor = name ;
        this->list = new LinkesList();
        this->listConfig = new LinkedLiyer();
        siguiente = NULL;
        anterior = NULL;
    }
};

class ListaCircularFiltors{
public:
    NodeFilter *primero;
    NodeFilter *ultimo;
    ListaCircularFiltors() {
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
    void mostrarLista() {
        NodeFilter *aux=primero;
        do{
            cout << aux->valor << endl;
            aux = aux->siguiente;
        } while (aux != primero);
    }
    NodeFilter *devolverNodo(string Nombre) {
        NodeFilter *aux=primero;

        do{
            if(aux->valor==Nombre){
                return aux;
            }
            aux = aux->siguiente;
        } while (aux != primero);

    }
    void insertarImg(NodeFilter *nuevo) {
        if (esVacia()) {
            primero = nuevo;
            primero->siguiente = primero;
            primero->anterior = ultimo;
            ultimo = nuevo;
        }
        else {
            ultimo->siguiente = nuevo;
            nuevo->siguiente = primero;
            nuevo->anterior = ultimo;
            ultimo->anterior = nuevo;
            ultimo = nuevo;
        }
    }
    void generarDoc() {
        string Cola1 = "\n digraph  List{ \n rankdir=LR;  \n node [shape=record];\n label=\"Lista Filtros\";\n";
        string compras = "";
        NodeFilter *aux = primero;

        do {

            compras += aux->valor;
            compras += " -> ";
            compras += aux->siguiente->valor;
            compras += ";\n";
            compras += aux->siguiente->valor;
            compras += " -> ";
            compras += aux->valor;
            compras += ";\n";
            aux = aux->siguiente;
        } while (aux != primero);

        if (aux == primero) {
            compras += "\n}";
            ofstream file;
            file.open("Filter.dot");
            file << Cola1+compras;
            file.close();
            system("dot -Tpng Filter.dot -o filter.png");
        }

    }
};



