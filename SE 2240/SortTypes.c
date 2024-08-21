#include <stdio.h>
#include <time.h>
#include <unistd.h>     // for sleep()

#define MAX 1000    
#define SMALL_SIZE 50    
#define BIG_SIZE 500    

int linearSearch(int array[MAX], int size, int key){

    for (int i = 0; i < size; i++) // iteration
    {
        if(array[i] == key) //check
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[MAX], int low,  int high, int key){

    if(low == high)//check low
        return -1;

    int mid = (high + low)/2;


    if(array[mid] == key)//check key
    {
        printf("found in %d\n", mid);
        return mid;
    }

    if(key < array[mid]) //check smaller
    {
        return binarySearch(array, low, mid, key);
    }

    if(key > array[mid]) //check bigger
    {
        return binarySearch(array, mid, high, key);
    }

    return 0;
}

void fillSmall(int array[SMALL_SIZE])
{
    for(int i = 0; i < SMALL_SIZE; i++)
    {
        array[i] = i+10;
    }
    
}

void fillBig(int array[BIG_SIZE])
{

    for (int i = 0; i < BIG_SIZE; i++)
    {
        array[i] = i+10;
    }
}
int main(int argc, char const *argv[])
{
    int testCaseSmall[SMALL_SIZE];
    int testCaseBig[BIG_SIZE];

    fillSmall(testCaseSmall);
    fillBig(testCaseBig);

   
    linearSearch(testCaseSmall, SMALL_SIZE, 25);
    linearSearch(testCaseBig, BIG_SIZE, 55);
    //complexity of linear search is (iteration + 1 + check)
    //it will be checking every array index and although it is not gonna effect in small case, it will spend more time in big case


    binarySearch(testCaseSmall, 0 , SMALL_SIZE , 25);
    binarySearch(testCaseBig, 0, BIG_SIZE,67 );
    // complexity of binary search is log(n) 
    //it will take so much less time according to linear search beacuse 
    return 0;
}
