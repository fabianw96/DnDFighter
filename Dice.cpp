//
// Created by wittg on 26/09/2024.
//

#include "Dice.h"


int Dice::RollDice(EDiceType diceType)
{
    std::random_device random_device;
    std::mt19937 rng(random_device());
    
    std::uniform_int_distribution<> distribution(0, diceType);

    return distribution(rng);
}
