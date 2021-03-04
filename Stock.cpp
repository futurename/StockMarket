#include "Stock.h"
#include <iostream>

using namespace std;

Stock::Stock(string name, string symbol) {
    companyName = name;
    tickerSymbol = symbol;
}

string Stock::getCompanyName() {
    return companyName;
}

double Stock::getOpenPrice() {
    return openPrice;
}

double Stock::getClosePrice() {
    return closePrice;
}

int Stock::getVolumeTraded() {
    return volumeTraded;
}

