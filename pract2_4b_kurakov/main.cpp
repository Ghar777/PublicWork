#include <iostream>
#include <time.h>
using namespace std;

struct Node
{
    char simb;
    Node* next;
    Node (char _simb) : simb (_simb), next(nullptr){}
};

struct List
{
    Node* first;
    Node* last;
    int size;
    List() : first(nullptr), last(nullptr), size(0){}

    bool is_empty() {return first == nullptr;}

    void print()
    {
        if (is_empty())
            return;

        Node* p = first;
        while (p)
        {
            cout << p->simb << endl;
            p = p->next;
        }
        cout << endl;
    }

    void push_back(char _simb)
    {
        Node* p = new Node(_simb);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void fill_list(int n)
    {
        for ( int i = 0; i < n; i++)
        {
            char s(33 + rand()%100);
            Node* p = new Node (s);

            if (is_empty())
            {
                first = p;
                last = p;
            }

            last -> next = p;
            last = p;
        }
    }

    void null_massive (int *arr, int n, int i)
    {
        Node *p = first;
        for (int j = 0; j < n; j++)
        {
            if (i == int(p->simb))
                arr[i]++;
            p = p->next;
        }
    }

};


int main()
{
    setlocale (LC_ALL, "Russian");
    srand(time(NULL));

    int a [301] {0};
    List L1;
    List L2;

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
    cout<<L1<<'\n';

    int a[300] {};
    for (int i=0;i<L1.size;i++)
        a[L1[i]]++;
    for (int i = 0; i < 300; i++)
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
