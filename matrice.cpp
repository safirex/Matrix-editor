#include "matrice.h"


Matrice::Matrice(std::list<std::string> list)
{
    for(auto const& str : list )
    {
        Sommet s(str);
        listSommet.push_back(s);
    }
    updateValues();
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
