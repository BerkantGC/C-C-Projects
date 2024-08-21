#include "Car.cpp"
#include "FormulaCar.cpp"
#include "Motorcycle.cpp"
#include "RacingVehicle.cpp"
#include "Track.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Car car("Car", 200, 0.7, "Toyota", "Supra", "John Doe");
    Motorcycle motorcycle("Motorcycle", 180, 0.9, "YAMAHA", "R1", "Jane Doe");
    FormulaCar formulaCar("FormulaCar", 300, 0.95, "Ferrari", "5F21", "Charles Roberts");

    Track track(50, 0.2, 0.4, 0.3, 0.1);

    car.display();
    motorcycle.display();
    formulaCar.display();

    cout << "Car : " << car.race(track) << "\n";
    cout << "Motorcycle : " << motorcycle.race(track) << "\n";
    cout << "Formula Car : " << formulaCar.race(track) << "\n";

    car.tuning(50,50);
    motorcycle.tuning(50,50);
    formulaCar.tuning(50,50);

    car.display();
    motorcycle.display();
    formulaCar.display();

    cout << "Car : " << car.race(track) << "\n";
    cout << "Motorcycle : " << motorcycle.race(track) << "\n";
    cout << "Formula Car : " << formulaCar.race(track) << "\n";

    return 0;
}
