#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,tableLoaded(false)
{
    ui->setupUi(this);
    ui->tableWidget->init();
    ui->toolButton->init(ui->tableWidget->getMatriceAddr());
    ui->graphicsView->setTab(ui->tableWidget);
    ui->graphicsView->updateDisplay();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInfoContent()
{
    //Ordre Label
    Matrice matrice=ui->tableWidget->getMatrice();
    QString qs;
    cout<<"label to "+to_string(matrice.ordre)<<endl;
    qs=qs.fromStdString(to_string(matrice.ordre));
    ui->label_Ordre->setText(qs);


    QString symetrie;
    if(matrice.type==Matrice::Type::NonOrientee)
        symetrie=symetrie.fromStdString("oui");
    ui->label_Symetrie->setText(symetrie);


    QString connexe;
    if(matrice.isConnex())
        connexe=connexe.fromStdString("oui");
    else
        connexe=connexe.fromStdString("non");
    ui->label_Connexe->setText(connexe);

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
    ui->tableWidget->displayRefresh();
}

void MainWindow::on_pushButton_Ponderation_clicked()
{
    Matrice* matrice =ui->tableWidget->getMatriceAddr();
    matrice->setNextPonderation();
    char ch[30];
    strcpy(ch,matrice->getPondereToString().c_str());
    QString qs(ch);
    ui->pushButton_Ponderation->setText(qs);

   // ui->tableWidget->setNextMatrice();



    ui->tableWidget->displayRefresh();
}


void MainWindow::on_pushButton_Dijkstra_clicked()
{
    Matrice matrice=ui->tableWidget->getMatrice();
    vector<float> tab (matrice.ordre*matrice.ordre);
    //int n=ui->factorNSpinBox->value();

    Sommet* s =matrice.getSommetNum(1);
    cout<<s->getName()+" pos = "+to_string(matrice.getPosSommet(s))<<endl;
    matrice.calculateDijkstra(*s,tab);
    cout<<"still ok"<<endl;
    Dialog dial(nullptr,tab);
    dial.setModal(true);
    dial.exec();
}




void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    ui->tableWidget-> resizeColumnsToContents();
     ui->tableWidget-> resizeRowsToContents();
}
