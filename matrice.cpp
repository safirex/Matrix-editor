#include "matrice.h"
#include "matrice.h"
#include <sommet.h>
#include <iostream>
#include <vector>
using namespace std;

Matrice::Matrice(std::list<std::string> list):listSommet{}
{
    listSommet.get_allocator().allocate(1);
    for(auto const& str : list )
    {
        addSommet(str);
    }
    updateValues();
}


Matrice::Matrice():listSommet{}
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
    for (int i=0;i<tab.size();i++)
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
        for (int i=0;i<tab.size();i++)  //for each case of new tab
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
