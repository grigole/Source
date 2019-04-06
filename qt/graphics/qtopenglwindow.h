#ifndef QTOPENGLWINDOW_H
#define QTOPENGLWINDOW_H

#include <QMainWindow>

namespace Ui {
class QtOpenGLWindow;
}

class QtOpenGLWindow : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit QtOpenGLWindow(QOpenGLWidget *parent = 0);
    ~QtOpenGLWindow();
};

#endif // QTOPENGLWINDOW_H
