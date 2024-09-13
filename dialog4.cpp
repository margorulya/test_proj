#include "dialog4.h"
#include "ui_dialog4.h"

Dialog4::Dialog4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);

    ui->comboBox->addItem("UDP");
    ui->comboBox->addItem("IGMP");


    ui->comboBox_3->addItem("239.2.2.8");
    ui->comboBox_3->addItem("239.2.2.9");

    ui->comboBox_5->addItem("239.2.2.8");
    ui->comboBox_5->addItem("239.2.2.9");

    model = new QStandardItemModel(10, 1); // 3 rows, 1 col
    QString data="Объект";
     for(int i=0;i<10;i++)
           {
               QStandardItem* item = new QStandardItem(data+" "+QString::number(i));

               item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
               item->setData(Qt::Unchecked, Qt::CheckStateRole);
               model->setItem(i, 0, item);
           }

   ui->comboBox_2->setModel(model);

   ui->comboBox_6->addItem("Add");
   ui->comboBox_6->addItem("SendM");

   ui->comboBox->setCurrentIndex(0);

   ui->stackedWidget->setCurrentIndex(0);

   connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), this, &Dialog4::changeWidget);
   connect(ui->m_pCancel, SIGNAL(clicked()), this, SLOT(on_pushButton_cansel_clicked()));
   setAttribute(Qt::WA_DeleteOnClose);

}

void Dialog4::changeWidget(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}
void Dialog4::on_pushButton_cansel_clicked()
{
    //думаю тут нужно просто закрытие
    int index=ui->comboBox->currentIndex();
    if(index==0)
    {
        ui->comboBox_3->setCurrentIndex(0);
        ui->spinBox->setValue(0);
        for(int i=0;i<10;i++)
        {
         model->item(i, 0)->setData(Qt::Unchecked, Qt::CheckStateRole);
        }
    }
    else
    {
        ui->comboBox_6->setCurrentIndex(0);
        ui->comboBox_5->setCurrentIndex(0);
    }

}
void Dialog4::on_pushButton_ok_clicked()
{
 //сформировать задачу
}

Dialog4::~Dialog4()
{
    delete ui;
}
