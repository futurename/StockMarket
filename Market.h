#pragma  once

#include <iostream>
#include <vector>

#include "Stock.h"
#include "Commodities.h"
#include "FinancialInstrument.h"
#include "Player.h"
#include "Holding.h"

using namespace std;

class Market {
public:
    enum FLUCTUATE_POLICY {
        SIMPLE_RAMDOM, MARKET_TREND, INDUSTRY_TREND
    };

    template<typename T>
    void print(vector<T> *list, int length, int from = 0);

    template<typename T>
    void addOne(vector<T> *list, T &t);

    template<typename T>
    void removeOne(vector<T> *list, int uniqueId);

    vector<Stock> *getStockList();

    vector<Commodities> *getCommoditiesList();

    double updateAllPrices(FLUCTUATE_POLICY policy);

    void updatePricesWithMarketTrend();

    void updatePricesWithIndustryTrend();

    void updatePricesWithSimpleRandom();

    void buyByPlayer(Player& player, FinancialInstrument *f, int shares);

    void sellByPlayer(Player& player, FinancialInstrument *f, int shares);

    FinancialInstrument *getPointerByUniqueId(int uniqueId);

    Stock& getStockById(int id);

    Commodities& getCommodityById(int id);

    string getTypeById(int id);

    void printHoldings(Player& player, Market& market);

    void printOneProduct(Stock& stock, Holding& holding);

    void printOneProduct(Commodities& commodity, Holding& holding);

    double getStockPrice(int id);

private:
    vector<Stock> stockList;
    vector<Commodities> commoditiesList;
    const int randRange = 15;

    bool getNumberLine();

    int getRandomRange(int range);

    void setNewPrice(FinancialInstrument *f);
};

#include "Market.tpp"