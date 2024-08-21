/*
Read the duration and pitch of notes from the file into memory.
Then play them using the speaker on the computer.
*/

#include <stdio.h>
#include "Music.h"

#pragma warning(disable : 4996)

int main(void)
{
	Note note_ary[MAX_SONG_SIZE]; // Array of Note structures

	FILE* fPtr = NULL;

	// Open the song file. On error, report and exit.
	fPtr = fopen("Song.txt", "r+");

	if(fPtr == NULL)
		return 0;

	// Read the notes into the note structure array

	for (int i = 0; i < 16; i++)
	{
		fscanf(fPtr, "%d %d", &note_ary[i].frequency, &note_ary[i].duration);
		printf("frequency : %d duration : %d\n", note_ary[i].frequency, note_ary[i].duration);
	}
	
	int num_notes = 0;	// number of notes

	// Stay in the loop until all notes are read or the array is full

	do
	{
		fscanf(fPtr, "%d %d", &note_ary[num_notes].frequency, &note_ary[num_notes].duration);

		if(note_ary[num_notes].frequency == 0)
		{
			note_ary[num_notes].fPlay = Rest;
		}
		else note_ary[num_notes].fPlay = Sound;

		num_notes++;
	} while(num_notes < 16);

	printf("\nNumber of notes: %d\n", num_notes);

	// When finished with the file, close it
	fclose(fPtr);

	// Report it the song file is empty and exit
	if(note_ary != NULL)
	{
		printf("There is no song");
		return ERROR_EXIT;
	}

	// Play the song from memory

	for (int i = 0; num_notes >= 0; num_notes--)
	{
		note_ary[i].fPlay(&note_ary[i]);
		i++;
	}

	printf("Hope you liked the song!..\n");

	return SUCCESS_EXIT;
}
