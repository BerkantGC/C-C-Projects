#include <iostream>

using namespace std;

class Planet
{
    private:
        string name;
        double distanceFromSun;;
        double diameter;

    public:
        Planet(string name = "Unknown", double distanceFromSun = 0, double diameter = 0){}

        string getName()
        {
            return name;
        }

        double getDistanceFromSun()
        {
            return distanceFromSun;
        }

        double getDiameter()
        {
            return diameter;
        }

        double distanceTo(const Planet& destination){
            if(destination.distanceFromSun > distanceFromSun)
            {
                return destination.distanceFromSun - distanceFromSun;
            } 
            else return distanceFromSun - destination.distanceFromSun;
        }
};