//
// Created by EG on 4/09/2019.
//
#include <stdlib.h>
#include <iostream>
#include "SparseMatrix.cpp"
#include <string>
using  namespace std;
#pragma once
class NodeList{
public:
    string nombre;
    SparseMatrix *matrix;
    NodeList *siguiente;
    NodeList *anterior;
    NodeList(string nombre){
        this->nombre = nombre;
        this->matrix=new SparseMatrix();
        siguiente = NULL;
        anterior = NULL;
    }
};

class LinkesList{
public:
    NodeList *primero;
    NodeList *ultimo;
    LinkesList() {
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
    void insertarImg(NodeList *nuevo) {
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
    void mostrarLista(){
        NodeList *temp=ultimo;
        do{
            cout<<temp->nombre<<endl;
            temp=temp->siguiente;
        }while(temp!=ultimo);
    }
    void linealizar(string nombre){
        NodeList *temp=ultimo;
        do{
            if(temp->nombre==nombre){
                temp->matrix->graficoLinealizarFila();
            }
            temp=temp->siguiente;
        }while(temp!=ultimo);
    }
    void linealizarColum(string nombre){
        NodeList *temp=ultimo;
        do{
            if(temp->nombre==nombre){
                temp->matrix->graficoLinealizarColumna();
            }
            temp=temp->siguiente;
        }while(temp!=ultimo);
    }
    void ingresarPos(string nombre,int x, int y, int r, int g, int b){
        NodeList *temp=ultimo;
        do{
            if(temp->nombre==nombre){
                temp->matrix->add(x,y,r,g,b);
            }
            temp=temp->siguiente;
        }while(temp!=ultimo);
    }
    void graficar(string nombre){
        NodeList *temp=ultimo;
        do{
            if(temp->nombre==nombre){
                temp->matrix->imageSpaseMatrix();
            }
           temp=temp->siguiente;
        }while(temp!=ultimo);
    }
};
