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
        cout<<"Menu"<<endl;
        cout<<"1. Insert Image"<<endl;
        cout<<"2. Insert Select Image"<<endl;
        cout<<"3. Apply filters"<<endl;
        cout<<"4. Manual editing"<<endl;
        cout<<"5. Export Image"<<endl;
        cout<<"6. Reports"<<endl;
        cin>>opcion;
        switch (opcion){
            case 1:
                system("cls");
                cout<<"Enter name"<<endl;
                cin>>nameImage;
                tree.insertarNodo(raiz,nameImage);
                break;
        }
    }
};