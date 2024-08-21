#include <iostream>
using namespace std;

void swapRandomly(int *number)
{
    *number = rand()%100;
}

int main(int argc, char const *argv[])
{
    int x = 15;
    int y = x;

    cout << "Originals x: " << x << " y: " << y << "\n";

    int *number = &y;
    swapRandomly(number);

    cout << "NEW x: " << x << " y: " << y << "\n";

    return 0;
}
