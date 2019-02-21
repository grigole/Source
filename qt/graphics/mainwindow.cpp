#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSquare_triggered()
{
    fprintf( stderr, "Square clicked\n" );
}

void MainWindow::on_actionRectangle_triggered()
{
    fprintf( stderr, "Rectange clicked\n" );
}

void MainWindow::on_actionCircle_triggered()
{
    fprintf( stderr, "Circle clicked\n" );
}
