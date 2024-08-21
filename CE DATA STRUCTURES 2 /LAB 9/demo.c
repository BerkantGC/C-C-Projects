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

void print_movie(RECORD_t rec) {
	printf("ID: %d\n", rec.film_id);
	printf("TITLE: %s\n", rec.title);
	printf("DESCRIPTION: %s\n", rec.description);
	printf("RELEASE YEAR: %d\n", rec.release_year);
	printf("RENTAL DURATION: %d\n", rec.rental_duration);
	printf("RENTAL RATE: %f\n", rec.rental_rate);
	printf("REPLACEMENT COST: %f\n", rec.replacement_cost);
	printf("RATING: %s\n", rec.rating);
	printf("LAST UPDATE: %s\n", rec.last_update);
	printf("\n");
}

void printAll(RECORD array, int size) {
	//TODO
	int i = 0;	
	//printf("print all ın içinde: %d \n", array[i].film_id);

	while (i < size)
	{
		print_movie(array[i]);
		i++;
	}
	
}

void findMovie(FILE * fp, int id)
{
    fseek(fp, (id-1)*sizeof(RECORD_t), SEEK_SET);

	RECORD record = (RECORD)malloc(sizeof(RECORD_t) * MAX);

	fread(record, sizeof(RECORD_t)*1, 1, fp);

	printAll(record,1);

	free(record);
}

void main()
{
    RECORD records = (RECORD)malloc(sizeof(RECORD_t) * MAX);

	FILE *fp = fopen("sorted.bin", "rb");

	fread(records, sizeof(RECORD_t) * MAX, 1, fp);

    findMovie(fp, 5);

	fclose(fp);
}