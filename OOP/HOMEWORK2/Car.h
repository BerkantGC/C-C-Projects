#include <iostream>
#include "Track.cpp"
#include "RacingVehicle.cpp"

using namespace std;

class Car: public RacingVehicle{
private: 
    double aerodynamics;
    
public: 
    Car(string vehicleType, double topSpeed, double handling, string manufacturer,
        string model, string driverName, double aerodynamics)
        : RacingVehicle(vehicleType, topSpeed, handling, manufacturer, model, driverName),
          aerodynamics(aerodynamics)
    {
    }

    double race(Track track) override {}

}