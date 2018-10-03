/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Interface de la classe TrajetSimple (fichier TrajetSimple.h) ----------------
#if ! defined (TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe TrajetSimple
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

		virtual void Afficher(int profondeur = 0) const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		//-------------------------------------------- Constructeurs - destructeur
		TrajetSimple();
		// Mode d'emploi :
		//
		// Contrat :
		//

		TrajetSimple(char* LieuDepart, char* LieuArrivee, char* MoyenTransport);
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
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés

	private:
		//----------------------------------------------------- Méthodes privées

		//----------------------------------------------------- Attributs privées
		char* lieuDepart;

		char* lieuArrivee;

		char* moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de TrajetSimple

#endif // TRAJETSIMPLE_H
