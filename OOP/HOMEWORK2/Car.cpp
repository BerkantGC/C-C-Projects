#include <iostream>
#include "Car.h"
#include "RacingVehicle.cpp"
using namespace std;

Car::race(){
    double distance = track.getLength();
        double topSpeedWithAero = topSpeed + aerodynamics * 0.1;
        
        double time = 0;

        double highHandlingPart;
        double mediumHandlingPart;
        double cruisePart = distance * track.getCruiseSpeedPct()/(topSpeed*0.5);
        double topSpeedPart = distance * track.getTopSpeedPct() / topSpeedWithAero;
        
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