#pragma once
#include "Holding.h"
#include <string>

using namespace std;


class Player {
private:
    string playerName;
    double cash;
    vector<Holding> holdings;
    void updateHolding(Holding & holdingToUpdate, const Holding & holdingToAdd);

public:
    // All player must have a name. 
    Player(string playerName, int cash = 0);

    string getName();

    void setName(string name);

    double getCash();

    void setCash(double cash);

    // To delete or not?
    vector<Holding> getHodings();

    void setHolding(vector<Holding> holdings);



    // return true if the player has enought cash
    //bool validateBuy(double amount);

    // deduct the amount 
    bool modifyCash(double amount);

    // give how many shares I can buy if they cost this price
    int MaxShareAtPrice(double price);

    void addHolding(Holding holding);

    void removeHolding(Holding holding);

    void autoPlay();

    void printHoldings();


};