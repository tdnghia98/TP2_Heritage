/*************************************************************************
                           CatalogueTest  -  description
                             -------------------
    début                : 30/10/2018
*************************************************************************/

//---------- Réalisation du module CatalogueTest (fichier CatalogueTest.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CatalogueTest.h"
#include "Catalogue.h"
#include "GestionnaireCatalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
{
	char saisieUtilisateur = 0;

	cout << "Travailler avec un catalogue exemple non vide ? (y/n)" << endl << "Saisir choix : ";
	cin >> saisieUtilisateur;

	if (saisieUtilisateur == 'y')
	{
		GestionnaireCatalogue gc(GetExempleCatalogue());

		gc.LancerMenu();
	}
	else
	{
		Catalogue c;
		GestionnaireCatalogue gc(&c);

		gc.LancerMenu();
	}

	return 0;
}

Catalogue* GetExempleCatalogue()
{
	TrajetSimple *ts;
	Catalogue *catalogue = new Catalogue;

	char departTS1[] = "A", arriveeTS1[] = "B", transportTS1[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS1, arriveeTS1, transportTS1));

	char departTS2[] = "B", arriveeTS2[] = "C", transportTS2[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS2, arriveeTS2, transportTS2));

	char departTS3[] = "C", arriveeTS3[] = "D", transportTS3[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS3, arriveeTS3, transportTS3));

	char departTS4[] = "M", arriveeTS4[] = "D", transportTS4[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS4, arriveeTS4, transportTS4));

	char departTS5[] = "B", arriveeTS5[] = "E", transportTS5[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS5, arriveeTS5, transportTS5));

	char departTS6[] = "A", arriveeTS6[] = "D", transportTS6[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS6, arriveeTS6, transportTS6));

	char departTS7[] = "B", arriveeTS7[] = "F", transportTS7[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS7, arriveeTS7, transportTS7));

	char departTC11[] = "B", arriveeTC11[] = "E", transportTC11[] = "";
	TrajetSimple *TC11 = GetTrajetSimple(departTC11, arriveeTC11, transportTC11);
	char departTC12[] = "E", arriveeTC12[] = "M", transportTC12[] = "";
	TrajetSimple *TC12 = GetTrajetSimple(departTC12, arriveeTC12, transportTC12);
	TrajetCompose *TC1 = new TrajetCompose(2);
	TC1->AjouterTrajet(TC11);
	TC1->AjouterTrajet(TC12);
	catalogue->AjouterTrajet(TC1);

	char departTS8[] = "C", arriveeTS8[] = "T", transportTS8[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS8, arriveeTS8, transportTS8));

	char departTS9[] = "M", arriveeTS9[] = "C", transportTS9[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS9, arriveeTS9, transportTS9));

	char departTS10[] = "A", arriveeTS10[] = "M", transportTS10[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS10, arriveeTS10, transportTS10));

	char departTS11[] = "T", arriveeTS11[] = "A", transportTS11[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS11, arriveeTS11, transportTS11));

	char departTS12[] = "T", arriveeTS12[] = "B", transportTS12[] = "";
	catalogue->AjouterTrajet(GetTrajetSimple(departTS12, arriveeTS12, transportTS12));

	char departTC21[] = "F", arriveeTC21[] = "W", transportTC21[] = "";
	TrajetSimple *TC21 = GetTrajetSimple(departTC21, arriveeTC21, transportTC21);
	char departTC22[] = "W", arriveeTC22[] = "C", transportTC22[] = "";
	TrajetSimple *TC22 = GetTrajetSimple(departTC22, arriveeTC22, transportTC22);
	TrajetCompose *TC2 = new TrajetCompose(2);
	TC2->AjouterTrajet(TC21);
	TC2->AjouterTrajet(TC22);
	catalogue->AjouterTrajet(TC2);

	return catalogue;
}

TrajetSimple* GetTrajetSimple(char lD[], char lA[], char mT[])
{
	TrajetSimple *ts;

	char *depart, *arrivee, *transport;

	depart = new char[strlen(lD) + 1];
	strcpy(depart, lD);

	arrivee = new char[strlen(lA) + 1];
	strcpy(arrivee, lA);

	transport = new char[strlen(mT) + 1];
	strcpy(transport, mT);

	return new TrajetSimple(depart, arrivee, transport);
}
