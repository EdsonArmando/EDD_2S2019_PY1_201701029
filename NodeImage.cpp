//
// Created by EG on 27/08/2019.
//
#include <iostream>
#include <string>
#include "LinkedList.cpp"
#include "ListLayer.cpp"
#pragma once
using namespace std;
class NodeImage {
public:
    string valor;
    LinkedLiyer *listConfig;
    LinkesList *list;
    NodeImage *izq;
    NodeImage *dere;
    NodeImage(string name) {
        this->valor = name ;
        this->list = new LinkesList();
        this->listConfig = new LinkedLiyer();
        izq = NULL;
        dere = NULL;
    }
};