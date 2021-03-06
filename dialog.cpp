#include "dialog.h"
#include "ui_dialog.h"

#include <limits>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog(QWidget *parent, std::vector<float> vect):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tableWidget->init(vect);
    ui->tableWidget->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}
