#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    void killSelf();

};

#endif
