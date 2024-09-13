#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtitanDBGrid.h>
#include<QtitanGrid.h>
#include<QtitanRibbon.h>
#include<QtitanBase.h>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include<DevMachines/QtitanGrid>
#include <QTableView>
#include <QItemDelegate>
#include <QPushButton>
#include<QStyledItemDelegate>
#include <QDate>
#include <QItemDelegate>
#include <QApplication>
#include <QTableView>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

#include <QtGui>
#include <QMessageBox>
#include <QVariant>
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void table(int rows,int columns, int num_packet, std::string sender);
    void read_js();

    public slots:
    void cellButtonClicked(CellButtonClickEventArgs* args);
    void showTable();



private slots:
    void on_Button_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    Qtitan::Grid* m_grid;

    Qtitan::Grid* grid_2;
    GridTableView* view_2;
    QJsonDocument doc;


};

#endif // MAINWINDOW_H
