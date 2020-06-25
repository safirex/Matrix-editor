#ifndef GRAPHICVIEW_H
#define GRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <matricetable.h>
#include <matrice.h>

#include <QGraphicsTextItem>

class GraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    MatriceTable* table;
    QGraphicsScene* scene;
    explicit GraphicView(QWidget *parent = nullptr);
    void setTab(MatriceTable* tab);
    void drawSommet(int x,int y,string str);
    void drawArrete(int sommet1,int sommet2,bool orientee,float value);
public slots:
    void updateDisplay();

signals:

};

#endif // GRAPHICVIEW_H
