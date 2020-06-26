#include "graphicview.h"
#include <math.h>
#include <iostream>
#define PI 3.141592
GraphicView::GraphicView(QWidget *parent) : QGraphicsView(parent),scene()
{}

void GraphicView::setTab(MatriceTable *tab)
{
    table=tab;

}

void GraphicView::drawSommet(int x, int y, string str)
{
    x=x-15; //offset to get in x y in the center
    y=y-15;

    QBrush brush(Qt::lightGray);
    QPen pen(Qt::black);
    pen.setWidth(5);
    QRect rect(x,y,30,30);
    scene->addEllipse(rect,pen,brush);

    QString qs=qs.fromStdString(str);
    QGraphicsTextItem *text = scene->addText(qs);
    text->setPos(x+5,y+5);
    cout<<"drawn at "<<x<<"  "<<y<<endl;
}

void GraphicView::drawArrete(int sommet1, int sommet2, bool orientee, float value)
{
    int nbSommet=table->getMatrice().getListSommet().size();


    int x1=100*cos(sommet1*PI*2/nbSommet);
    int y1=100*sin(sommet1*PI*2/nbSommet);

    int x2=100*cos(sommet2*PI*2/nbSommet);
    int y2=100*sin(sommet2*PI*2/nbSommet);

    QPen pen(Qt::black);
    pen.setWidth(5);

    scene->addLine(x1,y1,x2,y2,pen);
    cout<<"line drawn from "<<sommet1 <<" to "<<sommet2<<endl;
    cout<<sommet1 << " is at "<<x1<<" "<<y1<<endl;
    cout<<sommet2 << " is at "<<x2<<" "<<y2<<endl;
    cout<<nbSommet<<endl;
}


void GraphicView::updateDisplay()
{
    cout<<"display updated"<<endl;
    Matrice matrice=table->getMatrice();
    vector<float> vf(matrice.ordre*matrice.ordre);
    matrice.getCalculationTab(vf);
    scene=new QGraphicsScene(this);
    QBrush redbrush(Qt::red);
    QPen pen(Qt::black);
    pen.setWidth(5);
   // scene->addText("roar");
    //scene->addEllipse(10,10,30,30,pen,redbrush);
    cout<<"taille de la matrice "<<sqrt(vf.size())<<endl;
    int nbSommet=sqrt(vf.size());

    for(int i=0;i<vf.size();i++)
    {
        if(vf[i]!=0)
        {
            int line=i/nbSommet;
            int column=i%nbSommet;
            drawArrete(line,column,false,vf[i]);
        }
    }

    for(int i=0;i<(int)matrice.getListSommet().size();i++)
    {
        int x=100*cos(i*PI*2/nbSommet);
        int y=100*sin(i*PI*2/nbSommet);
        drawSommet(x,y,to_string(i+1));
    }

    setScene(scene);
    show();
}




