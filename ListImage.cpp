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
    NodeListLayerFilter *anterior;
    NodeListLayerFilter(string name){
        this->nameImage = name;
        this->liSta = new ListaCircularFiltors();
        siguiente=NULL;
        anterior=NULL;
    }
};

class ListLayerFilter{
public:
    NodeListLayerFilter *inicio;
    NodeListLayerFilter *fin;
    void apilarNodo(NodeListLayerFilter *nuevo) {
        if (inicio==NULL) {
            inicio = nuevo;
            fin=inicio;
            nuevo->siguiente=NULL;
        }
        else {
            inicio->siguiente=nuevo;
            inicio=nuevo;
        }
    }
    NodeListLayerFilter *returnNodo(string nombre){
        NodeListLayerFilter *aux = fin;
        while (aux!=NULL){
            if(aux->nameImage==nombre){
                return aux;
            }
            aux = aux->siguiente;
        }
        return NULL;
    }
    bool returnBool(string nombre){
        NodeListLayerFilter *aux = fin;
        while (aux!=NULL){
            if(aux->nameImage==nombre){
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }
    void mostrarLista(string nombre) {
        NodeListLayerFilter *aux = fin;

        while (aux!=NULL)
        {
            if(aux->nameImage==nombre){
                aux->liSta->mostrarLista();
            }
            aux = aux->siguiente;
        }
    }
};