#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QStandardItemModel* standardItemMoedl = new QStandardItemModel( ui -> treeView );
    // standardItemMoedl->setHorizontalHeaderItem( QStringList( ) << QStringLiteral( "项目名" ) << QStringLiteral( "信息" ));

}

MainWindow::~MainWindow()
{
    delete ui;
}
