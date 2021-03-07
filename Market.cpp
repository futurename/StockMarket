
#include "Market.h"
#include <chrono>

vector<Stock> *Market::getStockList() {
    return &stockList;
}

vector<Commodities> *Market::getCommoditiesList() {
    return &commoditiesList;
}

double Market::updateAllPrices(FLUCTUATE_POLICY policy) {
    switch (policy) {
        case MARKET_TREND:
            updatePricesWithMarketTrend();
            break;
        case INDUSTRY_TREND:
            updatePricesWithIndustryTrend();
            break;
        default:
            updatePricesWithSimpleRandom();
            break;
    }

    return 0;
}

void Market::updatePricesWithMarketTrend() {

}

void Market::updatePricesWithIndustryTrend() {

}

void Market::updatePricesWithSimpleRandom() {
    for (Stock &s: stockList) {
        Stock *sptr = &s;
        setNewPrice(sptr);
    }

    for (Commodities &c : commoditiesList) {
        Commodities *cptr = &c;
        setNewPrice(cptr);
    }
}

bool Market::getNumberLine() {
    long int timeNow = time(0);
    int shift = getRandomRange(20);
    srand(timeNow << shift);
    return rand() % 2 == 0;
}

void Market::setNewPrice(FinancialInstrument *f) {
    long int timeNow = time(0);
    int shift = getRandomRange(20);

    srand(timeNow << shift);
    double randNum = (rand() % randRange + 1) / 100.0;
    randNum = getNumberLine() ? randNum : randNum * -1;

    f->setPreviousPrice(f->getCurrentPrce());

    f->setCurrentPrice(f->getCurrentPrce() * (randNum + 1));
}

int Market::getRandomRange(int range) {
    return rand() % range;
}

void Market::buyByPlayer(Player &player, FinancialInstrument *f, int shares) {
    if (shares > 0) {
        double value = f->getCurrentPrce() * shares;
        player.modifyCash(value * -1);
        Holding holding(f->getUniqueId(), shares, value);
        player.addHolding(holding);
    }
}

void Market::sellByPlayer(Player &player, FinancialInstrument *f, int shares) {
    if (shares > 0) {
        double value = f->getCurrentPrce() * shares;
        player.modifyCash(value);
        Holding holding(f->getUniqueId(), shares * -1, value * -1);
        player.addHolding(holding);
    }
}

FinancialInstrument *Market::getPointerByUniqueId(int uniqueId) {
    for (Stock &s: stockList) {
        if (s.getUniqueId() == uniqueId) {
            FinancialInstrument *result = &s;
            return result;
        }
    }
    for (Commodities &c: commoditiesList) {
        if (c.getUniqueId() == uniqueId) {
            FinancialInstrument *result = &c;
            return result;
        }
    }
}

Commodities &Market::getCommodityById(int id) {
    //Not validate id;
    for (Commodities &c: commoditiesList) {
        if (c.getUniqueId() == id) {
            return c;
        }
    }
}

Stock &Market::getStockById(int id) {
    //Not validate id;
    for (Stock &s: stockList) {
        if (s.getUniqueId() == id) {
            return s;
        }
    }
}

string Market::getTypeById(int id) {
    //FIXME if id not exists
    for (Stock &s: stockList) {
        if (s.getUniqueId() == id) {
            return s.getName();
        }
    }
    for (Commodities &c: commoditiesList) {
        if (c.getUniqueId() == id) {
            return c.getName();
        }
    }
    return "Nothing found";
}


void Market::printHoldings(Player &player, Market &market) {
    if (player.getHodings().size() == 0) {
        cout << "Ohh, no any holding in your account, buy something today!" << endl;
        cout << "Cash left: $" << player.getCash() << endl;
        double result = player.getTotalBenefit(market);
        cout << setw(11) << (result > -0.001 ? "Benefit: " : "Loss: ") << "$" << fixed << setprecision(2)
             << result << endl;
        cout << endl;
        return;
    }
    cout << setfill('*') << setw(49) << "" << " All Holdings " << setw(49) << "" << endl;
    for (Holding &holding : player.getHodings()) {
        int id = holding.getUniqueID();
        string type = getTypeById(id);
        if (type == "Stock") {
            Stock &stock = getStockById(id);
            printOneProduct(stock, holding);
        }
        if (type == "Commodities") {
            Commodities &commodity = getCommodityById(id);
            printOneProduct(commodity, holding);
        }
    }
    cout << "Cash left: $" << player.getCash() << endl;
    double result = player.getTotalBenefit(market);
    cout << setw(11) << (result > -0.001 ? "Benefit: " : "Loss: ") << "$" << fixed << setprecision(2)
         << result << endl;
    cout << endl;
}

void Market::printOneProduct(Stock &stock, Holding &holding) {
    cout << setfill(' ');
    cout << setw(2) << (stock.getUniqueId() + 1) << "|" << setw(11) << stock.getName()
         << "|" << setw(8) << stock.getCompanyName()
         << "|shares:" << setw(4) << holding.getShares()
         << "|cur price:$" << setw(7) << stock.getCurrentPrce()
         << "|cur value:$" << setw(8) << stock.getCurrentPrce() * holding.getShares()
         << "|cost:$" << setw(8) << fixed << setprecision(2) << holding.getTotalValue()
         << "|avg:$" << setw(7) << fixed << setprecision(2) << holding.getTotalValue() / holding.getShares()
         << "|$" <<setw(7) << stock.getCurrentPrce() * holding.getShares() - holding.getTotalValue()
         << endl;
}

void Market::printOneProduct(Commodities &commodity, Holding &holding) {
    cout << setfill(' ');
    cout << setw(2) << (commodity.getUniqueId() + 1) << "|" << setw(11) << commodity.getName()
            << "|" << setw(8) << commodity.getCommodityName()
            << "|shares: " << setw(4) << holding.getShares()
            << "|cur price: $" << setw(7) << commodity.getCurrentPrce()
            << "|cur value: $" << setw(8) << commodity.getCurrentPrce() * holding.getShares()
            << "|cost: $" << setw(8) << fixed << setprecision(2) << holding.getTotalValue()
            << "|avg: $" << setw(7) << fixed << setprecision(2) << holding.getTotalValue() / holding.getShares()
            << "|$" <<setw(7) << commodity.getCurrentPrce() * holding.getShares() - holding.getTotalValue()
                 << endl;
}

double Market::getStockPrice(int id) {
    for (Stock &s: stockList) {
        if (s.getUniqueId() == id) {
            return s.getCurrentPrce();
        }
    }
    return 0.0;
}
