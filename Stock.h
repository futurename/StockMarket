#pragma  once
#include <iostream>
#include "FinancialInstrument.h"

using namespace std;

class Stock : public FinancialInstrument {
private:
    string companyName;
    string tickerSymbol;
    double openPrice = 0.0;
    double closePrice = 0.0;
    int volumeTraded = 0.0;

public:
    Stock(string name, string symbol, int uniqueId, double currentPrice =0.0);

    string getCompanyName();

    double getOpenPrice();

    double getClosePrice();

    void setOpenPrice(double openPrice);

    void setClosePrice(double closePrice);

    void setVolumeTraded(int volume);

    int getVolumeTraded();

    string getTickerSymbol();

    void printInfo() const override;
};