#ifndef ARRETE_H
#define ARRETE_H
#include <list>
#include <map>

class Sommet;


class Arrete
{
public:
    Arrete();
    Arrete(Sommet *a,Sommet *b);
private:
    Sommet *a,*b;
};

#endif // ARRETE_H
