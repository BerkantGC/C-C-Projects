#include <iostream>
#include "Track.cpp"
#include "RacingVehicle.h"

using namespace std;

class FormulaCar: public RacingVehicle{
private: 
    double aerodynamics;
    
public: 
    FormulaCar(string vehicleType, double topSpeed, double handling, string manufacturer,
        string model, string driverName, double aerodynamics)
        : RacingVehicle(vehicleType, topSpeed, handling, manufacturer, model, driverName),
          aerodynamics(aerodynamics)
    {
    }

    double race(Track track) override {}
};