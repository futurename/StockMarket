#pragma  once
#include <iostream>
#include <vector>

#include "Stock.h"
#include "Commodities.h"
#include "FinancialInstrument.h"

using namespace std;

class Market{
private:
    vector<Stock*> stockList;
    vector<Commodities*> commoditiesList;
public:
    void print(vector<FinancialInstrument* > list, int from, int to);

    void addOne(vector<FinancialInstrument*> list, FinancialInstrument* financialInstrument);

    void removeOne(vector<FinancialInstrument*> list, FinancialInstrument &financialInstrument);

    vector<Stock*> getStockList();

    vector<Commodities*> getCommoditiesList();

};
