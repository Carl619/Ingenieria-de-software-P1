// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mundo.h"

#define INICIOX 9
#define INICIOY 13
Personaje pers = { INICIOX,INICIOY };
Bala * bal = NULL;


void clear()
{
	system("cls");
}

void update() {
	clear();
	hacerMundo(pers, bal);
}

void mover() {
	int c;
	if (_kbhit()) {
		c = _getch();
		if (c == 'a')
			moverPersonaje(&pers, "izq");
		else if (c == 'd')
			moverPersonaje(&pers, "der");
		if (bal == NULL) {
			if (c == 'q')
				bal = disparar(pers, "izq");
			else if (c == 'e')
				bal = disparar(pers, "der");
		}
		return;
	}
}

int main()
{
	while (1) {
		update();
		mover();
		Sleep(100);
	}
	return 0;
}

