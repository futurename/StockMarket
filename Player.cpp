
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "FinancialInstrument.h"

using namespace std;


// All player must have a name.
Player::Player(string playerName, int cash) {
    this->playerName = playerName;
    this->cash = cash;
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
vector<Holding> Player::getHodings() {
    return holdings;
}

void Player::setHolding(vector<Holding> holdings) {
    this->holdings = holdings;
}


void Player::updateHolding(Holding &holdingToUpdate, const Holding &holdingToAdd) {
    //    int shares;
    //double totalValue;
    holdingToUpdate.setShares(holdingToUpdate.getShares() + holdingToAdd.getShares());
    holdingToUpdate.setTotalValue(holdingToUpdate.getTotalValue() + holdingToAdd.getTotalValue());

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
    // TODO

/*
  
  int index = -1;
  for(int i = 0; i < holdings.size(); i++){
    if(holdings[i] == holding){
      index = i;
      break;
    }
  }
  if(index != -1)
    holdings.erase(holdings.begin() + index);
  else
    cout << "ERROR : this financial instrument doesn't exist into your holdings" << endl;*/
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
int Player::MaxShareAtPrice(double price) {
    return (cash / price);
}

void Player::autoPlay() {

}



