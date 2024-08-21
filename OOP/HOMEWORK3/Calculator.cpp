#include <iostream>
#include <fstream>
#include "Operation.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const string INPUT_FILLE = "InputFile.txt";
    const string OUTPUT_FILLE = "OutputFile.txt";

    ifstream fInput(INPUT_FILLE);
    ofstream fOutput(OUTPUT_FILLE);

    const unsigned short MAX_OPERATIONS = 20;

    Operation *open_arr[MAX_OPERATIONS];

    int num_opers = 0;

    string myText;

    while (getline(fInput, myText)) {
        printf("%d \n", myText[0]);
        if(myText[0] == '+')
        {
            open_arr[num_opers] = new Add(myText[2], myText[4]);
        }
        else if(myText[0] == '-')
        {
            open_arr[num_opers] = new Subtract(myText[2], myText[4]);
        }
        else if(myText[0] == '*')
        {
            open_arr[num_opers] = new Multiply(myText[2], myText[4]);
        }
        else if(myText[0] == '/')
        {
            open_arr[num_opers] = new Divide(myText[2], myText[4]);
        }
        
        num_opers++;
    }

    for (int i = 0; i < num_opers; i++)
    {
        fOutput << open_arr[i]->Result();
    }
    
    return 0;
}
