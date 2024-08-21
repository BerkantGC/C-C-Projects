#include "FormulaCar.h"

FormulaCar::race(Track track) {
        double distance = track.getLength();
        double topSpeedWithAero = topSpeed + aerodynamics * 0.3;
        
        double time = 0;

        double highHandlingPart;
        double mediumHandlingPart;
        double cruisePart = distance * track.getCruiseSpeedPct()/(topSpeedWithAero*0.5);
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