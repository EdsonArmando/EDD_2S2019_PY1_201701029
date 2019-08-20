//
// Created by EG on 20/08/2019.
//
#include <iostream>
#include <string>
#pragma once
using namespace std;
class NodeContent {
public:
    int x, y, r, g ,b;
    NodeContent *arriba;
    NodeContent *abajo;
    NodeContent *izqui;
    NodeContent *derech;
    NodeContent(int x, int y, int r, int g, int b) {
        this->x = x;
        this->y = y;
        this->r = r;
        this->g = g;
        this->b = b;
        arriba = NULL;
        abajo = NULL;
        izqui = NULL;
        derech = NULL;
    }
};