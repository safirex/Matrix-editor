#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <vector>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    Dialog(QWidget *parent = nullptr,std::vector<float> vect = {0,0});
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
