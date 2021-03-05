
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

void Market::buyByPlayer(Player& player, FinancialInstrument *f, int shares) {
    double value = f->getCurrentPrce() * shares;
    player.modifyCash(value * -1);
    Holding holding(f->getUniqueId(), shares, value);
    player.addHolding(holding);
}

void Market::sellByPlayer(Player& player, FinancialInstrument *f, int shares) {
    double value = f->getCurrentPrce() * shares;
    player.modifyCash(value);
    Holding holding(f->getUniqueId(), shares* -1, value * -1);
    player.removeHolding(holding);
}

FinancialInstrument *Market::getPointerByUniqueId(int uniqueId) {
    for(Stock &s: stockList){
        if(s.getUniqueId() == uniqueId){
            FinancialInstrument* result = &s;
            return result;
        }
    }
    for(Commodities &c: commoditiesList){
        if(c.getUniqueId() == uniqueId){
            FinancialInstrument* result = &c;
            return result;
        }
    }
}

Commodities &Market::getCommodityById(int id) {
    //Not validate id;
   for(Commodities& c: commoditiesList){
       if(c.getUniqueId() == id){
           return c;
       }
   }
}

Stock &Market::getStockById(int id) {
    //Not validate id;
    for(Stock& s: stockList){
        if(s.getUniqueId() == id){
            return s;
        }
    }
}

string Market::getTypeById(int id) {
    //FIXME if id not exists
    for(Stock& s: stockList){
        if(s.getUniqueId() == id){
            return s.getName();
        }
    }
    for(Commodities& c: commoditiesList){
        if(c.getUniqueId() == id){
            return c.getName();
        }
    }
    return "Nothing found";
}
