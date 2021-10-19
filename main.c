#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

#define RIGHT_LIMIT 78
#define LEFT_LIMIT 1

#include "main_functions.h"
#include "Player.h"


/*
 

KEYS:

Esc = 0x1B
Enter = 0x0D
Up = 0x26			- W = 0x57
Down = 0x28			- S = 0x53
Left = 0x25			- A = 0x41
Right = 0x27		- D = 0x44


PLAYER:

 0
-+-	  0
 |	 /X\

*/


int main()
{
	PLAYER Player; // <-- Aim at the PLAYER's belly.
	Player.X = 37;
	Player.Y = 16;
	Player.crouched = false;

	drawMap();

	while (!GetAsyncKeyState(0x1B) && !GetAsyncKeyState(0x0D)) { // Tecla "Esc".
		if (kbhit()) {
			if (GetAsyncKeyState(0x26) || GetAsyncKeyState(0x57)) { // Up (jump)
				if (!Player.crouched) {
					jump(&Player);
				} else {
					stand_up(&Player);
				}
			} else if (GetAsyncKeyState(0x28) || GetAsyncKeyState(0x53)) { // Down (crouch)
				if (!Player.crouched) {
					crouch(&Player);
				}
			} else if (GetAsyncKeyState(0x25) || GetAsyncKeyState(0x41)) { // Left
				if (!Player.crouched && Player.X > LEFT_LIMIT) {
					left(&Player);
				} else {
					stand_up(&Player);
				}
			} else if (GetAsyncKeyState(0x27) || GetAsyncKeyState(0x44)) { // Right
				if (!Player.crouched && Player.X < RIGHT_LIMIT) {
					right(&Player);
				} else {
					stand_up(&Player);
				}
			}
		}
		conpos(0, 22);
		Sleep(100);
	}

	conpos(0, 22);
	printf("+++ Thanks for using my program! :D +++\n\n");
	Sleep(1000);
	return 0;
}
