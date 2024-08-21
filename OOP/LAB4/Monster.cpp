#include "Monster.h"

int Monster::monsterDamage(int attack, int enemyDefense)
{
    if(attack>enemyDefense)
        return attack-enemyDefense;
    
    else
        return 1;
}