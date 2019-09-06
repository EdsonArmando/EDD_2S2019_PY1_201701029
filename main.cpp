#include <iostream>
#include "SparseMatrix.cpp"
#include "Node_Y.cpp"
#include "Menu.cpp"
#include "NodeContent.cpp"
#pragma once
using namespace std;

int main() {
    Menu *menu = new Menu();

    menu->IniciarMenu();
    return  0;
}
