#pragma once

#include "FinancialInstrument"
#include <string>
using namespace std;



class Player{
  private: 
    string playerName;
    double cash;
    vector<FinancialInstrument *> holdings;

  public:
    // All player must have a name. 
    Player(string playerName, int cash = 0);

    string getName();
    void setName(string name);

    double getCash();
    void setCash(double cash);

    // To delete or not?
    vector<FinancialInstrument *> getHodings();
    void setHolding(vector<FinancialInstrument *> holdings);

    void addHoding(FinancialInstrument* fi);
    void removeHolding(FinancialInstrument *fi);

}