#include<iostream>
#define NDEBUG
#include <GL/freeglut.h>
#include "../include/prostokat.h"


Prostokat::Prostokat() {
	a = 1.0;
	b = 2.0;
	posx =0.0;
	posy = 0.0;
	r = 0.1;
	g = 0.1;
	n = 0.1;
	nr = 0;
	czyOdznaczona = false;
	juzCzas = false;
}
Prostokat::Prostokat(double x, double y, double _a, double _b, double _r, double _g, double _n, int nr, int nrB) {
	a = _a;
	b = _b;
	posx = x;
	posy = y;
	r = _r;
	g = _g;
	n = _n;
	nr = 0;
	czyOdznaczona = false;
	nrBonusu = nrB;

}


void Prostokat::rysuj() {

	glPushMatrix();
	glTranslated(posx, posy, 0.0);
	glRotated(0.0, 0.0, 0.0, 1.0);

	glColor3d(r, g, n);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-a / 2, b / 2, 0);
		glVertex3d(a / 2, b / 2, 0);
		glVertex3d(a / 2, -b / 2, 0);
		glVertex3d(-a / 2, -b / 2, 0);
	}
	glEnd();
	glPopMatrix();

}


void Prostokat::zmienKolor() {
	r = 0.8;
	g = 0.1;
	n = 0.1;

}
void Prostokat::zmienKolorZ() {
	r = 1.0;
	g = 1.0;
	n = 0.0;

}
void Prostokat::zmienKolorC() {
	r = 0.0;
	g = 0.0;
	n = 0.0;

}
void Prostokat::wybiel() {
	r = 0.9;
	g = 0.9;
	n = 0.9;
}




void Prostokat::zjazdKloca() {
	posy = posy - 0.5;
}

void Prostokat::zaznaczOdznaczenie() {
	czyOdznaczona = 1;
}


int Prostokat::zwrocNr() {
	return nr;
}

double Prostokat::zwrocX() {
	return posx;
}


double Prostokat::zwrocYy() {
	return posy;
}

int Prostokat::zwrocNrBonusu() {
	return nrBonusu;
}

bool Prostokat::zwrocCzyOdznaczona() {
	return czyOdznaczona;
}

bool Prostokat::CzyJuzCzas() {
	if (posy <= -2.8)
		juzCzas = true;
	return juzCzas;
}
