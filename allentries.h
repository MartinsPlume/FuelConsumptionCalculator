#ifndef ALLENTRIES_H
#define ALLENTRIES_H

#include <QObject>

class AllEntries : public QObject
{
    Q_OBJECT
public:
    explicit AllEntries(QObject *parent = nullptr);

signals:

    void valueCleared(double);

public slots:

    void clearClicked() { emit valueCleared(0); }
};

#endif // ALLENTRIES_H
