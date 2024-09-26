//
// Created by wittg on 26/09/2024.
//

#ifndef DICE_H
#define DICE_H
#include <random>

#include <iostream>


enum EDiceType
{
    DT_D4 = 4,
    DT_D6 = 6,
    DT_D8 = 8,
    DT_D10 = 10,
    DT_D12 = 12,
    DT_D20 = 20
};


class Dice {
private:
public:
    static int RollDice(EDiceType diceType);


};



#endif //DICE_H
