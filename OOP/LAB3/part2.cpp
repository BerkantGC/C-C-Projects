#include <iostream>

using namespace std;

#define PI 3.14
 
inline double areaSphereByValue(double radius){
    return PI*radius*radius;
}

inline void areaSphereByReference(double *radius){
    double tmp = *radius;

    *radius = PI*(tmp)*(tmp);

    cout << "\n" << *radius; 
}

int main()
{
    double x[10];

    // for (int i = 1; i <= 10; i++)
    // {
    //     x[i] = i;
    //     double area = areaSphereByValue(x[i]);
    //     cout << area << "\n";
    // }
    
    double radius = 3.00;
    areaSphereByReference(&radius);
    
    return 0;
}
