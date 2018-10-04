/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : 30/10/2018
*************************************************************************/

//---------- Réalisation du module Menu (fichier Menu.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Menu.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
{
	Catalogue *catalogue = new Catalogue;
	catalogue->Menu();

	return 0;
}
