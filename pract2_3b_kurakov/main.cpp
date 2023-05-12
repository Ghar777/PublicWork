
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstring>
using namespace std;
struct Node{
    string name;
    int age;

    Node* next;
    Node(string _name, int _age) : name(_name), age(_age), next(nullptr) {}
};
struct list{
    Node* first;
    Node* last;
    int size =0;
    list() : first(nullptr), last(nullptr) {}
    bool is_empty()
    {
        return first == nullptr;
    }


   void add (string _name, int _age){
    Node* p = new Node(_name, _age);
    if (is_empty())
        {
        first = p;
        last = p;
        size++;
        return;
        }
    Node *fast = first->next;
    Node *slow = first;
    while (fast && fast->name <= _name)
    {
        slow = fast;
        fast = fast->next;
    }
    slow->next = p;
    p->next = fast;
    size++;
}

    void print()
    {
        if (is_empty())
            return;
        Node *p = first;
        cout<<setw(20)<<"ФИО"<<setw(35)<<"возраст"<<endl;
        while (p)
            {
            cout<<setw(43) << p->name <<setw(17)<< p->age<<endl;
            p = p->next;
            }
        cout << endl;
    }
    void remove_first()
    {
        size--;
        if (is_empty())
        return;
        Node *p = first;
        first = p->next;
        delete p;    }
    void remove_last()
    {
        size--;
        if (is_empty())
            return;
        if (first == last)
            {
            remove_first();
            return;
            }
        Node *p = first;
        while (p->next != last)
            p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
        }
 void remove(Node* p)    {
        if (is_empty()) return;
        if (first == p)
        {
            remove_first();
            return;
        }
        else if (last == p)
            {
            remove_last();
            return;
        }
        Node* fast = first;
        while (fast && fast->next != p)        {
            fast = fast->next;        }
        fast->next = p->next;        delete p;
        size--;    }
    Node* operator[] (int index)
    {
        if (is_empty())
            return nullptr;
        Node *p = first;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
            if (!p)
                return nullptr;
            }
        return p;
        }

};
int main()
{
    setlocale (LC_ALL, "Russian");
    list Students;
    list OldStudents;
    char k;
    cout<<"введите первую букву фамилии"<<endl;
    cin>>k;
    Students.add("Avis", 25);
    Students.add("Polak", 60);
    Students.add("Poplovok", 30);
    Students.add("Bobro", 18);
    Students.add("Kolesi", 18);
    Students.add("Chumba", 28);
    Students.add("Mitenka", 27);
    Students.add("Koklock", 30);
    Students.add("Fortenov", 25);
    Students.print();
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < Students.size; i++)
        if (Students[i]->name[0] == k)        {
            OldStudents.add(Students[i]->name, Students[i]->age);
            Students.remove(Students[i]);
            i--;
            }
    cout << "старый список" << endl;
    Students.print();
        cout << "новый список" << endl;
    OldStudents.print();}


