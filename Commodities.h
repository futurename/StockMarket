#pragma  once

#include <iostream>
#include "FinancialInstrument.h"

using namespace std;

class Commodities : public FinancialInstrument {
public:
    enum INDUSTRY{
        METAL, ENERGY, AGRICULTURE
    };

    Commodities(int uniqueId, string commodityName, INDUSTRY industry, double currentPrice = 0.0, int availableVolume = 0);

    void printInfo() const override;

    string getCommodityName();

    string getIndustryString(INDUSTRY industry) const;

private:
    string commodityName;
    INDUSTRY industry;
};