#include <iostream>
#include <cmath>

using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }
};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(string name, double sideA, double sideB, double sideC) : Shape(name) {
        setSideA(sideA);
        setSideB(sideB);
        setSideC(sideC);
    }

    double getSideA() {
        return sideA;
    }

    void setSideA(double sideA) {
        this->sideA = sideA;
    }

    double getSideB() {
        return sideB;
    }

    void setSideB(double sideB) {
        this->sideB = sideB;
    }

    double getSideC() {
        return sideC;
    }

    void setSideC(double sideC) {
        this->sideC = sideC;
    }

    double getArea() override{
        double s = (sideA + sideB + sideC) / 2.0;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double getPerimeter() override{
        return sideA + sideB + sideC;
    }
};