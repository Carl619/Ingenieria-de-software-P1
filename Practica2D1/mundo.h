#pragma once
#include <conio.h>

struct Personaje {
	int x;
	int y;
	Personaje(int px, int py)
	{
		x = px;
		y = py;
	}
};


struct Bala {
	int x;
	int y;
	char * dibujo;
	Bala(int px, int py, char * d)
	{
		x = px;
		y = py;
		dibujo = d;
	}
};

void dibujarEscenario();
void dibujarBala(Bala * bala);
void moverBala(Bala * bala);
void  dibujarPersonaje(Personaje pers);

Bala * disparar(Personaje pers, char * direccion);


void hacerMundo(Personaje pers, Bala * bala);


void moverPersonaje(Personaje * pers, char * direccion);