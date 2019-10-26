#include "entry.h"
#include<QObject>
#include<QtDebug>

using namespace std;

Entry::Entry(int assignedId,
             double enteredLiters,
             double enteredRange,
             double enteredPrice)
{
    id=assignedId;
    liters=enteredLiters;
    range=enteredRange;
    price=enteredPrice;
}

void Entry::literValueChange(double i){

    oldLiters = liters;
    liters = i;


    emit kmPerLiter(range/liters);
    emit litersPerKm(100/(range/liters));
    emit eurPerKm(price/(range/liters));
}

void Entry::rangeValueChange(double i)
{

    oldRange=range;
    range = i;


    emit kmPerLiter(range/liters);
    emit litersPerKm(100/(range/liters));
    emit eurPerKm(price/(range/liters));
}

void Entry::priceValueChange(double i)
{

    oldPrice = price;
    price = i;

    emit kmPerLiter(range/liters);
    emit litersPerKm(100/(range/liters));
    emit eurPerKm(price/(range/liters));
}

void Entry::totalLiterChange()
{
    emit totalLiterChangeSignal(id);
}
void Entry::totalRangeChange()
{
    emit totalRangeChangeSignal(id);
}
void Entry::totalPriceChange()
{
    emit totalPriceChangeSignal(id);
}
