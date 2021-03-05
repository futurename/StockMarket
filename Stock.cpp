#include "Stock.h"
#include <iostream>
#include <iomanip>

using namespace std;

//constructor for init a stock
Stock::Stock(string name, string symbol, int uniqueId, double currentPrice) {
    companyName = name;
    tickerSymbol = symbol;
    this->uniqueId = uniqueId;
    setCurrentPrice(currentPrice);
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
    cout << "Stock: [" <<uniqueId <<"], " << companyName << ", <" << tickerSymbol << ">, current price: $"
         << fixed << setprecision(2) << currentPrice << ", open: $"
         << openPrice << ", close: $" << closePrice << endl;
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

