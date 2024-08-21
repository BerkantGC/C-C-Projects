 #include <iostream>
#include <string>
#include <cmath>

#include "Planet.h"
#include "Spaceship.h"

void main()
{
    Planet planets[9] = {
        Planet("Mercury", 0.39, 4879),
        Planet("Venus", 0.72, 12104),
        Planet("Earth", 1.0, 12756),
        Planet("Mars", 1.52, 6792),
        Planet("Jupiter", 5.2, 142984),
        Planet("Saturn", 9.58, 120536),
        Planet("Uranus", 19.18, 51118),
        Planet("Neptune", 30.07, 49528),
        Planet("Pluto", 39.48, 2370)
    };

    string spaceshipName;
    double spaceshipFuel;
    cout << "Enter spaceship name: ";
    cin >> spaceshipName;
    cout << "Enter initial fuel amount: ";
    cin >> spaceshipFuel;

    Spaceship spaceship(spaceshipName, spaceshipFuel);

    int choice = -1;
    while (choice != 0) {
        cout << endl << "Choose a planet to travel to " << endl;
        for (int i = 0; i < 9; i++) {
            cout << i + 1 << ". " << planets[i].getName() << endl;
        }
        cin >> choice;

        if (choice > 0 && choice <= 9) {
            Planet& destination = planets[choice - 1];
            spaceship.travel(destination, 0.1);
            spaceship.displayInfo();
        }
        else if (choice != 0) {
            cout << "Invalid!" << endl;
        }
    }

}
 