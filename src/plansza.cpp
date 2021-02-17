#include <iostream>
#include<ctime>
#include"../include/plansza.h"
#include "../include/prostokat.h"


Plansza::Plansza() {
	nrK = 0;
}

int Plansza::losujK() {
	int pon = 0;
	pon = rand() %5 +1;
	return pon;
}


int Plansza::tworzKloca(Prostokat &p, int k) {


	int nr = k;

	if (nr == 1) {
		Prostokat klocek(-2.78575, 3.0, 0.7685, 1.0, 0.06, 0.06, 0.06, 1, 0);
		p = klocek;
	}
	else if (nr == 2) {
		Prostokat klocek(-2.00425, 3.0, 0.7685, 1.0, 0.06, 0.06, 0.06, 2, 0);
		p = klocek;
	}
	else if (nr == 3) {
		Prostokat klocek(-1.23575, 3.0, 0.75, 1.0, 0.06, 0.06, 0.06, 3, 0);
		p = klocek;
	}
	else if (nr == 4) {
		Prostokat klocek(-0.46425, 3.0, 0.7685, 1.0, 0.06, 0.06, 0.06, 4, 0);
		p = klocek;
	}
	else if (nr == 5) {
		Prostokat klocek(0.31725, 3.0, 0.7685, 1.0, 0.06, 0.06, 0.06, 5, 0);
			p = klocek;
	}
	return nr;
}


void Plansza::dodajPlansze(std::vector<Prostokat> & plansza) {

	//x, y, a, b, r, g, b, nrkolumny, nrbonusu;
	Prostokat scianaG(-1.235, 2.25, 3.89, 0.02, 0.0, 0.0, 0.6, 0, 0), scianaD(-1.235, -2.25, 3.89, 0.02, 0.0, 0.0, 0.6, 0, 0);
	plansza.push_back(scianaG);
	plansza.push_back(scianaD);
	Prostokat scianaL(-3.18, 0.0, 0.02, 4.52, 0.0, 0.0, 0.6, 0, 0), scianaP(0.71, 0.0, 0.02, 4.52, 0.0, 0.0, 0.6, 0, 0);
	plansza.push_back(scianaL);
	plansza.push_back(scianaP);
	Prostokat kreska1(-2.39, 0.0, 0.003, 4.5, 0.01, 0.01, 0.01, 0, 0), kreska2(-1.62, 0.0, 0.003, 4.5, 0.01, 0.01, 0.01, 0, 0);
	plansza.push_back(kreska1);
	plansza.push_back(kreska2);
	Prostokat kreska3(-0.85, 0.0, 0.003, 4.5, 0.01, 0.01, 0.01, 0, 0), kreska4(-0.08, 0.0, 0.003, 4.5, 0.01, 0.01, 0.01, 0, 0);
	plansza.push_back(kreska3);
	plansza.push_back(kreska4);	
	Prostokat zaslonaG(-1.2, 2.76, 3.95, 1.0, 1.0, 1.0, 1.0, 0, 0), zaslonaD(-1.2, -2.76, 3.95, 1.0, 1.0, 1.0, 1.0, 0, 0);
	plansza.push_back(zaslonaG);
	plansza.push_back(zaslonaD);
}

void Plansza::dodajPodExpa(std::vector<Prostokat> & podPas) {

	//x, y, a, b, r, g, b, nrkolumny, nrbonusu;
	Prostokat pasExpaG(0.86, 1.92, 0.15, 0.015, 0.0, 0.0, 0.4, 0, 0), pasExpaD(0.86, -2.23, 0.15, 0.015, 0.0, 0.0, 0.6, 0, 0);
	podPas.push_back(pasExpaG);
	podPas.push_back(pasExpaD);
	Prostokat pasExpaL(0.78, -0.15, 0.015, 4.16, 0.0, 0.0, 0.6, 0, 0), pasExpaP(0.93, -0.15, 0.015, 4.16, 0.0, 0.0, 0.6, 0, 0);
	podPas.push_back(pasExpaL);
	podPas.push_back(pasExpaP);
}
