#include <iostream>
#include <vector>
#define NDEBUG
#include <GL/glut.h>
#include "include/prostokat.h"
#include"include/plansza.h"
#include "include/gra.h"


Gra g;

void InitGLUTSceneSTART(const char* window_name)
{
	glutInitWindowSize(1100, 700);
	glutInitWindowPosition(90,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);


	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void FunkcjaDoObslugiKlawiatury(unsigned char key, int mouse_x, int mouse_y)
{
	if (key == ' ') {
                glutHideWindow();
                //std::cout << g.zwrocCzyStart() << std::endl << std::endl << std::endl;
                g.TakStart();
                //std::cout << g.zwrocCzyStart() << std::endl << std::endl << std::endl;
	}

}
void displaySTART()
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		g.wyswietlInstrukcje();

	}
	glPopMatrix();

	glutSwapBuffers();

}
void resizeSTART(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idleSTART()
{
	glutPostRedisplay();
}

void SetCallbackFunctionsSTART()
{
	glutReshapeFunc(resizeSTART);
	glutDisplayFunc(displaySTART);
	glutIdleFunc(idleSTART);
	glutKeyboardFunc(FunkcjaDoObslugiKlawiatury);

}



		Plansza p;
		
                double czasGry = 0.0;
		int predkoscZjazdu = 450;
		double predkoscTworzenia= 1.0 / (0.5 / predkoscZjazdu);

		int ilePrzebiegow = 0;

		std::vector<Prostokat> klocki;
		std::vector<Prostokat> plansza;
		std::vector<Prostokat> podPas;

                Prostokat klocek(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0);
	

		//FUNKCJE PREDKOSCI
		void zwolnij(int c) {
			predkoscZjazdu = predkoscZjazdu + 80;
			if (predkoscZjazdu >= 650)
				predkoscZjazdu = 500;		
		}
	
		void przyspiesz(int c) {
			predkoscZjazdu = predkoscZjazdu - 70;
			if (predkoscZjazdu <= 50)
				predkoscZjazdu = 150;
		}
		//LICZNIK CZASU GRY
		void czasGryLogic(int c) {
			if (g.zwrocCzyStart() == 1)
			czasGry = czasGry + 0.01;			
			glutTimerFunc(10, czasGryLogic, NULL);
		}

		//ogolna logika predkosci
		void timeLogic(int c) {
			if (g.zwrocCzyStart() == 1){
			if (predkoscZjazdu >= 200) {
				przyspiesz(1);				
				glutTimerFunc(10000, timeLogic, NULL);
			}
			else {
				predkoscZjazdu = predkoscZjazdu - 40;
				if (predkoscZjazdu <= 50)
					predkoscZjazdu = 150;
				glutTimerFunc(80000, timeLogic, NULL);
			}
			}
		}


		bool czyJuz = false;

		//LOGIKA PASA EXPA
		void UpdateExp(int c) {
			if (g.zwrocCzyStart() == 1) {
				g.ladujExpa();
			}
			if (g.zwrocCzyNadalGra() == 1) {
				if (g.zwrocSpeedUp() == 1 && czyJuz == false) {
					for (int i = 0; i <= 15; i++)
						przyspiesz(1);
					czyJuz = true;
				}


				glutTimerFunc(g.zwrocT(), UpdateExp, NULL);
			}
			else {
				std::cout << "twoj czas :  " << czasGry << " sekund"<<std::endl;
				g.oczernExpa();
			}
		}



		//DETONACJA
		void detonacja(unsigned char key, int mouse_x, int mouse_y)
		{
			if (key == ' '&& g.zwrocIleBomb() >= 1) {
				g.rozladujExpa(czyJuz, predkoscZjazdu);
			}
		}




		//LOGIKA DODAWANIA KLOCKOW I BONUSOW
		void Update(int c) {
			if (g.zwrocCzyStart() == 1)
			{
			Prostokat klocek(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0);
			int kol = p.losujK();
			p.tworzKloca(klocek, kol);
			klocki.push_back(klocek);
			if (klocki.size() >= 7) {
				klocki.erase(klocki.begin());
				klocki.resize(6);
			}
			predkoscTworzenia = 1.0 / (0.5 / predkoscZjazdu);
			int nrKol;
			double xKloca = klocki[klocki.size() - 1].zwrocYy();
			nrKol = klocek.zwrocNr();
			//std::cout << klocki[0].zwrocYy() << std::endl;

			if (ilePrzebiegow >= 10)
			{
				//std::cout << "LECI BONUS   " << nrKol << std::endl;
				Prostokat bonus;
				int kolB = g.losujPozB(kol);
				g.losujBonus(kolB, bonus, xKloca + 1.0);
				klocki.push_back(bonus);
				//std::cout << kolB << "   " << bonus.zwrocYy() << std::endl;
				ilePrzebiegow = ilePrzebiegow - 5;
			}
			ilePrzebiegow++;
		}
			if (g.zwrocCzyNadalGra() == 1)
				glutTimerFunc((int)predkoscTworzenia, Update, NULL);
		}




		//LOGIKA ZJAZDU I PRZEGRANEJ
		void zjazdUpdate() {

			for (auto i = klocki.begin(); i != klocki.end(); i++) {
				i->zjazdKloca();
			}
		}
		void hideLogic(int c)
		{
			glutHideWindow();
		}
		void zjazdLogic(int c) {
			if (g.zwrocCzyStart() == 1) {
				zjazdUpdate();
				g.przegrana(klocki);
			}
				if (g.zwrocCzyNadalGra() == 1)
					glutTimerFunc((int)predkoscZjazdu, zjazdLogic, NULL);
				else
					glutTimerFunc(2000, hideLogic, NULL);
			}
			
		



		//OBSLUGA MYSZKI I ODZNACZEN
		void odznaczenie(int k, int l) {
			int u = 0;
			double oX = ((k - 400.0) / 400.0) * 3.23;
			double oY = -((l - 310.0) / 310.0) * 2.5;

			for (auto i = klocki.begin(); i != klocki.end(); i++)
			{

				if (oY >= (i->zwrocYy() - 0.5) && oY <= (i->zwrocYy() + 0.5) && oX <= (i->zwrocX() + 0.385) && oX >= (i->zwrocX() - 0.385)) {

					if (i->zwrocNrBonusu() == 0 && i->zwrocCzyOdznaczona() == 0) {
						i->wybiel();
						i->zaznaczOdznaczenie();
					}
					else if (i->zwrocNrBonusu() == 1 && i->zwrocCzyOdznaczona() == 0 && g.zwrocIleZyc() < 5) {
						g.pasekZyc();
						//std::cout << "dodano zycie" << std::endl;
						i->zaznaczOdznaczenie();
						i->wybiel();
					}

					else if (i->zwrocNrBonusu() == 2 && i->zwrocCzyOdznaczona() == 0 && g.zwrocIleBomb() < 5) {
						g.pasekBomb();
						//std::cout << "dodano bombe" << std::endl;
						i->zaznaczOdznaczenie();
						i->wybiel();
					}


					else if (i->zwrocNrBonusu() == 3 && i->zwrocCzyOdznaczona() == 0) {
						predkoscZjazdu = predkoscZjazdu - 70;
						if (predkoscZjazdu <= 45)
							predkoscZjazdu = 50;
						//std::cout << "speed up" << std::endl;
						i->zaznaczOdznaczenie();
						i->wybiel();
						glutTimerFunc(10000, zwolnij, NULL);

					}
					else if (i->zwrocNrBonusu() == 4 && i->zwrocCzyOdznaczona() == 0) {
						zwolnij(u);
						//std::cout << "slow down" << std::endl;
						i->zaznaczOdznaczenie();
						i->wybiel();

						if (g.zwrocCzyStart() == 1) 
							if (g.zwrocCzyNadalGra() == 1)
							glutTimerFunc(10000, przyspiesz, NULL);
					}
				}
			}
		}



		void display()
		{
			predkoscTworzenia = 1.0 / (0.5 / predkoscZjazdu);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glPushMatrix();
			{
				//std::cout << g.zwrocCzyStart() << std::endl;
				g.wyswietlNapisy();
				g.rysujLadowanie();
				g.rysujZycia();
				g.rysujBomby();
				for (auto a = plansza.begin(); a != plansza.end(); a++)
					a->rysuj();
				for (auto a = podPas.begin(); a != podPas.end(); a++)
					a->rysuj();
				for (auto a = klocki.begin(); a != klocki.end(); a++)
					a->rysuj();
			}
			glPopMatrix();

			glutSwapBuffers();

		}


		void InitGLUTScene(const char* window_name)
		{
			glutInitWindowSize(800, 620);
			glutInitWindowPosition(100, 10);
			glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

			glutCreateWindow(window_name);


			glClearColor(1, 1, 1, 1);

			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);

			glEnable(GL_LIGHT0);
			glEnable(GL_NORMALIZE);
			glEnable(GL_COLOR_MATERIAL);
		}



		void resize(int width, int height)
		{
			const float ar = (float)width / (float)height;

			glViewport(0, 0, width, height);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
			gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

		void idle()
		{
			glutPostRedisplay();
		}

		void SetCallbackFunctions()
		{

			glutReshapeFunc(resize);
			glutDisplayFunc(display);
			glutIdleFunc(idle);
			glutPassiveMotionFunc(odznaczenie);
			glutKeyboardFunc(detonacja);   

                        glutTimerFunc(g.zwrocT(), UpdateExp, NULL);
                        glutTimerFunc((int)predkoscTworzenia, Update, NULL);
                        glutTimerFunc(predkoscZjazdu, zjazdLogic, NULL);
                        glutTimerFunc(10000, przyspiesz, NULL);
                        glutTimerFunc(10000, zwolnij, NULL);
                        glutTimerFunc(10000, timeLogic, NULL);
                        glutTimerFunc(80000, timeLogic, NULL);
                        glutTimerFunc(10, czasGryLogic, NULL);
                        if (g.zwrocCzyNadalGra() == 0)
                                glutTimerFunc(2000, hideLogic, NULL);
			
		}
	

int main(int argc, char *argv[])
{
	
	p.dodajPlansze(plansza);
	p.dodajPodExpa(podPas);
	std::cout << "LET'S PLAY A GAME!" << std::endl  << std::endl;
	glutInit(&argc, argv);
	InitGLUTScene("Touch'emAll");
	SetCallbackFunctions();
	InitGLUTSceneSTART("Touch'emAll  (instrukcja)");
	SetCallbackFunctionsSTART();
	glutMainLoop();
	return 0;
	system("pause");
}


