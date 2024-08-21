#include <iostream>
#include "Shape.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "Triangle.cpp"

void main()
{
    Rectangle rect("Rect1", 5, 10);
    Circle circle("Circle1", 3);
    Triangle tri("Tri1", 3, 4, 5);

    cout << "Rectangle " << rect.getName() << ": " << endl;
    cout << "  Width: " << rect.getWidth() << endl;
    cout << "  Height: " << rect.getHeight() << endl;
    cout << "  Area: " << rect.getArea() << endl;
    cout << "  Perimeter: " << rect.getPerimeter() << endl;

    cout << "Circle " << circle.getName() << ": " << endl;
    cout << "  Radius: " << circle.getRadius() << endl;
    cout << "  Area: " << circle.getArea() << endl;
    cout << "  Perimeter: " << circle.getPerimeter() << endl;

    cout << "  Triangle " << tri.getName() << ": " << endl;
    cout << "  SideA: " << tri.getSideA() << endl;
    cout << "  SideB: " << tri.getSideB() << endl;
    cout << "  SideC: " << tri.getSideC() << endl;
    cout << "  Area: " << tri.getArea() << endl;
    cout << "  Perimeter: " << tri.getPerimeter() << endl;

}