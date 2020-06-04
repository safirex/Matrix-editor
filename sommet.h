#ifndef SOMMET_H
#define SOMMET_H
#include <string>
#include <list>
#include <arrete.h>

class Sommet
{
public:

    Sommet(std::string f);
    int getDegree();
    void linkTo(std::string s);
    std::list<Sommet> getListSommet();

private :
    std::string name;

    static std::list<Sommet> listSommet;
    std::list<Arrete> listArretes;

    void addArrete(Sommet s);
};

#endif // SOMMET_H
