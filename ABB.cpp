//
// Created by EG on 27/08/2019.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include "NodeImage.cpp"
#include "NodeContent.cpp"
#include "LinkedList.cpp"
#include "ListImage.cpp"
#include <cstdlib>
#include <unistd.h>

using  namespace std;
static NodeImage *raiz;
class ABB {
public:
    NodeFilter *tempo;

    ListLayerFilter *lista= new ListLayerFilter();
    int width,height;

    string inicio = "digraph grafica{\nrankdir=TB;\n subgraph cluster_0{\n label=\"Arbol Binario de Imagenes\"; \n node [shape = record, style=filled, fillcolor=seashell2];\n";
    string nodes,rela,rela2;
    string recorrido=" digraph{\n"
                     " rankdir=LR;  \n"
                     " node [shape=record];\n";

    void edicionMaual(string nameImage,string name,int x, int y, int r,int g, int b){
        NodeImage *temp;
        temp=mostrarArbole(raiz,nameImage);
        temp->list->ingresarPos(name,x,y,r,g,b);
    }
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
    void exportImage(string nombre){
        lista->mostrarLista(nombre);
    }
    void imageLayerReport(string name){
        NodeImage *temp;
        temp=mostrarArbole(raiz,name);
        temp->list->mostrarLista();

    }
    void linearMatrix(string name){
        NodeImage *temp;
        temp=mostrarArbole(raiz,name);
        temp->list->mostrarLista();
    }
    void graficoLinealizarMatriz(string name,string capa,string tipo){
        NodeImage *temp;
        temp=mostrarArbole(raiz,name);
        if(tipo=="filas"){
            temp->list->linealizar(capa);
        }else{
            temp->list->linealizarColum(capa);
        }

    }
    void imageLayerReport2(string name,string capa){
        NodeImage *temp;
        temp=mostrarArbole(raiz,name);
        temp->list->graficar(capa);
    }
    void graphDoubleList(string name){
        NodeListLayerFilter *temp=NULL;
        temp=lista->returnNodo(name);
        if(temp!=NULL){
          temp->liSta->generarDoc();
        }else{
          cout<<"No hay filtos aplicados"<<endl;
        }

    }
    void aplyFilter(string nameImage, string nameFilter,int x, int y){
        NodeListLayerFilter *listFiltro;
        NodeList *temp4;
        NodeImage *temp;
        NodeList *temp3;
        bool esta=lista->returnBool(nameImage);
        temp=mostrarArbole(raiz,nameImage);
        temp3=temp->list->ultimo;
        listFiltro=lista->returnNodo(nameImage);
        if(listFiltro==NULL){
            listFiltro = new NodeListLayerFilter(nameImage);
        }
        tempo = new NodeFilter(nameImage+nameFilter);

        width = temp->listConfig->ultimo->size;
        SparseMatrix *mirrorXs;
        if(nameFilter=="X_Mirror"){
            do {
                //temp4->matrix=temp3->matrix->mirrorX(width);
                mirrorXs=temp3->matrix->mirrorX(width);

                temp4 = new NodeList(temp3->nombre);
                temp4->matrix=mirrorXs;

                temp3=temp3->siguiente;
                tempo->list->insertarImg(temp4);
                listFiltro->liSta->insertarImg(tempo);

            } while (temp3!=temp->list->ultimo);
            if(esta==true){

            }else{
                lista->apilarNodo(listFiltro);
            }

            //cout<< mirrorXs->generateImages(width);
        }else if(nameFilter=="Y_Mirror"){
            do {
                //temp4->matrix=temp3->matrix->mirrorX(width);
                mirrorXs=temp3->matrix->mirrorY(height);

                temp4 = new NodeList(temp3->nombre);
                temp4->matrix=mirrorXs;

                temp3=temp3->siguiente;
                tempo->list->insertarImg(temp4);
                listFiltro->liSta->insertarImg(tempo);

            } while (temp3!=temp->list->ultimo);
            if(esta==true){

            }else{
                lista->apilarNodo(listFiltro);
            }
        }else if(nameFilter=="DouebleMirror"){
            do {
                //temp4->matrix=temp3->matrix->mirrorX(width);
                mirrorXs=temp3->matrix->DoubleMirror(width,height);

                temp4 = new NodeList(temp3->nombre);
                temp4->matrix=mirrorXs;

                temp3=temp3->siguiente;
                tempo->list->insertarImg(temp4);
                listFiltro->liSta->insertarImg(tempo);

            } while (temp3!=temp->list->ultimo);
            if(esta==true){

            }else{
                lista->apilarNodo(listFiltro);
            }
        }else if(nameFilter=="Collage"){
            do {
                //temp4->matrix=temp3->matrix->mirrorX(width);
                mirrorXs=temp3->matrix->Collage(width,height,x,y);

                temp4 = new NodeList(temp3->nombre);
                temp4->matrix=mirrorXs;

                temp3=temp3->siguiente;
                tempo->list->insertarImg(temp4);
                listFiltro->liSta->insertarImg(tempo);

            } while (temp3!=temp->list->ultimo);
            if(esta==true){

            }else{
                lista->apilarNodo(listFiltro);
            }
        }else if(nameFilter=="grises"){
            do {
                //temp4->matrix=temp3->matrix->mirrorX(width);
                mirrorXs=temp3->matrix->escalaGrises(width,height,0,0);

                temp4 = new NodeList(temp3->nombre);
                temp4->matrix=mirrorXs;

                temp3=temp3->siguiente;
                tempo->list->insertarImg(temp4);
                listFiltro->liSta->insertarImg(tempo);

            } while (temp3!=temp->list->ultimo);
            if(esta==true){

            }else{
                lista->apilarNodo(listFiltro);
            }
        }else if(nameFilter=="negative"){
            do {
                //temp4->matrix=temp3->matrix->mirrorX(width);
                mirrorXs=temp3->matrix->negative(width,height,0,0);

                temp4 = new NodeList(temp3->nombre);
                temp4->matrix=mirrorXs;

                temp3=temp3->siguiente;
                tempo->list->insertarImg(temp4);
                listFiltro->liSta->insertarImg(tempo);

            } while (temp3!=temp->list->ultimo);
            if(esta==true){

            }else{
                lista->apilarNodo(listFiltro);
            }
        }
    }
    void generateImage(string name){
        NodeList *temp3;
        NodeImage *temp2;
        temp2=mostrarArbole(raiz,name);
        string pixelImage;
        width = temp2->listConfig->ultimo->size;
        height = temp2->listConfig->ultimo->siguiente->size;
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

        temp3=temp2->list->ultimo;
        do {
            pixelImage+=temp3->matrix->generateImages(width);
            pixelImage+="\n";
            temp3=temp3->siguiente;

        } while (temp3!=temp2->list->ultimo);
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
        file<< "width: "+ std::to_string((width)*temp2->listConfig->ultimo->siguiente->siguiente->size)+"px;\n";
        file<< "height: "+ std::to_string((height)*temp2->listConfig->ultimo->siguiente->siguiente->siguiente->size)+"px;\n";
        file<<"\n}\n.pixel {\n";
        file<< "width: "+ std::to_string(temp2->listConfig->ultimo->siguiente->siguiente->size)+"px;";
        file<< "height: "+ std::to_string(temp2->listConfig->ultimo->siguiente->siguiente->siguiente->size)+"px;\n";
        file<< "float: left;\nbox-shadow: 0px 0px 1px #fff;\n";
        file<< "\n}\n";
        file<< pixelImage;
        file.close();
        string imagHtm="\\"+name+".html";
        const char *one = name.c_str();
        const char *two = imagHtm.c_str();

        string total( string(one) + two );

        system(total.c_str());

    }
    void generateImage(string name, string nameFilter){
        NodeList *temp3;
        NodeImage *temp2;
        NodeListLayerFilter *tempoImage;
        NodeFilter *tempFilter;
        temp2=mostrarArbole(raiz,name);
        tempoImage = lista->returnNodo(name);
        string pixelImage;
        width = temp2->listConfig->ultimo->size;
        height = temp2->listConfig->ultimo->siguiente->size;
        ofstream file;
        file.open(name+"\\"+name+nameFilter+".html");
        file<<"<!DOCTYPE html>\n"
              "<html>\n"
              "<head>\n"
              "  <link rel=\"stylesheet\" href=\""+name+nameFilter+".css"+"\">\n"
                                                                "</head>\n"
                                                                "<body>\n<div class=\"canvas\">";
        for(int i=0;i<=(width*height);i++){
            file <<"<div class=\"pixel\"></div>\n";
        }
        tempFilter=tempoImage->liSta->devolverNodo(name+nameFilter);
        temp3=tempFilter->list->ultimo;
        do {
            pixelImage+=temp3->matrix->generateImages(width);
            pixelImage+="\n";
            temp3=temp3->siguiente;

        } while (temp3!=tempFilter->list->ultimo);
        cout<<pixelImage<<endl;
        file<<"</div>\n"
              "\n"
              "</body>\n"
              "</html>";
        file.close();
        file.open(name+"\\"+name+nameFilter+".css");
        file<<"body {\n"
              "  background: #333333;      /* Background color of the whole page */\n"
              "  height: 100vh;            /* 100 viewport heigh units */\n"
              "  display: flex;            /* defines a flex container */\n"
              "  justify-content: center;  /* centers the canvas horizontally */\n"
              "  align-items: center;      /* centers the canvas vertically */\n";
              if(nameFilter=="negative"){
                  file<<"filter:invert(75%);";
              }else if(nameFilter=="grises"){
                  file<<"filter:grayscale(100%);";
              }
             file<< "}\n";
        file<<".canvas {\n";
        file<< "width: "+ std::to_string((width)*temp2->listConfig->ultimo->siguiente->siguiente->size)+"px;\n";
        file<< "height: "+ std::to_string((height)*temp2->listConfig->ultimo->siguiente->siguiente->siguiente->size)+"px;\n";
        file<<"\n}\n.pixel {\n";
        file<< "width: "+ std::to_string(temp2->listConfig->ultimo->siguiente->siguiente->size)+"px;";
        file<< "height: "+ std::to_string(temp2->listConfig->ultimo->siguiente->siguiente->siguiente->size)+"px;\n";
        file<< "float: left;\nbox-shadow: 0px 0px 1px #fff;\n";
        file<< "\n}\n";
        file<< pixelImage;
        file.close();
        string imagHtm="\\"+name+nameFilter+".html";
        const char *one = name.c_str();
        const char *two = imagHtm.c_str();

        string total( string(one) + two );

        system(total.c_str());
    }
    void generateImage(string name, string nameFilter,int x, int y){
        NodeList *temp3;
        NodeImage *temp2;
        NodeListLayerFilter *tempoImage;
        NodeFilter *tempFilter;
        temp2=mostrarArbole(raiz,name);
        tempoImage = lista->returnNodo(name);
        string pixelImage;
        width = temp2->listConfig->ultimo->size;
        height = temp2->listConfig->ultimo->siguiente->size;
        ofstream file;
        file.open(name+"\\"+name+nameFilter+".html");
        file<<"<!DOCTYPE html>\n"
              "<html>\n"
              "<head>\n"
              "  <link rel=\"stylesheet\" href=\""+name+nameFilter+".scss"+"\">\n"
                                                                           "</head>\n"
                                                                           "<body>\n<div class=\"canvas\">";
        for(int i=0;i<=(width*height)*(x*y);i++){
            file <<"<div class=\"pixel\"></div>\n";
        }
        tempFilter=tempoImage->liSta->devolverNodo(name+nameFilter);
        temp3=tempFilter->list->ultimo;
        do {
            pixelImage+=temp3->matrix->generateImages(width,height,x,y);
            pixelImage+="\n";
            temp3=temp3->siguiente;

        } while (temp3!=tempFilter->list->ultimo);
        cout<<"GeneradoCorrectamente"<<endl;
        file<<"</div>\n"
              "\n"
              "</body>\n"
              "</html>";
        file.close();
        file.open(name+"\\"+name+nameFilter+".scss");
        file<<"body {\n"
              "  background: #333333;      /* Background color of the whole page */\n"
              "  height: 100vh;            /* 100 viewport heigh units */\n"
              "  display: flex;            /* defines a flex container */\n"
              "  justify-content: center;  /* centers the canvas horizontally */\n"
              "  align-items: center;      /* centers the canvas vertically */\n"
              "}";
        file<<".canvas {\n";
        file<< "width: "+ std::to_string((width*x)*temp2->listConfig->ultimo->siguiente->siguiente->size)+"px;\n";
        file<< "height: "+ std::to_string((height*y)*temp2->listConfig->ultimo->siguiente->siguiente->siguiente->size)+"px;\n";
        file<<"\n}\n.pixel {\n";
        file<< "width: "+ std::to_string(temp2->listConfig->ultimo->siguiente->siguiente->size)+"px;\n";
        file<< "height: "+ std::to_string(temp2->listConfig->ultimo->siguiente->siguiente->siguiente->size)+"px;\n";
        file<< "float: left;\nbox-shadow: 0px 0px 1px #fff;\n";
        file<< "\n}\n";
        file<< pixelImage;
        file.close();
        string imagHtm="\\"+name+nameFilter+".html";
        const char *one = name.c_str();
        const char *two = imagHtm.c_str();

        string total( string(one) + two );

        system(total.c_str());
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
