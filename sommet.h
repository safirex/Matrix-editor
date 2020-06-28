#ifndef SOMMET_H
#define SOMMET_H
#include <string>
#include <list>
#include <arrete.h>
using namespace std;
class Sommet
{
public:
    Sommet ();
    Sommet(std::string f);
    void linkTo(std::string s);
    void linkTo(Sommet* s);
    void linkTo(Sommet* s,float value);
    std::list<Sommet*> getListSommet();
    list<Arrete>* getListArretes();
    list<Arrete>& getAddrListArretes();

    string toString();
    bool isSommet(string s);
    void addArrete(Sommet* s, float value);
    bool checkHaveArrete(string s);
    int getDegree();
    string getName();
    Arrete* getArreteTo(string s);
private :
    std::string name;
    std::list<Arrete> listArretes;
    static std::list<Sommet*> listSommet;
};

#endif // SOMMET_H


