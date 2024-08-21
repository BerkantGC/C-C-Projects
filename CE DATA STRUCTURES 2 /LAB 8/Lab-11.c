#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

typedef struct {
	int film_id;
	char title[255];
	char description[1023];
	unsigned int release_year;
	int rental_duration;
	float rental_rate;
	unsigned char length;
	float replacement_cost;
	char rating[10];
	char last_update[30];
} RECORD_t, *RECORD;

void printAll(RECORD array, int size) {
	int i;
	for(i=0; i<size-2 ; i++){
		printf("%d \n", array[i].film_id);
		printf("%s \n", array[i].title);
		printf("%s \n", array[i].description);
		printf("%d \n", array[i].release_year);
		printf("%d \n", array[i].rental_duration);
		printf("%f \n", array[i].rental_rate);
		printf("%d \n", array[i].length);
		printf("%f \n", array[i].replacement_cost);
		printf("%s \n", array[i].rating);
		printf("%s\n", array[i].last_update);
		printf("\n");
	}
}

int binarySearch(FILE* fp, RECORD record, int l, int r, int x);

int min(int first, int second)
{
    if(first < second)
        return first;

    else return second;
}

int exponentialSearch(FILE *fp, int n, int x)
{
    RECORD record = (RECORD)malloc(sizeof(RECORD_t)*1);
    
    fseek(fp, 0, SEEK_SET);
    fread(record, sizeof(RECORD_t), 1, fp);

    if (record[0].film_id == x)
    {
        return 0;
    }
 
    int i = 1;
    fseek(fp, i, SEEK_SET);
    fread(record, sizeof(RECORD_t), 1, fp);
    while (i < n && record[0].film_id <= x)
        i = i*2;

    return binarySearch(fp, record, i/2, min(i, n-1), x);
}

int binarySearch(FILE * fp, RECORD record, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        fseek(fp, mid*(sizeof(RECORD_t)), SEEK_SET);
        fread(record, sizeof(RECORD_t), 1, fp);

        if (record[0].film_id == x)
        {    
            printf("%d \n", record->film_id);
            printf("%s \n", record->title);
            printf("%s \n", record->description);
            printf("%d \n", record->release_year);
            printf("%d \n", record->rental_duration);
            printf("%f \n", record->rental_rate);
            printf("%d \n", record->length);
            printf("%f \n", record->replacement_cost);
            printf("%s \n", record->rating);
            printf("%s\n", record->last_update);
            printf("\n");
            return mid;
        }

        if (record[0].film_id > x)
            return binarySearch(fp, record, l, mid-1, x);

        return binarySearch(fp, record, mid+1, r, x);
    }

    return -1;
}

void seekSort(FILE * fp, int size) {
    RECORD record1 = (RECORD)malloc(sizeof(RECORD_t));
    RECORD record2 = (RECORD)malloc(sizeof(RECORD_t));

	for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size - i -1; j++)
        {

            fseek(fp, (j)*sizeof(RECORD_t), SEEK_SET);
            
            fread(record1, sizeof(RECORD_t)*1, 1, fp);

            fseek(fp, (j+1)*sizeof(RECORD_t), SEEK_SET);

            fread(record2, sizeof(RECORD_t)*1, 1, fp);

            if(record1->film_id > record2->film_id)
            {   
                fseek(fp, (j)*sizeof(RECORD_t), SEEK_SET);

                fwrite(record2, sizeof(RECORD)*1, 1 ,fp);
                
                fseek(fp, (j+1)*sizeof(RECORD_t), SEEK_SET);

                fwrite(record1, sizeof(RECORD)*1, 1 ,fp);
            }
        }
    }
    
}

void findfilm(FILE *f1, int id){
	fseek(f1, (id-1)*sizeof(RECORD_t), SEEK_SET);
	RECORD record = (RECORD)malloc(sizeof(RECORD_t) * MAX);
	fread(record, sizeof(RECORD_t)*1, 1, f1);
	printAll(record,1);
	free(record);
}

int main() {
	//TODO
	//Read "data.bin" in binary.
	FILE *file = fopen("data.bin", "rb+");

    seekSort(file, MAX);
    
	RECORD records = (RECORD)malloc(sizeof(RECORD_t) * MAX);
	fread(records, sizeof(RECORD_t) * MAX, 1, file);

    printAll(records, MAX);

    exponentialSearch(file, MAX, 619);

	return 0;
}