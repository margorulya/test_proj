#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog1)
{
         ui->setupUi(this);

         ui->comboBox->addItem("UDP");
         ui->comboBox->addItem("IGMP");

         ui->comboBox_3->addItem("239.2.2.8");
         ui->comboBox_3->addItem("239.2.2.9");

         QStandardItemModel *model = new QStandardItemModel(10, 1); // 3 rows, 1 col
         QString data="Объект";
                for(int i=0;i<10;i++)
                {
                    QStandardItem* item = new QStandardItem(data+" "+QString::number(i));

                    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
                    item->setData(Qt::Unchecked, Qt::CheckStateRole);
                    model->setItem(i, 0, item);
                }

        ui->comboBox_2->setModel(model);

        connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Dialog1::changeWidget);

        ui->comboBox->setCurrentIndex(0);



        // Создание и настройка QStackedWidget
       //   stackedWidget = new QStackedWidget(this);
          //QWidget *widge1t = page_udp();
         // stackedWidget->addWidget(widge1t);
       // Установка слота для обработки изменения значения в QComboBox
       //  connect(ui->comboBox,QOverload<int>::of(&QComboBox::activated), this, &Dialog1::changeWidget);
      //  connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Dialog1::changeWidget);
       // Установка начального значения в QComboBox
       //  ui->comboBox->setCurrentIndex(0);

         // QVBoxLayout *layout = new QVBoxLayout;
        //  layout->addWidget(ui->comboBox);
         // layout->addWidget(ui->comboBox_2);
         // layout->addWidget(ui->comboBox_3);
         // layout->addWidget(stackedWidget);

          //QWidget *centralWidget = new QWidget;
          //centralWidget->setLayout(layout);
         // this->setLayout(layout);
        //  QWidget *centralWidget = new QWidget;
        //  centralWidget->setLayout(layout);
    }

QWidget *Dialog1:: page_udp()
{
   QWidget *widget = nullptr;
   QStandardItemModel *model = new QStandardItemModel(10, 1); // 3 rows, 1 col
   QString data="Объект";
          for(int i=0;i<10;i++)
          {
              QStandardItem* item = new QStandardItem(data+" "+QString::number(i));

              item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
              item->setData(Qt::Unchecked, Qt::CheckStateRole);
              model->setItem(i, 0, item);
          }

   comboBox2 = new QComboBox(widget);
   comboBox2->setModel(model);

   SpinB = new QSpinBox(widget);

   label2 = new QLabel("Получатели",widget);
   label2->setFont(QFont("Purisa", 10));

   auto *hbox2 = new QHBoxLayout();
   hbox2->addWidget(label2);
   hbox2->addWidget(comboBox2);

   label3 = new QLabel("Кол-во пакетов",widget);
   label3->setFont(QFont("Purisa", 10));

   auto *hbox3 = new QHBoxLayout();
   hbox3->addWidget(label3);
   hbox3->addWidget(SpinB);

   return widget;
}
void Dialog1::changeWidget(int index)
{
   QWidget *widget = nullptr;
    switch (index) {
                case 0:


                    break;
                case 1:
     /*
               ui->comboBox_2->hide();
               ui->label_2->hide();
               ui->label_3->hide();
               ui->spinBox->hide();
               comboBox3=new QComboBox(this);
               comboBox3->addItem("add");
               comboBox3->addItem("send");
               label_4=new QLabel(this);
               label_4->setText("Команда");

               auto *hbox2 = new QHBoxLayout();
               hbox2->addWidget(label_4);
               hbox2->addWidget(comboBox3);
               ui->verticalLayout->addLayout(hbox2);

 */
        break;
                default:
                    widget = new QLabel("Widget 1");
            }

            stackedWidget->addWidget(widget);
            stackedWidget->setCurrentWidget(widget);
}

Dialog1::~Dialog1()
{
    delete ui;
}
