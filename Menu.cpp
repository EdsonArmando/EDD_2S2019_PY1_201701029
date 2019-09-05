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
                leerArchivo(nameImage);
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

    void leerArchivo(string ruta) {
        archivoEntrada.open(ruta);
        if (archivoEntrada.is_open()) {
            while (archivoEntrada.good())
            {
                getline(archivoEntrada, linea);
                texto += linea + "\n";
            }
        }
        archivoEntrada.close();
        leerDatosArchivo(texto);
    }

    void leerDatosArchivo(string s){
        string de = "\n";
        string delimi = ", ";
        size_t  pos=0;
        size_t  pos2=0;
        string archivo="";
        string dato;
        int cont =0;
        while ((pos = s.find(de))!= std::string::npos){
            if(cont>0){
                dato=s.substr(0,pos);
                obteainName(dato);
                s.erase(0, pos + de.length());
            }else{
                s.erase(0, pos + de.length());
                cont++;
            }
        }
    }
    void obteainName(string text){
        LinkesList *lista=new LinkesList();
        NodeList *nuevo;
        std::string s = text;
        std::string delimiter = ", ";

        size_t pos = 0;
        std::string config;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            config = s.substr(0, pos);
            s.erase(0, pos + delimiter.length());
            leerArchivoCSV(s);
        }
    }

    void leerArchivoCSV(string nombreArchivo){
        nombreArchivo.erase(nombreArchivo.length()-4);
        NodeImage *temp=tree.mostrarArbole(raiz,nameImage);

    }
};