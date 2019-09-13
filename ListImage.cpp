//
// Created by EG on 13/09/2019.
//
#include <string>
#include "LinkedList.cpp"
#include "ListLayer.cpp"
#include "ListaCircularFiltros.cpp"
#pragma once
using namespace std;
class NodeListLayerFilter{
public:
    string nameImage;
    ListaCircularFiltors *liSta;
    NodeListLayerFilter *siguiente;
    NodeListLayerFilter(string name){
        this->nameImage = name;
        this->liSta = new ListaCircularFiltors();
        siguiente=NULL;
    }
};

class ListLayerFilter{
public:
    NodeListLayerFilter *inicio;
    void apilarNodo(NodeListLayerFilter *nuevo) {
        if (inicio==NULL) {
            inicio = nuevo;
        }
        else {
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
    }
    NodeListLayerFilter *returnNodo(string nombre){
        NodeListLayerFilter *aux = inicio;
        while (aux!=NULL)
        {
            if(aux->nameImage==nombre){
                return aux;
            }
            aux = aux->siguiente;
        }
        return NULL;
    }
    void mostrarLista(string nombre) {
        NodeListLayerFilter *aux = inicio;
        do
        {
            if(aux->nameImage==nombre){
                aux->liSta->mostrarLista();
            }
            aux = aux->siguiente;
        }while (aux!=inicio);
    }
};