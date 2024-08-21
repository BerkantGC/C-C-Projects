#include <iostream>
#include "Track.cpp"

using namespace std;

class RacingVehicle{
protected:
    string vehicleType;
    double topSpeed;
    double handling;
    string manufacturer;
    string model;
    string driverName;

public:
    RacingVehicle(string &vehicleType, double topSpeed, double handling, string &manufacturer, string &model, string &driverName) 
    : vehicleType(vehicleType), topSpeed(topSpeed), handling(handling), manufacturer(manufacturer), model(model), driverName(driverName)
    {}

    void display()
    {
        cout << "Vehicle type : " << vehicleType << "\n"
             << "Top speed: " << topSpeed << "\n"
             << "Handling : " << handling << "\n"
             << "Manufacturer : " << manufacturer << "\n"
             << "Model : " << model << "\n"
             << "Driver name : " << driverName << "\n";
    }

    virtual double race(Track &track) = 0;

    void tuning(double topSpeedPercent = 0, double handlingPercent = 0)
    {
        topSpeed *= (1 + topSpeedPercent);
        handling *= (1 + handlingPercent);
    }
};