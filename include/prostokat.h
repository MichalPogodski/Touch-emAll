#ifndef PROSTOKAT_H
#define PROSTOKAT_H
#include<iostream>
#include <vector>
class Prostokat {
public:

	Prostokat();
	 Prostokat(double x, double y, double _a, double _b, double r, double g, double b, int nr, int nrB);

	 void rysuj();

	 void zmienKolor();
	 void zmienKolorZ();
	 void zmienKolorC();
	 void wybiel();
	 bool CzyJuzCzas();
	 void zjazdKloca();
	

	double zwrocYy();
	void zaznaczOdznaczenie();
	bool zwrocCzyOdznaczona();
	int zwrocNrBonusu();
	int zwrocNr();
	double zwrocX();

private:
	
	bool juzCzas;
	bool czyOdznaczona;
	double posx, posy;
	double r, g, n;
	double a, b;
	int nr, nrBonusu;


};
#endif 
