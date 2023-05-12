#include <fstream>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstring>
using namespace std;


/*struct Node{
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

    void print(ofstream &input_data)
    {

        if (is_empty())
            return;
        Node *p = first;
        cout<<setw(20)<<"ФИО"<<setw(35)<<"возраст"<<endl;
        while (p)
            {
            cout<<setw(43) << p->name <<setw(17)<< p->age<<endl;
            input_data.write(reinterpret_cast<char*>(&(p->name)),sizeof (string));
            input_data.write(reinterpret_cast<char*>(&(p->age)),sizeof (int));
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
void read_file(ifstream &infile)
{
	int v;
	string k;
	infile.read(reinterpret_cast<char*>(&v),sizeof (int));
	infile.read(reinterpret_cast<char*>(&k),sizeof (string));
	while( !infile.eof())
	{
		cout<<k<<" "<<v;
	infile.read(reinterpret_cast<char*>(&v),sizeof (int));
	infile.read(reinterpret_cast<char*>(&k),sizeof (string));
	}
	cout<<endl;
}
/*
int main()
{
    setlocale (LC_ALL, "Russian");
    list Students;
    list OldStudents;
    char k;
    int course;
    string bufer;
    int course_bufer;
    cout<<"введите первую букву фамилии"<<endl;
    cin>>k;
    cout<<"введите курс"<<endl;
    cin>>course;
    ofstream input_data("input.bin", ios::binary);
    ofstream output_data("output.bin", ios::binary);
    for (int i=0; i<5;i++)
    {
        cin >> bufer;
        cin >> course_bufer;
        input_data.write(reinterpret_cast<char*>(&bufer),sizeof (string));
        input_data.write(reinterpret_cast<char*>(&course_bufer),sizeof (int));
    }
    input_data.close ();
    ifstream input1_data ("input.bin", ios::binary);
        for (int i=0; i<5;i++){
            input1_data.read(reinterpret_cast<char*>(&bufer),sizeof (string));
            input1_data.read(reinterpret_cast<char*>(&course_bufer),sizeof (int));
            Students.add(bufer,course_bufer);
    }
    //Students.print();
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < Students.size; i++)
        if (Students[i]->name[0] == k && Students[i]->age == course)        {
            OldStudents.add(Students[i]->name, Students[i]->age);
            Students.remove(Students[i]);
            i--;
            }
   // cout << "старый список" << endl;
    //Students.print();
    cout << "новый список" << endl;
    OldStudents.print(output_data);
    output_data.close();
    ifstream output1 ("output.bin", ios::binary);
    read_file (output1);
    }
*/
struct Students
{
int coyrs;
char name [100];
};
void read_file(fstream &infile)
{
	Students s1;
	infile.read(reinterpret_cast<char*>(&s1),sizeof (Students));
	while(1)
	{
		cout<<s1.name<<" "<<s1.coyrs;
    infile.read(reinterpret_cast<char*>(&s1),sizeof (Students));
	if (infile.eof())
        break;
	}
	cout<<endl;
}

void write_file (ofstream &input_data, int kolvo)
{
    Students s1;
    for (int i=0; i<kolvo;i++)
    {
        cin >> s1.name;
        cin >> s1.coyrs;
        input_data.write(reinterpret_cast<char*>(&s1),sizeof (Students));
    }
}
void sort_students (ifstream &input, fstream &output_data,  char k, int course)
{
    Students s1;
    while (input.eof()==0)
    {
        input.read(reinterpret_cast<char*>(&s1),sizeof (Students));
        if (s1.name[0]==k && s1.coyrs==course)
        {
            output_data.write(reinterpret_cast<char*>(&s1),sizeof (Students));
            cout << s1.name<< "   "<<s1.coyrs<<'\n';
        }
    }
}
int main ()
{
    setlocale (LC_ALL, "Russian");
    char k;
    int course, kolvo;
    cout<<"введите количество студентов"<<endl;
    cin>>kolvo;
    cout<<"введите первую букву фамилии"<<endl;
    cin>>k;
    cout<<"введите курс"<<endl;
    cin>>course;
    cout << '\n';
    ofstream input_data("input1.txt");
    fstream output_data("output1.txt");
    write_file (input_data, kolvo);
    input_data.close();
    ifstream input ("input1.txt");
    sort_students (input, output_data, k, course);
}

