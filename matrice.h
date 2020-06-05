#ifndef MATRICE_H
#define MATRICE_H
#include <sommet.h>
#include <string>
#include <list>
using namespace std;
class Matrice
{
public:
     bool orientee,probabiliste,symetrique;
    int taille,ordre;

    Matrice();
    Matrice(list<string> list);
    Matrice calculateDijkstra();
    Matrice calculatePowN();
    Matrice getConnexPath();
    bool isConnex();
    void removeSommet(string s);
    void addSommet(string s);
private:
    std::list<Sommet> listSommet;
    void updateValues();
    void updateTaille();
    void updateOrdre();



};

#endif // MATRICE_H
