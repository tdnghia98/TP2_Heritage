//
// Created by dntran on 9/27/2018.
//

#ifndef TP2_HERITAGE_TRAJETSIMPLE_H
#define TP2_HERITAGE_TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
virtual char* GetLieuDepart() const;
// Mode d'emploi :
//
// Contrat :
//

virtual char* GetLieuArrivee() const;
// Mode d'emploi :
//
// Contrat :
//

virtual void Afficher() const;
// Mode d'emploi :
//
// Contrat :
//


//------------------------------------------------- Surcharge d'opérateurs
//${file_base} & operator = ( const ${file_base} & un${file_base} );
// Mode d'emploi :
//
// Contrat :
//


//-------------------------------------------- Constructeurs - destructeur
//${file_base} ( const ${file_base} & un${file_base} );
// Mode d'emploi (constructeur de copie) :
//
// Contrat :
//

TrajetSimple (char* LieuDepart, char* LieuArrivee, char* MoyenTransport);
// Mode d'emploi :
//
// Contrat :
//

virtual ~TrajetSimple();
// Mode d'emploi :
//
// Contrat :
//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Attributs privés
char* lieuDepart;

char* lieuArrivee;

char* moyenTransport;

//------------------------------------------------------- Méthodes privées

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <${file_base}>


#endif //TP2_HERITAGE_TRAJETSIMPLE_H
