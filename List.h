// Linked List CPP 
#pragma once
#include"nodo.h"
#include<iostream>

using namespace std;
//HOla mundo desde vscode
template<typename G>
class List
{
    Node<G> *head;
    Node<G> *tail;
    Node<G> *temp;
    bool isEmpty();
    
public:
    List();
    string j;
    void insert(G x);
    void insertAtEnd(G x);
    void remove(G x);
    void find(G x);
    void display();
    int tamaño;
};
