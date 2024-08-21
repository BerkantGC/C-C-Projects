#include <iostream>
using namespace std;

class Shape
{
protected:
    string name;
public:
    Shape(string name){
        this->name = name;
    }
    void getName(string name);
    void setName(string name, string newName);
    virtual double getArea();
    virtual double getPerimeter();
};

