/*************************************************************************
                           CatalogueTest  -  description
                             -------------------
    début                : 03/10/2018
*************************************************************************/

//---------- Interface du module Menu (fichier CatalogueTest.h) -------------------
#if ! defined (CATALOGUETEST_H)
#define CATALOGUETEST_H

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

Catalogue* GetExempleCatalogue();

TrajetSimple* GetTrajetSimple(char lD[], char lA[], char mT[]);

#endif // CATALOGUETEST_H
