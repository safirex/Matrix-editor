#include "matricetable.h"
#include <iostream>

using namespace std;



MatriceTable::MatriceTable(QWidget *parent) : QTableWidget(parent)
{
    for(int ul=0;ul<columnCount();ul++){

        string tmp=horizontalHeaderItem(ul)->text().toStdString();
        m.addSommet(tmp);
    }

}

void MatriceTable::addElement()
{

    std::cout << "Hello world!" << std::endl;
    //  ajoute element dans case ligne 0 col 1
    //    this->setItem(0,1,new QTableWidgetItem("test"));

    int i=this->rowCount();
    int p=this->columnAt(i);
    this->insertRow(i);
    this->insertColumn(i);
    this->resizeColumnsToContents();
    resizeRowsToContents();


    //setHorizontalHeaderItem(i, new QTableWidgetItem(qs));

}

void MatriceTable::removeElement()
{

}

void MatriceTable::updateModel()
{

}
