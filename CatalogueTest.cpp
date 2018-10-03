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
	// TRAJETS SIMPLE
	char departTS1[] = "Lyon", arriveeTS1[] = "Bordeaux", transportTS1[] = "Train";
	char departTS2[] = "Lyon", arriveeTS2[] = "Paris", transportTS2[] = "Auto";

	TrajetSimple *TS1 = new TrajetSimple(departTS1, arriveeTS1, transportTS1);

	TrajetSimple *TS2 = new TrajetSimple(departTS2, arriveeTS2, transportTS2);

	// TRAJET COMPOSE
	char departTC11[] = "Lyon", arriveeTC11[] = "Marseille", transportTC11[] = "Bateau";
	TrajetSimple *TC11 = new TrajetSimple(departTC11, arriveeTC11, transportTC11);

	char departTC12[] = "Marseille", arriveeTC12[] = "Paris", transportTC12[] = "Avion";
	TrajetSimple *TC12 = new TrajetSimple(departTC12, arriveeTC12, transportTC12);

	TrajetCompose *TC1 = new TrajetCompose(2);
	TC1->AjouterTrajet(TC11);
	TC1->AjouterTrajet(TC12);

	// CATALOGUE
	Catalogue c(3);
	c.AjouterTrajet(TS1);
	c.AjouterTrajet(TS2);
	c.AjouterTrajet(TC1);
	c.RechercherTrajet(departTS1, arriveeTS1);
	c.Afficher();

	return 0;
}

//type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom
