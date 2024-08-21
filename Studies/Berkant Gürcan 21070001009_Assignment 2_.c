#include <stdio.h>

void weirdSort(int arr[], int size)
{
	int min;
	
    for (int i = 0; i < size; i = i + 2) 
	{     
        for (int j = i + 2; j < size; j = j + 2) 
		{     
           if(arr[i] > arr[j]) 
		   {    
               min = arr[i];    
               arr[i] = arr[j];    
               arr[j] = min;    
           }     
        }     
    } 
	
	int max;
	for (int i = 1; i < size; i = i + 2) 
	{     
        for (int j = i + 2; j < size; j = j + 2) 
		{     
           if(arr[i] < arr[j]) 
		   {    
               max = arr[i];    
               arr[i] = arr[j];    
               arr[j] = max;    
           }     
        }     
    }   
	  
}

void readArray(int arr[], int size)
{
	for (int i=0; i < size; i++)
	{
		printf("Please enter the number for index %d!\n", i);
		scanf("%d", &arr[i]);
	}		
}

void printArray(int arr[], int size)
{
   printf("Sorted form : ");
    for(int i = 0; i < size - 1 ; i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("%d\n", arr[size - 1]);	
}

void weirdPrint(int arr[], int size)
{
	if (size % 2 == 0)
	{
	
	printf("Even indexes : ");
    for(int i = 0; i < size - 2 ; i = i + 2)
	{
		printf("%d ", arr[i]);
	}
	
	printf("%d\n", arr[size - 2]);	
	
	printf("Odd indexes : ");
	for(int i = 1; i < size - 1 ; i = i + 2)
	{
		printf("%d ", arr[i]);
	}
	
	printf("%d\n", arr[size - 1]);		
	}
	
	else
	{
	
	printf("Even indexes : ");
    for(int i = 0; i < size - 2 ; i = i + 2)
	{
		printf("%d ", arr[i]);
	}
	
	printf("%d\n", arr[size - 1]);	
	
	printf("Odd indexes : ");
	for(int i = 1; i < size - 1 ; i = i + 2)
	{
		printf("%d ", arr[i]);
	}
	
	printf("%d\n", arr[size - 2]);	
	}
}

void main()
{
	int arr[10];
	readArray(arr, 10);
	weirdSort(arr, 10);
	printArray(arr, 10);
	weirdPrint(arr, 10);
}
