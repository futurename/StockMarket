#pragma  once

#include <iostream>
#include <vector>

#include "Stock.h"
#include "Commodities.h"
#include "FinancialInstrument.h"

using namespace std;


class Market {
private:
    vector<Stock> stockList;
    vector<Commodities> commoditiesList;

public:
    template<typename T>
    void print(vector<T> *list, int length, int from = 0);

    template<typename T>
    void addOne(vector<T> *list, T &t);

    template<typename T>
    void removeOne(vector<T> *list, int uniqueId);

    vector<Stock> *getStockList();

    vector<Commodities> *getCommoditiesList();

};

#include "Market.tpp"