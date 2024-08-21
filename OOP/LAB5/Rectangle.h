#include <iostream>
#include "Shape.h"

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

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(string name, double width, double height) : Shape(name) {
        this->width = width;
        this->height = height;
    }

    double getWidth() {
        return width;
    }

    void setWidth(double width) {
        this->width = width;
    }

    double getHeight() {
        return height;
    }

    void setHeight(double height) {
        this->height = height;
    }

    double getArea() override{
        return width * height;
    }

    double getPerimeter() override{
        return 2 * (width + height);
    }
};


