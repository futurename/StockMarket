/*
 Created by Wei Wang on 3/5/2021 005.
*/

#ifndef STOCKMARKET_HOLDING_H
#define STOCKMARKET_HOLDING_H


class Holding {

private:
    int uniqueId;
    int shares;
    double totalValue;

public:
    Holding(int uniqueId, int shares = 0, double totalValue= 0.0);
    int getUniqueID();
    int getShares();
    double getTotalValue();

    void setShares(int newShares);
    void setTotalValue(double newValue);


};




#endif //STOCKMARKET_HOLDING_H
