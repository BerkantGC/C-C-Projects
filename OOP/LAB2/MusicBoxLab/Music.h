/* 
This header file contains the definitions for the Music program.
*/

#define SUCCESS_EXIT 0
#define ERROR_EXIT -1

#define SONG_FILE "Song.txt"

#define MAX_SONG_SIZE 300

struct note
{
	unsigned short frequency;			// in hertz	
	unsigned short duration;			// in milliseconds
	void (*fPlay)(struct note* ptr);	// play function 
};

typedef struct note Note;

void Sound(Note* ptr);	// plays the note
void Rest(Note* ptr);	// rests 

