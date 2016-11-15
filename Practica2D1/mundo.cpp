#include "stdafx.h"
#include "mundo.h"

void dibujarEscenario()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("-------------------------------------------------------------");
	return;
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void hacerMundo(Personaje pers, Bala * bala) {
	dibujarEscenario();
	dibujarPersonaje(pers);
	if (bala != NULL)
		if (bala->x <= 0 || bala->x > 80) {
			delete bala;
		}
	if (bala != NULL) {
		moverBala(bala);
		dibujarBala(bala);
	}
}
Bala * disparar(Personaje pers, char * direccion)
{
	Bala * b;
	if (strcmp(direccion, "der") == 0)
		b = new Bala(pers.x + 1, pers.y, ">");
	else if (strcmp(direccion, "izq") == 0)
		b = new Bala(pers.x - 1, pers.y, "<");
	else return NULL;
	return b;

}
void dibujarPersonaje(Personaje pers)
{
	gotoxy(pers.x, pers.y);
	printf("*");
	return;
}

void dibujarBala(Bala * bala) {
	gotoxy(bala->x, bala->y);
	printf(bala->dibujo);
	return;
}

void moverBala(Bala * bala)
{
	if (strcmp(bala->dibujo, ">") == 0)
		bala->x++;
	else if (strcmp(bala->dibujo, "<") == 0)
		bala->x--;
	else return;

	return;
}

void moverPersonaje(Personaje * pers, char * direccion)
{
	if (strcmp(direccion, "der") == 0)
		pers->x++;
	else if (strcmp(direccion, "izq") == 0)
		pers->x--;
	else return;
	return;
}
