#include "FinancialInstrument.h"

void FinancialInstrument::setName(string passedName) {
    name = passedName;
}

void FinancialInstrument::setCurrentPrice(double passedCurrentPrice) {
    currentPrice = passedCurrentPrice;
}

void FinancialInstrument::setAvailableVolume(int passedAvailableVolume) {
    availableVolume = passedAvailableVolume;
}

string FinancialInstrument::getName() {
    return name;
}

double FinancialInstrument::getCurrentPrce() {
    return currentPrice;
}

int FinancialInstrument::getAvailableVolume() {
    return availableVolume;
}

void FinancialInstrument::printInfo() const {
    cout << "FinancialInstrument print()" << endl;
}
