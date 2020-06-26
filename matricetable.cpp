#include "matricetable.h"
#include <iostream>
#include <math.h>
#include <qheaderview.h>
using namespace std;

//Matrice matrice;
MatriceTable::MatriceTable(QWidget *parent) : QTableWidget(parent),loaded(false), matrice()
{}


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
    loaded=true;
}




/**
 * @brief MatriceTable::init
 * used for the initialization of popup matrix table widget
 * @param matrice
 */
void MatriceTable::init(vector<float> vect)
{
    int nbSommet=sqrt (vect.size());
    for (int i=0;i<nbSommet;i++)
    {
        int s=this->rowCount();
        this->insertRow(s);
        this->insertColumn(s);
    }

    for(int c=0;c<(int)vect.size();c++)
    {
        int line=c/nbSommet,column=c%nbSommet;
        char ch[10];
        string str=typesetCellValue(vect[c]);
        if(vect[c]==INFINITY)
            str="Inf";
        //sprintf(ch,"%f", vect[c]);
        strcpy(ch,str.c_str());
        setItem(line,column,new QTableWidgetItem(ch));
    }
}

Matrice MatriceTable::getMatrice()
{
    return matrice;
}

Matrice* MatriceTable::getMatriceAddr()
{
    return &matrice;
}

void MatriceTable::displayRefresh()
{
    cout<<"la matrice est : "+matrice.getPondereToString()<<endl;

    vector<float> vf(matrice.ordre*matrice.ordre);
    matrice.getCalculationTab(vf);
    int nbSomm=sqrt(vf.size());
    for(int i=0;i<(int)vf.size();i++)
    {
        string strg=typesetCellValue(vf[i]);
        QTableWidgetItem* obj=item(i/nbSomm,i%nbSomm);


        QString qst=obj->text();
        string qs=qst.toStdString();

        if(qs.compare(strg)!=0)
            obj->setText(strg.c_str());
        //setItem(i/nbSomm,i%nbSomm,new QTableWidgetItem(strg.c_str()));
    }
}

void MatriceTable::updateTypeSetCell(int line, int column)
{


    float f=getValueCell(line,column);

    string strg=to_string(f);

    strg=typesetCellValue(f);
    cout<<"typesetted string = "+strg<<endl;

    setItem(line,column,new QTableWidgetItem(strg.c_str()));
}

void MatriceTable::setMatrice(Matrice m)
{
    matrice=m;
}

void MatriceTable::setNextMatrice()
{
    vector<float> vf;
    matrice.getCalculationTab(vf);
    Matrice * mat=&matrice;
    Matrice newMat;
    if (dynamic_cast<MatriceNOrientee*>(mat) != nullptr) {
      // mat instance of MNO

    } else {
         // mat not instance of MNO
        newMat= MatriceNOrientee(vf);
    }

    setMatrice(newMat);
}



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

    matrice.updateValues();


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

    if(matrice.pondere==Matrice::Ponderation::non)
         if(v!=0)
             v=1;
    matrice.linkTo(a,b,v);
    //string tmpstr=horizontalHeaderItem(b)->text().toStdString();
    matrice.updateValues();
    cout<<"connexe : "+to_string(matrice.isConnex())<<endl;

}


/**
 * @brief change the value of the cell in UI and in the code
 */
void MatriceTable::modificateValue(int line, int column,float f)
{
    string strg=to_string(f);
    char c[20];

    //sprintf(c,"%f", str);

    strg=typesetCellValue(f);
    cout<<"typesetted string = "+strg<<endl;
    strcpy(c,strg.c_str());

    setItem(line,column,new QTableWidgetItem(c));
    updateSommet(line,column);
}

/**
 * @brief only change the UI look of the matrix, (not modifying the matrix itself)
 */
void MatriceTable::changeValueCell(int line, int column,float f)
{
    string strg=to_string(f);
    char c[20];
    strg=typesetCellValue(f);
    cout<<"typesetted string = "+strg<<endl;
    strcpy(c,strg.c_str());
    setItem(line,column,new QTableWidgetItem(c));
}

//met la valeur en int
string MatriceTable::typesetCellValue(float f)
{
    int i=0;

    /*if (matrice.type==Matrice::Type::NonOrientee)
        i=f;
        return to_string(i);
    */
    if(matrice.pondere==Matrice::Ponderation::non)
    {
        i=f;
        if(i!=0)
            i=1;
        return to_string(i);
    }
    return to_string((int)f);

}



float MatriceTable::getValueCell(int line, int column)
{
    string val=item(line,column)->text().toStdString();
    float tmp=stof(val);
    return tmp;
}

