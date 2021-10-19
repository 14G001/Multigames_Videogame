#include <stdio.h>
#include <windows.h>

#include "main_functions.h"


// Console position
void conpos(int x , int y)
{
	
	HANDLE window; // Controller for our window and console handling.
	window = GetStdHandle(STD_OUTPUT_HANDLE);
	 
	COORD coordinates; // Create structure coordinates.
	
	coordinates.X = x; // Redirect function values to structure values
	coordinates.Y = y;
	 
	// Position the next message on our console to the specified coordinates.
	SetConsoleCursorPosition(window, coordinates);
	// ESPANOL: Si aca ponemos "CloseHandle(window);" rompe el programa.
	return;
}


void drawMap()
{
	//printf("01234567890123456789012345678901234567890123456789012345678901234567890123456789"); // <--- Complete line
	//printf("1         2         3         4         5         6         7         8\n");		  // <--- Complete line
	printf("+Press \"Esc\" to exit.\n");

	for (char i = 0; i < 14; i++) {
		printf("                                                                                "); // <--- Complete line
	}

	printf("                                     0                                          ");
	printf("                                    -+-                                         ");
	printf("                                     |                                          ");
	printf("--------------------------------------------------------------------------------");
  //printf("1         2         3         4         5         6         7         8\n"); // <--- Complete line
	return;
}