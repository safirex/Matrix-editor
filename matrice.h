#ifndef MATRICE_H
#define MATRICE_H
#include <sommet.h>
#include <string>
#include <list>

class Matrice
{
public:
     bool orientee,probabiliste,symetrique;
    int taille,ordre;
    Matrice(std::list<std::string> list);
    Matrice calculateDijkstra();
    Matrice calculatePowN();
    Matrice getConnexPath();
    bool isConnex();

private:
    std::list<Sommet> listSommet;
    void updateValues();
    void updateTaille();
    void updateOrdre();



};

#endif // MATRICE_H
