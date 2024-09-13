#ifndef DIALOG1_H
#define DIALOG1_H

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
#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private:
    Ui::Dialog1 *ui;
    QStackedWidget *stackedWidget;
    QSpinBox *SpinB;
    QComboBox *comboBox2;
    QLabel *label2;
    QLabel *label3;
   QComboBox *comboBox3;
   QLabel * label_4;
    QWidget *page_udp();
    QWidget *page_igmp();

private Q_SLOTS:
    void changeWidget(int index);

};

#endif // DIALOG1_H
