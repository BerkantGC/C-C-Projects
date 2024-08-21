#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[50], int low, int mid, int high)
{
    int n1 = (mid - low) + 1;
    int n2 = (high - mid);

    //geçici arrayler tanımlıyoruz
    int left[n1];
    int right[n2];

    //bu arraylari dolduruyoruz
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }

    //orijinal arrayde bulunan yerlere göre geçici arrayleri yerleştiriyoruz
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    /* Eksik kalanlar olursa dolduruyoruz*/
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[50], int low, int high)
{
    if(low < high)
    {
    int mid = low + (high - low) / 2;

    //parçalara bölüyor
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    //gerçek iş burada
    merge(arr, low, mid, high);
    }
}

void swap(int arr[], int first, int second)
{
    int tmp = arr[first];
    arr[first]= arr[second];
    arr[second] = tmp;
}

int partition(int arr[], int left , int high)
{
    int pivot = arr[high];

    int i = left -1;
    int j= left;

    while(j < high)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr, i , j);
        }
        j++;
    }

    swap(arr, i+1, high);

    return i + 1;
}

void quickSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int curr = partition(arr, left, right);

        quickSort(arr, left, curr-1);
        quickSort(arr, curr+1, right);
    }
}

void multipliedMatrix(int newMatrix[MATRIX_SIZE][MATRIX_SIZE], int matrixFirst[MATRIX_SIZE][MATRIX_SIZE], int matrixSecond[MATRIX_SIZE][MATRIX_SIZE])
{
    int sum = 0 , i = 0, j = 0, k = 0;

    for (i = 0; i < MATRIX_SIZE; i++) {
            for (j = 0; j < MATRIX_SIZE; j++) {
                newMatrix[i][j] = 0;
                for (k = 0; k < MATRIX_SIZE; k++) {
                    newMatrix[i][j] += matrixFirst[i][k] * matrixSecond[k][j];
                }
            }
    }   
}

void printMatrix(int arr[MATRIX_SIZE][MATRIX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}

int main()
{
    // Test of MERGE SORT
    int arr1[] = { 12, 11, 13, 5, 6, 7, 39, 20, 10, 54, 2};
    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array before merge sort:  \n");
    printArray(arr1, arr1_size);

    mergeSort(arr1, 0, arr1_size - 1);
    printf("Merged:  \n");
    printArray(arr1, arr1_size);
 
    printf("\n\n");

    // Test of QUICK SORT
    int arr2[] = { 5, 3, 7, 12, 16, 78, 42, 61, 52, 9, 2};
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);

    printf("Original array before merge sort:  \n");
    printArray(arr2, arr2_size);

    quickSort(arr2, 0, arr2_size - 1);
    printf("quick:  \n");
    printArray(arr2, arr2_size);

    printf("\n\n");

    //Test of MATRIX MULTIPICATION
    
    int matrix1[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix2[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printMatrix(matrix1, MATRIX_SIZE);
    printMatrix(matrix2, MATRIX_SIZE);
    
    int newMatrix[MATRIX_SIZE][MATRIX_SIZE];
    multipliedMatrix(newMatrix, matrix1, matrix2);
    printf("MULTIPLIED : \n");
    printMatrix(newMatrix, MATRIX_SIZE);


    return 0;
}
