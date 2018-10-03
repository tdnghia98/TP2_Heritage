/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Interface de la classe Catalogue (fichier Catalogue.h) ----------------
#if ! defined (CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Catalogue
//
//
//------------------------------------------------------------------------

class Catalogue
{
	//----------------------------------------------------------------- PUBLIC

	public:
		//----------------------------------------------------- Méthodes publiques
	    void Afficher();
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

		bool AjouterTrajet(Trajet *trajet);
		// Mode d'emploi :
	    //
	    // Contrat :
	    //

		void RechercherTrajet(char *lieuDepart, char *lieuArrivee);

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
		Catalogue(unsigned int capaciteMax = NOMBRE_TRAJETS_MAX_DEFAUT);
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

		//----------------------------------------------------- Attributs protégés

	private:
		//----------------------------------------------------- Méthodes privées

		//----------------------------------------------------- Attributs privées
		ListeTrajets *listeDeTrajets;
};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
