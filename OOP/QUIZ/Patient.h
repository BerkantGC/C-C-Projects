// This header file contains the definitions for the Hospital program.

#define RANDOM_PATIENT_FILE "RandomPatients.txt"
#define ORDERED_PATIENT_FILE "OrderedPatients.txt"

#define MAX_BEDS 1000
#define NAME_SIZE 15
#define SURNAME_SIZE 15

typedef struct patient
{
	char name[NAME_SIZE + 1];		
	char surname[NAME_SIZE + 1];	
	unsigned int age;		
} Patient;
