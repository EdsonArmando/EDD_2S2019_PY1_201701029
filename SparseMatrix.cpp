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
        /*NodeImage *temp=tree.mostrarArbole(raiz,nameImage);
        nuevo = new NodeList(nombreArchivo);*/
        temp1->listaY->insertar(nuevo);
        temp2->listX->insertar(nuevo);
        /*  void leerArchivoCSV(string nombreArchivo){
         nombreArchivo.erase(nombreArchivo.length()-5);
         NodeImage *temp=tree.mostrarArbole(raiz,nameImage);
         nuevo = new NodeList(nombreArchivo);
         string textoConfi = devolverTexto(nombreArchivo+".csv");
         std::string de = "\n";
         string dato;
         std::string delimiter = ", ";
         size_t pos2 = 0;
         std::string config;
         int cont=0;
         size_t pos = 0;
         while ((pos = textoConfi.find(de))!= std::string::npos){
             if(cont>0){
                 dato=textoConfi.substr(0,pos);
                 while ((pos2 = dato.find(delimiter)) != std::string::npos) {
                     config = dato.substr(0, pos2);
                     dato.erase(0, pos2 + delimiter.length());
                     cout<<config<<endl;
                     cout<<dato<<endl;
                     nuevo->matrix->add(10,2,5,6,41);
                 }
                 textoConfi.erase(0, pos + de.length());
             }else{
                 textoConfi.erase(0, pos + de.length());
                 cont++;
             }
         }
         temp->list->insertarImg(nuevo);

     }*/
    }
    void imageSpaseMatrix(){
        string header="digraph Sparce_Matrix {\n node [shape=box]\n  Mt[ label = \"0\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];"
                      "\ne0[ shape = point, width = 0 ];\n e1[ shape = point, width = 0 ];\n";
        string listaX="";
        int cont=0;
        string links="";
        string listay="";
        string linksY="";
        string listNiveles="";
        string rank=" { rank = same; Mt;";
        Node_X *temp=ejeX->first;
        Node_Y *temp1=ejeY->primero;
        NodeContent *content=NULL;
        List_X_Matrix *tempX=NULL;
        listaX+="Mt->A"+std::to_string(temp->x)+"\n";
        listaX+="A"+std::to_string(temp->x)+"->Mt"+"\n";
        while(temp!=NULL){
            rank+="A"+std::to_string(temp->x)+";";
            listaX+="A"+std::to_string(temp->x)+"[label = \""+std::to_string(temp->x)+"\"   width = 1.5 style = filled, fillcolor = lightskyblue, group = 2 ];\n";
            listaX+="A"+std::to_string(temp->x)+" -> N"+std::to_string(temp->listaY->first->x)+"_L"+std::to_string(temp->listaY->first->y)+"\n";
            listaX+="N"+std::to_string(temp->listaY->first->x)+"_L"+std::to_string(temp->listaY->first->y)+" -> A"+std::to_string(temp->x)+"\n";
            content=temp->listaY->first;

            if(temp->siguiente!=NULL){
                listaX+="A"+std::to_string(temp->x)+" -> "+"A"+std::to_string(temp->siguiente->x)+"\n";
                listaX+="A"+std::to_string(temp->siguiente->x)+" -> "+"A"+std::to_string(temp->x)+"\n";
            }
            if(temp1!=NULL){
                if(temp1->y==1){
                    listay+="Mt->U"+std::to_string(temp1->y)+"\n";
                }
            }

            while(temp1!=NULL){
                content = temp1->listX->first;
                listay+="U"+std::to_string(temp1->y)+"[label = \""+std::to_string(temp1->y)+"\" pos = \"5.3,3.5!\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n";
                listay+="U"+std::to_string(temp1->y)+" -> N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+"\n";

                if(temp1->siguiente!=NULL){

                    listay+="U"+std::to_string(temp1->y)+" -> U"+std::to_string(temp1->siguiente->y)+"\n";
                    listay+="U"+std::to_string(temp1->siguiente->y)+" -> U"+std::to_string(temp1->y)+"\n";

                }
                while(content!=NULL){
                    listay+="N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+"[label = \""+std::to_string(content->x)+"\" width = 1.5, group = 2 ];\n";
                    listay+="{ rank = same; U"+std::to_string(temp1->y)+";N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+"; }\n";
                    if(content->derech!=NULL){
                        listay+="N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+" -> N"+std::to_string(content->derech->x)+"_L"+std::to_string(temp1->y)+"\n";
                    }

                    content=content->derech;
                }
                temp1=temp1->siguiente;
            }
            temp=temp->siguiente;
        }
        ofstream file;
        file.open("matrix.dot");
        file <<header+listay+listaX+rank+"}\n}";
        file.close();
        system("dot -Tpng matrix.dot -o matiz.png");
        cout<<listNiveles<<endl;
        //system("matiz.png");
    }
};
