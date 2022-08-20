// Linked List CPP 
#include "List.h"
//#include "nodo.h"
#include<iostream>
#include<string>

using namespace std;
//HOla mundo desde vscode
List::List()
{
    tamaño = 0;
    head = NULL;
    tail = NULL;
    j = "estoy vivo otra vez";
}

bool List::isEmpty()
    {
        return head == NULL;
    }



void List::insert(int x)
{
        temp = new Node;
        temp->data = x;
        if(isEmpty())
        {
            temp->next = NULL;
            temp->Prev = NULL;
            head = temp;

        }
        else
        {
            Node *ahora;
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

    void List::insertAtEnd(int x)
    {
        temp = new Node;
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

    void List::remove(int x)
    {
        temp = head;
        Node *prev;
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

    void List::find(int x)
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

    void List::display()
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




