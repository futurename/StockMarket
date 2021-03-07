
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "Market.h"

using namespace std;


// All player must have a name.
Player::Player(string playerName, double cash) {
    this->playerName = playerName;
    this->cash = cash;
    this->initFortune = cash;
}

string Player::getName() {
    return playerName;
}

void Player::setName(string name) {
    playerName = name;
}

double Player::getCash() {
    return cash;
}

void Player::setCash(double cash) {
    this->cash = cash;
}

// To delete or not?
vector<Holding> &Player::getHodings() {
    return holdings;
}

void Player::setHolding(vector<Holding> holdings) {
    this->holdings = holdings;
}


void Player::updateHolding(Holding &holdingToUpdate, Holding &holdingToAdd) {
    //    int shares;
    //double totalValue;
    holdingToUpdate.setShares(holdingToUpdate.getShares() + holdingToAdd.getShares());
    holdingToUpdate.setTotalValue(holdingToUpdate.getTotalValue() + holdingToAdd.getTotalValue());
    if(holdingToUpdate.getShares() == 0){
        removeHolding(holdingToUpdate);
    }
}

void Player::addHolding(Holding holding) {
    int index = -1;
    for (int i = 0; i < holdings.size(); i++) {
        if (holdings[i].getUniqueID() == holding.getUniqueID()) {
            index = i;
            break;
        }
    }
    if (index == -1)
        this->holdings.push_back(holding);
    else
        updateHolding(holdings[index], holding);
}

void Player::removeHolding(Holding holding) {
    for (int i = 0; i < holdings.size(); i++) {
        if (holdings.at(i).getUniqueID() == holding.getUniqueID()) {
            holdings.erase(holdings.begin() + i);
        }
    }
}

// deduct the amount 
bool Player::modifyCash(double amount) {
    if (amount < 0 && -amount > cash) {
        cout << "ERROR, the player doesn't have enought money" << endl;
        return false;
    }
    cash += amount;
    return true;
}

// give how many shares I can buy if they cost this price
int Player::getMaxShareAtPrice(double price) {
    return (cash / price);
}

void Player::autoPlay() {

}

int Player::getMaxSharesToSell(int id) {
    vector<Holding> &holdings = getHodings();
    auto it = find_if(holdings.begin(), holdings.end(),
                      [&id](Holding &holding) { return holding.getUniqueID() == id; });
    if (it != holdings.end()) {
        return it->getShares();
    } else {
        return 0;
    }
}

double Player::getTotalFortune(Market &market) {
    double result = 0.0;
    for (Holding h: holdings) {
        int id = h.getUniqueID();
        double curPrice = market.getStockPrice(id);
        result += h.getShares() * curPrice;
    }
    result += cash;
    return result;
}

double Player::getTotalBenefit(Market &market) {
    return getTotalFortune(market) - initFortune;
}

double Player::getInitFortune() {
    return initFortune;
}



