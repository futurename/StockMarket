#pragma  once

#include <iostream>
#include "FinancialInstrument.h"

using namespace std;

class Stock : public FinancialInstrument {
public:
    enum INDUSTRY {
        DIGITAL, MEDICAL, ENERGY, BANK
    };

    Stock(string companyName, string tickerSymbol, int uniqueId, INDUSTRY industry,
          double currentPrice = 0.0, int availableVolue = 0,string name = "Stock");

    string getCompanyName();

    void setVolumeTraded(int volume);

    int getVolumeTraded() const;

    void setCurrentPrice(double price);

    string getTickerSymbol();

    INDUSTRY getIndustry();

    void printInfo() const override;

    static string getIndustryString(INDUSTRY industry);

private:
    string companyName;
    string tickerSymbol;
    INDUSTRY industry;
    int volumeTraded = 0;
};