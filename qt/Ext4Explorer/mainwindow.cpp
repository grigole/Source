/****************************************************************************
**
** Copyright (C) 2021 - Greg Rigole
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qfiledialog.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionDisk_Image_triggered()
{
    QString filter = "Disk Image (*.dd) ;; All Files (*.*)";

    // For example: "Mpeg Layer 3 music files (*.mp3)"
    QString filename = QFileDialog::getOpenFileName(
                this, "Select a file...", "/mnt/windows/c", filter);

    std::cout << filename.toStdString() << std::endl;
}
