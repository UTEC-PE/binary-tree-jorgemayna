#ifndef ITERATOR_H
#define ITERATOR_H
#include <stack>
#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;


    public:
        stack<Node<T>*> pila;
        Iterator();
        Iterator(Node<T>* node);

        Iterator<T> operator=(Iterator<T> node);
        bool operator!=(Iterator<T> cmp);
        void ins(Node<T>* node);
        Iterator<T> operator++();
        Iterator<T> operator--();
        T operator*();
};

template<class T> Iterator<T>::Iterator()
{

    current=NULL;

}
template<class T> Iterator<T>::Iterator(Node<T>* node)
{
    current=node;

}
template<typename T> Iterator<T> Iterator<T>::operator=(Iterator<T> node)
{
    current=node.current;
    pila=node.pila;

    return *this;
}
template<typename T> bool Iterator<T>::operator!=(Iterator<T> node)
{
    if (current==node.current)
    {
        return false;

    }
    else{
        return true;
    }

}
template<typename T> void Iterator<T>::ins(Node<T>* node)
{
    current=node;

}


template<typename T> Iterator<T> Iterator<T>::operator++()
{
    current=pila.top();
    pila.pop();
    if (current!=nullptr)
    {
        if(current->right!=nullptr)
        {

            Node<T>* temp=current->right;
            while(temp!=nullptr)
            {
                pila.push(temp);
                temp=temp->left;
            }
        }
    }

    return *this;

}
template<typename T> Iterator<T> Iterator<T>::operator--()
{
    current=current->prev;
    return *this;

}
template<typename T> T Iterator<T>::operator*()
{
    return current->data;

}

#endif
