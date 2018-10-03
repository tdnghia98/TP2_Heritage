/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : 03/10/2018
*************************************************************************/

//---------- Interface du module Menu (fichier Menu.h) -------------------
#if ! defined (MENU_H)
#define MENU_H

//------------------------------------------------------------------------
// Rôle du module Menu
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main();

void RechercherVoyage(Catalogue *catalogue);
// Mode d'emploi :
//
// Contrat :
//

int SaisirNombreTrajets();
// Mode d'emploi :
//
// Contrat :
//

TrajetCompose* CreerTrajetCompose(int nombreTrajetsSimples);
// Mode d'emploi :
//
// Contrat :
//

void CreerTrajet(Catalogue *catalogue);
// Mode d'emploi :
//
// Contrat :
//

TrajetSimple* CreerTrajetSimple();
// Mode d'emploi :
//
// Contrat :
//

int SaisirChoix(int borneInf, int borneSup);
// Mode d'emploi :
//
// Contrat :
//

void AfficherChoix();
// Mode d'emploi :
//
// Contrat :
//

#endif // MENU_H
