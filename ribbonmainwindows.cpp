#include "ribbonmainwindows.h"
#include "ui_ribbonmainwindows.h"

RibbonMainWindows::RibbonMainWindows(QWidget *parent) :
    RibbonMainWindow(parent),
    ui(new Ui::RibbonMainWindows)
{
    Grid::loadTranslation();
    ui->setupUi(this);
    m_grid = new Qtitan::Grid();
   // setCentralWidget(m_grid);
    m_grid->setViewType(Qtitan::Grid::TableView);
    GridTableView* view = m_grid->view<GridTableView>();

    QStandardItemModel model(4, 3);
        model.setHorizontalHeaderItem(0, new QStandardItem("Column 1"));
        model.setHorizontalHeaderItem(1, new QStandardItem("Column 2"));
        model.setHorizontalHeaderItem(2, new QStandardItem("Column 3"));
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                model.setItem(row, col, new QStandardItem(QString("%1,%2").arg(row).arg(col)));
            }
        }

        //view->options().setRowAutoHeight(true);
        view->options().setNewRowPlace(Qtitan::AtBeginning);
        view->options().setNewRowHighlightEffect(Qtitan::AlphaEffect);
        view->options().setSupportedDropActions(Qt::CopyAction);
        view->options().setModelItemsDragEnabled(true);
        view->setModel(&model);

}

RibbonMainWindows::~RibbonMainWindows()
{
    delete ui;
}
