#include <iostream>
#include "Monster.h"
#include "Player.h"

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    Player player; 
    Monster monster;

    player.health = (rand()%150) + 100;
    monster.health = (rand()%150) + 100;

    player.attackPower = (rand()%40)+10;
    monster.attackPower = (rand()%40)+10;

    player.defense = (rand()%20) + 10;
    monster.defense = (rand()%20) + 10;

    cout << "Player is entering the arena:\n" << "Health: " << player.health << "\nAttack Power : " << player.attackPower << "\nDefence : " << player.defense << "\n\n";
    cout << "Monster is entering the arena:\n" << "Health: " << monster.health << "\nAttack Power : " << monster.attackPower << "\nDefence : " << monster.defense << "\n\n";
    while (1)
    {
        cout << "Player is attacking...\n";
        int playerDamage = player.playerDamage(player.attackPower, monster.defense);
        cout << "Player Damage : " << playerDamage << "\n";
        monster.health -= playerDamage;

        if(monster.health <= 0)
            monster.health = 0;
        cout << "Monster health : " << monster.health << "\n\n";

        if(monster.health == 0)
        {
            cout << "Monster is defeated!";
            return 1;
        }

        cout << "Monster is attacking...\n";
        int monsterDamage = monster.monsterDamage(monster.attackPower, player.defense);
        cout << "Monster Damage : " << monsterDamage << "\n";
        monster.health -= monsterDamage;

        if(player.health <= 0)
            player.health = 0;
        cout << "Player health : " << player.health << "\n\n";

         if(player.health == 0)
         {
            cout << "Player is defeated!";
            return 1;
         }
    }
    

    return 0;
}
