#include <iostream>
#include "Planet.h"

using namespace std;

class Spaceship{
private: 
    string name;
    double fuel;
    Planet* currentLocation;
public: 
    Spaceship(string name, double fuel)
        : name(name), fuel(fuel), currentLocation(nullptr) {}
    
    string getName()
    {
        return name;
    }
    double getFuel()
    {
        return fuel;
    }
    Planet* getCurrentLocation(){
        return currentLocation;
    }

    void travel(Planet& destination, double fuelPerDistance) {
        double distance = currentLocation->distanceTo(destination);
        double fuelNeeded = distance * fuelPerDistance;

        if (fuel >= fuelNeeded) {
            cout << "Travelling from " << currentLocation->getName() << " to " << destination.getName() << std::endl;
            currentLocation = &destination;
            fuel -= fuelNeeded;
        } else {
            cout << "Not enough fuel to travel from " << currentLocation->getName() << " to " << destination.getName() << std::endl;
        }
    }

    inline void displayInfo() const {
        cout << "Spaceship Name: " << name << std::endl;
        cout << "Fuel: " << fuel << " units" << std::endl;
        if (currentLocation != nullptr) {
            cout << "Current Location: " << currentLocation->getName() << std::endl;
        } else {
            cout << "Current Location: N/A" << std::endl;
        }
    }
};