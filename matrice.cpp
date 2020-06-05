#include "matrice.h"


Matrice::Matrice(std::list<std::string> list)
{
    listSommet.assign(1);
    for(auto const& str : list )
    {
        addSommet(str);
    }
    updateValues();
}


Matrice::Matrice()
{
    listSommet.get_allocator().allocate(1);
}

void Matrice::removeSommet(string s)
{
    for(auto str : listSommet )
    {
        if (str.getName()==s){
            listSommet.remove(str);
            break;
        }
    }
    updateValues();
}

void Matrice::addSommet(string s)
{
    listSommet.get_allocator().allocate(1);
    Sommet sommet(s);
    listSommet.push_back(s);

}









void Matrice::updateValues()
{
    updateTaille();
    updateOrdre();
}

void Matrice::updateTaille()
{

}

void Matrice::updateOrdre()
{

}
