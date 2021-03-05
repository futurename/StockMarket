
#include <iostream>
#include "Market.h"

void initMarket(Market &market, int &i);

void printMainMenu();

void tradeStocks();

void tradeCommodities();

bool valideInput(string basicString);

using namespace std;

int main() {
    Market market;
    static int uniqueCounter = 0;

    initMarket(market, uniqueCounter);

    string userInput;

    while (true) {
        printMainMenu();
        getline(cin, userInput);

        if (valideInput(userInput)) {
            switch (stoi(userInput)) {
                case 1:
                    tradeStocks();
                    break;
                case 2:
                    tradeCommodities();
                    break;
                case 3:
                    market.updateAllPrices(Market::SIMPLE_RAMDOM);
                    continue;
                case 4:
                    exit(0);
                default:
                    cout << "No such choice, please try again.." << endl;
            }
        }
        cout << "No such choice, please try again.." << endl;
    }

    market.updateAllPrices(Market::SIMPLE_RAMDOM);
    market.print(market.getStockList(), 0);
    market.print(market.getCommoditiesList(), 0);


    return 0;
}

bool valideInput(string basicString) {
    for (char c: basicString) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void tradeCommodities() {
    cout << setw(20) << setfill('*') << "" << " Trade Comodities Menu " << setw(20) << "" << endl;
    cout << setfill(' ');
    cout << "Do you want to buy or sell commodities" << endl;
    cout << "1. Buy" << endl;
    cout << "2. Sell" << endl;
    cout << setfill('*') << setw(51) << "" << endl;
    cout << setfill(' ');

    string userInput;
    getline(cin, userInput);
    if (valideInput(userInput)) {
        switch (stoi(userInput)) {
            default:
                break;
        }
    }


}

void tradeStocks() {


}

void printMainMenu() {
    cout << setw(20) << setfill('*') << "" << " Main Menu " << setw(20) << "" << endl;
    cout << setfill(' ');
    cout << "1. Trading stocks today?" << endl
         << "2. Trading commodities today?" << endl
         << "3. Bypass today?" << endl
         << "4. Quit?" << endl
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
