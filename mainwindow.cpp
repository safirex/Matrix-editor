#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
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

void MainWindow::on_typeChangeButton_clicked()
{

   Matrice* matrice =ui->tableWidget->getMatriceAddr();
    matrice->setNextType();
    char ch[30];
    strcpy(ch,matrice->getTypeToString().c_str());
    QString qs(ch);
    ui->typeChangeButton->setText(qs);
}

void MainWindow::on_pushButton_4_clicked()
{
    Matrice matrice=ui->tableWidget->getMatrice();
    vector<float> tab (matrice.ordre*matrice.ordre);
    int n=ui->factorNSpinBox->value();

   // Sommet* s=matrice.getSommetNum(2);
    Sommet* s =matrice.getSommetNum(1);
    cout<<s->getName()+" pos = "+to_string(matrice.getPosSommet(s))<<endl;
    matrice.calculateDijkstra(*s,tab);
    cout<<"still ok"<<endl;
    Dialog dial(nullptr,tab);
    dial.setModal(true);
    dial.exec();
}
