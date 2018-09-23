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
        void insertar(Node<T>* &temp,T value)
        {

            if(temp==nullptr)
            {
                temp = new Node<T>;
                temp->data=value;
                temp->left=nullptr;
                temp->right=nullptr;
                nodes++;
            }else if(value < temp->data)
            {
                insertar(temp->left,value);
            }else if(value > temp->data)
            {
                insertar(temp->right,value);
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


        bool empty();
        int size()
        {
            return nodes;
        };
        void clear();
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
