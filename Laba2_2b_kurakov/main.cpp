#include <iostream>
#include <time.h>
#include <algorithm>
#define simb simbol
#define _simb _simbol
using namespace std;

template <class T> class Node
{
public:
    T simbol;
    Node<T>* next;
    Node () : simbol (NULL), next(nullptr){}
    Node (T _simbol) : simbol (_simbol), next(nullptr){}
};

template <class T> class List
{
    Node<T>* first;
    Node<T>* last;
    public:

    List() : first(nullptr), last(nullptr){}

    bool is_empty() const  {return first == nullptr;}
    List(const List &a) : first(nullptr), last(nullptr)
    {
        for (Node<T> *n = a.first; n != nullptr; n =n->next)
        {
            Node<T> *p = new Node<T>(n->simbol);
            if (!first)
                first = p;
            else
                last->next =p;
            last = p;
        }
    }

    List (List &&a):first(a.first), last(a.first)
    {
        a.first = nullptr;
        a.last = nullptr;
    }
    ~List()
    {
        while (first != nullptr)
        {
            Node <T> *p = first;
        while (p->next != last)
            p = p->next;
        if (p==first)
        {
            delete first;
            first = nullptr;
        }
        p->next = nullptr;
        delete last;
        last =p;
        }
    }

    List& operator = (List &&a)
    {
        swap(first, a.first);
        swap(last, a.last);
        return *this;
    }



    List& operator = (const List &a)
    {
        while (first!=nullptr)
        {
            Node<T> *p = first;
            first = first->next;
            delete p;
        }
        if (this != &a)
            for (const Node<T> *p =a.first; p!=nullptr; p=p->next)
                push_back(p->simbol);
            return *this;
    }

/*    Node<T>* operator [] (int index)
    {
        if (is_empty())
            return nullptr;
        Node<T>* p = first;
        for (int i=0;i<index;i++)
        {
            p=p->next;
            if (!p)
                return nullptr;
        }
        return p;
    }*/
    void delete_element (T _simbol)
    {
        Node <T> *p = first;
        while (p->next->simbol != _simbol)
            p = p->next;
        Node<T> *d = p->next;
        p->next = d -> next;
        delete d;
    }
    Node<T>* search_element (T _simbol)
    {
        Node <T> *p = first;
        while (p->next->simbol != _simbol);
        return p;
    }
    void print() const
    {
        Node<T>* p = first;
        while (p)
        {
            cout << p->simbol << endl;
            p = p->next;
        }
        cout << endl;
    }

    void push_back(char _simb)
    {
        Node<T>* p = new Node<T>(_simb);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }


    void null_massive (int *arr, int n, int i)
    {
        Node<T> *p = first;
        for (int j = 0; j < n; j++)
        {
            if (i == int(p->simb))
                arr[i]++;
            p = p->next;
        }
    }


};
  void fill_double_list(List<double> S, int n)
    {
        for ( int i = 0; i < n; i++)
            S.push_back((double)rand()/RAND_MAX);
    }
    void fill_char_list(List<char> S, int n)
    {
        for ( int i = 0; i < n; i++)
            S.push_back(33 + rand()%100);
    }


int main()
{
    setlocale (LC_ALL, "Russian");
    srand(time(NULL));

    int a [301] {0};
    List<char> L1;
    List<char> L2;

    cout << "введите размер списка" << endl;
    int n;
    cin >> n;

    cout << "исходный список" << endl;
   // L1.fill_list(n);
    L1.push_back('c');
    L1.push_back('c');
    L1.push_back('3');
    L1.push_back('f');
    L1.push_back('f');
    L1.push_back('c');
    L1.print();

    for (int i = 0; i < 133; i++)
        L1.null_massive(a,n,i);
    for (int i = 0; i < 133; i++)
    {
        if(a[i]==2)
        {
            char c = char(i);
            L2.push_back(c);
        }
    }

    cout << "результат" << endl;
    L2.print();
}
