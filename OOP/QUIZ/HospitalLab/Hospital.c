// This provides the entry point for the Hospital program

#include <stdio.h>
#include "Patient.h"

#pragma warning(disable : 4996)

int main(void)
{
	Patient patient_ary[MAX_BEDS]; 

	// Open the random patient file for reading
	.
	.
	.
	// Open the ordered patient file for writing
	.
	.
	.
	// Read the patients into the structure array

	int num_pats = 0;

	while (...)
	{
		fscanf(...);
		.
		.
		.
	}

	fclose(...);	// we are finished with the random file, close it

	// Order the patients for age using the Bubble Sort Algorithm

	for (int i=0; i < num_pats; i++ )
	{
		for (int j = 0; j < num_pats-1; j++)
		{
			.
			.
			.
		}
	}

	// Write the ordered patients to the output file

	for (int i = 0; i < num_pats; i++, ptr++)
		.
		.
		.

	fclose(...);	// we are finished with the ordered file, close it

	printf("Patients ordered by age in the output file!..\n");

	return 0;
}
