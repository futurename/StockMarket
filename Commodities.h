#pragma  once
#include <iostream>
#include "FinancialInstrument.h"

using namespace std;

class Commodities : public FinancialInstrument{
public:
    void printInfo() const override;
};