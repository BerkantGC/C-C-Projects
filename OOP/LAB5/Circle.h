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

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string name, double radius) : Shape(name) {
        setRadius(radius);
    }

    double getRadius() {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    double getArea() override{
        return M_PI * radius * radius;
    }

    double getPerimeter() override{
        return 2 * M_PI * radius;
    }
};