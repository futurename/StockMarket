#include <iostream>
#include <fstream>
#include <algorithm>
#include "Market.h"

void initMarket(Market &market, int &i);

void printMainMenu();

void tradeStocks(Market &market, Player &player);

void tradeCommodities(Market &market, Player &player);

bool valideInput(string basicString);

bool valideProductId(int id, const string &type, Market *market);

bool valideExistHolding(int id,const string& type, Player &player);

static int dayCounter = 1;
static int uniqueCounter = 0;
const int DAYS_LIMIT = 10;

using namespace std;

int main() {

    srand(time(nullptr));

    Market market;

    Player player("Kishan");

    initMarket(market, uniqueCounter);

    cout << "@@@@ Current version can buy/sell stocks, MAX 10 days @@@@" << endl << endl;

    market.printHoldings(player, market);

    string userInput;

    while (dayCounter < DAYS_LIMIT) {
        printMainMenu();
        getline(cin, userInput);

        if (valideInput(userInput)) {
            switch (stoi(userInput)) {
                case 1:
                    tradeStocks(market, player);
                    break;
                case 2:
                    tradeCommodities(market, player);
                    break;
                case 3:
                    market.printHoldings(player, market);
                    break;
                case 4:
                    dayCounter++;
                    market.updateAllPrices(Market::SIMPLE_RAMDOM);
                    break;
                case 5:
                    exit(0);
                default:
                    cout << "No such choice, please try again.." << endl;
            }
        }
    }

    return 0;
}

bool valideInput(string basicString) {
    if (basicString.empty()) {
        return false;
    }
    for (char c: basicString) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

Commodities *askUserWhichCommodity(Market &market) {
    vector<Commodities> *commodities = market.getCommoditiesList();

    while (1) {
        for (unsigned int i = 0; i < commodities->size(); i++) {
            cout << i + 1 << ". ";
            (*commodities)[i].printInfo();
        }
        string userInput;
        int indexCommodity;
        getline(cin, userInput);
        if (valideInput(userInput)) {
            indexCommodity = stoi(userInput);
            return (&((*commodities)[indexCommodity - 1]));
        }
    }
    // We never arrive here
    return (&(*commodities)[0]);
}


void tradeCommodities(Market &market, Player &player) {
    // TODO : modify the setw
    cout << setw(10) << setfill('*') << "" << " Trade Comodities Menu " << setw(10) << "" << endl;
    cout << setfill(' ');
    cout << "Do you want to buy or sell commodities" << endl;
    cout << "1. Buy" << endl;
    cout << "2. Sell" << endl;
    cout << "3. Main menu" << endl;
    cout << setfill('*') << setw(51) << "" << endl;
    cout << setfill(' ');

    Commodities *commodity;
    int nbShares;

    string userInput, userInput2;

    do {
        getline(cin, userInput);
    } while (!valideInput(userInput));

    switch (stoi(userInput)) {
        case 1: // Buy
            commodity = askUserWhichCommodity(market);
            int maxSharesToBuy;
            maxSharesToBuy = player.getMaxShareAtPrice(commodity->getCurrentPrce());
            if (maxSharesToBuy == 0) {
                cout << "Sorry, you have no enought cash to buy this stock!" << endl;
            } else {

                cout << "You can buy up to <" << maxSharesToBuy << "> shares" << endl;
                while (true) {
                    do {
                        cout << "How many share do you want to buy? ";
                        getline(cin, userInput2);
                    } while (!valideInput(userInput2));
                    nbShares = stoi(userInput2);
                    if (nbShares > player.getMaxShareAtPrice(commodity->getCurrentPrce()))
                        cout << "You can't buy these many <" << nbShares << ">" << endl;
                    else
                        break;
                }

                market.buyByPlayer(player, commodity, nbShares);

                cout << endl << "Now, your current holdings are: " << endl;
                market.printHoldings(player,market);
                tradeStocks(market, player);
            }
            break;
        case 2:
            cout << "You will sell. BUILDING...." << endl;
            break;
        default:
            cout << "Main menu" << endl;
            printMainMenu();
            break;
    }
}

Stock *askUserWhichStock(Market &market, bool ifPrint, Player& player) {
    vector<Stock> *stocks = market.getStockList();

    while (true) {
        if(ifPrint) {
            for (unsigned int i = 0; i < stocks->size(); i++) {
                (*stocks)[i].printInfo();
            }
        }
        string userInput;
        int stockIndex;
        if(ifPrint) {
            do {
                cout << "Which stock to process?" << endl;
                getline(cin, userInput);
            } while (!valideInput(userInput) || !valideProductId(stoi(userInput), "Stock", &market));
        }else{
            do {
                cout << "Which stock to process?" << endl;
                getline(cin, userInput);
            } while (!valideInput(userInput) || !valideProductId(stoi(userInput), "Stock", &market) || !valideExistHolding(stoi(userInput), "Stock", player));
        }

        stockIndex = stoi(userInput);
        return (&((*stocks)[stockIndex - 1]));

    }
    // We never arrive here
    return (&(*stocks)[0]);
}

bool valideExistHolding(int id, const string& type, Player &player) {
    for(Holding h: player.getHodings()){
        if(h.getUniqueID() == id - 1){
            return true;
        }
    }
    return false;
}

void tradeStocks(Market &market, Player &player) {
    // TODO : modify the setw
    cout << setw(10) << setfill('*') << "" << " Trade stocks Menu " << setw(10) << "" << endl;
    cout << setfill(' ');
    cout << "Do you want to buy or sell stock" << endl;
    cout << "1. Buy" << endl;
    cout << "2. Sell" << endl;
    cout << "3. Main menu" << endl;
    cout << setfill('*') << setw(51) << "" << endl;
    cout << setfill(' ');

    Stock *stock;
    int nbShares;

    string userInput, userInput2;
    getline(cin, userInput);
    if (valideInput(userInput)) {
        switch (stoi(userInput)) {
            case 1:
                stock = askUserWhichStock(market, true, player);
                int maxSharesToBuy;
                maxSharesToBuy = player.getMaxShareAtPrice(stock->getCurrentPrce());
                if (maxSharesToBuy == 0) {
                    cout << "Sorry, you have no enough cash to buy this stock!" << endl;
                } else {
                    cout << "You can buy up to <" << maxSharesToBuy << "> shares" << endl;
                    while (true) {
                        do {
                            cout << "How many share do you want to buy? ";
                            getline(cin, userInput2);
                        } while (!valideInput(userInput2));
                        nbShares = stoi(userInput2);
                        if (nbShares > maxSharesToBuy)
                            cout << "You can't buy these many <" << nbShares << ">" << endl;
                        else
                            break;
                    }

                    market.buyByPlayer(player, stock, nbShares);

                    cout << endl << "Now, your current holdings are: " << endl;
                    market.printHoldings(player,market);
                }
                break;

            case 2:
                market.printHoldings(player,market);
                stock = askUserWhichStock(market, false, player);

                int maxSharesToSell;
                maxSharesToSell = player.getMaxSharesToSell(stock->getUniqueId());

                if (maxSharesToSell == 0) {
                    cout << "Sorry, you have no shares for selling" << endl;
                } else {
                    cout << "You can sell up to <" << maxSharesToSell << "> shares" << endl;
                    while (true) {
                        do {
                            cout << "How many share do you want to sell? ";
                            getline(cin, userInput2);
                        } while (!valideInput(userInput2));

                        nbShares = stoi(userInput2);
                        if (nbShares > maxSharesToSell)
                            cout << "You can't sell these many <" << nbShares << ">" << endl;
                        else
                            break;
                    }

                    market.sellByPlayer(player, stock, nbShares);

                    cout << endl << "Now, your current holdings are: " << endl;
                    market.printHoldings(player, market);
                }
                break;

            default:
                cout << "Main menu" << endl;
                printMainMenu();
                break;

        }
    }
}


bool valideProductId(int id, const string &type, Market *market) {
    if (type == "Stock") {
        vector<Stock> *list = market->getStockList();
        auto it = find_if(list->begin(), list->end(), [&id](Stock &stock) {
            return stock.getUniqueId() == id - 1;
        });
        if (it != list->end()) {
            return true;
        }
        return false;
    }

    if (type == "Commodities") {
        for (Commodities &commodity : *market->getCommoditiesList()) {
            if (id == commodity.getUniqueId()) {
                return true;
            }
        }
        return false;
    }
    return false;
}


void printMainMenu() {
    cout << setw(16) << setfill('*') << "" << " Main Menu (Day:"
         << setfill(' ') << setw(2) << dayCounter << ") " << setfill('*')
         << setw(16) << "" << endl;
    cout << setfill(' ');
    cout << "1. Trading stocks today?" << endl
         << "2. Trading commodities today?" << endl
         << "3. Print holdings?" << endl
         << "4. Bypass today?" << endl
         << "5. Quit?" << endl
         << setfill('*') << setw(51) << "" << endl;
    cout << setfill(' ');
}

void initMarket(Market &market, int &uniqueCounter) {

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

    Commodities commodities1(uniqueCounter++, "Goal", Commodities::METAL, 2345.53);
    Commodities commodities2(uniqueCounter++, "Silver", Commodities::METAL, 687.66);
    Commodities commodities3(uniqueCounter++, "Steel", Commodities::METAL, 1982.10);
    Commodities commodities4(uniqueCounter++, "Oil", Commodities::ENERGY, 45.32);
    Commodities commodities5(uniqueCounter++, "Coal", Commodities::ENERGY, 656.09);
    Commodities commodities6(uniqueCounter++, "Grain", Commodities::AGRICULTURE, 1209.44);
    Commodities commodities7(uniqueCounter++, "Sugar", Commodities::AGRICULTURE, 2120.44);
    Commodities commodities8(uniqueCounter++, "Cotton", Commodities::AGRICULTURE, 896.44);

    market.addOne(market.getCommoditiesList(), commodities1);
    market.addOne(market.getCommoditiesList(), commodities2);
    market.addOne(market.getCommoditiesList(), commodities3);
    market.addOne(market.getCommoditiesList(), commodities4);
    market.addOne(market.getCommoditiesList(), commodities5);
    market.addOne(market.getCommoditiesList(), commodities6);
    market.addOne(market.getCommoditiesList(), commodities7);
    market.addOne(market.getCommoditiesList(), commodities8);

}
