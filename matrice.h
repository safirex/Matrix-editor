#ifndef MATRICE_H
#define MATRICE_H
#include <sommet.h>
#include <string>
#include <list>
#include<sommet.h>
#include <vector>
using namespace std;
class Sommet;
class MatriceNOrientee;
class Matrice
{
public:
    enum class Type
    {
        Orientee=0,
        NonOrientee=1
    };

    enum class Ponderation
    {
        oui=1,
        non=0
    };

    Type type;
    Ponderation pondere;
     bool orientee,probabiliste,symetrique,connexe,fortementConnexe;
    int taille,ordre;

    Matrice();
    Matrice(list<string> list);
    Matrice getConnexPath();
    bool isConnex();
    bool isFortementConnex();
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
    list<Sommet> getListSommet();
    void updateValues();
    void setNextType();
    void setNextPonderation();
    string getTypeToString();
    string getPondereToString();
    virtual void linkTo(int a, int b, int value);
private:
    list<Sommet> listSommet;
    void updateTaille();
    void updateOrdre();
    void updateSymetrie();
    void updateConnexe();

    void updateFortementConnexe();
    void fillVoisin(vector<float> &DijkstraMap,Sommet & sommet,vector<Sommet*>&outList);

};

#endif // MATRICE_H
