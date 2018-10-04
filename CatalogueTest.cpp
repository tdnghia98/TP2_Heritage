/*************************************************************************
                           CatalogueTest  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Réalisation du module CatalogueTest (fichier CatalogueTest.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CatalogueTest.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
{
	Catalogue *catalogue = new Catalogue;

	char departTS1[] = "A", arriveeTS1[] = "B", transportTS1[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS1, arriveeTS1, transportTS1));

	char departTS2[] = "B", arriveeTS2[] = "C", transportTS2[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS2, arriveeTS2, transportTS2));

	char departTS3[] = "C", arriveeTS3[] = "D", transportTS3[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS3, arriveeTS3, transportTS3));

	char departTS4[] = "M", arriveeTS4[] = "D", transportTS4[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS4, arriveeTS4, transportTS4));

	char departTS5[] = "B", arriveeTS5[] = "E", transportTS5[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS5, arriveeTS5, transportTS5));

	char departTS6[] = "A", arriveeTS6[] = "D", transportTS6[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS6, arriveeTS6, transportTS6));

	char departTS7[] = "B", arriveeTS7[] = "F", transportTS7[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS7, arriveeTS7, transportTS7));

	char departTC11[] = "B", arriveeTC11[] = "E", transportTC11[] = "";
	TrajetSimple *TC11 = new TrajetSimple(departTC11, arriveeTC11, transportTC11);
	char departTC12[] = "E", arriveeTC12[] = "M", transportTC12[] = "";
	TrajetSimple *TC12 = new TrajetSimple(departTC12, arriveeTC12, transportTC12);
	TrajetCompose *TC1 = new TrajetCompose(2);
	TC1->AjouterTrajet(TC11);
	TC1->AjouterTrajet(TC12);
	catalogue->AjouterTrajet(TC1);

	char departTS8[] = "C", arriveeTS8[] = "T", transportTS8[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS8, arriveeTS8, transportTS8));

	char departTS9[] = "M", arriveeTS9[] = "C", transportTS9[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS9, arriveeTS9, transportTS9));

	char departTS10[] = "A", arriveeTS10[] = "M", transportTS10[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS10, arriveeTS10, transportTS10));

	char departTS11[] = "T", arriveeTS11[] = "A", transportTS11[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS11, arriveeTS11, transportTS11));

	char departTS12[] = "T", arriveeTS12[] = "B", transportTS12[] = "";
	catalogue->AjouterTrajet(new TrajetSimple(departTS12, arriveeTS12, transportTS12));

	char departTC21[] = "F", arriveeTC21[] = "W", transportTC21[] = "";
	TrajetSimple *TC21 = new TrajetSimple(departTC21, arriveeTC21, transportTC21);
	char departTC22[] = "W", arriveeTC22[] = "C", transportTC22[] = "";
	TrajetSimple *TC22 = new TrajetSimple(departTC22, arriveeTC22, transportTC22);
	TrajetCompose *TC2 = new TrajetCompose(2);
	TC2->AjouterTrajet(TC21);
	TC2->AjouterTrajet(TC22);
	catalogue->AjouterTrajet(TC2);

	catalogue->Afficher();

	char lD[] = "A", lA[] = "W";
	catalogue->RechercherTrajet(lD, lA);


	// TRAJET COMPOSE
	// char departTC11[] = "Lyon", arriveeTC11[] = "Marseille", transportTC11[] = "Bateau";
	// TrajetSimple *TC11 = new TrajetSimple(departTC11, arriveeTC11, transportTC11);
	//
	// char departTC12[] = "Marseille", arriveeTC12[] = "Paris", transportTC12[] = "Avion";
	// TrajetSimple *TC12 = new TrajetSimple(departTC12, arriveeTC12, transportTC12);
	//
	// TrajetCompose *TC1 = new TrajetCompose(2);
	// TC1->AjouterTrajet(TC11);
	// TC1->AjouterTrajet(TC12);
	//
	// // CATALOGUE
	// Catalogue *c = new Catalogue;
	// c->AjouterTrajet(TS1);
	// c->AjouterTrajet(TS2);
	// c->AjouterTrajet(TC1);
	// //c.RechercherTrajet(departTS1, arriveeTS1);
	// c->Afficher();

	return 0;
}

//type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom
