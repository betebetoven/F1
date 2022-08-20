// Linked List CPP 
#pragma once
#include"nodo.h"
#include<iostream>

using namespace std;
//HOla mundo desde vscode

class List
{
    Node *head;
    Node *tail;
    Node *temp;
    bool isEmpty();
    
public:
    List();
    string j;
    void insert(int x);
    void insertAtEnd(int x);
    void remove(int x);
    void find(int x);
    void display();
    int tamaño;
};
