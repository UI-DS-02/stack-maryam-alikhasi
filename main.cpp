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
long int factorial(long int n) 
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int precedence(char c) 
{
    if (c == '^' || c == '!') 
    {
        return 3;

    } else if (c == '*' || c == '/') 
    {
        return 2;

    } else if (c == '+' || c == '-') 
    {
        return 1;

    } else 
        return -1;
}
//************************************************************************************************
mystack<double> convert(string expr)
{
    mystack<double> s;
    mystack<double> postfix;
    mystack<double> result;
    for(int i=0 ; i<expr.size() ; i++)
    {
        double curr = expr[i];
        if(curr == '(')
        {
           s.push('(') ;
        }
        else if(curr == ')')
        {
            while (s.topp()!='(' && !s.isempty())
            {
                postfix.push(s.topp());
                s.pop();
            }
            s.pop();
        }
        else if(curr=='-' && isdigit(expr[i+1]) && (i == 0 || (!isdigit(expr[i-1]) && expr[i-1] != 'I' && expr[i-1] != 'e' && expr[i-1] != '!')))
        {
            string f = "";
            f += curr;
            i++;
            while(isdigit(expr[i])||expr[i]=='.')
            {
                f+=expr[i];
                i++;
            }
            i--;
            if(f.length()>1) 
            {
                float num = stof(f);
                postfix.push(num);
            }
            else{
                postfix.push(curr+48);
            }
        }else if (curr=='-' && expr[i+1] == 'P' && expr[i+2] == 'I' && (i == 0 || (!isdigit(expr[i-1]) && expr[i-1] != 'I' && expr[i-1] != 'e' && expr[i-1] != '!')))
        {
            i+=2;
            float num = -3.14;
            postfix.push(num);
        }
        else if (curr=='-' && expr[i+1] == 'e'&& (i == 0 || (!isdigit(expr[i-1]) && expr[i-1] != 'I' && expr[i-1] != 'e')))
        {
            i+=1;
            float num = -2.71;
            postfix.push(num);
        }
        else if(curr == '+' || curr == '-' || curr ==  '*' || curr == '^' || curr == '!' || curr == '/')
        {
            while(!s.isempty() && precedence(curr) < precedence(s.topp()))
            {
                postfix.push(s.topp());
                s.pop();
            }
            s.push(curr);
        }
        else
        {
            if (curr == 'P' && expr[i+1] == 'I')
            {
                float num = 3.14 ;
                postfix.push(num) ;
                i++;
            }
            else if (curr == 'e')
            {
                float num = 2.71;
                postfix.push(num);
            }
            else 
            {
                string f;
                f=curr;
                i++;
                while(isdigit(expr[i]) || expr[i]=='.')
                {

                    f += expr[i];
                    i++;
                }
                i--;
                if(f.length()>1) {
                    float num = stof(f);
                    postfix.push(num);
                }
                else
                {
                    postfix.push(curr-48);
                }
            }
        }
    }
    while(!s.isempty())
    {
        postfix.push(s.topp());
        s.pop();
    }
    for(int i=postfix.size()-1 ; i>=0 ; i--)
    {
        result.push(postfix.topp());
        postfix.pop();
    }
    return result;
}