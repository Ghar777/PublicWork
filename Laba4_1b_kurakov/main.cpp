#include <iostream>

using namespace std;

class kosm_objekt
{
protected:
    int X =1;
    int Y =1;
    int Z =1;
public:
    virtual void print () = 0;

};
/////////////////////////////////////////////////////////////////

class planet: public kosm_objekt
{
    string type = "planet";
protected:
    int temp = 22;
    string nazv = "classik";
    bool poverhnost = 1;
public:
    void print ()
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
        nazv = nazv1;
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
};
///////////////////////////////////////////////////////////////////
class asteroid: public podvizh_objekt
{
    string type = "asteroid";
protected:
    int razm = 1;
public:
    void print ()
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
     void print ()
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
    char name[100] {'s','i','n','i','a',' ','c','h','a','i','k','a'};
    int max_speed = 100;
    int shot = 10;
public:
   // korab (int X1, int Y1, int Z1, int Vx1, int Vy1, int Vz1, int shot1, char name1 [100], int max_speed1):X(X1),Y(Y1),Z(Z1),Vx(Vx1),Vy(Vy1),Vz(Vz1), for (int i=0;i<100;i++) name[i](name1[i]),shot(shot1), max_speed(max_speed1){}
     void print ()
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
    void set_data (int X1, int Y1, int Z1, int Vx1, int Vy1, int Vz1, int shot1, char name1 [100], int max_speed1 )
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

////////////////////////////////////////////////////////////////////
int main()
{
    korab alpha;
    //alpha.set_data(1,2,3,1,2,3,5,"Alpha",100);
    //alpha.print();
    kosm_objekt *obj [4];
    obj[0]=&alpha;
    obj[1]= new asteroid;
    obj[2]= new rocket;
    obj [3] = new planet;
    for (int i=0;i<4;i++){
        obj[i]->print();
        cout <<'\n'<<"/////////////////////////////////////////////////////////////////////////"<<'\n'<<'\n';
    }
    return 0;
}
