#ifndef RIBBONMAINWINDOWS_H
#define RIBBONMAINWINDOWS_H

#include <QMainWindow>
#include<QtitanDBGrid.h>
#include<QtitanGrid.h>
#include<QtitanRibbon.h>
#include<QtitanBase.h>
#include <QStandardItemModel>
#include <QVBoxLayout>

namespace Ui {
class RibbonMainWindows;
}

class RibbonMainWindows : public RibbonMainWindow
{
    Q_OBJECT

public:
    explicit RibbonMainWindows(QWidget *parent = nullptr);
    ~RibbonMainWindows();

private:
    Ui::RibbonMainWindows *ui;
    Qtitan::Grid* m_grid;
};

#endif // RIBBONMAINWINDOWS_H
