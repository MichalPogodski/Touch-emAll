#include <iostream>
#include <vector>
#include <cstring>
#define NDEBUG
#include <GL/freeglut.h>
#include"gra.h"
#include "prostokat.h"
Prostokat prst;


Gra::Gra() {
		 czyPierwsza=true;
		 nrGry=0;
		 wynik=0;

		 i = 0;
		 p = false;
		 d = false;
		 g = false;
		 czyStartGry = false;
		 czyNadalGra = true;
		t = 700;
		
}

int Gra::zwrocT() {
		return t;

}


void Gra::ladujExpa() {

		if (i == 46) {
			p = true;
			i = 0;
			t = 100;
		}

		if (p == 0) {
			Prostokat jednstokaExpa(0.855, (-2.18 + (i*0.09)), 0.15, 0.09, 0.0, 0.8, 0.0, 0, 0);
			i++;
			EXP.push_back(jednstokaExpa);
		}

		else if (g == 0) {
			EXP[i].zmienKolor();
			i++;
			if (i == 46) {
				g = true;
				i = 0;
				t = 5;
			}

		}
		else {
			speedUp = true;
			EXP[i].zmienKolorZ();
			i++;
			if (i == 46)
			{
				i = 0;
				g = false;
			}
		}

	
}

void Gra::rozladujExpa(bool & czyJuz, int & predkosc) {
	EXP.resize(0);
	if (czyJuz == true) {
		for (int i = 0; i <= 15; i++) {
			predkosc = predkosc + 15 * 70;
				}		
		if (predkosc >= 450)
			predkosc = 350;
	}
	bomby.resize(bomby.size() - 1);
	i = 0;
	czyJuz = false;
	p = false;
	g = false;
	speedUp = false;
	t = 700;
	p = false;
}
void Gra::oczernExpa() {
	for (unsigned int i = 0; i < EXP.size(); i++)
	{
		EXP[i].zmienKolorC();
	}
}

void Gra::rysujLadowanie() {
	for (unsigned int i = 0; i < EXP.size(); i++)
	{
		EXP[i].rysuj();
	}
}


void Gra::napisz(double x, double y, char *string) {
	
	
		glRasterPos2d(x, y);

                int len = strlen(string);
		for (int i = 0; i < len; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
	
}


void Gra::wyswietlNapisy() {

        glColor3f(0, 0, 0);
	napisz(1.2, 0.5, string2);
	napisz(1.2, -0.9, string3);
	napisz(0.75, 1.98, string4);
}

void Gra::wyswietlInstrukcje() {
	glColor3f(0, 0, 0);
	napisz(-3.45, 1.5, string11);
	napisz(-3.45, 1.3, string21);
	napisz(-3.45, 1.1, string31);
	napisz(-3.45, 0.9, string41);
	napisz(-3.45, 0.7, string5);
	napisz(-3.45, 0.5, string6);
	napisz(-3.45,0.3, string7);
	napisz(-3.45, 0.1, string71);
	napisz(-3.45, -0.3, string8);
}

int Gra::losujPozB(int nrKol) {
	int pozB = rand() % 5 + 1;
	if (pozB == nrKol)
	{
		pozB = pozB - 1;
		if (pozB == 0) {
			pozB = 5;
		}
	}
	return pozB;
}



void Gra::losujBonus(int poz, Prostokat &b, double y) {
	int numerBonusu=rand()%4 +1;
	if (numerBonusu == 1) {
		if (poz == 1) {
			Prostokat zycie(-2.78575, y, 0.7685, 1.0, 1.0, 0.0, 0.0, 1, 1);	
			b = zycie;
		}
		else if (poz == 2) {
			Prostokat zycie(-2.00425, y, 0.7685, 1.0, 1.0, 0.0, 0.0, 2, 1);
			b = zycie;
		}
		else if (poz == 3) {
			Prostokat zycie(-1.23575, y, 0.75, 1.0, 1.0, 0.0, 0.0, 3, 1);
			b = zycie;
		}
		else if (poz == 4) {
			Prostokat zycie(-0.46425, y, 0.7685, 1.0, 1.0, 0.0, 0.0, 4, 1);
			b = zycie;
		}
		else if (poz == 5) {
			Prostokat zycie(0.31725, y, 0.7685, 1.0, 1.0, 0.0, 0.0, 5, 1);
			b = zycie;
		}
		
	
	}
	else if (numerBonusu == 2) {
		if (poz == 1) {
			Prostokat bomba(-2.78575, y, 0.7685, 1.0, 0.5, 0.0, 0.5, 1, 2);
			b = bomba;
		}
		else if (poz == 2) {
			Prostokat bomba(-2.00425, y, 0.7685, 1.0, 0.5, 0.0, 0.5, 2, 2);
			b = bomba;
		}
		else if (poz == 3) {
			Prostokat bomba(-1.23575, y, 0.75, 1.0, 0.5, 0.0, 0.5, 3, 2);
			b = bomba;
		}
		else if (poz == 4) {
			Prostokat bomba(-0.46425, y, 0.7685, 1.0, 0.5, 0.0, 0.5, 4, 2);
			b = bomba;
		}
		else if (poz == 5) {
			Prostokat bomba(0.31725, y, 0.7685, 1.0, 0.5, 0.0, 0.5, 5, 2);
			b = bomba;
		}
		
	}
	else if (numerBonusu == 3) {
		if (poz == 1) {
			Prostokat speed(-2.78575, y, 0.7685, 1.0, 0.0, 1.0,0.0, 1, 3);
			b = speed;
		}
		else if (poz == 2) {
			Prostokat speed(-2.00425, y, 0.7685, 1.0, 0.0, 1.0, 0.0, 2, 3);
			b = speed;
		}
		else if (poz == 3) {
			Prostokat speed(-1.23575, y, 0.75, 1.0, 0.0, 1.0, 0.0, 3, 3);
			b = speed;
		}
		else if (poz == 4) {
			Prostokat speed(-0.46425, y, 0.7685, 1.0, 0.0, 1.0, 0.0, 4, 3);
			b = speed;
		}
		else if (poz == 5) {
			Prostokat speed(0.31725, y, 0.7685, 1.0, 0.0, 1.0, 0.0, 5, 3);
			b = speed;
		}
		
	}
	else if (numerBonusu == 4) {
		if (poz == 1) {
			Prostokat slow(-2.78575, y, 0.7685, 1.0, 0.0, 0.0, 1.0, 1,4);
			b = slow;
		}
		else if (poz == 2) {
			Prostokat slow(-2.00425, y, 0.7685, 1.0, 0.0, 0.0, 1.0, 2, 4);
			b = slow;
		}
		else if (poz == 3) {
			Prostokat slow(-1.23575, y, 0.75, 1.0, 0.0, 0.0, 1.0, 3, 4);
			b = slow;
		}
		else if (poz == 4) {
			Prostokat slow(-0.46425, y, 0.7685, 1.0, 0.0, 0.0, 1.0, 4, 4);
			b = slow;
		}
		else if (poz == 5) {
			Prostokat slow(0.31725, y, 0.7685, 1.0, 0.0, 0.0, 1.0, 5, 4);
			b = slow;
		}
	}
	
}

void Gra::pasekZyc() {
 		double iksy = 1.75 + 0.2*zycia.size();
		//x, y, a, b, r, g, b, nrKolumny, nrBonusu;
		Prostokat zycie(iksy, 0.55,0.17, 0.17, 1.0, 0.0, 0.0, 0, 0);
		zycia.push_back(zycie);
}

void Gra::rysujZycia() {
	for (auto i =zycia.begin(); i != zycia.end(); i++ )
	{
		
		i->rysuj();
	}
}

void Gra::pasekBomb() {
	
		double iksiki = 1.75 + 0.2*bomby.size();
		//x, y, a, b, r, g, b;
		Prostokat bomba(iksiki, -0.875, 0.17, 0.17, 0.5, 0.0, 0.5, 0, 0);
		bomby.push_back(bomba);

}
void Gra::rysujBomby() {
	for (auto i = bomby.begin(); i !=bomby.end(); i++)
	{
		i->rysuj();
	}
}


void Gra::przegranaMax(){
	czyNadalGra = 0;
        std::cout <<"PRZEGRALES" << std::endl;
}


void Gra::straconoZycie() {
	int rozmiar;
	rozmiar = zycia.size();
	zycia.resize(rozmiar -1);
}
int Gra::zwrocIleZyc() {
	return zycia.size();
}



void Gra::przegrana(std::vector<Prostokat> & klocki) {
	
	for (auto i = klocki.begin(); i != klocki.end(); i++) {
		if (i->zwrocYy() <= -1.75) {
			if (i->zwrocCzyOdznaczona() == 0 && i->zwrocNrBonusu() == 0 && zwrocIleZyc() > 0) {
				straconoZycie();
				i->zaznaczOdznaczenie();
			}
			else if (zwrocIleZyc() == 0 && i->zwrocCzyOdznaczona() == 0 && i->zwrocNrBonusu() == 0) {
							przegranaMax();	
		
			}
		}
	}
	}



int Gra::zwrocIleBomb() {
	return bomby.size();
}

bool Gra::zwrocCzyNadalGra() {
	return czyNadalGra;
}
bool Gra::zwrocSpeedUp() {
	return speedUp;
}
void Gra::TakStart() {
	czyStartGry = true;
}
bool Gra::zwrocCzyStart() {
	return czyStartGry;;
}
