#pragma  once

#include <iostream>
#include "FinancialInstrument.h"

using namespace std;

class Commodities : public FinancialInstrument {
private:
    int volumeTraded;

public:
    Commodities( int uniqueId,string name = "Commodities", double currentPrice = 0.0, int availableVolume = 0);

    void printInfo() const override;
};