#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	//TODO
	//Read "data.bin" in binary.
	RECORD records = (RECORD)malloc(sizeof(RECORD_t) * MAX);

	FILE *file = fopen("data.bin", "rb");
	fread(records, sizeof(RECORD_t) * MAX, 1, file);
	fclose(file);

	//xsort(records, MAX, cmp_ID_asc); 
	printAll(records, MAX);

	FILE *file2 = fopen("sorted.bin", "rb");
	findfilm(file2,3);
	

	fclose(file2);


	return 0;
}