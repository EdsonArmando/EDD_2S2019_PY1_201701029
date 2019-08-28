//
// Created by EG on 27/08/2019.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include "NodeImage.cpp"
using  namespace std;
static NodeImage *raiz;
class ABB {
public:
    string inicio = "digraph grafica{\nrankdir=TB;\n subgraph cluster_0{\n label=\"Arbol Binario de Imagenes\"; \n node [shape = record, style=filled, fillcolor=seashell2];\n";
    string nodes,rela;
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
};