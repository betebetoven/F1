// Linked List CPP 
#include "List.h"
//#include "nodo.h"
#include "json/json.h"
#include<iostream>
#include<string>

using namespace std;
//HOla mundo desde vscode
template<typename G>
 List<G>::List()
{
    tamaño = 0;
    head = NULL;
    tail = NULL;
    j = "estoy vivo otra vez";
}
template<typename G>
bool List<G>::isEmpty()
    {
        return head == NULL;
    }


template<typename G>
void List<G>::insert(G x)
{
        temp = new Node<G>;
        temp->data = x;
        if(isEmpty())
        {
            temp->next = NULL;
            temp->Prev = NULL;
            head = temp;

        }
        else
        {
            Node<G> *ahora;
            ahora = head;
            while (ahora->next != NULL)
            {
                ahora = ahora->next;

            }
            ahora->next =temp;
            temp->Prev = ahora;
            temp-> next = NULL;
        }
        tamaño= tamaño+1;

          
    }
template<typename G>
    void List<G>::insertAtEnd(G x)
    {
        temp = new Node<G>;
        temp->data = x;
        temp->next = NULL;
        if(isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
template<typename G>
    void List<G>::remove(G x)
    {
        temp = head;
        Node<G> *prev;
        while(temp->next != NULL && temp->data != x)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp->data == x)
        {
            prev->next = temp->next;
            delete temp;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }
template<typename G>
    void List<G>::find(G x)
    {
        int i;
        for(i=1, temp = head;temp->next != NULL && temp->data != x;temp = temp->next, i++);
        if(temp->data == x)
        {
            cout << "Found at position:" << i << endl;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }
template<typename G>
    void List<G>::display()
    {
        if(!isEmpty())
        {
            for(temp = head; temp != NULL; temp=temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }
    template class List<string>;
    template class Node<string>;
    template class List<Json::Value>;
    template class Node<Json::Value>;
    




