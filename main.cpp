
#include <iostream>
#include <vector>
#include "Market.h"


using namespace std;

int main() {
    Market market;
    Stock stock("Google", "GOGL");
    Stock *stockptr = &stock;

    vector<FinancialInstrument *> list;

    list.push_back(stockptr);

    list.at(0)->printInfo();

    return 0;
}
