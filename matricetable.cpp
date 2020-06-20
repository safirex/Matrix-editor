#include "matricetable.h"
#include <iostream>
#include <math.h>
using namespace std;


//Matrice m;
MatriceTable::MatriceTable(QWidget *parent) : QTableWidget(parent), matrice()
{




}


void MatriceTable::init()
{
    //create every Sommet already present

    for(int ul=0;ul<columnCount();ul++){
        string tmp=horizontalHeaderItem(ul)->text().toStdString();
        matrice.addSommet(tmp);
    }


    //for every item, set it to 0 and create the Sommet link
    for(int ul=0;ul<columnCount();ul++)
    {
        for (int li=0;li<rowCount();li++)
        {
            changeValueCell(li,ul,0);
        }
    }
}




/**
 * @brief MatriceTable::init
 * used for the initialization of popup matrix table widget
 * @param matrice
 */
void MatriceTable::init(vector<float> vect)
{
    cout<<"inited with vector"<<endl;
    int nbSommet=sqrt (vect.size());
    for (int i=0;i<nbSommet;i++)
    {
        int s=this->rowCount();
        this->insertRow(s);
        this->insertColumn(s);
    }

    for(int c=0;c<(int)vect.size();c++)
    {
        cout<< "round "+to_string(c)+" line "+to_string(c%nbSommet)+" col "+to_string(c/nbSommet)<<endl;
        cout<<to_string(c) +" " +to_string(vect[c])<<endl;
        int line=c/nbSommet,column=c%nbSommet;
        char ch[10];
        sprintf(ch,"%f", vect[c]);
        setItem(line,column,new QTableWidgetItem(ch));

    }
}

Matrice MatriceTable::getMatrice()
{
    return matrice;
}



#include <qheaderview.h>
void MatriceTable::addElement()
{
    //  ajoute element dans case ligne 0 col 1
    //    this->setItem(0,1,new QTableWidgetItem("test"));

    int i=this->rowCount();
   // int p=this->columnAt(i);
    this->insertRow(i);
    this->insertColumn(i);



    //add the sommet to the matrix
    string tmpstr= to_string(i+1);
    matrice.addSommet(tmpstr);
    QString qs;
    qs=qs.fromStdString(tmpstr);

   // setVerticalHeaderItem(i+1, new QTableWidgetItem(qs));
   // setHorizontalHeaderItem(i+1, new QTableWidgetItem(qs));
    cout<<matrice.toString()<<endl;



    //fill the new created items
    for(int line=0;line<i;line++)
    {
        changeValueCell(line,i,0.0);
    }
    for(int col=0;col<i;col++)
    {
        changeValueCell(i,col,0);
    }


    changeValueCell(i,i,0);
}

void MatriceTable::removeElement()
{

}



/**
 * @brief linked to the UI table and run whenever a cell is changed,
 * will change the links of Sommet a and Sommet b
 *
 * @param a line of the cell
 * @param b col of the cell
 */
void MatriceTable::updateSommet(int a, int b)
{
    float v=getValueCell(a,b);
    cout<< "valeur lien = "+to_string(v)<<endl;

    Sommet* col=matrice.getSommetNum(b);
    Sommet* line=matrice.getSommetNum(a);
    line->linkTo(col,v);
    cout<< line->toString()<<endl;
    //string tmpstr=horizontalHeaderItem(b)->text().toStdString();
}



void MatriceTable::changeValueCell(int line, int column,float str)
{
    char c[10];
    sprintf(c,"%f", str);
    setItem(line,column,new QTableWidgetItem(c));
    updateSommet(line,column);

    resizeColumnsToContents();
    resizeRowsToContents();
}

float MatriceTable::getValueCell(int line, int column)
{
    string val=item(line,column)->text().toStdString();
    float tmp=stof(val);
    return tmp;
}

