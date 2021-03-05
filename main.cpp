
#include <iostream>
#include <vector>
#include "Market.h"

using namespace std;

int main() {
    Market market;
    static int uniqueCounter = 0;

    Stock stock1("Google", "GOGL", uniqueCounter++, Stock::INDUSTRY::DIGITAL, 243.34);
    Stock stock2("Apple", "APPL", uniqueCounter++, Stock::INDUSTRY::DIGITAL, 435.34);

    market.addOne(market.getStockList(), stock1);
    market.addOne(market.getStockList(), stock2);

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
