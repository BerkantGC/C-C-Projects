#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Do not forget to do big oh analyses for each function.

void min_insertion_sort(int *arr, int n);
void min_heap_sort(int *arr, int n);
void build_min_heap(int *arr, int n);
void min_heapify(int *arr, int n, int i);
int left(int index);
int right(int index);
void swap(int *a, int *b);
void min_insertion_sort_accuracy_test();
void min_heap_sort_accuracy_test();
void comparison_test();

//this is my function
void printHeap(int *arr, int n);

void min_insertion_sort(int *arr, int n) {
	// TODO: Fill this function.
	int key, j;

    for (int i = 1; i < n; i++) { //O(N)

        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) { // Because j = i its O(N) again
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

	//O(N)*o(N) = O(N^2)

}

void min_heap_sort(int *arr, int n) {
	// TODO: Fill this function.
	build_min_heap(arr, n);

	for(int i = n; n>= 1 ; i-- ) // o(N)
	{
		swap(&arr[0], &arr[i-1]);
		n--;
		min_heapify(arr, n, 0); // O(log(N))
	}

	//time complexity is O(Nlog(N))
}

void build_min_heap(int *arr, int n) {
// 	int * normalde void ti düzelt onu


	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i];
	}

	for (int i = n/2; i >= 0 ; i--)
	{
		min_heapify(arr, n, i);
	}
	


}

void min_heapify(int *arr, int n, int i) {
	// TODO: Fill this function.
	// TODO: Fill this function.
	int smallest;

	int l = left(i);
	int r = right(i);

	if(l < n && arr[l] < arr[i])
		smallest = l;
	
	else smallest = i;

	if(r < n && arr[r] < arr[smallest])
		smallest =  r;

	if(smallest != i)
	{
		swap(&arr[i], &arr[smallest]);
		min_heapify(arr, n, smallest);
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
	// TODO: Fill this function;
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

void min_insertion_sort_accuracy_test() {
	printf("STARTING MIN INSERTION SORT ACCURACY TEST\n");
	// TODO: Do your tests here.
	int arr[] = {4 ,1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    min_insertion_sort(arr, n);
    printHeap(arr, n);

	printf("ENDING MIN INSERTION SORT ACCURACY TEST\n\n");
}

void min_heap_sort_accuracy_test() {
	printf("STARTING MIN HEAP SORT ACCURACY TEST\n");
	// TODO: Do your tests here.

	int arr[] = {4 ,1, 3, 2, 16, 9, 10, 14, 8, 7};

	int size = sizeof(arr)/sizeof(arr[0]);

	min_heap_sort(arr, size);

	printHeap(arr, size);

	printf("ENDING MIN HEAP SORT ACCURACY TEST\n\n");
}

void comparison_test() {
	printf("\n\n\n\nSTARTING COMPARISON TEST\n");
	// TODO: Do your tests here.
	double startOfInsertion = clock();

	min_insertion_sort_accuracy_test();

	double endOfInsertion = clock();

	printf("Total time for Insertion Sort is %f\n", (double)(endOfInsertion - startOfInsertion));

	double startOfHeapsort = clock();

	min_heap_sort_accuracy_test();

	double endOfHeapsort = clock();

	printf("Total time for HeapSort is %f\n", (double)(endOfHeapsort - startOfHeapsort));

	printf("ENDING COMPARISON TEST\n\n");
	// Write your conclusion here:
	/*
		Time complexity of Insertion sort is O(N^2) beacause the wrong chosen pivot for insertion sort may work like bubble sort and in bigger
		datas that will be a huge problem.

		But for heap sort timecomplexity will always be O(Nlog(N)). Therefore, it has no such that risk at all unlike insertion sort.
		Heap sort is less riskier than insertion sort.
	*/
}

