#pragma once

#include <iostream>

using namespace std;

class FinancialInstrument {
protected:
    string name;
    double currentPrice;
    int availableVolume;
    int uniqueId;

public:
    void setName(string passedName);

    void setCurrentPrice(double passedCurrentPrice);

    void setAvailableVolume(int passedAvailableVolume);

    virtual void printInfo() const;

    string getName();

    double getCurrentPrce();

    int getAvailableVolume();

    int getUniqueId();
};