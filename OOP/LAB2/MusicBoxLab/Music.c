/*
This file contains the implementation of the utility functions.
*/

#include <stdio.h>
#include "Music.h"

#pragma warning(disable : 4996)

void Sound(Note *ptr)
{
	//Beep(ptr->frequency, ptr->duration);
	printf("%d ", ptr->frequency);
}

void Rest(Note *ptr)
{
	//Sleep(ptr->duration);
	printf("%d ", ptr->duration);
}
