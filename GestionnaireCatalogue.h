/*************************************************************************
                           GestionnaireCatalogue  -  description
                             -------------------
    début                : 04/10/2018
*************************************************************************/

//---------- Interface de la classe GestionnaireCatalogue (fichier GestionnaireCatalogue.h) ----------------
#if ! defined (GESTIONNAIRECATALOGUE_H)
#define GESTIONNAIRECATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe GestionnaireCatalogue
//
//
//------------------------------------------------------------------------

class GestionnaireCatalogue
{
	//----------------------------------------------------------------- PUBLIC

	public:
		//----------------------------------------------------- Méthodes publiques
		void LancerMenu();
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

		void AjouterTrajet();
		// Mode d'emploi :
		//
		// Contrat :
		//

		void RechercherVoyage(int type);
		// Mode d'emploi :
		//
		// Contrat :
		//

		TrajetSimple* CreerTrajetSimple();
		// Mode d'emploi :
		//
		// Contrat :
		//

		TrajetCompose* CreerTrajetCompose();
		// Mode d'emploi :
		//
		// Contrat :
		//

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
	    GestionnaireCatalogue(Catalogue *unCatalogue);
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

	    virtual ~GestionnaireCatalogue();
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
		void AfficherMenuGestionnaire() const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		int SaisirChoix(int borneInf, int borneSup);
		// Mode d'emploi :
		//
		// Contrat :
		//

		int SaisirNombreTrajets();
		// Mode d'emploi :
		//
		// Contrat :
		//

		//----------------------------------------------------- Attributs privées
		Catalogue *catalogue;

};

//-------------------------------- Autres définitions dépendantes de GestionnaireCatalogue

#endif // GESTIONNAIRECATALOGUE_H
