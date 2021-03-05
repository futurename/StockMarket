/*
 Created by Wei Wang on 3/5/2021 005.
*/

#include "Holding.h"


Holding::Holding(int uniqueId, int shares, double totalValue){
  this->uniqueId = uniqueId;
  this->shares = shares;
  this->totalValue = totalValue;

}

int Holding::getUniqueID(){
  return(uniqueId);
}

int Holding::getShares(){
  return(shares);
}

double Holding::getTotalValue(){
  return totalValue;
}

void Holding::setShares(int newShares){
  shares = newShares;
}

void Holding::setTotalValue(double newValue){
  totalValue = newValue;
}



