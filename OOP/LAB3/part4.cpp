#include <iostream>
using namespace std;

void swapRandomly(int *number)
{
    *number = rand()%100;
}

int main(int argc, char const *argv[])
{
    FILE* fp;

    fp = fopen("numbers.txt", "r+");

    srand(time(NULL));

    int numbers[10];

    if(fp == NULL)
		return 0;

	// Read the notes into the note structure array

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d", &numbers[i]);
		cout << "number : " << numbers[i] << "\n";
	}
    

	for (int i = 0; i < 10; i++)
	{
		swapRandomly(&numbers[i]);
		cout << "new number : " << numbers[i] << "\n";
	}

    return 0;
}
