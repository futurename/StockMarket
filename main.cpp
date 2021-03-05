
#include <iostream>
#include <vector>
#include "Market.h"

using namespace std;

int main() {
    Market market;
    static int uniqueCounter = 0;

    Stock stock1("Google", "GOGL", uniqueCounter++);
    Stock stock2("Apple", "APPL", uniqueCounter++);

    market.addOne(market.getStockList(), stock1);
    market.addOne(market.getStockList(), stock2);

    market.print(market.getStockList(),0);

    market.removeOne(market.getStockList(), 0);

    cout << "size after deletion: " << market.getStockList()->size() << endl;
    market.print(market.getStockList(), 2, 0);

    return 0;
}
