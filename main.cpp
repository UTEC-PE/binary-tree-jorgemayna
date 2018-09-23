#include<iostream>
#include "tree.h"
using namespace std;

int menu()
{
    int ope;
    cout<<"------------------------------------------------"<<endl;
    cout<<"- Elija una opcion:"<<endl;
    cout<<"1) Inserta nuevo elemento"<<endl;
    cout<<"2) Imprimir en orden"<<endl;
    cout<<"3) Imprimir en preorder"<<endl;
    cout<<"4) Imprimir en posorder"<<endl;
    cout<<"5) salir"<<endl;
    cout<<"   ## op: ";
    cin >>ope;
    return ope;

}
int main()
{
    Tree<int> tree;
    int op=2,exit=0;
    while(exit!=5)
    {

        if(exit==1)
        {
            int a;
            cout<<endl;
            cout <<"Ingrese el numero: ";
            cin >>a;
            tree.insertar(tree.root,a);
        }
        system("cls");
        cout<<"------------------------------------------------"<<endl;
        cout<<"---------   ARBOL BINARIO DE BUSQUEDA  ---------"<<endl;
        cout<<"------------------------------------------------"<<endl;
        if(exit==2)op=2;
        if(exit==3)op=3;
        if(exit==4)op=4;

        if(op==2)tree.enorder(tree.root);
        if(op==3)tree.preorder(tree.root);
        if(op==4)tree.posorder(tree.root);
        cout<<endl;
        exit=menu();
    }


    /*Iterator<int> it;


    for(it=tree.left();it!=tree.end();++it)
    {
        cout << *it<<endl;
    }
    */

    return 0;
}
