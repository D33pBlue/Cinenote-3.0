#ifndef SX_LIBRI_CRONOLOGIA_H
#define SX_LIBRI_CRONOLOGIA_H

#include <QWidget>
#include <QtSql>
#include <QVector>
#include <QtWidgets>

namespace Ui {
class sx_libri_cronologia;
}

class sx_libri_cronologia : public QWidget
{
    Q_OBJECT

public:
    explicit sx_libri_cronologia(QWidget *parent = 0);
    ~sx_libri_cronologia();

private:
    Ui::sx_libri_cronologia *ui;
    QVector<QTableWidgetItem*>ele;
private slots:
    void vedilib(int r,int c);
};

#endif // SX_LIBRI_CRONOLOGIA_H
