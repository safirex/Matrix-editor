#ifndef MATRICE_H
#define MATRICE_H
#include <sommet.h>
#include <string>
#include <list>
#include<sommet.h>
#include <vector>
using namespace std;
class Sommet;

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
    Sommet* getSommetNum(int i);
    string toString();
    void getCalculationTab(vector<float>&);
    void calculTransposee(vector<float>& emptyVector);

private:
    list<Sommet> listSommet;
    void updateValues();
    void updateTaille();
    void updateOrdre();



};

#endif // MATRICE_H
