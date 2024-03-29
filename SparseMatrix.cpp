//
// Created by EG on 20/08/2019.
//
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
    Node_X *temp;
    Node_Y *temp1;
    ListX *ejeX;
    ListY *ejeY;
    int suma;
    NodeContent *content=NULL;
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
        temp = ejeX->buscarNodo(x);
        temp1 = ejeY->buscarNodo(y);
        /*NodeImage *temp=tree.mostrarArbole(raiz,nameImage);
        nuevo = new NodeList(nombreArchivo);*/
        temp->listaY->insertar(nuevo);
        temp1->listX->insertar(nuevo);
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
    SparseMatrix *mirrorX(int fila){
        SparseMatrix *mirrorXs=new SparseMatrix();
        Node_X *temp=NULL;
        Node_Y *temp1=NULL;
        temp1=ejeY->primero;
        while (temp1!=NULL){
            content=temp1->listX->first;
            while(content!=NULL){
                mirrorXs->add((fila-content->x)+1,content->y,content->r,content->g,content->b);
                content=content->derech;
            }
            temp1=temp1->siguiente;
        }
        return mirrorXs;
    }
    SparseMatrix *mirrorY(int fila){
        SparseMatrix *mirrorXs=new SparseMatrix();
        Node_X *temp=NULL;
        Node_Y *temp1=NULL;
        temp1=ejeY->primero;
        while (temp1!=NULL){
            content=temp1->listX->first;
            while(content!=NULL){
                mirrorXs->add(content->x,((fila+1)-content->y),content->r,content->g,content->b);
                content=content->derech;
            }
            temp1=temp1->siguiente;
        }
        return mirrorXs;
    }
    SparseMatrix *DoubleMirror(int columnas,int fila){
        SparseMatrix *mirrorXs=new SparseMatrix();
        Node_X *temp=NULL;
        Node_Y *temp1=NULL;
        temp1=ejeY->primero;
        while (temp1!=NULL){
            content=temp1->listX->first;
            while(content!=NULL){
                mirrorXs->add((columnas-content->x)+1,((fila+1)-content->y),content->r,content->g,content->b);
                content=content->derech;
            }
            temp1=temp1->siguiente;
        }
        return mirrorXs;
    }
    SparseMatrix *Collage(int columnas,int fila,int x, int y){
        SparseMatrix *mirrorXs=new SparseMatrix();
        Node_X *temp=NULL;
        Node_Y *temp1=NULL;
        temp1=ejeY->primero;
        while (temp1!=NULL){
            content=temp1->listX->first;
            while(content!=NULL){
                mirrorXs->add(content->x,content->y,content->r,content->g,content->b);
                content=content->derech;
            }
            temp1=temp1->siguiente;
        }
        return mirrorXs;
    }
    SparseMatrix *escalaGrises(int columnas,int fila,int x, int y){
        SparseMatrix *mirrorXs=new SparseMatrix();
        Node_X *temp=NULL;
        double result=0;
        Node_Y *temp1=NULL;
        temp1=ejeY->primero;
        while (temp1!=NULL){
            content=temp1->listX->first;
            while(content!=NULL){
                suma = (content->r*0.3)+ (content->r*0.5)+ (content->r*0.11);
                mirrorXs->add(content->x,content->y,suma,suma,suma);
                content=content->derech;
            }
            temp1=temp1->siguiente;
        }
        return mirrorXs;
    }
    SparseMatrix *negative(int columnas,int fila,int x, int y){
        SparseMatrix *mirrorXs=new SparseMatrix();
        Node_X *temp=NULL;
        double result=0;
        Node_Y *temp1=NULL;
        temp1=ejeY->primero;
        while (temp1!=NULL){
            content=temp1->listX->first;
            while(content!=NULL){
                mirrorXs->add(content->x,content->y,255-(content->r),255-(content->g),255-(content->b));
                content=content->derech;
            }
            temp1=temp1->siguiente;
        }
        return mirrorXs;
    }
    void graficoLinealizarColumna(){
        string grafico= "digraph {\n"
                        " rankdir=LR; \n"
                        " node [shape=record]; \n"
                        " label=\"Liealizacion por columnas\";\n"
                        " null [label=\"NULL\" shape=box];";
        string relaciones="";
        Node_X *temp=NULL;
        double result=0;
        Node_X *temp1=NULL;
        temp1=ejeX->first;
        int cont=0;
        while (temp1!=NULL){
            content=temp1->listaY->first;
            while(content!=NULL){
                relaciones+= std::to_string(cont)+"[label=\"{<data>("+std::to_string(content->x)+','+std::to_string(content->y)+") "+std::to_string(content->r)+"-"+std::to_string(content->g)+"-"+std::to_string(content->b)+ "| <ref>  }\", width=1.2]\n";

                    relaciones+= std::to_string(cont)+":ref:c->" +std::to_string(cont+1)+":data\n";

                cont++;
                content=content->abajo;
            }
            temp1=temp1->siguiente;
        }
        ofstream file;
        relaciones+="null->0\n";
        file.open("linealizarFila.dot");
        file <<grafico+relaciones+"}";
        file.close();
        system("dot -Tpng linealizarFila.dot -o filas.png");
        system("filas.png");
    }
    void graficoLinealizarFila(){
        string grafico= "digraph {\n"
                        " rankdir=LR; \n"
                        " node [shape=record]; \n"
                        " label=\"Liealizacion por filas\";\n"
                        " null [label=\"NULL\" shape=box];";
        string relaciones="";
        Node_X *temp=NULL;
        double result=0;
        Node_Y *temp1=NULL;
        temp1=ejeY->primero;
        int cont=0;
        while (temp1!=NULL){
            content=temp1->listX->first;
            while(content!=NULL){
                relaciones+= std::to_string(cont)+"[label=\"{<data>("+std::to_string(content->x)+','+std::to_string(content->y)+") "+std::to_string(content->r)+"-"+std::to_string(content->g)+"-"+std::to_string(content->b)+ "| <ref>  }\", width=1.2]\n";
                if(temp1!=NULL){
                    relaciones+= std::to_string(cont)+":ref:c->" +std::to_string(cont+1)+":data\n";
                }
                cont++;
                content=content->derech;
            }
            temp1=temp1->siguiente;
        }
        ofstream file;
        relaciones+="null->0\n";
        file.open("linealizarFila.dot");
        file <<grafico+relaciones+"}";
        file.close();
        system("dot -Tpng linealizarFila.dot -o filas.png");
        system("filas.png");
    }
    string generateImages(int columnas,int fila,int x, int y){
        string pixel="";
        Node_X *temp=NULL;
        Node_Y *temp1=NULL;
        int valx = x;
        int valy = y;
        temp1=ejeY->primero;
        while(x!=0){
            while (temp1!=NULL){
                content=temp1->listX->first;
                while(content!=NULL){
                    if(content->y!=1){
                        pixel+=".pixel:nth-child("+std::to_string((valx)*columnas*content->y-columnas*(x)+(content->x))+"){background-color: rgb("+std::to_string(content->r)+","+std::to_string(content->g)+","+std::to_string(content->b)+")"+";}\n";
                    }else{
                        pixel+=".pixel:nth-child("+std::to_string((valx)*columnas-columnas*(x)+(content->x))+"){background-color: rgb("+std::to_string(content->r)+","+std::to_string(content->g)+","+std::to_string(content->b)+")"+";}\n";
                    }
                    content=content->derech;
                }
                temp1=temp1->siguiente;
            }
            temp1=ejeY->primero;
            x--;
        }
        x=valx;
        y--;
        while(y!=0){
            while(x!=0){
                while (temp1!=NULL){
                    content=temp1->listX->first;
                    while(content!=NULL){
                        if(content->y!=1){
                            pixel+=".pixel:nth-child("+std::to_string(((valx)*columnas*(content->y+fila-1)+(content->x)+columnas*(x-1))+(columnas*valx*fila)*(y-1))+"){background-color: rgb("+std::to_string(content->r)+","+std::to_string(content->g)+","+std::to_string(content->b)+")"+";}\n";
                        }else{
                            pixel+=".pixel:nth-child("+std::to_string(((valx)*columnas*(content->y+fila-1)+(content->x)+columnas*(x-1))+(columnas*valx*fila-1)*(y-1))+"){background-color: rgb("+std::to_string(content->r)+","+std::to_string(content->g)+","+std::to_string(content->b)+")"+";}\n";
                        }
                        content=content->derech;
                    }
                    temp1=temp1->siguiente;
                }
                temp1=ejeY->primero;
                x--;
            }
            x=valx;
            y--;
        }
        return pixel;
    }
    string generateImages(int fila){
          string pixel="";
          Node_X *temp=NULL;
          Node_Y *temp1=NULL;
          temp1=ejeY->primero;
          while (temp1!=NULL){
              content=temp1->listX->first;
              while(content!=NULL){
                  if(content->y!=1){
                      pixel+=".pixel:nth-child("+std::to_string((content->x)+fila*(content->y-1))+"){background-color: rgb("+std::to_string(content->r)+","+std::to_string(content->g)+","+std::to_string(content->b)+")"+";}\n";
                  }else{
                      pixel+=".pixel:nth-child("+std::to_string(content->x)+"){background-color: rgb("+std::to_string(content->r)+","+std::to_string(content->g)+","+std::to_string(content->b)+")"+";}\n";
                  }
                  content=content->derech;
              }
              temp1=temp1->siguiente;
          }
          return pixel;
      }
   std::string convertToHexa(int r, int g, int b){
        if(r==0 && g==0 && b==0){

            return "#000000";
        }
        std::stringstream ss;
        ss<< "#";
        ss<< std::hex << (r<<16|g<<8|b);
        return ss.str();

    }

    void imageSpaseMatrix(){
        Node_X *temp=NULL;
        Node_Y *temp1=NULL;
        string header="digraph Sparce_Matrix {\n node [shape=box]\n  Mt[ label = \"0\", width = 1.5, style = filled, fillcolor = yellow, group = 1 ];"
                      "\ne0[ shape = point, width = 0 ];\n e1[ shape = point, width = 0 ];\n";
        string listaX="";
        string listay="";
        string linksY="";
        string rank=" { rank = same; Mt;";
        temp=ejeX->first;
        temp1=ejeY->primero;
        listaX+="Mt->A"+std::to_string(temp->x)+"\n";
        listaX+="A"+std::to_string(temp->x)+"->Mt"+"\n";
        while(temp!=NULL){
            rank+="A"+std::to_string(temp->x)+";";
            listaX+="A"+std::to_string(temp->x)+"[label = \""+std::to_string(temp->x)+"\"   width = 1.5 style = filled, fillcolor = darkseagreen, group = 2 ];\n";
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
                listay+="U"+std::to_string(temp1->y)+"[label = \""+std::to_string(temp1->y)+"\" pos = \"5.3,3.5!\" width = 1.5 style = filled, fillcolor = cyan4, group = 1 ];\n";
                listay+="U"+std::to_string(temp1->y)+" -> N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+"\n";
                listay+="N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+" ->U"+std::to_string(temp1->y)+"\n";
                if(temp1->siguiente!=NULL){

                    listay+="U"+std::to_string(temp1->y)+" -> U"+std::to_string(temp1->siguiente->y)+"\n";
                    listay+="U"+std::to_string(temp1->siguiente->y)+" -> U"+std::to_string(temp1->y)+"\n";

                }
                while(content!=NULL){
                    if(content->abajo!=NULL){
                        listay+="N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+" -> "+"N"+std::to_string(content->abajo->x)+"_L"+std::to_string(content->abajo->y)+"\n";
                        listay+="N"+std::to_string(content->abajo->x)+"_L"+std::to_string(content->abajo->y)+" -> "+"N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+"\n";

                    }
                    listay+="N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+"[label = \"("+std::to_string(content->r)+"-"+std::to_string(content->g)+"-"+std::to_string(content->b)+")\" width = 1.5, group = 2 ];\n";
                    listay+="{ rank = same; U"+std::to_string(temp1->y)+";N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+"; }\n";
                    if(content->derech!=NULL){
                        listay+="N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+" -> N"+std::to_string(content->derech->x)+"_L"+std::to_string(temp1->y)+"\n";
                        listay+="N"+std::to_string(content->derech->x)+"_L"+std::to_string(temp1->y)+" -> N"+std::to_string(content->x)+"_L"+std::to_string(temp1->y)+"\n";
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
        system("matiz.png");
    }
};
