#ifndef ENTRY_H
#define ENTRY_H

#include <QObject>

class Entry : public QObject
{
    Q_OBJECT

public:
    Entry(int assignedId,
          double enteredLiters,
          double enteredRange,
          double enteredPrice);

signals:

    void valueCleared(double);

    void kmPerLiter(double);
    void litersPerKm(double);
    void eurPerKm(double);

    void totalLiterChangeSignal(int);
    void totalRangeChangeSignal(int);
    void totalPriceChangeSignal(int);

public slots:

    void clearClicked() { emit valueCleared(0); }
    void literValueChange(double i);
    void rangeValueChange(double i);
    void priceValueChange(double i);

    void totalLiterChange();
    void totalRangeChange();
    void totalPriceChange();
public:
    int id;
    double liters;
    double range;
    double price;

    double oldLiters;
    double oldRange;
    double oldPrice;
};

#endif // ENTRY_H
