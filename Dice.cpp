//
// Created by wittg on 26/09/2024.
//

#include "Dice.h"


//Roll dice depending on dicetype
int Dice::RollDice(EDiceType diceType)
{
    std::random_device random_device;
    std::mt19937 rng(random_device());
    
    std::uniform_int_distribution<> distribution(1, diceType);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    return distribution(rng);
}
