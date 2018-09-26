#include<iostream>
#include "tree.h"
using namespace std;
#include<limits>
int menu()
{
    int ope;
    cout<<"------------------------------------------------"<<endl;
    cout<<"- Elija una opcion:"<<endl;
    cout<<"1) Inserta nuevo elemento"<<endl;
    cout<<"2) Imprimir en orden"<<endl;
    cout<<"3) Imprimir en preorder"<<endl;
    cout<<"4) Imprimir en posorder"<<endl;
    cout<<"5) Eliminar elemento"<<endl;
    cout<<"6) Peso de un nodo"<<endl;
    cout<<"7) salir"<<endl;
    cout<<"   ## op: ";
    cin >>ope;

    if (cin.fail())
    {
        cout << "Porfavor ingre un numero";

        cin.clear();

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return ope;


}
int main()
{
    Tree<int> tree;
    int op=2,exit=0;
    while(exit!=7)
    {

        if(exit==1)
        {
            int a;
            cout<<endl;
            cout <<"Ingrese el numero: ";
            cin >>a;
            tree.insertar(a);
        }
        if(exit==5)
        {
            int a;
            cout<<endl;
            cout <<"Ingrese elemento a borrar: ";
            cin >>a;
            tree.eliminar(a);
            system("pause");
        }
        if(exit == 6)
        {
            int a;
            cout<<endl;
            cout <<"Ingrese el nodo: ";
            cin >>a;
            cout <<"El peso es : "<< tree.cualquier_nodo(a)<<endl;
            system("pause");
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
