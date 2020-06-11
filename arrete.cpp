#include "arrete.h"

Arrete::Arrete()
{}

Arrete::Arrete(Sommet* a,Sommet* b): a(a),b(b),poid(0)
{}

Arrete::Arrete(Sommet* a,Sommet* b,int poid): a(a),b(b),poid(poid)
{}

Sommet* Arrete::getFirst()
{
    return a;
}

Sommet* Arrete::getSecond()
{
    return b;
}

void Arrete::setPoid(float value)
{
    poid=value;
}

float Arrete::getPoid()
{
    return poid;
}


