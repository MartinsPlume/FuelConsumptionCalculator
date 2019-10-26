#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Fuel Consumption Calculator");
    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("Fuel Consumption Calculator");
    QGridLayout *windowLayout = new QGridLayout;
    windowLayout->setAlignment(Qt::AlignTop);

    // setting labels for entry titles
    QLabel *mainWindowTitles=new QLabel[8];
    mainWindowTitles[0].setText("Date");
    mainWindowTitles[1].setText("Volume (l)");
    mainWindowTitles[2].setText("Range (KM)");
    mainWindowTitles[3].setText("Price per Liter (EUR)");
    mainWindowTitles[4].setText("Km per Liter");
    mainWindowTitles[5].setText("Liters per 100 km");
    mainWindowTitles[6].setText("EUR per km");

    // adding titles for collumns
    for (int i=0;i<7;i++)
    {
        windowLayout->addWidget(&mainWindowTitles[i],0,i);
    }

    // creating line objects
    AllEntries *allentries = new AllEntries();

    // creating entry fields for date,liters,
    QDateEdit *mainWindowDates = new QDateEdit[lines];
    QDoubleSpinBox *mainWindowLiters = new QDoubleSpinBox [lines];
    QDoubleSpinBox *mainWindowRange = new QDoubleSpinBox [lines];
    QDoubleSpinBox *mainWindowPrice = new QDoubleSpinBox[lines];

    // clear button for the line
    QPushButton *mainWindowClearButtons = new QPushButton[lines];

    // set up result labels
    QLabel *KmPerLiter = new QLabel[lines];
    QLabel *litersPerKm = new QLabel[lines];
    QLabel *eurPerKm = new QLabel[lines];

    // set up total labels

    QLabel *totalVolumeTitle = new QLabel;
    QLabel *totalRangeTitle = new QLabel;
    QLabel *totalSumTitle = new QLabel;
    QLabel *averageKmPerLiterTitle = new QLabel;
    QLabel *averageLitersPerKmTitle = new QLabel;
    QLabel *averageEurPerKmTitle = new QLabel;

    //set up total volume
    windowLayout->addWidget(totalVolumeTitle,lines+3,1);
    windowLayout->addWidget(totalVolume,lines+2,1);
    totalVolumeTitle->setText("Total Volume");

    // set up total range
    windowLayout->addWidget(totalRangeTitle,lines+3,2);
    windowLayout->addWidget(totalRange,lines+2,2);
    totalRangeTitle->setText("Total Range");

    // set up total price
    windowLayout->addWidget(totalSumTitle,lines+3,3);
    windowLayout->addWidget(totalSum,lines+2,3);
    totalSumTitle->setText("Total Sum");

    // set up total average kmPerLiter
    windowLayout->addWidget(averageKmPerLiterTitle,lines+3,4);
    windowLayout->addWidget(averageKmPerLiter,lines+2,4);
    averageKmPerLiterTitle->setText("Average Km per Liter");

    // set up total average liters per 100 km
    windowLayout->addWidget(averageLitersPerKmTitle,lines+3,5);
    windowLayout->addWidget(averageLitersPerKm,lines+2,5);
    averageLitersPerKmTitle->setText("Average liters per 100km");

    // set up total average Eur per Km
    windowLayout->addWidget(averageEurPerKmTitle,lines+3,6);
    windowLayout->addWidget(averageEurPerKm,lines+2,6);
    averageEurPerKmTitle->setText("Average Eur Per Km");

    // set up the clear all button
    QPushButton *mainWindowClearAllButton = new QPushButton;
    mainWindowClearAllButton->setText("Clear All");
    windowLayout->addWidget(mainWindowClearAllButton,lines+2,7);
    QObject::connect(mainWindowClearAllButton,SIGNAL(clicked()),allentries,SLOT(clearClicked()));

    // set up status bar

    QStatusBar *mainWindowStatusBar = new QStatusBar;
    windowLayout->addWidget(mainWindowStatusBar);

    for (int i=0;i<lines;i++)
    {
        entry[i] = new Entry(i,0,0,0); // create an object

        windowLayout->addWidget(&mainWindowDates[i],i+1,0);
        windowLayout->addWidget(&mainWindowLiters[i],i+1,1);
        mainWindowLiters[i].setMaximum(5000);
        windowLayout->addWidget(&mainWindowRange[i],i+1,2);
        mainWindowRange[i].setMaximum(10000);
        windowLayout->addWidget(&mainWindowPrice[i],i+1,3);
        mainWindowPrice[i].setMaximum(100);

        // result
        windowLayout->addWidget(&KmPerLiter[i],i+1,4);
        windowLayout->addWidget(&litersPerKm[i],i+1,5);
        windowLayout->addWidget(&eurPerKm[i],i+1,6);

        // clear button
        mainWindowClearButtons[i].setText("Clear");
        windowLayout->addWidget(&mainWindowClearButtons[i],i+1,7);

        // Set up clear buttons for each line
        QObject::connect(&mainWindowClearButtons[i],SIGNAL(clicked()),entry[i],SLOT(clearClicked()));
        QObject::connect(entry[i],SIGNAL(valueCleared(double)),&mainWindowLiters[i],SLOT(setValue(double)));
        QObject::connect(entry[i],SIGNAL(valueCleared(double)),&mainWindowRange[i],SLOT(setValue(double)));
        QObject::connect(entry[i],SIGNAL(valueCleared(double)),&mainWindowPrice[i],SLOT(setValue(double)));

        //set up clear all button on all lines
        QObject::connect(allentries,SIGNAL(valueCleared(double)),&mainWindowLiters[i],SLOT(setValue(double)));
        QObject::connect(allentries,SIGNAL(valueCleared(double)),&mainWindowRange[i],SLOT(setValue(double)));
        QObject::connect(allentries,SIGNAL(valueCleared(double)),&mainWindowPrice[i],SLOT(setValue(double)));

        // set up liters change calculation
        QObject::connect(&mainWindowLiters[i],SIGNAL(valueChanged(double)),entry[i],SLOT(literValueChange(double)));
        QObject::connect(entry[i],SIGNAL(kmPerLiter(double)),&KmPerLiter[i],SLOT(setNum(double)));
        QObject::connect(entry[i],SIGNAL(litersPerKm(double)),&litersPerKm[i],SLOT(setNum(double)));
        QObject::connect(entry[i],SIGNAL(eurPerKm(double)),&eurPerKm[i],SLOT(setNum(double)));

        // set up range change calculation
        QObject::connect(&mainWindowRange[i],SIGNAL(valueChanged(double)),entry[i],SLOT(rangeValueChange(double)));
        QObject::connect(entry[i],SIGNAL(kmPerLiter(double)),&KmPerLiter[i],SLOT(setNum(double)));
        QObject::connect(entry[i],SIGNAL(litersPerKm(double)),&litersPerKm[i],SLOT(setNum(double)));
        QObject::connect(entry[i],SIGNAL(eurPerKm(double)),&eurPerKm[i],SLOT(setNum(double)));

        // set up price change calculation
        QObject::connect(&mainWindowPrice[i],SIGNAL(valueChanged(double)),entry[i],SLOT(priceValueChange(double)));
        QObject::connect(entry[i],SIGNAL(kmPerLiter(double)),&KmPerLiter[i],SLOT(setNum(double)));
        QObject::connect(entry[i],SIGNAL(litersPerKm(double)),&litersPerKm[i],SLOT(setNum(double)));
        QObject::connect(entry[i],SIGNAL(eurPerKm(double)),&eurPerKm[i],SLOT(setNum(double)));

        // set up total liters
        QObject::connect(&mainWindowLiters[i],SIGNAL(valueChanged(double)),entry[i],SLOT(totalLiterChange()));
        QObject::connect(entry[i],SIGNAL(totalLiterChangeSignal(int)),this,SLOT(LitersChanged(int)));

        // set up total range
        QObject::connect(&mainWindowRange[i],SIGNAL(valueChanged(double)),entry[i],SLOT(totalRangeChange()));
        QObject::connect(entry[i],SIGNAL(totalRangeChangeSignal(int)),this,SLOT(RangeChanged(int)));

        // set up total price
        QObject::connect(&mainWindowPrice[i],SIGNAL(valueChanged(double)),entry[i],SLOT(totalPriceChange()));
        QObject::connect(entry[i],SIGNAL(totalPriceChangeSignal(int)),this,SLOT(PriceChanged(int)));
    }

    mainWindow->setLayout(windowLayout);
    this->setCentralWidget(mainWindow);
    this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LitersChanged(int id)
{
    totalFuelSum+=(entry[id]->liters-entry[id]->oldLiters);
    totalPriceSum+=(entry[id]->liters*entry[id]->price)-(entry[id]->oldLiters*entry[id]->price);
    totalVolume->setNum(totalFuelSum);
    totalSum->setNum(totalPriceSum);

    averageKmPerLiter->setNum(totalRangeSum/totalFuelSum);
    averageLitersPerKm->setNum(100/(totalRangeSum/totalFuelSum));
    averageEurPerKm->setNum((totalPriceSum/(totalRangeSum/totalFuelSum))/totalFuelSum);
}
void MainWindow::RangeChanged(int id)
{
    totalRangeSum+=(entry[id]->range-entry[id]->oldRange);
    totalRange->setNum(totalRangeSum);
    averageKmPerLiter->setNum(totalRangeSum/totalFuelSum);
    averageLitersPerKm->setNum(100/(totalRangeSum/totalFuelSum));
    averageEurPerKm->setNum((totalPriceSum/(totalRangeSum/totalFuelSum))/totalFuelSum);
}
void MainWindow::PriceChanged(int id)
{
    totalPriceSum+=(entry[id]->liters*entry[id]->price)-(entry[id]->liters*entry[id]->oldPrice);
    totalSum->setNum(totalPriceSum);
    averageEurPerKm->setNum((totalPriceSum/(totalRangeSum/totalFuelSum))/totalFuelSum);
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_actionNew_triggered()
{
    MainWindow *Win = new MainWindow();
      Win->show();
}
