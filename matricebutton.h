#ifndef MATRICEBUTTON_H
#define MATRICEBUTTON_H

#include <QPushButton>

class MatriceButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MatriceButton(QWidget *parent = nullptr);

public slots:
    void updateButton();

signals:

};

#endif // MATRICEBUTTON_H
