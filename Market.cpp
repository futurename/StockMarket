
#include "Market.h"


void Market::print(vector<FinancialInstrument*> list, int from, int to) {
    for(FinancialInstrument* f : list){
        f->printInfo();
    }
}

void Market::addOne(vector<FinancialInstrument*> list, FinancialInstrument* financialInstrument) {
    list.push_back(financialInstrument);
}

vector<Stock*> Market::getStockList() {
    return stockList;
}

vector<Commodities*> Market::getCommoditiesList() {
    return commoditiesList;
}
