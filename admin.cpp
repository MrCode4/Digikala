#include "admin.h"
#include "ui_admin.h"
#include "itemlistmodel.h"
#include <QVBoxLayout>
#include <QTableView>

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    ItemListModel* itemListModel = new ItemListModel(this);

    ui->tableView->setModel(itemListModel);
    //QTableView* tableView = new QTableView(this);
    //tableView->setModel(itemListModel);

    //QVBoxLayout* layout = new QVBoxLayout();

    //layout->addWidget(tableView);

    //ui->pending_submiting_products_contents->setLayout(layout);
}

Admin::~Admin()
{
    delete ui;
}
