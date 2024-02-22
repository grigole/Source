/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSquare;
    QAction *actionRectangle;
    QAction *actionCircle;
    QAction *actionexit;
    QWidget *centralWidget;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menuGraphics;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        actionSquare = new QAction(MainWindow);
        actionSquare->setObjectName(QString::fromUtf8("actionSquare"));
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(-1, -1, 471, 281));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 30));
        menuGraphics = new QMenu(menuBar);
        menuGraphics->setObjectName(QString::fromUtf8("menuGraphics"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGraphics->menuAction());
        menuGraphics->addAction(actionSquare);
        menuGraphics->addAction(actionRectangle);
        menuGraphics->addAction(actionCircle);
        menuGraphics->addSeparator();
        menuGraphics->addAction(actionexit);

        retranslateUi(MainWindow);
        QObject::connect(actionexit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OpenGL Demo", nullptr));
        actionSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        actionRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        actionCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        actionexit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuGraphics->setTitle(QCoreApplication::translate("MainWindow", "Graphics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
