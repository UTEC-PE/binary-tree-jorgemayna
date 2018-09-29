#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "iterator.h"
#include <iostream>


using namespace std;

template <typename T>
class Tree {
    private:

        int nodes;

    public:
        Node<T>* root;
        Tree()
        {
            root= nullptr;
            nodes=0;
        };
        void insertar(T value)
        {
            Node<T>** temp=buscar(root,value);
            if((*temp)==nullptr)
            {
                (*temp) = new Node<T>;
                (*temp)->data=value;
                (*temp)->left=nullptr;
                (*temp)->right=nullptr;
                nodes++;
            }
        };
        void enorder(Node<T>* temp)
        {
            if(temp!=nullptr)
            {
                enorder(temp->left);
                cout<<temp->data<<" ";
                enorder(temp->right);
            }
        };

        void preorder(Node<T>* temp)
        {
            if(temp!=nullptr)
            {
                cout<<temp->data<<" ";
                preorder(temp->left);
                preorder(temp->right);
            }
        };
        void posorder(Node<T>* temp)
        {
            if(temp!=nullptr)
            {
                posorder(temp->left);
                posorder(temp->right);
                cout<<temp->data<<" ";
            }
        };

        bool empty(){return root;}

        T peso(Node<T>* nodo)
        {
            if(nodo!=nullptr)
            {
                return (nodo->data + peso(nodo->left) + peso(nodo->right));
            }else
            {
                return 0;
            }

        }
        T cualquier_nodo(T nodo)
        {
            return (peso(*buscar(root,nodo)));
        }
        int size()
        {
            return nodes;
        };
        void clear();
        Node<T>** buscar(Node<T>* &temp,T eli)
        {
            if(temp==nullptr || temp->data==eli)
            {
                return &temp;
            }
            else if(temp->data>eli)
            {
                buscar(temp->left,eli);
            }
            else if(root->data<eli)
            {
                buscar(temp->right,eli);
            }

        };
        void eliminar(T eli)
        {
            Node<T>** temp=buscar(root,eli);
            if((*temp)==nullptr)
            {
                cout<<"El valor ingresado no esta en el arbol"<<endl;
            }else
            {
                if((*temp)->right==nullptr && (*temp)->left==nullptr)
                {
                    delete (*temp);
                    (*temp)=nullptr;
                }
                else if((*temp)->right==nullptr || (*temp)->left==nullptr)
                {
                    if((*temp)->right!=nullptr)
                    {
                        Node<T>* te=(*temp)->right;
                        delete (*temp);
                        (*temp)=te;
                    }else
                    {
                        Node<T>* te=(*temp)->left;
                        delete (*temp);
                        (*temp)=te;
                    }
                }
                else if((*temp)->right!=nullptr && (*temp)->left!=nullptr)
                {

                    Node<T>* te=(*temp)->right;
                    if(te->left==nullptr)
                    {
                        int a=te->data;
                        eliminar(a);
                        (*temp)->data=a;

                    }else
                    {
                        while(te->left!=nullptr)
                        {
                            te=te->left;
                        }
                        int a=te->data;
                        eliminar(a);
                        (*temp)->data=a;
                    }

                }


            }
        };
        Iterator<T> left()
        {
            Iterator<T> te;
            Node<T>* temp;
            temp=nullptr;
            te.pila.push(temp);
            temp=root;
            while(temp->left!=nullptr)
            {
                te.pila.push(temp);
                temp=temp->left;
            }
            te.ins(temp);
            if(temp->right!=nullptr)
            {

                temp=temp->right;
                while(temp!=nullptr)
                {
                    te.pila.push(temp);
                    temp=temp->left;
                }
            }

            return te;
        };
        Iterator<T> end()
        {
            Iterator<T> e(nullptr);
            return e;
        };

        ~Tree()
        {

        };
};

#endif
