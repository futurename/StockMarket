
#include <iomanip>
#include "Commodities.h"

Commodities::Commodities(int uniqueId, string name, double currentPrice, int availableVolume) {
    this->name = name;
    this->uniqueId = uniqueId;
    this->currentPrice = currentPrice;
    this->availableVolume = availableVolume;
}

void Commodities::printInfo() const {
    cout << name << ": [" << setw(2) << right << uniqueId << "] | cur price: $"
         << fixed << setprecision(2) << setw(6) << currentPrice
         << "| ava volume: " << setw(6) << left << availableVolume << endl;
}

