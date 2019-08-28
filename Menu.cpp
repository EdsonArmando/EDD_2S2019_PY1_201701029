//
// Created by EG on 27/08/2019.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include "NodeImage.cpp"
#include "ABB.cpp"
using  namespace std;

class Menu {
private:
    ABB tree;
    int opcion=0;
    string nameImage;
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
};