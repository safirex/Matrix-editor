#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <matrice.h>
#include <matricebutton.h>
#include <matricetable.h>
#include <sommet.h>
#include <arrete.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
