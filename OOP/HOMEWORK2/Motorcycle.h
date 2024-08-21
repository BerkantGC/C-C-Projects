#include <iostream>
#include "Track.cpp"
#include "RacingVehicle.cpp"

using namespace std;

class Motorcycle: public RacingVehicle{
private: 
    double aerodynamics;
    
public: 
    Motorcycle(string vehicleType, double topSpeed, double handling, string manufacturer,
        string model, string driverName, double aerodynamics)
        : RacingVehicle(vehicleType, topSpeed, handling, manufacturer, model, driverName),
          aerodynamics(aerodynamics)
    {
    }

    double race(Track track) override {
        double distance = track.getLength();
        double topSpeedWithAero = topSpeed + aerodynamics * 0.2;
        
        double time = 0;

        double highHandlingPart;
        double mediumHandlingPart;
        double cruisePart = distance * track.getCruiseSpeedPct()/(topSpeed*0.5);
        double topSpeedPart = distance * track.getTopSpeedPct() / topSpeed;
        
        if(handling > 0.8)
        {
            highHandlingPart = distance * track.getHighHandlingPct()/topSpeedWithAero;
        }
        else {
            highHandlingPart = distance * track.getHighHandlingPct()/(topSpeedWithAero*0.8);
        }
        if(handling > 0.6)
        {
            mediumHandlingPart = distance * track.getMediumHandlingPct()/topSpeedWithAero;
        }
        else {
            mediumHandlingPart = distance * track.getMediumHandlingPct()/(topSpeedWithAero*0.9);
        }

        time = mediumHandlingPart + highHandlingPart + cruisePart + topSpeedPart;
        return time;
    }
}