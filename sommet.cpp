#include "sommet.h"
#include "sommet.h"
#include "sommet.h"
#include "sommet.h"
#include <string>
#include <iostream>

/*
 * name
 * listSommet
 * listArrete
 *
 *
*/
using namespace std;
list<Sommet*> Sommet::listSommet{};

Sommet::Sommet(std::string s) : name(s),listArretes{}
{
    listArretes.get_allocator().allocate(1);
    listSommet.push_back(this);
}

void Sommet::linkTo(Sommet *s)
{
    linkTo(s,0);
}

int  Sommet::getDegree()
{
    return listArretes.size();
}

std::list<Sommet*> Sommet::getListSommet()
{
    return listSommet;
}

list<Arrete>* Sommet::getListArretes()
{
    return &listArretes;
}

list<Arrete> &Sommet::getAddrListArretes()
{
    return listArretes;
}


void Sommet::linkTo(Sommet* s,float value)
{
    if(!checkHaveArrete(s->getName()))
        addArrete(s,value);
    else
    {
        Arrete* arr=getArreteTo(s->getName());
        if(arr->getPoid()!=value)
        {
            arr->setPoid(value);
        }
    }
}

/**
 * add an arrete between this and s
*/
void Sommet::addArrete(Sommet* s,float value)
{
    this->listArretes.push_back(Arrete(this,s,value));
}


string Sommet::getName()
{
    return name;
}

string Sommet::toString()
{
    string tmp="Sommet "+name+"\n";
    tmp+=to_string(this->getDegree())+" connections\n";
    for (auto &it: listArretes)
    {
        tmp+="\tArrete "+ name + " --- "+it.getSecond()->getName()+"  poid: "+to_string(it.getPoid())+"\n";
    }
    return tmp;
}

bool Sommet::isSommet(string s)
{
    if (name.compare(s)==0)
        return true;
    return false;
}

Arrete* Sommet::getArreteTo(string s)
{
    int cpt=0;
    Arrete* som=nullptr;
    for (auto & itt : listArretes) {
        if(itt.getSecond()->getName().compare(s)==0)
        {
            som=&itt;
            break;
        }
        cpt+=1;
    }
    return som;
}

bool Sommet::checkHaveArrete(string s)
{
    if(getArreteTo(s)!=nullptr)
        return true;
    return  false;
}



