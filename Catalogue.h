//
// Created by dntran on 9/27/2018.
//

#ifndef TP2_HERITAGE_CATALOGUE_H
#define TP2_HERITAGE_CATALOGUE_H


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Cette classe contient les Trajets sous forme d'un tableau de Trajet
// Elle permet de stocker et faire des recherches de trajet
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
void Afficher();

////------------------------------------------------- Surcharge d'opérateurs
//${file_base} & operator = ( const ${file_base} & un${file_base} );
//// Mode d'emploi :
////
//// Contrat :
////
//

//-------------------------------------------- Constructeurs - destructeur
Catalogue(int nbTMax);
// Mode d'emploi () :
//
// Contrat :
//

virtual ~Catalogue();
// Mode d'emploi :
//
// Contrat :
//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
Trajet** tableauTrajet; // Tableau de trajet
int nbTrajetMax;
int nbTrajetActuel;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <${file_base}>


#endif //TP2_HERITAGE_CATALOGUE_H
