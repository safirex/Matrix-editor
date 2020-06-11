#ifndef ARRETE_H
#define ARRETE_H
#include <list>
#include <map>

class Sommet;
using namespace std;

class Arrete
{
public:
    Arrete();
    Arrete(Sommet *a,Sommet *b);
    Arrete(Sommet *a, Sommet *b, int poid);
    Sommet* getFirst();
    Sommet* getSecond();
    string toString();

    void setPoid(float value);
    float getPoid();
private:
    Sommet *a,*b;
    float poid;
};

#endif // ARRETE_H
