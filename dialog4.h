#ifndef DIALOG4_H
#define DIALOG4_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QPushButton>
#include<QStyledItemDelegate>
#include <QDate>
#include <QItemDelegate>
#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include <QtWidgets>
#include <QDialog>


namespace Ui {
class Dialog4;
}

class Dialog4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = nullptr);
   ~Dialog4();
    QStringList list;
    int row_index;
private:
    Ui::Dialog4 *ui;
    QStandardItemModel *model;
    int pack;
    QString IP_MC;
    QString cmd;


private slots:
    void changeWidget(int index);
    void on_pushButton_cansel_clicked();
    void  on_pushButton_ok_clicked();
    void on_m_pOk_clicked();
};

#endif // DIALOG4_H
