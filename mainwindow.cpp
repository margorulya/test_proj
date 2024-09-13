 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog4.h"
#include "ui_dialog4.h"

#include<iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    read_js();
    ui->grid->hide();

    //QSpacerItem *verticallSpacer;
    //verticallSpacer = new QSpacerItem(10,ui->groupBox->height()-ui->comboBox->height(),QSizePolicy::Expanding,QSizePolicy::Expanding);
   // ui->verticalLayout_3->addStretch();


    /*-----------------------------------------------------------------*/
    GridTableView* view =ui->m_grid->view<GridTableView>();

    model = new QStandardItemModel(10, 5); //С каждой ячейкой таблицы ассоциируется определенный объект QStandardItem, который передается в метод в качестве последнего параметра.
                                          //В конструктор класса QStandardItem можно передать непосредственно его содержимое в виде объекта QString

    model->setHorizontalHeaderLabels(QStringList() << "Объект" << "IP" << "Статус"<<" Текущая задача"<<"Настройка"<<"Очистка");//простые текстовые заголовки для столбцов и строк
    model->setItem(0, 0, new QStandardItem("29/2"));
    model->setItem(1, 0, new QStandardItem("29/3"));
    model->setItem(2, 0, new QStandardItem("29/4"));

    model->setItem(0, 1, new QStandardItem(doc.object().value("29/2").toString()));
    model->setItem(1, 1, new QStandardItem(doc.object().value("29/3").toString()));
    model->setItem(2, 1, new QStandardItem(doc.object().value("29/4").toString()));

    model->setItem(0, 2, new QStandardItem("подключен"));
    model->setItem(0, 3, new QStandardItem("название выполняемой задачи"));

    view->setModel(model);


    view->options().setRowAutoHeight(true); //Установка автоматической высоты
    view->options().setNewRowPlace(Qtitan::AtBeginning);
   // view->options().setNewRowHighlightEffect(Qtitan::AlphaEffect); //Sets the effect of highlighting for the gird row
    view->options().setSupportedDropActions(Qt::CopyAction); //Sets the supported drop actions for the grid view.
  //  view->options().setModelItemsDragEnabled(true);//Sets the location to place of a special line for creating and editing the new row of the grid.
    view->options().setColumnAutoWidth(true);
    view->options().setMainMenuDisabled(true);

  //  Qtitan::GridCardColumn* column2 = (Qtitan::GridCardColumn *)view->getColumn(3);
  //  column2->setDefaultGroupSummary(GridSummary::Count);
 //   column2 = (Qtitan::GridCardColumn *)view->getColumn(3);


    /*-----------------------------------------------------------------*/
    //ui->comboBox->addItem("Тест 20:20:20 15.08.2024");
   // ui->comboBox->addItem("Тест 17:20:20 15.08.2024");
   // ui->comboBox->setCurrentIndex(-1);

    table(8,5,5,"ff"); // заполнение таблицы для отчета....


    Qtitan::GridTableColumn* column = (Qtitan::GridTableColumn *)view->getColumn(4);

    Qtitan::GridTableColumn* column1 = (Qtitan::GridTableColumn *)view->getColumn(5);
    column1->addButton(GridColumn::ClearButtonIcon, Qtitan::AtEnd,GridColumn::MouseOverPolicy);
    //Add cell button to the column.
    column->addButton(GridColumn::ChoiceButtonIcon, Qtitan::AtBeginning);
    connect(column, SIGNAL(buttonClicked(CellButtonClickEventArgs*)), this, SLOT(cellButtonClicked(CellButtonClickEventArgs*)));
    //connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::showTable);
    //сегодня уже ничего делать не хочу лучше потренируюсь на скоропечатанье

}

void MainWindow::showTable()
{
  // if(ui->comboBox->currentIndex()!=-1)
   // {
   //  ui->grid->show();
   //  ui->verticalLayout_3->removeItem(ui->verticalLayout_3->itemAt(ui->verticalLayout_3->count() - 1));
    // ui->verticalLayout_3->addStretch();


}
 void  MainWindow:: table(int rows,int columns, int num_packet, std::string sender)
 {
     view_2 =ui->grid->view<GridTableView>();
     QStandardItemModel *model;
     model = new QStandardItemModel(rows, columns);
     model->setHorizontalHeaderLabels(QStringList() << "    " << "Кол-во пакетов отправлено" << "Принято"<<" IP Multicast"<<"Тест");
     model->setItem(0, 0, new QStandardItem("192.168.1.1"));
     model->setItem(0, 1, new QStandardItem("1000"));
     model->setItem(0, 2, new QStandardItem("1000"));
     model->setItem(0, 3, new QStandardItem("ip of group"));
     model->setItem(0, 4, new QStandardItem(" 20:20:20 15.08.24"));
     model->setItem(1, 4, new QStandardItem(" 20:19:20 15.08.24"));
     model->setItem(2, 4, new QStandardItem(" 20:19:20 15.08.24"));
     model->setItem(3, 4, new QStandardItem(" 20:19:20 18.08.24"));
     model->setItem(4, 4, new QStandardItem(" 20:20:20 15.08.24"));
     model->setItem(5, 4, new QStandardItem(" 20:20:20 15.08.24"));
     model->setItem(6, 4, new QStandardItem(" 20:20:20 15.08.24"));
     model->setItem(7, 4, new QStandardItem(" 20:15:20 15.08.24"));


     view_2->setModel(model);
    // view_2->options().setGroupingEnabled(true);

     Qtitan::GridTableColumn* column1 = (Qtitan::GridTableColumn *)view_2->getColumn(4);
     column1 = (Qtitan::GridBandedTableColumn *)view_2->getColumn(4);
     column1->setGroupIndex(0);

     //Configure the summary
     column1->setDefaultGroupSummary(GridSummary::Min);

    // column1->setFooterSummary(GridSummary::Max);


     view_2->options().setRowAutoHeight(true); //Установка автоматической высоты
     view_2->options().setNewRowPlace(Qtitan::AtBeginning);
     view_2->options().setNewRowHighlightEffect(Qtitan::AlphaEffect); //Sets the effect of highlighting for the gird row
     view_2->options().setSupportedDropActions(Qt::CopyAction); //Sets the supported drop actions for the grid view.
     view_2->options().setModelItemsDragEnabled(true);//Sets the location to place of a special line for creating and editing the new row of the grid.
     view_2->options().setColumnAutoWidth(true);


 }

void MainWindow::cellButtonClicked(CellButtonClickEventArgs* args)
{
    Dialog4 *dialog;
    dialog= new Dialog4;
    dialog->show();
}


void MainWindow:: read_js()
{

  QJsonParseError docError;
    QFile file("ip.json");
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {

    doc = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError);
    file.close();
    }
   QString ip=doc.object().value("29/2").toString();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_clicked()
{
     ui->grid->show();
}
