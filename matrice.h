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
    enum class Type
    {
        Orientee=0,
        NonOrientee=1

    };

    Type type;
     bool orientee,probabiliste,symetrique;
    int taille,ordre;

    Matrice();
    Matrice(list<string> list);
     Matrice getConnexPath();
    bool isConnex();
    void removeSommet(string s);
    void addSommet(string s);
    Sommet* getSommetNum(int i);
    string toString();
    void getCalculationTab(vector<float>&);
    void calculTransposee(vector<float>& emptyVector);
    void calculPowN(int n,vector<float>& emptyVector);
    void calculateDijkstra(Sommet& s,vector<float>& emptyVector);
    int getPosSommet(Sommet* s);
    int getPosSommet(Sommet& s);

    void setNextType();
    string getTypeToString();
private:
    list<Sommet> listSommet;
    void updateValues();
    void updateTaille();
    void updateOrdre();
    void fillVoisin(vector<float> &DijkstraMap,Sommet & sommet,vector<Sommet*>&outList);

};

#endif // MATRICE_H
