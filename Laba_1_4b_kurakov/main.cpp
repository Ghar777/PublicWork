#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class kosm_objekt
{
protected:
    int X =1;
    int Y =1;
    int Z =1;
public:
    virtual void print () const = 0;
    virtual ~kosm_objekt (){};
    friend ostream& operator << (ostream& out, const kosm_objekt &a)
    {
        a.print();
        cout <<'\n';
        return out;
    }
};
/////////////////////////////////////////////////////////////////

class planet: public kosm_objekt
{
    string type = "planet";
protected:
    int temp = 22;
    int size_name;
    char* nazv;
    bool poverhnost = 1;
public:
    planet ():size_name(100),temp(0),nazv(new char [size_name]), poverhnost(0)
    {
        nazv[0]=0;
        strcpy(nazv, "interprise");
    }
    planet (int temp1, char nazv1 [100], bool poverhnost1):size_name(100),temp(temp1),nazv(nazv1), poverhnost(poverhnost1){}
    ~planet ()
    {
        delete [] nazv;
        size_name =0;
        temp =0;
        poverhnost = 0;
    }
    void print () const
    {
        cout <<type<<'\n';
        cout<<nazv<<'\n';
        cout<<temp<<'\n';
        cout<<poverhnost<<'\n';
        cout<<X<<'\n';
        cout<<Y<<'\n';
        cout<<Z<<'\n';
    }
    void set_data (int X1, int Y1, int Z1, int temp1, string nazv1, bool pov)
    {
        X=X1;
        Y=Y1;
        Z=Z1;
        temp = temp1;
        for (int i=0;i<100;i++)
        nazv[i]= nazv1[i];
        poverhnost=pov;
    }
};
///////////////////////////////////////////////////////////////////
class podvizh_objekt: public kosm_objekt
{
protected:
    int Vx = 1;
    int Vy = 1;
    int Vz = 1;
public:
    virtual ~podvizh_objekt (){};
};
///////////////////////////////////////////////////////////////////
class asteroid: public podvizh_objekt
{
    string type = "asteroid";
protected:
    int razm = 1;
public:
     asteroid():razm(0){}
    asteroid (int razm_):razm(razm_){}
    ~asteroid ()
    {
        razm =0;
    }
    void print () const
    {
        cout<<type<<'\n';
        cout<<"Vx: " << Vx<<'\n';
        cout<<"Vy: " << Vy<<'\n';
        cout<<"Vz: " << Vz<<'\n';
        cout<<"X: "<< X<<'\n';
        cout<<"Y: "<<Y<<'\n';
        cout<<"Z: "<<Z<<'\n';
        cout<<"razm: "<<razm<<'\n';
    }
    void set_data (int X1, int Y1, int Z1, int Vx1, int Vy1, int Vz1, int razm1)
    {
        X=X1;
        Y=Y1;
        Z=Z1;
        Vx=Vx1;
        Vy=Vy1;
        Vz=Vz1;
        razm = razm1;
    }
};
///////////////////////////////////////////////////////////////////
class rocket: public podvizh_objekt
{
    string type = "rocket";
protected:
    int power =10;
    int timer =10;
public:
    rocket():power(0),timer(0){}
    rocket (int power_,int timer_):power(power_),timer(timer_){}
    ~rocket ()
    {
        power =0;
        timer=0;
    }
     void print () const
    {
        cout<<type<<'\n';
        cout<<power<<'\n';
        cout<<timer<<'\n';
        cout<<"Vx: " << Vx<<'\n';
        cout<<"Vy: " << Vy<<'\n';
        cout<<"Vz: " << Vz<<'\n';
        cout<<"X: "<< X<<'\n';
        cout<<"Y: "<<Y<<'\n';
        cout<<"Z: "<<Z<<'\n';
    }
   void set_data (int X1, int Y1, int Z1, int Vx1, int Vy1, int Vz1, int power1, int timer1)
    {
        X=X1;
        Y=Y1;
        Z=Z1;
        Vx=Vx1;
        Vy=Vy1;
        Vz=Vz1;
        power = power1;
        timer = timer1;
    }
};

///////////////////////////////////////////////////////////////////
class korab: public podvizh_objekt
{
    string type = "korab";
protected:
    int size_name;
    char* name;
    int max_speed;
    int shot;
public:
    korab ():size_name(100),shot(0),name(new char [size_name]), max_speed(0)
    {
        name[0]=0;
        strcpy(name, "interprise");
    }
    korab (int shot1, char name1 [100], int max_speed1):size_name(100),shot(shot1),name(name1), max_speed(max_speed1){}
    ~korab ()
    {
        delete [] name;
        size_name =0;
        max_speed =0;
        shot = 0;
    }

     void print () const
    {
        cout <<type<<'\n';
        cout<<name<<'\n';
        cout<<max_speed<<'\n';
        cout <<shot<<'\n';
        cout<<"Vx: " << Vx<<'\n';
        cout<<"Vy: " << Vy<<'\n';
        cout<<"Vz: " << Vz<<'\n';
        cout<<"X: "<< X<<'\n';
        cout<<"Y: "<<Y<<'\n';
        cout<<"Z: "<<Z<<'\n';
    }
    void set_data (int X1, int Y1, int Z1, int Vx1, int Vy1, int Vz1, int shot1, char name1[], int max_speed1 )
    {
        X=X1;
        Y=Y1;
        Z=Z1;
        Vx=Vx1;
        Vy=Vy1;
        Vz=Vz1;
        for (int i=0;i<100;i++)
        name[i]= name1[i];
        shot=shot1;
        max_speed=max_speed1;
    }
};
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

    void Push_back(T _simb)
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
/*class arr
{
    kosm_objekt **ar;
    int size_ar;
public:
    arr():ar(nullptr),size_ar(0){}
    arr(const arr &a): size_ar(a.size_ar), ar(new kosm_objekt*[a.size_ar])
    {
        for (int i=0;i<size_ar; i++)
            ar[i]=a.ar[i];
    }
    arr(arr &&a)
    {
        swap(size_ar, a.size_ar);
        swap(ar,a.ar);
    }
    arr& operator = (const arr &a)
    {
        if (this != &a){
        this->Delete();
        kosm_objekt **ar=new kosm_objekt*[a.size_ar];
        for (int i=0;i<size_ar; i++)
            ar[i]=a.ar[i];
        }
        return *this;
    }
    arr& operator = (arr &&a)
    {
        swap(size_ar, a.size_ar);
        swap(ar,a.ar);
        return *this;
    }
    ~arr()
    {
        delete[] ar;
        size_ar =0;
    }
    kosm_objekt* operator [](int index)
    {
        assert (index >=0 && index <size_ar);
        return ar[index];
    }
    const kosm_objekt* operator [](int index)const
    {
        assert (index >=0 && index <size_ar);
        return ar[index];
    }
    void push_back (kosm_objekt* a)
    {
        if (!size_ar)
        {
            size_ar=1;
            ar = new kosm_objekt*[size_ar];
            ar[0]=a;
            return;
        }
        size_ar++;
        kosm_objekt **br=new kosm_objekt*[size_ar];
        for (int i=0;i<size_ar-1;i++)
            br[i]=ar[i];
        br[size_ar-1]=a;
        delete[] ar;
        ar=br;
    }
    void Delete ()
    {
        delete [] ar;
        size_ar = 0;
    }
    void print() const
    {
        for (int i=0;i<size_ar;i++)
            ar[i]->print();
    }
    friend ostream& operator << (ostream& out,const arr &a)
    {
        a.print();
        cout <<'\n';
        return out;
    }
    void delete_elements (const int index)
    {
        assert (index >=0 && index < size_ar);
        kosm_objekt ** br = new kosm_objekt* [size_ar-1];
        bool same =0;
        for (int i=0;i<size_ar; i++)
        {
            if (i==index)
            {
                same =1;
                continue;
            }
            if (!same)
                br[i]=ar[i];
            else
                br[i-1]=ar[i];
        }
        delete [] ar;
        ar = br;
        }
};*/
////////////////////////////////////////////////////////////////////
int main()
{
    List <kosm_objekt&> b;
    asteroid alpha;
    korab beta;
    alpha.set_data (2,4, 5, 7,3, 1,7);
    beta.set_data(1,2,3,1,2,3,10,"sinia chaika",100);
    b.Push_back (beta);
    b.Push_back (alpha);
    b.print();
    cout << beta;
    return 0;
}
