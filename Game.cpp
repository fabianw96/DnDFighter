//
// Created by wittg on 18/09/2024.
//

#include "Game.h"


void Game::InitGame(const EntityData& player, const std::vector<EntityData>& monsters, const std::vector<Weapon>& weapons)
{
    PopulateMonsterGroups(monsters);
    ChooseRandomMonster(player);
}

void Game::PopulateMonsterGroups(const std::vector<EntityData>& monsters)
{
    for (const auto & monster : monsters)
    {
        if (monster.GetLevel() < 5)
        {
            m_lowLevelMonster.emplace_back(monster);
        }
        else if (monster.GetLevel() >= 5 && monster.GetLevel() < 10)
        {
            m_midLevelMonster.emplace_back(monster);
        }
        else
        {
            m_highLevelMonster.emplace_back(monster);
        }
    }
}

void Game::ChooseRandomMonster(const EntityData& player)
{
    std::random_device random_device;
    std::mt19937 rng(random_device());

    if (player.GetLevel() <= 10)
    {
        std::uniform_int_distribution<> distribution(0, m_lowLevelMonster.size());
        StartFight(player, m_lowLevelMonster[distribution(rng)]);
    }
    else if (player.GetLevel() > 10 && player.GetLevel() < 20)
    {
        std::uniform_int_distribution<> distribution(0, m_midLevelMonster.size());
        StartFight(player, m_midLevelMonster[distribution(rng)]);
    }
    else
    {
        std::uniform_int_distribution<> distribution(0, m_highLevelMonster.size());
        StartFight(player, m_highLevelMonster[distribution(rng)]);
    }
}

void Game::StartFight(const EntityData& player, const EntityData& chosenMonster)
{
    int playerInit = player.GetAbilityModifier(player.GetDexterity());
    int monsterInit = chosenMonster.GetAbilityModifier(chosenMonster.GetDexterity());

    EntityData attacker;
    EntityData defender;

    //dmg is dealt if roll is even or higher to enemy AC
    //dmg is then dealt with dmg die
    std::cout << "Today fighting: " << player.GetName() << " vs. " << chosenMonster.GetName() << "\n";
    std::cout << player.GetHealthPoints() << " : " << chosenMonster.GetHealthPoints();
    std::cout << "Roll for Initiative!\n";
    playerInit += Dice::RollDice(DT_D20);
    std::cout << player.GetName() << " rolled a " << playerInit << "\n";
    monsterInit += Dice::RollDice(DT_D20);
    std::cout << chosenMonster.GetName() << " rolled a " << monsterInit << "\n";

    if (playerInit > monsterInit) {
        std::cout << player.GetName() << " attacks first!\n";
        attacker = player;
        defender = chosenMonster;
        Attack(attacker, defender);
    } else {
        std::cout << chosenMonster.GetName() << " attacks first!\n";
        attacker = chosenMonster;
        defender = player;
        Attack(attacker, defender);
    }
}


//TODO: Implement weapons!
void Game::Attack(const EntityData& attacker, const EntityData& defender) {
    int hitRoll = Dice::RollDice(DT_D20) + attacker.GetAbilityModifier(attacker.GetStrength());

    if (defender.GetHealthPoints() > 0 && attacker.GetHealthPoints() > 0) {
        if (hitRoll < defender.GetArmorClass())
        {
            std::cout << attacker.GetName() << " rolled a " << hitRoll << " against " << defender.GetName() << "'s AC of " << defender.GetArmorClass() <<". The attack missed the Target\n";
        }
        else
        {
            std::cout << attacker.GetName() << " rolled a " << hitRoll << " against " << defender.GetName() << "'s AC of " << defender.GetArmorClass() <<". The attack hit!\n";
            std::cout << "Rolling for damage!\n";
            int damageDealt = Dice::RollDice(DT_D6) + attacker.GetAbilityModifier(attacker.GetStrength());
            std::cout << attacker.GetName() << " hit " << defender.GetName() << " for " << damageDealt << " Damage!\n";
            defender.GetHit(damageDealt);
        }

        Attack(defender, attacker);
    }
    else
    {
        std::cout << "The fight ended! " << attacker.GetName() << " : " << attacker.GetHealthPoints() << "HP left\n";
        std::cout << "The fight ended! " << defender.GetName() << " : " << defender.GetHealthPoints() << "HP left\n";
    }
}







