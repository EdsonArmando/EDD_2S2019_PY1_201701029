//
// Created by EG on 27/08/2019.
//

#include <stdlib.h>
#include <iostream>
#include "LinkedList.cpp"
#include <string>
#include "NodeImage.cpp"
#include "ABB.cpp"
using  namespace std;

class Menu {
private:
    ifstream archivoEntrada;
    NodeList *nuevo;
    ABB tree;
    int opcion=0;
    string nameImage,linea,texto;
public:
    void IniciarMenu(){
        cout<<"----------Menu----------"<<endl;
        cout<<"1. Insert Image"<<endl;
        cout<<"2. Insert Select Image"<<endl;
        cout<<"3. Apply filters"<<endl;
        cout<<"4. Manual editing"<<endl;
        cout<<"5. Export Image"<<endl;
        cout<<"6. Reports"<<endl;
        cout<<"Enter Option: "<<endl;
        cin>>opcion;
        switch (opcion){
            case 1:
                system("cls");
                cout<<"Enter name"<<endl;
                cin>>nameImage;
                tree.insertarNodo(raiz,nameImage);
                readInitialFile(nameImage);
                IniciarMenu();
                break;
            case 2:
                tree.recoOrdenAlfa(raiz);
                system("pause");
                IniciarMenu();
                break;
            case 6:
                cout<<"----------Reports----------"<<endl;
                cout<<"1. Imported Images "<<endl;
                cout<<"2. Traversal "<<endl;
                cout<<"3. Image Layer"<<endl;
                cout<<"4. Linear Matrix "<<endl;
                cout<<"5. Filters"<<endl;
                cout<<"Enter Option: "<<endl;
                cin>>opcion;
                switch (opcion){
                    case 1:
                        tree.graficarArbol(raiz);
                        tree.mostrarArbol();
                        IniciarMenu();
                        break;
                    case 2:
                        cout<<"----------Reports----------"<<endl;
                        cout<<"1. Inorder Traversal "<<endl;
                        cout<<"2. Preorder Traversal "<<endl;
                        cout<<"3. Posorder Traversal"<<endl;
                        cout<<"Enter Option: "<<endl;
                        cin>>opcion;
                        switch (opcion){
                            case 1:
                                tree.recoIn(raiz);
                                tree.grafReco("Inorder Treversal");
                                IniciarMenu();
                                break;
                            case 2:
                                tree.recoPre(raiz);
                                tree.grafReco("Preorder Traversal");
                                IniciarMenu();
                                break;
                            case 3:
                                tree.recoPost(raiz);
                                tree.grafReco("Posorder Traversal");
                                IniciarMenu();
                                break;
                        }
                        break;
                }
                break;
        }
    }
    string devolverTexto(string ruta){
        texto="";
        archivoEntrada.open(ruta);
        if (archivoEntrada.is_open()) {
            while (archivoEntrada.good())
            {
                getline(archivoEntrada, linea);
                texto += linea + "\n";
            }
        }else{
            return "";
        }
        archivoEntrada.close();
        return texto;
    }
    void readInitialFile(string ruta){
        string texto = devolverTexto(ruta);
        string de = "\n";
        string delimi = ", ";
        size_t  pos=0;
        size_t  pos2=0;
        string archivo="";
        string nameCSV;
        string dato;
        int cont =0;
        while ((pos = texto.find(de))!= std::string::npos){
            if(cont>0){
                dato=texto.substr(0,pos);
                while ((pos2 = dato.find(delimi)) != std::string::npos) {
                    nameCSV = dato.substr(0, pos2);
                    dato.erase(0, pos2 + delimi.length());
                    //cout<<dato<<endl;
                    leerArchivoCSV(dato);
                }
                texto.erase(0, pos + de.length());
            }else{
                texto.erase(0, pos + de.length());
                cont++;
            }
        }

    }
    void leerArchivoCSV(string fileName){
        fileName.erase(fileName.length()-1);
        string texto = devolverTexto(fileName);
        string de = "\n";
        string delimi = ", ";
        size_t  pos=0;
        size_t  pos2=0;
        string archivo="";
        string nameCSV;
        string dato;
        int cont =0;
        if(texto!=""){
            while ((pos = texto.find(de))!= std::string::npos){
                if(cont>0){
                    dato=texto.substr(0,pos);
                    while ((pos2 = dato.find(delimi)) != std::string::npos) {
                        nameCSV = dato.substr(0, pos2);
                        dato.erase(0, pos2 + delimi.length());
                        cout<<nameCSV<<endl;
                        cout<<dato<<endl;
                    }
                    texto.erase(0, pos + de.length());
                }else{
                    texto.erase(0, pos + de.length());
                    cont++;
                }
            }
        }
    }
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
};