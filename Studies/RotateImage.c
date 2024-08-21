#include "stdio.h"

void rotate(int image[3][3], int size){
    int tmp;
    /*
    1 2 3   7 4 1 
    4 5 6   8 5 2
    7 8 9   9 6 3
    */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    int tmp;
    int i = 0;
    int j;
    for (i = 0; i < matrixSize/2; i++)
    {
        for (j = i; j < matrixSize-i-1; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize-j-1][i];
            matrix[matrixSize-j-1][i] = matrix[matrixSize-i-1][matrixSize-j-1];
            matrix[matrixSize-i-1][matrixSize-j-1] = matrix[j][matrixSize-i-1];
            matrix[j][matrixSize-i-1] = tmp;
            printf(" deneme: \n");
        }

    }
    // 0 1
    // 1 0

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int image[3][3] ={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(image, 3);

    
    return 0;
    
}