#include <iostream>

using namespace std;

class Track {
private:
    int length;
    double topSpeedPct;
    double highHandlingPct;
    double mediumHandlingPct;
    double cruiseSpeedPct;

public:
    Track(int length, double topSpeedPct, double highHandlingPct, double mediumHandlingPct, double cruiseSpeedPct) : 
    length(length), topSpeedPct(topSpeedPct), highHandlingPct(highHandlingPct), mediumHandlingPct(mediumHandlingPct), 
    cruiseSpeedPct(cruiseSpeedPct)
    {
        double totalPct = topSpeedPct + highHandlingPct + mediumHandlingPct + cruiseSpeedPct;
        if (totalPct != 1.0) {
            cout << "Percentage values should always be equal to 1.0\n";
        }
    }

    int getLength() {
        return length;
    }

    double getTopSpeedPct() {
        return topSpeedPct;
    }

    double getHighHandlingPct() {
        return highHandlingPct;
    }

    double getMediumHandlingPct() {
        return mediumHandlingPct;
    }

    double getCruiseSpeedPct() {
        return cruiseSpeedPct;
    }
};