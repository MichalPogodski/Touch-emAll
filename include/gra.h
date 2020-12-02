#ifndef GRA_H
#define GRA_H
#include <iostream>
#include "prostokat.h"
#include<vector>


class Gra {
public:
	Gra();
	
	void ladujExpa();
	void rozladujExpa(bool & czyJuz, int & predkosc);
	void rysujLadowanie();
	void wyswietlNapisy();
	void oczernExpa();
	int zwrocT();
	bool zwrocSpeedUp();
	void napisz(double x, double y, char *string);

	void losujBonus(int poz, Prostokat &b, double y);

	void pasekZyc();
	void rysujZycia();
	int zwrocIleZyc();

	void pasekBomb();
	void rysujBomby();

	void straconoZycie();
	void przegranaMax();
	int zwrocIleBomb();
	void przegrana(std::vector<Prostokat> & klocki);


	int losujPozB(int nrKol);
	bool zwrocCzyNadalGra();
	void wyswietlInstrukcje();
	void TakStart();
	bool zwrocCzyStart();
private:

	bool czyPierwsza;
	bool czyStartGry ;
	int nrGry;
	double wynik;
	bool czasStart = false;
	bool czyNadalGra;
	int i;
	bool p, d, g, speedUp = false;
	int t;

	std::vector<Prostokat> EXP;
	std::vector<Prostokat> zycia;
	std::vector<Prostokat> bomby;


	//napisy z ekranu gry:
	char string1[50] = "czas: ";
	char string4[50] = "EXP:";
	char string3[50] = "bomby: ";
	char string2[50] = "zycia: ";


	char string11[500] = "Witaj uzytkowniku.";
	char string21[500] = "W tej grze przegrywasz, gdy czarny prostokat dojedzie do konca planszy. Odznacz je wszystkie za pomoca myszki. ";
	char string31[500] = "Z czasem bedzie coraz trudniej. Zbieraj rowniez bonusy! CZERWONY daje Ci dodatkowe zycie,";
	char string41[500] = "ZIELONY chwilowo przyspiesza gre, NIEBIESKI chwilowo spowalnia, a FIOLETOWY daje Ci 'bombe',";
	char string5[500] = "ktora zdetonowac mozesz spacja. Po prawej stronie planszy znajduje sie pas doswiadczenia.";
	char string6[500] = "Nie pozwol, by zaladowal sie on caly, poniewaz wtedy gra dramatycznie przyspieszy. Aby tego uniknac, ";
	char string7[500] = "odpowiednio wczesnie zdetonuj bombe (to rozladuje pas oraz chwilowo spowolni gre).";
	char string71[500] = "Postaraj sie przetrwac jak najdluzej. POWODZENIA!";
	char string8[500] = "Aby rozpoczac gre, wcisnij SPACJE.";

};
#endif