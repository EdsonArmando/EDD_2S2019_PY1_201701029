//
// Created by EG on 27/08/2019.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include "LinkedList.cpp"
#include "ListLayer.cpp"
#include "NodeImage.cpp"
#include "ABB.cpp"
using  namespace std;

class Menu {
private:
    ifstream archivoEntrada;
    NodeList *nuevo;
    int posX=1,x,y,rs,gs,bs;
    string folder="",nameFilter;
    int posY=1;
    string r,g,b;
    NodeConfig *nuevos;
    ABB tree;
    int opcion=0;
    string nameImage,linea,texto,capaImage,na,linealizar;
    char letra;
    int contNum = 0;
    string color="";
    int op = 0;
    int lon,cantidadx,cantidady;
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
            case 4:
                tree.imageLayerReport(nameImage);
                cout<<"2. Filtros"<<endl;
                cout<<"Enter Name: "<<endl;
                cin>>capaImage;
                cout<<"1. Ingresar nueva posiciion"<<endl;
                cout<<"2. Modificar Posicion"<<endl;
                cin>>opcion;
                if(opcion==1){
                    cout<<"X"<<endl;
                    cin>>x;
                    cout<<"Y"<<endl;
                    cin>>y;
                    cout<<"r"<<endl;
                    cin>>rs;
                    cout<<"g"<<endl;
                    cin>>gs;
                    cout<<"b"<<endl;
                    cin>>bs;
                    tree.edicionMaual(nameImage,capaImage,x,y,rs,gs,bs);
                }
                IniciarMenu();
                break;
            case 1:
                system("cls");
                cout<<"Enter name"<<endl;
                cin>>nameImage;
                folder=nameImage;
                tree.insertarNodo(raiz,nameImage);
                readInitialFile(nameImage);
                obtenerNodoArbol();
                IniciarMenu();
                break;
            case 2:
                tree.recoOrdenAlfa(raiz);
                cout<<"Enter name"<<endl;
                cin>>nameImage;
                folder=nameImage;
                tree.generateImage(nameImage);
                system("pause");
                IniciarMenu();
                break;
            case 3:
                cout<<"----------Filters----------"<<endl;
                cout<<"1. Negative "<<endl;
                cout<<"2. Grayscale "<<endl;
                cout<<"3. X-Mirror"<<endl;
                cout<<"4. Y-Mirror"<<endl;
                cout<<"5. DouebleMirror"<<endl;
                cout<<"6. Collage"<<endl;
                cout<<"7. Mosaic"<<endl;
                cout<<"8. Layer"<<endl;
                cout<<"Enter Option: "<<endl;
                cin>>opcion;
                switch(opcion){
                    case 1:
                        tree.aplyFilter(nameImage,"negative",0,0);
                        IniciarMenu();
                        break;
                    case 2:
                        tree.aplyFilter(nameImage,"grises",0,0);
                        IniciarMenu();
                        break;
                    case 3:
                        tree.aplyFilter(nameImage,"X_Mirror",0,0);
                        IniciarMenu();
                        break;
                    case 4:
                        tree.aplyFilter(nameImage,"Y_Mirror",0,0);
                        IniciarMenu();
                        break;
                    case 5:
                        tree.aplyFilter(nameImage,"DouebleMirror",0,0);
                        IniciarMenu();
                        break;
                    case 6:
                        cout<<"Repeticiones eje x"<<endl;
                        cin>>cantidadx;
                        cout<<"Repeticiones eje y"<<endl;
                        cin>>cantidady;
                        tree.aplyFilter(nameImage,"Collage",cantidadx,cantidady);
                        IniciarMenu();
                        break;
                   case 8:
                       tree.imageLayerReport(nameImage);
                       cout<<"Enter Name: "<<endl;
                       cin>>capaImage;
                       cout<<"Seleccione el filtro"<<endl;
                       cout<<"1. Negative "<<endl;
                       cout<<"2. Grayscale "<<endl;
                       cin>>opcion;
                       if(opcion==1){
                          tree.filterLayer(nameImage,capaImage,"negative");
                       }else if(opcion==2){
                         tree.filterLayer(nameImage,capaImage,"grises");
                       }

                       IniciarMenu();
                      break;
                }
                break;
            case 5:
                tree.exportImage(nameImage);
                cout<<"Enter Name: "<<endl;
                cin>>nameFilter;
                if(nameFilter=="collage"){
                    tree.generateImage(nameImage,nameFilter,cantidadx,cantidady);
                }else{
                    tree.generateImage(nameImage,nameFilter);
                }
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
                    case 4:
                        tree.recoOrdenAlfa(raiz);
                        cout<<"Enter name"<<endl;
                        cin>>na;
                        tree.linearMatrix(na);
                        cout<<"Enter name"<<endl;
                        cin>>capaImage;
                        cout<<"Tipo Linealizacion"<<endl;
                        cout<<"1. filas"<<endl;
                        cout<<"2. columnas"<<endl;
                        cin>>opcion;
                        if(opcion==1){
                            tree.graficoLinealizarMatriz(na,capaImage,"filas");
                        }else{
                            tree.graficoLinealizarMatriz(na,capaImage,"columnas");
                        }
                        IniciarMenu();
                        break;
                    case 3:
                        cout<<"LayerReports"<<endl;
                        cout<<"1. Image Original"<<endl;
                        cout<<"2. Image Filter"<<endl;
                        cin>>opcion;
                        if(opcion==1){
                          tree.imageLayerReport(nameImage);
                          cout<<"Enter Name: "<<endl;
                          cin>>capaImage;
                          tree.imageLayerReport2(nameImage,capaImage);
                        }else if(opcion==2){
                          cout<<"1. Negative "<<endl;
                          cout<<"2. Grayscale "<<endl;
                          cout<<"3. X-Mirror"<<endl;
                          cout<<"4. Y-Mirror"<<endl;
                          cout<<"5. DouebleMirror"<<endl;
                          cout<<"6. Collage"<<endl;
                          cout<<"7. Mosaic"<<endl;
                          cout<<"8. Layer"<<endl;
                          cout<<"Enter Option: "<<endl;
                          cin>>opcion;
                          tree.imageLayerReport(nameImage);
                          cout<<"Enter Name: "<<endl;
                          cin>>capaImage;
                          switch (opcion) {
                            case 1:
                            imageMatrixFilter(nameImage,"negative",capaImage);
                            break;
                            case 2:
                              imageMatrixFilter(nameImage,"grises",capaImage);
                            break;
                            case 3:
                              imageMatrixFilter(nameImage,"X_Mirror",capaImage);
                            case 3:
                              imageMatrixFilter(nameImage,"Y_Mirror",capaImage);
                            break;
                          }
                        }

                        IniciarMenu();
                        break;
                    case 5:
                        tree.graphDoubleList(nameImage);
                        IniciarMenu();
                        break;
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
        if(ruta==folder){
            archivoEntrada.open(folder+"\\"+ruta+".csv");
        }else{
            archivoEntrada.open(folder+"\\"+ruta);
        }

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
        string delimi = ",";
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
                    cout<<nameCSV<<endl;
                    leerArchivoCSV(dato,nameCSV);
                }
                texto.erase(0, pos + de.length());
            }else{
                texto.erase(0, pos + de.length());
                cont++;
            }
        }

    }
    void leerArchivoCSV(string fileName,string noCapa){
        string texto = devolverTexto(fileName);
        NodeImage *temp=tree.mostrarArbole(raiz,nameImage);
        string de = "\n";
        string delimi = ",";
        size_t  pos=0;
        size_t  pos2=0;
        string archivo="";
        string nameCSV="";
        string dato;
        int cont =0;
        if(fileName=="Config.csv"||noCapa=="0"){
            while ((pos = texto.find(de))!= std::string::npos){
                if(cont>0){
                    dato=texto.substr(0,pos);
                    while ((pos2 = dato.find(delimi)) != std::string::npos) {
                        nameCSV = dato.substr(0, pos2);
                        dato.erase(0, pos2 + delimi.length());
                        nuevos = new NodeConfig(nameCSV, std::stoi(dato));
                        temp->listConfig->addConfig(nuevos);
                    }
                    texto.erase(0, pos + de.length());
                }else{
                    texto.erase(0, pos + de.length());
                    cont++;
                }
            }
        }else if(fileName !="Config.csv" && texto!="") {
            nuevo = new NodeList(fileName);
            cout<<"------"+fileName+"------"<<endl;
            lon=texto.length();
            for (int i = 0; i < lon; i++) {
                letra = texto[i];
                switch (op) {
                    case 0:
                        switch (letra) {

                            case '\t':
                            case '\r':
                            case ' ':
                                op = 0;
                                break;
                            case '\n':
                                if(r!=""){
                                    nuevo->matrix->add(posX,posY,std::stoi(r),std::stoi(g),std::stoi(b));
                                    contNum=0;
                                    posX=1;
                                    color = "";
                                    op = 0;
                                    r="";
                                    g="";
                                    b="";
                                    posY++;
                                }else{
                                    contNum=0;
                                    posX=1;
                                    color = "";
                                    op = 0;
                                    r="";
                                    g="";
                                    b="";
                                    posY++;
                                }

                                break;
                            case 'x':
                                op = 0;
                                posX++;
                                if(posX==0){
                                    posY++;
                                }

                                break;
                            case ',':
                                if(r==""){
                                    op=0;
                                }else if(std::stoi(r)>=0){
                                    nuevo->matrix->add(posX,posY,std::stoi(r),std::stoi(g),std::stoi(b));
                                    contNum=0;
                                    posX++;
                                    color = "";
                                    op = 0;
                                    r="";
                                    g="";
                                    b="";
                                    op=0;
                                }
                                break;
                            default:
                                op = 1;
                                r+=letra;
                                break;
                        }
                        break;
                    case 1:
                       if(letra!='\r'||letra!='\n'){
                            if(contNum==0){
                                if(letra!='-'){
                                    r += letra;
                                    op = 1;
                                } else{
                                    contNum=1;
                                }

                            }else if(contNum ==1){
                                if(letra!='-'){
                                    g += letra;
                                    op = 1;
                                }else{
                                    contNum=2;
                                }

                            }else if(contNum==2){
                                if(letra!=','&& letra!='\n'){
                                    b += letra;
                                    op = 1;
                                }else if(letra==','||letra=='\n'||letra=='\r'){
                                    contNum=0;
                                    op=0;
                                    i=i-1;
                                }

                            }
                        }
                        break;
                }
            }
            temp->list->insertarImg(nuevo);
            archivo = "";
            texto = "";
            linea = "";
            lon = 0;
            posX=1;
            posY=1;
            op = 0;
        }
    }

    void obtenerNodoArbol(){
        NodeContent *matri=NULL;
        NodeList *tempo=NULL;
        NodeImage *temp=tree.mostrarArbole(raiz,nameImage);
        tempo = temp->list->primero;
        tempo->matrix->imageSpaseMatrix();
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
