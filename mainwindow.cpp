#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    Matrice matrice=ui->tableWidget->getMatrice();
    vector<float> tab (matrice.ordre*matrice.ordre);
    matrice.calculTransposee(tab);
     Dialog dial(nullptr,tab);
    dial.setModal(true);
    dial.exec();
}

void MainWindow::on_pushButton_clicked()
{
    Matrice matrice=ui->tableWidget->getMatrice();
    vector<float> tab (matrice.ordre*matrice.ordre);
    int n=ui->factorNSpinBox->value();
    matrice.calculPowN(n,tab);
    Dialog dial(nullptr,tab);
    dial.setModal(true);
    dial.exec();
}
