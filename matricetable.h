#ifndef MATRICETABLE_H
#define MATRICETABLE_H
#include <QTableWidget>
#include <matrice.h>
#include <vector>
#include <dialog.h>
#include <matricenorientee.h>
using namespace std;

class MatriceTable : public QTableWidget
{
    Q_OBJECT
public:
    bool loaded;
    explicit MatriceTable(QWidget *parent =0);
    void changeValueCell(int line, int column,float str);
    float getValueCell(int line,int column);
    void updateModel();
    void init();
    void init(vector<float> matrice);
    Matrice getMatrice();
    Matrice* getMatriceAddr();
    void displayRefresh();
    void updateTypeSetCell(int line,int column);
    void setMatrice(Matrice m);
    void setNextMatrice();
    void modificateValue(int line,int column,float f);

public slots:
    void addElement();
    void removeElement();
    void updateSommet(int line,int column);

private :
    Matrice matrice;
    string typesetCellValue(float f);

signals:
    void focusLost();
};

#endif // MATRICETABLE_H
