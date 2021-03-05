
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "FinancialInstrument.h"

using namespace std;



    // All player must have a name. 
Player::Player(string playerName, int cash){
  this->playerName = playerName;
  this->cash = cash;
}

string Player::getName(){
  return playerName;
}

void Player::setName(string name){
  playerName = name;
}

double Player::getCash(){
  return cash;
}
    
void Player::setCash(double cash){
  this->cash = cash;
}

// To delete or not?
vector<FinancialInstrument *> Player::getHodings(){
  return holdings;
}

void Player::setHolding(vector<FinancialInstrument *> holdings){
  this->holdings = holdings;
}

void Player::addHoding(FinancialInstrument* fi){
  this->holdings.push_back(fi);
}

void Player::removeHolding(FinancialInstrument *fi){
  int index = -1;
  for(int i = 0; i < holdings.size(); i++){
    if(holdings[i] == fi){
      index = i;
      break;
    }
  }
  if(index != -1)
    holdings.erase(holdings.begin() + index);
  else
    cout << "ERROR : this financial instrument doesn't exist into your holdings" << endl;
}