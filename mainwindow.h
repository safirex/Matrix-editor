#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <matrice.h>
#include <matricetable.h>
#include <sommet.h>
#include <arrete.h>
#include <dialog.h>
#include <qtoolbutton.h>
#include <graphicview.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:

    void updateInfoContent();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_typeChangeButton_clicked();

    void on_pushButton_Dijkstra_clicked();


    void on_pushButton_Ponderation_clicked();

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
    bool tableLoaded;
};
#endif // MAINWINDOW_H
