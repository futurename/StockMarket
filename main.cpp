#include <iostream>
#include "Market.h"

void initMarket(Market &market, int &i);

void printMainMenu();

void tradeStocks(Market& market, Player &player);

void tradeCommodities(Market& market, Player &player);

bool valideInput(string basicString);

using namespace std;

int main() {
    Market market;
    static int uniqueCounter = 0;
    Player player("Kishan", 300);

    initMarket(market, uniqueCounter);

    string userInput;
    bool flag = true;

    while (flag) {
        flag = false;
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
                    market.updateAllPrices(Market::SIMPLE_RAMDOM);
                    continue;
                case 4:
                    exit(0);
                default:
                    cout << "No such choice, please try again.." << endl;
                    flag = true;
            }
            
        }
    }

    cout << "The Market will updates: " << endl;
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

Commodities* askUserWhichCommodity(Market &market){
  vector<Commodities>* commodities = market.getCommoditiesList();
  
  while(1){
    for(unsigned int i = 0; i < commodities->size(); i++ ){
      cout << i + 1 << ". ";
      (*commodities)[i].printInfo();
      cout << endl;
    }
    string userInput;
    int indexCommodity;
    getline(cin, userInput);
    if (valideInput(userInput)) {
        indexCommodity = stoi(userInput);
        return(&((*commodities)[indexCommodity - 1]));
    }
  }
  // We never arrive here
  return(&(*commodities)[0]);
}



void tradeCommodities(Market &market, Player &player) {  
  // TODO : modify the setw
  cout << setw(10) << setfill('*') << "" << " Trade Comodities Menu " << setw(10) << "" << endl;
  cout << setfill(' ');
  cout << "Do you want to buy or sell commodities" << endl;
  cout << "1. Buy" << endl;
  cout << "2. Sell" << endl;
  cout << setfill('*') << setw(51) << "" << endl;
  cout << setfill(' ');

  Commodities* commodity;
  int nbShares;

  string userInput, userInput2;
  getline(cin, userInput);
      if (valideInput(userInput)) {
          switch (stoi(userInput)) {
            case 1: // Buy          
              commodity = askUserWhichCommodity(market);

              cout << "You can buy until " <<
              player.MaxShareAtPrice(commodity->getCurrentPrce()) << "shares" << endl;              
              while(1){
                do{
                  cout << "How many share do you want to buy? ";
                  getline(cin, userInput2);
                }while (!valideInput(userInput2));
                nbShares = stoi(userInput2);
                if(nbShares > player.MaxShareAtPrice(commodity->getCurrentPrce()))
                  cout << "You can't buy so many" << endl;
                else 
                  break;
              }

              market.buyByPlayer(player, commodity, nbShares);

              cout << "Now, your current holdings are: "<< endl;
              market.printHoldings(player);

              break;
            case 2:
              cout << "You will sell. BUILDING...." << endl;


              break; 
            default: 
              break;
          }
      }


}

Stock* askUserWhichStock(Market &market){
  vector<Stock>* stocks = market.getStockList();
  
  while(1){
    for(unsigned int i = 0; i < stocks->size(); i++ ){
      cout << i + 1 << ". ";
      (*stocks)[i].printInfo();
      cout << endl;
    }
    string userInput;
    int indexCommodity;
    getline(cin, userInput);
    if (valideInput(userInput)) {
        indexCommodity = stoi(userInput);
        return(&((*stocks)[indexCommodity - 1]));
    }
  }
  // We never arrive here
  return(&(*stocks)[0]);
}

void tradeStocks(Market &market, Player &player) {
      // TODO : modify the setw
  cout << setw(10) << setfill('*') << "" << " Trade stocks Menu " << setw(10) << "" << endl;
  cout << setfill(' ');
  cout << "Do you want to buy or sell stock" << endl;
  cout << "1. Buy" << endl;
  cout << "2. Sell" << endl;
  cout << setfill('*') << setw(51) << "" << endl;
  cout << setfill(' ');

  Stock* stock;
  int nbShares;

  string userInput, userInput2;
  getline(cin, userInput);
      if (valideInput(userInput)) {
          switch (stoi(userInput)) {
            case 1: // Buy          
              stock = askUserWhichStock(market);

              cout << "You can buy until " <<
              player.MaxShareAtPrice(stock->getCurrentPrce()) << "shares" << endl;              
              while(1){
                do{
                  cout << "How many share do you want to buy? ";
                  getline(cin, userInput2);
                }while (!valideInput(userInput2));
                nbShares = stoi(userInput2);
                if(nbShares > player.MaxShareAtPrice(stock->getCurrentPrce()))
                  cout << "You can't buy so many" << endl;
                else 
                  break;
              }

              market.buyByPlayer(player, stock, nbShares);

              cout << "Now, your current holdings are: "<< endl;
              market.printHoldings(player);

              break;
            case 2:
              cout << "You will sell. BUILDING...." << endl;


              break; 
            default: 
              break;
          }
      }

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
