#include <iostream>

using namespace std;

#define PI 3.14
 
inline double areaSphere(double radius){
    return PI*radius*radius;
}

int main()
{
    double x[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> x[i];

        if(x[i] < 0)
        {
            break;
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        int area = areaSphere(x[i]);
        cout << area << "\n";
    }
    
    
    return 0;
}
