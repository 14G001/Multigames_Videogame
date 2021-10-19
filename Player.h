#pragma once


typedef struct PLAYER {
	char X;
	char Y;
	bool crouched;
} PLAYER;




void left(PLAYER* p);

void right(PLAYER* p);

void up(char X, char Y);

void down(char X, char Y);

void moveOnAir(PLAYER* p);

void jump(PLAYER* p);

void crouch(PLAYER* p);

void stand_up(PLAYER* p);