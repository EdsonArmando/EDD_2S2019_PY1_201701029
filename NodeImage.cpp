//
// Created by EG on 27/08/2019.
//
#include <iostream>
#include <string>
#pragma once
using namespace std;
class NodeImage {
public:
    string valor;
    NodeImage *izq;
    NodeImage *dere;
    NodeImage(string name) {
        this->valor = name ;
        izq = NULL;
        dere = NULL;
    }
};