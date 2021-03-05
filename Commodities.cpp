
#include <iomanip>
#include "Commodities.h"

Commodities::Commodities(int uniqueId, string commodityName, INDUSTRY industry, double currentPrice,
                         int availableVolume) {
    this->name = "Commodities";
    this->uniqueId = uniqueId;
    this->commodityName = commodityName;
    this->currentPrice = currentPrice;
    this->industry = industry;
    this->availableVolume = availableVolume;
}

void Commodities::printInfo() const {
    cout << setw(2) << right << uniqueId
         << " | " << setw(6) << commodityName << " | "
         << setw(11) << getIndustryString(industry) << " | cur price: $"
         << fixed << setprecision(2) << setw(7) << right<< currentPrice
         << endl;
}

string Commodities::getCommodityName() {
    return commodityName;
}

string Commodities::getIndustryString(Commodities::INDUSTRY industry) const {
    switch (industry) {
        case METAL:
            return "METAL";
        case ENERGY:
            return "ENERGY";
        case AGRICULTURE:
            return "AGRICULTURE";
    }
}

