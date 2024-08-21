// This provides the entry point for the Hospital program

#include <stdio.h>
#include "Patient.h"

#pragma warning(disable : 4996)

void swap(Patient *p1, Patient *p2)
{
    Patient *temp = p1;
    p1 = p2;
    p2 = temp;
}

int main(void)
{
	Patient patient_ary[MAX_BEDS]; 

	// Open the random patient file for reading
	FILE *fileReading = fopen(RANDOM_PATIENT_FILE , "r");

	// Open the ordered patient file for writing
	FILE *fileWriting = fopen(ORDERED_PATIENT_FILE , "w");
	
	// Read the patients into the structure array

	int num_pats = 0;

	while (!feof(fileReading))
	{
		fscanf(fileReading, "%s %s %d", patient_ary[num_pats].name, patient_ary[num_pats].surname, &patient_ary[num_pats].age);
		num_pats++;
	}

	fclose(fileReading);	// we are finished with the random file, close it

	// Order the patients for age using the Bubble Sort Algorithm

	for (int i=0; i < num_pats; i++ )
	{
		for (int j = 0; j < num_pats-1; j++)
		{
			if (patient_ary[j].age > patient_ary[j + 1].age)
                swap(&patient_ary[j], &patient_ary[j + 1]);
		}
	}

	// Write the ordered patients to the output file

	for (int i = 0; i < num_pats; i++)
	{
		fwrite(&patient_ary[i], sizeof(Patient), 1, fileWriting);
	}

	fclose(fileWriting);	// we are finished with the ordered file, close it

	printf("Patients ordered by age in the output file!..\n");

	return 0;
}
