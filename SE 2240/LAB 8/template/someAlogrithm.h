// do sorting with ascending order you can use any amount of functions 
// But dont change parameter and return type of this functions

// Do big o analyis use T(n) for time, finally calculate
// big O of your algorithm
void min_heap_sort(char **arr, int n);
void build_min_heap(char **arr, int n);
void min_heapify(char **arr, int n, int i);
int left(int index);
int right(int index);
void swap(void *a, void *b);

void min_heap_sort(char **arr, int n) {
	// TODO: Fill this function.
	build_min_heap(arr, n);

	for(int i = n; n>= 1 ; i-- ) // o(N)
	{
		swap(arr[0], arr[i-1]);
		n--;
		min_heapify(arr, n, 0); // O(log(N))
	}

	//time complexity is O(Nlog(N))
}

void build_min_heap(char **arr, int n) {
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

void min_heapify(char **arr, int n, int i) {
	// TODO: Fill this function.
	// TODO: Fill this function.
	int smallest;

	int l = left(i);
	int r = right(i);

	if(l < n && strcmp(arr[l], arr[i]) < 0)
		smallest = l;
	
	else smallest = i;

	if(r < n && strcmp(arr[r], arr[smallest]) < 0)
		smallest =  r;

	if(smallest != i)
	{
		swap(arr[i], arr[smallest]);
		min_heapify(arr, n, smallest);
	}
}

int left(int index) {
	int result = 2*(index+1) -1 ;

	return result;
}

int right(int index) {
	int result = 2*(index+1);

	return result;
}

void swap(void *a, void *b) {
	int tmp = a;
	a = b;
	b = tmp;
}


void someAlgorithm1(char **words, int n) {
    char* key;
    int j;

    for (int i = 1; i < n; i++) {// O(n)

        key = words[i];
        j = i - 1;

        while (j >= 0 && strcmp(words[j], key) < 0) { // O(n)
            words[j + 1] = words[j];
            j = j - 1;
        }
        words[j + 1] = key;
    }
}
// 1. Big O analysis someAlgorithm1

void someAlgorithm2(char **words, int n) {
    min_heap_sort(words, n);
}
// 2. Big O analysis someAlgorithm2
// O(nlogN)

int partition(char **arr,int low, int high)
{
    char * pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++){

        if (strcmp(arr[j] , pivot) <= 0)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i + 1);
}

void quickSort(char** arr,int low, int high){
	int i;

    if(low < high){
        i = partition(arr,low,high);
        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}

void someAlgorithm3(char **words, int n) {
    // int i, j, min;

    // for (i = 0; i < n-1; i++)
    // {
    // min = i;
    // for (j = i+1; j < n; j++)
    // {
    //     if (strcmp(words[j], words[min]) < 0)
    //     {
    //         min = j;
    //     }
    // }
    // // Swap the found minimum element with the first element
    // if(min != i)
    //     swap(words[min], words[i]);
    // }

	quickSort(words, 0 , n-1);
}
// 3. Big O analysis someAlgorithm3
// O(n^2)


// Questions and Answers write minimum 1-2 sentences for each question

// 1. Which algorithm is the fastest for ascending order? Why?
// Heap sort is fastest one. Altough heap sort and quick sort have similar complexities. Because of pivot selection quick sort
// takes more time than heap in ascending order.

// 2. Which algorithm is fastest for random order? Why?
// Quick sort is fastest one on random order. Because it just don't use any addition things like merging.

