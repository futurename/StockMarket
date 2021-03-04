
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
    void printFinancialInstruments(vector<FinancialInstrument> &list, int from, int to);

    void addFinancialInstrument(FinancialInstrument* financialInstrument);

    void removeFinancialInstrument();



};
