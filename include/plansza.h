#ifndef PLANSZA_H
#define PLANSZA_H
#include<iostream>
#include <vector>
#include"prostokat.h"
class Plansza {
public:
	Plansza();
	int losujK();
	int tworzKloca( Prostokat & p, int k);
	void dodajPlansze(std::vector<Prostokat> & plansza);
	void dodajPodExpa(std::vector<Prostokat> & podPas);
private:
	int nrK;

};
#endif 
