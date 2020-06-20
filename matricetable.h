#ifndef MATRICETABLE_H
#define MATRICETABLE_H
#include <QTableWidget>
#include <matrice.h>
#include <vector>
#include <dialog.h>
using namespace std;

class MatriceTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit MatriceTable(QWidget *parent =0);
    void changeValueCell(int line, int column,float str);
    float getValueCell(int line,int column);
    void updateModel();
    void init();
    void init(vector<float> matrice);
    Matrice getMatrice();

public slots:
    void addElement();
    void removeElement();
    void updateSommet(int line,int column);

private :
    Matrice matrice;

signals:
    void focusLost();
};

#endif // MATRICETABLE_H
