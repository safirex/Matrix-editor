#ifndef MATRICETABLE_H
#define MATRICETABLE_H
#include <QTableWidget>
#include <matrice.h>

class MatriceTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit MatriceTable(QWidget *parent =0);

public slots:
    void addElement();
    void removeElement();
    void updateModel();
private :
    Matrice m;
signals:

};

#endif // MATRICETABLE_H
