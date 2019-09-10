//
// Created by EG on 27/08/2019.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include "NodeImage.cpp"
#include "NodeContent.cpp"
#include "LinkedList.cpp"
using  namespace std;
static NodeImage *raiz;
class ABB {
public:
    NodeImage *temp;
    NodeContent *temp2;
    int width,height;
    NodeList *temp3;
    string inicio = "digraph grafica{\nrankdir=TB;\n subgraph cluster_0{\n label=\"Arbol Binario de Imagenes\"; \n node [shape = record, style=filled, fillcolor=seashell2];\n";
    string nodes,rela,rela2;
    string recorrido=" digraph{\n"
                     " rankdir=LR;  \n"
                     " node [shape=record];\n";


    void insertarNodo(NodeImage *&raiz,string n) {
        if (raiz ==NULL) {
            NodeImage *nuevo = new NodeImage(n);
            raiz = nuevo;
            raiz->izq = NULL;
            raiz->dere = NULL;
        }else if (n < raiz->valor)
            insertarNodo(raiz->izq, n);

        else if (n > raiz->valor)
            insertarNodo(raiz->dere, n);
    }
    void generateImage(string name){
        temp=mostrarArbole(raiz,name);
        string pixelImage;
        width = temp->listConfig->ultimo->size;
        height = temp->listConfig->ultimo->siguiente->size;
        ofstream file;
        file.open(name+"\\"+name+".html");
        file<<"<!DOCTYPE html>\n"
              "<html>\n"
              "<head>\n"
              "  <link rel=\"stylesheet\" href=\""+name+".scss"+"\">\n"
              "</head>\n"
              "<body>\n<div class=\"canvas\">";
        for(int i=0;i<=(width*height);i++){
            file <<"<div class=\"pixel\"></div>\n";
        }

        temp3=temp->list->ultimo;
        do {
            pixelImage=temp3->matrix->generateImage(width);

            temp3=temp3->siguiente;

        } while (temp3 != temp3->anterior);
        cout<<pixelImage<<endl;
        file<<"</div>\n"
              "\n"
              "</body>\n"
              "</html>";
        file.close();
        file.open(name+"\\"+name+".scss");
        file<<"body {\n"
              "  background: #333333;      /* Background color of the whole page */\n"
              "  height: 100vh;            /* 100 viewport heigh units */\n"
              "  display: flex;            /* defines a flex container */\n"
              "  justify-content: center;  /* centers the canvas horizontally */\n"
              "  align-items: center;      /* centers the canvas vertically */\n"
              "}";
        file<<".canvas {\n";
        file<< "width: "+ std::to_string((width)*temp->listConfig->ultimo->siguiente->siguiente->size)+"px;";
        file<< "height: "+ std::to_string((height)*temp->listConfig->ultimo->siguiente->siguiente->siguiente->size)+"px;";
        file<<"\n}\n.pixel {\n";
        file<< "width: "+ std::to_string(temp->listConfig->ultimo->siguiente->siguiente->size)+"px;";
        file<< "height: "+ std::to_string(temp->listConfig->ultimo->siguiente->siguiente->siguiente->size)+"px;";
        file<< "float: left;";
        file<< "\n}\n";
        file<< pixelImage;
        file.close();
    }
    void mostrarArbol(){
        ofstream file;
        file.open("Arbol.dot");
        file <<inicio+nodes+rela+"\n}\n}";
        file.close();
        system("dot -Tpng Arbol.dot -o arbol.png");
        system("arbol.png");
        nodes="";
        rela="";
    }
    NodeImage *mostrarArbole(NodeImage *raiz,string n) {
        if (raiz==NULL) {

        }
        else if (raiz->valor==n) {
            return raiz;
        }
        else if (n<raiz->valor) {
            return mostrarArbole(raiz->izq,n);
        }
        else {
            return mostrarArbole(raiz->dere, n);
        }

    }
    void graficarArbol(NodeImage *raiz) {
        NodeImage *temp = raiz;
        if (raiz!=NULL) {
            nodes = nodes + "nodo" +raiz->valor + " " + "[ label = \"<C0>|" + raiz->valor + "|<C1>\"" + "];\n";
            if (raiz->izq!=NULL) {
                rela = rela + "nodo"+raiz->valor+":C0->"+"nodo"+raiz->izq->valor+"\n";
            }
            if (raiz->dere != NULL) {
                rela = rela + "nodo" + raiz->valor + ":C1->" + "nodo" + raiz->dere->valor + "\n";
            }
            graficarArbol(raiz->izq);
            graficarArbol(raiz->dere);
        }

    }
    void grafReco(string reco){
        ofstream file;
        recorrido+="label=\""+reco+"\"\n";
        rela2.erase(rela2.length()-2);
        file.open("recorrido.dot");

        file <<recorrido+rela2+"\n}";
        file.close();
        system("dot -Tpng recorrido.dot -o reco.png");
        system("reco.png");
        nodes="";
        rela2="";

    }
    void recoPost(NodeImage *raiz) {

        if (raiz == NULL) {

        }
        else {
            recoPost(raiz->izq);
            recoPost(raiz->dere);
            rela2+=raiz->valor;
            rela2+="->";
        }
    }
    void recoOrdenAlfa(NodeImage *raiz){
        if (raiz == NULL) {
        }
        else {
            recoOrdenAlfa(raiz->izq);
            cout<<raiz->valor<<endl;
            recoOrdenAlfa(raiz->dere);
        }
    }
    void recoIn(NodeImage *raiz) {
        if (raiz == NULL) {

        }
        else {
            recoIn(raiz->izq);
            rela2+=raiz->valor;
            rela2+="->";
            recoIn(raiz->dere);
        }
    }
    void recoPre(NodeImage *raiz) {
        if (raiz == NULL) {

        }
        else {
            rela2+=raiz->valor;
            rela2+="->";
            recoPre(raiz->izq);
            recoPre(raiz->dere);
        }
    }
};