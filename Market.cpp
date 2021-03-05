
#include "Market.h"
#include <chrono>

vector<Stock> *Market::getStockList() {
    return &stockList;
}

vector<Commodities> *Market::getCommoditiesList() {
    return &commoditiesList;
}

double Market::updateAllPrices(FLUCTUATE_POLICY policy) {
    switch (policy) {
        case MARKET_TREND:
            updatePricesWithMarketTrend();
            break;
        case INDUSTRY_TREND:
            updatePricesWithIndustryTrend();
            break;
        default:
            updatePricesWithSimpleRandom();
            break;
    }

    return 0;
}

void Market::updatePricesWithMarketTrend() {

}

void Market::updatePricesWithIndustryTrend() {

}

void Market::updatePricesWithSimpleRandom() {
    for (Stock &s: stockList) {
        Stock *sptr = &s;
        setNewPrice(sptr);
    }

    for (Commodities &c : commoditiesList) {
        Commodities *cptr = &c;
        setNewPrice(cptr);
    }
}

bool Market::getNumberLine() {
    long int timeNow = time(0);
    int shift = getRandomRange(20);
    srand(timeNow << shift);
    return rand() % 2 == 0;
}

void Market::setNewPrice(FinancialInstrument *f) {
    long int timeNow = time(0);
    int shift = getRandomRange(20);

    srand(timeNow << shift);
    double randNum = (rand() % randRange + 1) / 100.0;
    randNum = getNumberLine() ? randNum : randNum * -1;

    cout << randNum << endl;

    f->setCurrentPrice(f->getCurrentPrce() * (randNum + 1));
}

int Market::getRandomRange(int range) {
    return rand() % range;
}
