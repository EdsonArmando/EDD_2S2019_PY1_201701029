//
// Created by EG on 27/08/2019.
//
#include <iostream>
#include <string>
#include "LinkedList.cpp"
#pragma once
using namespace std;
class NodeImage {
public:
    string valor;
    LinkesList *list;
    NodeImage *izq;
    NodeImage *dere;
    NodeImage(string name) {
        this->valor = name ;
        this->list = new LinkesList();
        izq = NULL;
        dere = NULL;
    }
};