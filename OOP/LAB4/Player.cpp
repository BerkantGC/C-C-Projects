#include "Player.h"

int Player::playerDamage(int attack, int enemyDefense)
{
    if(attack>enemyDefense)
        return attack-enemyDefense;
    
    else
        return 1;
}