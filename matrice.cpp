#include "matrice.h"
#include "matrice.h"
#include <sommet.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include <limits>

using namespace std;

Matrice::Matrice(std::list<std::string> list): type(Type::NonOrientee),listSommet{}
{
    listSommet.get_allocator().allocate(1);
    for(auto const& str : list )
    {
        addSommet(str);
    }
    updateValues();
}


Matrice::Matrice(): type(Type::NonOrientee),listSommet{}
{
    listSommet.get_allocator().allocate(1);
}

void Matrice::removeSommet(string s)
{
    for(auto &str : listSommet )
    {
        /*if (str.getName().compare(s)==0){
            cout << s << endl;
            listSommet.remove(str);
            break;
        }*/
    }
    updateValues();
}

void Matrice::addSommet(string s)
{
    Sommet sommet(s);
    listSommet.push_back(s);updateValues();
}

string Matrice::toString()
{
    string tmp="matrice:\n";
    for(auto &str : listSommet )
    {
        tmp+="\tSommet "+str.getName()+"\n";
    }
    return tmp;
}

void Matrice::getCalculationTab(vector<float>& tab)
{
    int i=0;
    for (auto s:listSommet)
    {
        list<Arrete>* arreteListPtr=s.getListArretes();
        for (auto  a:*arreteListPtr)
        {
            tab[i]= a.getPoid();
            i++;
        }
    }
}

//TODO: gerer vector
void Matrice::calculTransposee(vector<float>& emptyVector)
{
    vector<float> tab (ordre*ordre);
    vector<float> newtab (ordre*ordre);
    getCalculationTab(tab);
    int maxline=ordre;
    int currLine=0;
    int currCol=0;
    for (int i=0;i<(int)tab.size();i++)
    {
        currCol=i/maxline;
        currLine=i%maxline;
        // if(currLine!=currCol)
        newtab[i]=tab[currLine*maxline+currCol];
        cout<<"line "+to_string(currLine)+" col "+to_string(currCol)<<endl;

    }

    string tmp="| ";
    for (int i=0;i<ordre*ordre;i++)
    {
        tmp+=to_string(newtab[i])+" | ";
        if((i+1)%ordre==0)
            tmp+="\n| ";
    }
    cout<<tmp<<endl;
    emptyVector=newtab;
}

void Matrice::calculPowN(int n, vector<float> &emptyVector)
{
    vector<float> tab (ordre*ordre);
    vector<float> newtab (ordre*ordre);
    vector<float> tab2 (ordre*ordre);
    getCalculationTab(tab);
    newtab=tab;
    tab2=tab;
    int maxline=ordre;
    int currLine=0;
    int currCol=0;
    for (int it=1;it<n;it++)    //number of n
    {
        for (int i=0;i<(int)tab.size();i++)  //for each case of new tab
        {

            currCol=i/maxline;
            currLine=i%maxline;
            //newtab[i]=tab[]
            float tmpValue=0;   //hold the value of each multiplication of the box
            float caseValue=0;  //hold the addition of all tmpValue
            for (int tmp=0;tmp<maxline;tmp++)
            {
                tmpValue=tab[currLine+tmp*maxline];
                tmpValue=tmpValue*tab2[currCol*maxline+tmp]; //value of all box in the same line as i
                caseValue+=tmpValue;
            }
            newtab[i]=caseValue;

        }
        tab2=newtab;
        string tmp="| ";
        for (int i=0;i<ordre*ordre;i++)
        {
            tmp+=to_string(newtab[i])+" | ";
            if((i+1)%ordre==0)
                tmp+="\n| ";
        }
        cout<<tmp<<endl;


    }
    emptyVector=newtab;
}

void Matrice::calculateDijkstra(Sommet &s, vector<float> &emptyVector)
{
    updateOrdre();
    vector<float> tab (ordre*ordre);
    vector<float> newtab;
    getCalculationTab(tab);
    vector<Sommet*> outedSommetList(ordre);
    //while (newtab!=tab)
    //{
    tab=newtab;

    // first loop
    vector<float>vf(ordre,numeric_limits<float>::infinity());
    newtab=vf;
    int pos=getPosSommet(&s);
    cout<<"pos =  "+to_string(pos)<<endl;
    newtab[pos]=0.0;
    vector<Sommet*>vs;

    //all next loop
    fillVoisin(newtab,s,vs);
    //}
    cout<<"matrice be like :"<<endl;
    string tmp="| ";
    for (int i=0;i<newtab.size();i++)
    {
        tmp+=to_string(newtab[i])+" | ";
        if((i+1)%ordre==0)
            tmp+="\n| ";
    }
    cout<<tmp<<endl;
    cout<<"outta the loop"<<endl;
    emptyVector=newtab;
}


void Matrice::fillVoisin(vector<float> &DijkstraMap, Sommet & sommet, vector<Sommet *> &outList)
{
    cout<<"fill voisin point: "+sommet.getName()+"  pos: "+to_string(getPosSommet(&sommet))<<endl;
    float infValue=numeric_limits<float>::infinity();
    int lastLine=((DijkstraMap.size()/ordre)-1)*ordre;    //get to first elem of last line
    float poidSommet=DijkstraMap[lastLine+getPosSommet(sommet)];

    for(int i=lastLine;i<lastLine+ordre;i++){   //copy the last line of the weight list
        float f=DijkstraMap[i];
        DijkstraMap.push_back(f);
    }

    list<Arrete>::iterator it;
    list<Arrete>* arrList=sommet.getListArretes();

    for (it=arrList->begin();it!=arrList->end();it++)   //for each arrete of actual Sommet
    {
        //switch
        int posSommet2=getPosSommet(it->getSecond());
        float poidSommet2=DijkstraMap[lastLine+posSommet2];
        cout<<"poid distrib = "+to_string(poidSommet+it->getPoid())<<endl;
        cout<<"/tpoidsommet "+to_string(poidSommet)+"/tpoid arrete "+to_string(it->getPoid())<<endl;

        if(poidSommet2>poidSommet+it->getPoid() || poidSommet2==infValue)
        {
            if(poidSommet==0)
                continue;

            DijkstraMap[lastLine+ordre+posSommet2]=poidSommet+it->getPoid();
        }
    }


    string tmp="| ";
    for (int i=0;i<(int)DijkstraMap.size();i++)
    {
        tmp+=to_string(DijkstraMap[i])+" | ";
        if((i+1)%ordre==0)
            tmp+="\n| ";
    }
    cout<<tmp<<endl;

    outList.push_back(&sommet);
    if((int)outList.size()<ordre)
    {
        for (it=arrList->begin();it!=arrList->end();it++)   //for each arrete of actual Sommet
        {
            bool roar=true;
            for (auto somm : outList)
            {
                if(somm->getName().compare(it->getSecond()->getName())==0)
                    roar=false;
            }
            if(roar)
            {
                // v does not contain x
                fillVoisin(DijkstraMap,it->getSecondAddr(),outList);
                cout<<"Nouveau Sommet = "+it->getSecond()->getName()<<endl;
            }
        }
    }

}






void Matrice::setNextType()
{
    if(type==Type::Orientee)
        type=Type::NonOrientee;
    else if(type==Type::NonOrientee)
         type=Type::Orientee;

}
string Matrice::getTypeToString()
{
    if(type==Type::Orientee)
        return "Orientée";
    if(type==Type::NonOrientee)
        return "Non Orientée";
    return "";
}



Sommet* Matrice::getSommetNum(int i)
{
    int cpt=0;
    Sommet* som=nullptr;
    for (auto & itt : listSommet) {
        if(cpt==i)
        {
            som=&itt;
            break;
        }
        cpt+=1;
    }

    return som;
}

int Matrice::getPosSommet(Sommet *s)
{
    int i=0;
    for (auto & itt : listSommet) {

        if(itt.getName().compare(s->getName())==0)
            return i;
        i++;
    }
    return -1;
}

int Matrice::getPosSommet(Sommet &s)
{
    int i=0;
    for (auto & itt : listSommet) {

        if(itt.getName().compare(s.getName())==0)
            return i;
        i++;
    }
    return -1;
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
    ordre=listSommet.size();
}

