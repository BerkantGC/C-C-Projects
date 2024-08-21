#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *build_max_heap(int *arr, int n);
void max_heapify(int *arr, int n, int i);
int left(int index);
int right(int index);
void swap(int *a, int *b);
void test();

void printHeap(int *arr, int n);

int *build_max_heap(int *arr, int n) {
	// TODO: Fill this function.
	int *maxHeap = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		maxHeap[i] = arr[i];
	}

	for (int i = n/2; i >= 0 ; i--)
	{
		max_heapify(maxHeap, n, i);
	}
	

	return maxHeap;
}

void max_heapify(int *arr, int n, int i) {
	// TODO: Fill this function.
	int largest;

	int l = left(i);
	int r = right(i);

	if(l < n && arr[l] > arr[i])
		largest = l;
	
	else largest = i;

	if(r < n && arr[r] > arr[largest])
		largest =  r;

	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		max_heapify(arr, n, largest);
	}
}

int left(int index) {
	// TODO: Fill this function.
	int result = 2*(index+1) -1 ;

	return result;
}

int right(int index) {
	// TODO: Fill this function.
	int result = 2*(index+1);

	return result;
}

void swap(int *a, int *b) {
	// TODO: Fill this function.
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

void printHeap(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
		
	printf("\n");
}

void test() {
	// TODO: Do your tests here.
	int arr[] = {4 ,1, 3, 2, 16, 9, 10, 14, 8, 7};

	int size = sizeof(arr)/sizeof(arr[0]);

	printf("original : ");
	printHeap(arr, size);

	int *maxHeap = build_max_heap(arr , size);

	printf("\nheap : ");
	printHeap(maxHeap, size);

}

