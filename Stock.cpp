#include "Stock.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>


using namespace std;

//constructor for init a stock
Stock::Stock(string companyName, string tickerSymbol, int uniqueId, INDUSTRY industry,
             double currentPrice, int availableVolume, string name) {
    this->companyName = companyName;
    this->tickerSymbol = tickerSymbol;
    this->uniqueId = uniqueId;
    this->industry = industry;
    this->name = name;
    this->currentPrice = currentPrice;
    this->availableVolume = availableVolume;
}

//getter for company name
string Stock::getCompanyName() {
    return companyName;
}

//getter for volume traded
int Stock::getVolumeTraded() const {
    return volumeTraded;
}

//getter for stock ticker symbol
string Stock::getTickerSymbol() {
    return tickerSymbol;
}

//print stock info
void Stock::printInfo() const {
    SetConsoleOutputCP( CP_UTF8 );

    string indicator;
    if(previousPrice < 0.001){
        indicator = " ";
    }else{
        indicator =  previousPrice - currentPrice < 0.001 ?"\u2191" : "\u2193";
    }

    cout << name << ": [" << setw(2)  << right << uniqueId
         << "] | " << setw(10) << companyName
         << " | <" << setw(4) << tickerSymbol
         << "> | " << setw(7) << getIndustryString(industry)
         << " | cur price: $"
         << fixed << setprecision(2) << setw(6) << currentPrice
         << " | pre Price: $" << setw(6) << previousPrice
         << " | ava volume: " << setw(6) << left << availableVolume
         << " " << indicator <<  endl;
}

//setter for volume traded
void Stock::setVolumeTraded(int volume) {
    volumeTraded = volume;
}

Stock::INDUSTRY Stock::getIndustry() {
    return industry;
}

string Stock::getIndustryString(Stock::INDUSTRY industry) {
    {
        switch (industry) {
            case DIGITAL:
                return "DIGITAL";
            case MEDICAL:
                return "MEDICAL";
            case ENERGY:
                return "ENERGY";
            case BANK:
                return "BANK";
        }
    }
}

void Stock::setCurrentPrice(double price) {
    currentPrice = price;
}

