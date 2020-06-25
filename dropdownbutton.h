#ifndef DROPDOWNBUTTON_H
#define DROPDOWNBUTTON_H

#include <QWidget>
#include <qtoolbutton.h>
#include <matrice.h>
class DropDownButton :public QToolButton
{
    Q_OBJECT
public:
    explicit DropDownButton(QWidget *parent = nullptr);
    void init(Matrice* matrice);
public slots:
    void dropdown();
    void setButtonText(QString s);
private:
    Matrice* matrice;
signals:

};

#endif // DROPDOWNBUTTON_H
