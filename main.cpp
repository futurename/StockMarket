
#include <iostream>
#include <vector>
#include "Market.h"

using namespace std;

int main() {
    Market market;
    static int uniqueCounter = 0;

    Stock stock1("Google", "GOGL", uniqueCounter++, Stock::INDUSTRY::DIGITAL, 243.34);
    Stock stock2("Apple", "APPL", uniqueCounter++, Stock::INDUSTRY::DIGITAL, 435.34);
    Stock stock3("TD BANK", "TDBK", uniqueCounter++, Stock::INDUSTRY::BANK, 120.21);
    Stock stock4("CBC BANK", "CBBK", uniqueCounter++, Stock::INDUSTRY::BANK, 56.89);
    Stock stock5("Exxon", "EXXN", uniqueCounter++, Stock::INDUSTRY::ENERGY, 21.45);
    Stock stock6("Shell", "SHEL", uniqueCounter++, Stock::INDUSTRY::ENERGY, 167.65);
    Stock stock7("Chevron", "CHVN", uniqueCounter++, Stock::INDUSTRY::ENERGY, 88.97);
    Stock stock8("Petro", "PETO", uniqueCounter++, Stock::INDUSTRY::ENERGY, 362.34);
    Stock stock9("HSBC", "HSBC", uniqueCounter++, Stock::INDUSTRY::BANK, 18.90);
    Stock stock10("EA Sports", "EASP", uniqueCounter++, Stock::INDUSTRY::DIGITAL, 345.98);

    market.addOne(market.getStockList(), stock1);
    market.addOne(market.getStockList(), stock2);
    market.addOne(market.getStockList(), stock3);
    market.addOne(market.getStockList(), stock4);
    market.addOne(market.getStockList(), stock5);
    market.addOne(market.getStockList(), stock6);
    market.addOne(market.getStockList(), stock7);
    market.addOne(market.getStockList(), stock8);
    market.addOne(market.getStockList(), stock9);
    market.addOne(market.getStockList(), stock10);

    market.print(market.getStockList(), 2);

    market.removeOne(market.getStockList(), 0);

    cout << "size after deletion: " << market.getStockList()->size() << endl;
    market.print(market.getStockList(), 2, 0);
    market.addOne(market.getStockList(), stock1);

    cout << endl;

    market.updateAllPrices(Market::SIMPLE_RAMDOM);
    market.print(market.getStockList(), 0);



    return 0;
}
