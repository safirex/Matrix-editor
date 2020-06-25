#include "dropdownbutton.h"
#include <qmenu.h>
DropDownButton::DropDownButton(QWidget *parent) : QToolButton(parent)
{}

void DropDownButton::init(Matrice* mat)
{

    this->matrice=mat;

    QMenu *menu=new QMenu ;
    for(auto it : matrice->getListSommet())
    {
        QString qs;
        qs=qs.fromStdString(it.getName());


        menu->addAction(qs);
    }

    setMenu(menu);
}

void DropDownButton::dropdown()
{
    QMenu *menu=new QMenu ;
    for(auto it : matrice->getListSommet())
    {
        QString qs;
        string text=it.getName();
        qs=qs.fromStdString(text);

        QAction* qa=new QAction(qs);
        qa->setText(qs);
        QObject::connect(qa,SIGNAL(triggered()),this,SLOT(setButtonText(qs)));
        menu->addAction(qs);
    }
    setMenu(menu);
}

void DropDownButton::setButtonText(QString s)
{
    setText(s);
}

