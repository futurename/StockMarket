
#include <iostream>

using namespace std;

class Stock{
private:
    string companyName;
    string tickerSymbol;
    double openPrice;
    double closePrice;
    int volumeTraded;

public:
    Stock(string name, string symbol);
    string getCompanyName();
    double getOpenPrice();
    double getClosePrice();
    int getVolumeTraded();
};