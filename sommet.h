#ifndef SOMMET_H
#define SOMMET_H
#include <string>
#include <list>
#include <arrete.h>
using namespace std;
class Sommet
{
public:

    Sommet(std::string f);
    int getDegree();
    void linkTo(std::string s);
    std::list<Sommet*> getListSommet();
    string getName();
private :
    std::string name;

    std::list<Arrete> listArretes;

    void addArrete(Sommet* s);
};

#endif // SOMMET_H


