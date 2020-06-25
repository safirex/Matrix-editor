#include "matricenorientee.h"
#include <vector>
#include <math.h>
using namespace std;


MatriceNOrientee::MatriceNOrientee(vector<float> vf ):super()
{
    int len=vf.size();
    int nbSommet=sqrt(len);
    for(int i=0;i<nbSommet;i++)
    {
        addSommet(to_string(i));
    }

    for(int i=nbSommet;i>0;i--)
    {
        for (int l=i;l<nbSommet;l++)
        {
            linkTo(i,l,vf[i,l]);
        }
    }

    updateValues();
}

void MatriceNOrientee::linkTo(int a, int b, int value)
{
    Sommet* s1=getSommetNum(a);
    Sommet* s2=getSommetNum(b);
    if(value!=0)
        value=1;
    s2->linkTo(s1,value);
    s1->linkTo(s2,value);
}




