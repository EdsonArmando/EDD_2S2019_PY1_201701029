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