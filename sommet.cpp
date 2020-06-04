#include "sommet.h"
#include <string>


/*
 * name
 * listSommet
 * listArrete
 *
 *
*/


Sommet::Sommet(std::string s) : name(s)
{}

int  Sommet::getDegree()
{
    return listArretes.size();
}

std::list<Sommet> Sommet::getListSommet()
{
    return listSommet;
}

void Sommet::linkTo(std::string s)
{
    for (auto const& somm : listSommet) {
        if(somm.name==s){
           addArrete(somm);
           break;
        }
    }
}

/**
 * add an arrete between this and s
*/
void Sommet::addArrete(Sommet s)
{
    Arrete arr(this,&s);
    listArretes.push_back(arr);

}
