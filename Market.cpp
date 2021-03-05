
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

    f->setPreviousPrice(f->getCurrentPrce());

    f->setCurrentPrice(f->getCurrentPrce() * (randNum + 1));
}

int Market::getRandomRange(int range) {
    return rand() % range;
}

void Market::buyByPlayer(Player player, FinancialInstrument *f, int shares) {
    double value = f->getCurrentPrce() * shares;
    player.deduct(value);
    Holding holding(f->getUniqueId(), shares, value);
    player.addHolding(holding);
}

void Market::sellByPlayer(Player player, FinancialInstrument *f, int shares) {

}

int Market::getUniqueIdFromStock(string tickerSymbol) {
    for (Stock s: stockList) {
        if (s.getTickerSymbol() == tickerSymbol) {
            return s.getUniqueId();
        }
    }
    cout << "This ticker symbol: " << tickerSymbol << " NOT exist in stock list" << endl;
    return -1;
}

int Market::getUniqueIdFromCommodities(string name) {
    for (Commodities c: commoditiesList) {
        if (c.getName() == name) {
            return c.getUniqueId();
        }
    }
    cout << "This name: " << name << " NOT exist in commodities list" << endl;
    return -1;
}
