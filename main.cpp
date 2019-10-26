#include <QApplication>
#include <QObject>
#include <QtWidgets>
#include <QtCore>

#include "entry.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);
    MainWindow w;
    w.show();
    return prog.exec();
}
