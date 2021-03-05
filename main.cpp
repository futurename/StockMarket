
#include <iostream>
#include <vector>
#include "Market.h"

using namespace std;

int main() {
    Market market;
    static int uniqueCounter = 0;

    Stock stock("Google", "GOGL", uniqueCounter++);

    market.addOne(market.getStockList(), stock);
    market.addOne(market.getStockList(), stock);

    market.getStockList()->at(0).printInfo();
    market.getStockList()->at(1).printInfo();


    market.removeOne(market.getStockList(), 0);

    cout << "size after deletion: " << market.getStockList()->size() << endl;
    market.print(market.getStockList(), 2, 0);

    return 0;
}
