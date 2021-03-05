#include "Stock.h"
#include <iostream>
#include <iomanip>

using namespace std;

//constructor for init a stock
Stock::Stock(string companyName, string tickerSymbol, int uniqueId, string name, double currentPrice,
             int avaliableVolume) {
    this->companyName = companyName;
    this->tickerSymbol = tickerSymbol;
    this->uniqueId = uniqueId;
    this->name = name;
    this->currentPrice = currentPrice;
    this->availableVolume = avaliableVolume;
}

//getter for company name
string Stock::getCompanyName() {
    return companyName;
}

//getter for open price
double Stock::getOpenPrice() {
    return openPrice;
}

//getter for close price
double Stock::getClosePrice() {
    return closePrice;
}

//getter for volume traded
int Stock::getVolumeTraded() {
    return volumeTraded;
}

//getter for stock ticker symbol
string Stock::getTickerSymbol() {
    return tickerSymbol;
}

//print stock info
void Stock::printInfo() const {
    cout << name << ": [" << setw(2) <<  uniqueId
         << "] | " << setw(10) << companyName
         << " | <" << setw(4) << tickerSymbol << "> | cur price: $"
         << fixed << setprecision(2) << setw(6) << currentPrice
         << " | open: $" << setw(6) << openPrice << " | close: $"
         << setw(6) << closePrice << " | ava volume: "
         << setw(6) << availableVolume << endl;
}

//setter for opeen price
void Stock::setOpenPrice(double openPrice) {
    this->openPrice = openPrice;
}

//setter for close price
void Stock::setClosePrice(double closePrice) {
    this->closePrice = closePrice;
}

//setter for volume traded
void Stock::setVolumeTraded(int volume) {
    volumeTraded = volume;
}

