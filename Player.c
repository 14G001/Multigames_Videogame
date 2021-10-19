#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define RIGHT_LIMIT 78
#define LEFT_LIMIT 1

#include "main_functions.h"
#include "Player.h"


void left(PLAYER* p)
{
	conpos(p->X - 1, p->Y - 1); // Face
	printf("0 ");
	conpos(p->X - 2, p->Y); // Left arm | Belly | Right arm
	printf("-+- ");
	conpos(p->X - 1, p->Y + 1); // Legs
	printf("| ");
	p->X--;
	return;
}


void right(PLAYER* p)
{
	conpos(p->X, p->Y - 1); // Face
	printf(" 0");
	conpos(p->X - 1, p->Y); // Left arm | Belly | Right arm
	printf(" -+-");
	conpos(p->X, p->Y + 1); // Legs
	printf(" |");
	p->X++;
	return;
}


void up(char X, char Y)
{
	conpos(X, Y + 1); // Legs
	printf(" ");
	conpos(X - 1, Y); // Left arm | Belly | Right arm
	printf(" | ");
	conpos(X - 1, Y - 1); // Face
	printf("-+-");
	conpos(X, Y - 2); // New face
	printf("0");
	return;
}


void down(char X, char Y)
{
	conpos(X, Y - 1); // Face
	printf(" ");
	conpos(X - 1, Y); // Left arm | Belly | Right arm
	printf(" 0 ");
	conpos(X - 1, Y + 1); // Legs
	printf("-+-");
	conpos(X, Y + 2); // New legs
	printf("|");
	return;
}


void moveOnAir(PLAYER* p)
{
	if (GetAsyncKeyState(0x25) || GetAsyncKeyState(0x41)) { // Left
		if (p->X > LEFT_LIMIT) {
			left(p);
		}
	} else if (GetAsyncKeyState(0x27) || GetAsyncKeyState(0x44)) { // Right
		if (p->X < RIGHT_LIMIT) {
			right(p);
		}
	}
	return;
}


void jump(PLAYER* p)
{
	moveOnAir(p);

	up(p->X, p->Y);
	p->Y--;
	Sleep(100);
	moveOnAir(p);

	up(p->X, p->Y);
	p->Y--;
	Sleep(100);
	moveOnAir(p);

	down(p->X, p->Y);
	p->Y++;
	Sleep(100);
	moveOnAir(p);

	down(p->X, p->Y);
	p->Y++;
	Sleep(100);
	moveOnAir(p);

	return;
}


void crouch(PLAYER* p)
{
	conpos(p->X, p->Y - 1); // Face
	printf(" ");
	conpos(p->X - 1, p->Y); // Left arm | Belly | Right arm
	printf(" 0 ");
	conpos(p->X - 1, p->Y + 1); // Legs
	printf("/X\\");

	p->crouched = true;
	return;
}


void stand_up(PLAYER* p)
{
	conpos(p->X, p->Y - 1); // Face
	printf("0");
	conpos(p->X - 1, p->Y); // Left arm | Belly | Right arm
	printf("-+-");
	conpos(p->X - 1, p->Y + 1); // Legs
	printf(" | ");

	p->crouched = false;
	return;
}
