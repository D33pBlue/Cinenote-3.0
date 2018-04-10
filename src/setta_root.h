#ifndef SETTA_ROOT_H
#define SETTA_ROOT_H

#include <QDialog>
#include <QCompleter>
#include <QDirModel>

namespace Ui {
class setta_root;
}

class setta_root : public QDialog
{
    Q_OBJECT

public:
    explicit setta_root(QWidget *parent = 0);
    ~setta_root();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::setta_root *ui;
    QCompleter *completadir;
    //QCompleter *compl2;
    //QCompleter *compl3;
};

#endif // SETTA_ROOT_H
