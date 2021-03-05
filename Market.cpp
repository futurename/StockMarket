
#include "Market.h"

vector<Stock>* Market::getStockList() {
    return &stockList;
}

vector<Commodities>* Market::getCommoditiesList() {
    return &commoditiesList;
}
