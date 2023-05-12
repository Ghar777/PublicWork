#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

struct Node
{
     int x;
    Node* next;
    Node* prev;
    Node () :  x (NULL), next(nullptr), prev(nullptr){}
    Node (int _x) : x  (_x), next(nullptr), prev(nullptr){}
};

struct List
{
    Node* first;
    Node* last;
    List() : first(nullptr), last(nullptr){}

    bool is_empty() {return first == nullptr;}

    void print()
    {
        if (is_empty())
            return;

        Node* p = first;
        while (p)
        {
            cout << p->x << endl;
            p = p->next;
        }
        cout << endl;
    }

    void fill_list(int n)
    {
        for ( int i = 0; i < n; i++)
        {
            int s = i+1; //rand()%10;
            Node* p = new Node (s);

            if (is_empty())
            {
                first = p;
                last = p;
            }

            last -> next = p;
            p -> prev = last;
            last = p;
        }
    }

    int summ(int n)
    {
        Node* f = first;
        Node* l = last;
        int sum = 0;

        while (f != last )
        {
            sum += (f->x + f->next->x + n*(l -> x));
            f = f->next;
            l = l -> prev;
            n--;
           // cout <<'\n'<< sum<<'\n';
        }

        return sum;
    }

};


int main()
{
    setlocale (LC_ALL, "Russian");
    srand(time(NULL));

    cout << "введите размер списка" << endl;
    int n;
    cin >> n;
    int n1 = n;
    List l;
    l.fill_list(n);
    l.print();

    cout << "результат: " << l.summ(n1) << endl;
}
