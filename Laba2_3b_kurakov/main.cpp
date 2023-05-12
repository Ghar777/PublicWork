#include <iostream>
#include <time.h>

using namespace std;

template <class T> struct Node
{

    T x;
    Node* next;
    Node* prev;
    Node () : x (NULL), next(nullptr), prev(nullptr){}
    Node (T _x) : x  (_x), next(nullptr), prev(nullptr){}
};

template <class T> class List
{
//    public:
    Node<T>* first;
    Node<T>* last;

    public:
    List() : first(nullptr), last(nullptr){}

    bool is_empty() const  {return first == nullptr;}
    List(const List &a) : first(nullptr), last(nullptr)
    {
        for (Node<T> *n = a.first; n != nullptr; n =n->next)
        {
            Node<T> *p = new Node<T>(n->x);
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
                push_back(p->x);
            return *this;
    }
    void delete_element (T _x)
    {
        Node <T> *p = first;
        while (p->next->x != _x)
            p = p->next;
        Node<T> *d = p->next;
        p->next = d -> next;
        delete d;
    }
    Node<T>* search_element (T _x)
    {
        Node <T> *p = first;
        while (p->next->x != _x);
        return p;
    }
    void print() const
    {
        Node<T>* p = first;
        while (p)
        {
            cout << p->x << endl;
            p = p->next;
        }
        cout << endl;
    }

    void push_back(int _x)
    {
        Node<T>* p = new Node<T>(_x);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        last -> next = p;
        p -> prev = last;
        last = p;
    }
    Node<T>* get_first () const
    {
        return first;
    }
    Node<T>* get_last () const
    {
        return last;
    }


};
void fill_int_list(List<int> &S, int n)
    {
        for ( int i = 0; i < n; i++)
            S.push_back(i+1);
        //S.print();
    }
template <typename T> summ(const List<T> &S, int n)
    {
        Node<T>* f = S.get_first();
        Node<T>* l = S.get_last();
        T sum = 0;

        while (f != S.get_last())
        {
            sum += (f->x + f->next->x + n*(l -> x));
            f = f->next;
            l = l -> prev;
            n--;
            //cout <<'\n'<< sum<<'\n';
        }

        return sum;
    }
int main()
{
    setlocale (LC_ALL, "Russian");
    srand(time(NULL));
    cout << "введите размер списка" << endl;
    int n;
    cin >> n;
    List<int> S;
    fill_int_list(S, n);
    S.print();
    cout << "результат: " << summ(S,n);
}
