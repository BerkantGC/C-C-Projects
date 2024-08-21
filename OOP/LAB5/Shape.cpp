#include "Shape.h"

Shape::Shape(string name)
{
}

void Shape::getName(string name)
{
    return name;
}

void Shape::setName(string name, string newName)
{
    name = newName;
}

virtual double Shape::getArea()
{
    return 0.0;
}

virtual double Shape::getPerimeter()
{
    return 0.0;
}
