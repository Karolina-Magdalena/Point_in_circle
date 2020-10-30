#include <iostream>
#include <math.h>

using namespace std;

int a;
float odcinek;

class Kolo;

class Punkt
{
   float x,y;

public:
    Punkt(float=0, float=0);
    void wczytaj();

    friend float odleglosc (Punkt &pkt, Kolo &k);
};

class Kolo
{
    float x,y,r;

public:
    Kolo(float=0,float=0,float=1);
    void wczytaj();

    friend void sedzia (float &o, Kolo &k);
    friend float odleglosc (Punkt &pkt, Kolo &k);
};

Punkt::Punkt(float xx, float yy)
{
    x=xx;
    y=yy;
}

void Punkt::wczytaj()
{
    cin>>x>>y;
}

Kolo::Kolo(float xx, float yy, float zz)
{
   x=xx;
   y=yy;
   r=zz;
}

void Kolo::wczytaj()
{
    cin>>x>>y>>r;
}

float odleglosc (Punkt &pkt, Kolo &k)
{
    odcinek=sqrt(pow(k.x-pkt.x,2)+pow(k.y-pkt.y,2));
    return odcinek;
}

void sedzia (float &o, Kolo &k)
{
    o=odcinek;
    if (odcinek>k.r) cout<<"O"<<endl;
    if (odcinek==k.r) cout<<"E"<<endl;
    if (odcinek<k.r) cout<<"I"<<endl;
}

int main()
{
    Kolo k1;
    k1.wczytaj();
    cin>>a;
    Punkt *pkt;
    pkt = new Punkt [a];
    for (int i=0;i<a;i++)
    {
        pkt[i].wczytaj();
        odleglosc(pkt[i],k1);
        sedzia(odcinek,k1);
    }

    return 0;
}
