#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QObject>
#include <QtWidgets>
#include <QtCore>

#include "entry.h"
#include "allentries.h"

static const int lines = 30;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void LitersChanged(int id);
    void RangeChanged(int id);
    void PriceChanged(int id);

    void on_actionClose_triggered();

    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;

    QLabel *totalVolume= new QLabel;
    QLabel *totalRange= new QLabel;
    QLabel *totalSum= new QLabel;
    QLabel *averageKmPerLiter= new QLabel;
    QLabel *averageLitersPerKm= new QLabel;
    QLabel *averageEurPerKm= new QLabel;

    Entry *entry[lines]; // variables stored in objects

    double totalFuelSum;
    double totalRangeSum;
    double totalPriceSum;

    int validEntry;
    int validEntryPrice;

public:

};

#endif // MAINWINDOW_H
