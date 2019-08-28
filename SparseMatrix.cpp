//
// Created by EG on 20/08/2019.
//
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

#include "List_Y_Matrix.cpp"
#include "List_X_Matrix.cpp"
#include "ListX.cpp"
#include "ListY.cpp"
#include "Node_X.cpp"
#include "Node_Y.cpp"
#include "NodeContent.cpp"
#pragma once
class SparseMatrix {
public:
    List_Y_Matrix *ver;
    Node_X *temp1;
    Node_Y *temp2;
    ListX *ejeX;
    ListY *ejeY;
    SparseMatrix() {
        ejeX = new ListX();
        ejeY = new ListY();
    }
    void add(int x, int y, int r, int g, int b) {
        NodeContent *nuevo = new NodeContent(x,y,r,g,b);
        if (ejeX->buscar(x)==false) {
            ejeX->insertar(new Node_X(x));
        }
        if (ejeY->buscar(y)==false) {
            ejeY->insertar(new Node_Y(y));
        }
        temp1 = ejeX->buscarNodo(x);
        temp2 = ejeY->buscarNodo(y);
        temp1->listaY->insertar(nuevo);
        temp2->listX->insertar(nuevo);
        cout << "Inserto " << r << " en " << x << " ," << y << endl;
    }
    void imageSpaseMatrix(){
        string header="digraph Sparce_Matrix {\n node [shape=box]\n  Mt[ label = \"0\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];"
                      "\ne0[ shape = point, width = 0 ];\n e1[ shape = point, width = 0 ];";
        string listaX="";
        string links="";
        string listay="";
        string linksY="";
        string rank=" { rank = same; Mt;";
        Node_X *temp=ejeX->first;
        Node_Y *temp1=ejeY->primero;
        NodeContent *content=NULL;
        List_X_Matrix *tempX=NULL;
        links+="Mt -> A"+std::to_string(temp1->y)+"\n";
        linksY+="Mt -> U"+std::to_string(temp->x)+"\n";
        while(temp1!=NULL){

            listay+="U"+std::to_string(temp1->y) +"[label ="+"\""+std::to_string(temp1->y)+"\""+ "pos = \"5.3,3.5!\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n";

            while(temp!=NULL){
                rank+="A"+std::to_string(temp->x)+";";
                content = temp->listaY->first;

                listaX+="A"+std::to_string(temp->x) +"[label ="+"\""+std::to_string(temp->x)+"\""+ "pos = \"5.3,3.5!\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n";
                if(temp->siguiente!=NULL){
                    links+="A"+std::to_string(temp->x)+"->"+"A"+std::to_string(temp->siguiente->x)+"\n";
                }
                temp=temp->siguiente;
            }
            if(temp1->siguiente!=NULL){
                linksY+="U"+std::to_string(temp1->y)+"->"+"U"+std::to_string(temp1->siguiente->y)+"\n";
            }
            temp1=temp1->siguiente;
        }
      /*cout<<listaX<<endl;
        cout<<links<<endl;
        cout<<listay<<endl;
        cout<<linksY<<endl;
        cout<<rank<<endl;*/
        ofstream file;
        file.open("matrix.dot");
        file <<header+listaX+links+listay+linksY+rank+"}\n}";
        file.close();
        system("dot -Tpng matrix.dot -o matiz.png");
        //system("matiz.png");
    }
};
