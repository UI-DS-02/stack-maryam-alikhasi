#include <iostream>
#include <string>
#include <cmath>
using namespace std ;

template <typename T>
class node
{
    public :
    T data ;
    node* next;
    node(T data) 
    {
        this->data = data ;
    };
};
template <typename T>
class list
{
    public :
    node<T> * head;
    node<T> * tail ;
    int size ;

    list()
    {
        head = nullptr ;
        tail = nullptr ;
        size = 0 ; 
    }

    int sizee()
    {
        return size ;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true ;
        else 
            return false ;
    }

    node<T> * first()
    {
        if(isEmpty() != true)
            return head ;
        else 
            return nullptr ;
    }
    void addFirst(T data)
    {
        node<T> * tmp = new node<T>(data);
        tmp->next = head ;
        if (head == nullptr)
        {
            head = tmp ;
            tail = tmp ;
        }
        else 
        {
            head = tmp ;
        }
        size ++ ;
    }
    void removeFirst()
    {
        if (head != nullptr)
        {
            node<T> * dele = head ;
            head = head->next;
            delete dele ;
            size -=1;
        }
    }

};
template <typename T>
class mystack
{
public :
    int top ;
    list<T> a ;
    mystack()
    {
        top = -1 ;
    }
    void push(T data)
    {
        a.addFirst(data) ;
        top += 1 ;
    }
    bool isempty()
    {
        return a.isEmpty() ;
    }
    void pop()
    {
        a.removeFirst() ;
        top -= 1 ;
    }
    T topp()
    {
        return a.first()->data ;
    }
    int size ()
    {
        return a.sizee();
    }
};
//********************************************************************************************************