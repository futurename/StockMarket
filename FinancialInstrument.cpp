#include "FinancialInstrument.h"

FinancialInstrument::SetName(string passedName){
  name = passedName;
}

FinancialInstrument::SetCurrentPrice(double passedCurrentPrice){
  currentPrice = passedCurrentPrice;
}

FinancialInstrument::SetAvailableVolume(int passedAvailableVolume){
  availableVolume = passedAvailableVolume;
}

string FinancialInstrument::GetName(){
  return name;
}

double FinancialInstrument::GetCurrentPrce(){
  return price;
}

int FinancialInstrument::GetAvailableVolume(){
  return availableVolume;
}