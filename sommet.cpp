#include "sommet.h"
#include <string>


/*
 * name
 * listSommet
 * listArrete
 *
 *
*/
static std::list<Sommet*> listSommet;


Sommet::Sommet(std::string s) : name(s)
{
    listSommet.push_back(this);
}

int  Sommet::getDegree()
{
    return listArretes.size();
}

std::list<Sommet*> Sommet::getListSommet()
{
    return listSommet;
}

void Sommet::linkTo(std::string s)
{

    for (auto somm : listSommet) {

        if(somm->name==s){
           addArrete(somm);
           break;
        }
    }
}

/**
 * add an arrete between this and s
*/
void Sommet::addArrete(Sommet* s)
{
    Arrete arr(this,s);
    listArretes.push_back(arr);

}




string Sommet::getName()
{
    return name;
}


