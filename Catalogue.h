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
#include "CollectionTrajets.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

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
	    void Afficher(int profondeur = 0);
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

		void AjouterTrajet(Trajet *trajet);
		// Mode d'emploi :
	    //
	    // Contrat :
	    //

		// void AjouterTrajet(Trajet *trajet);

		// void RechercherTrajet(char *lieuDepart, char *lieuArrivee);

		void RechercherVoyageCompose(char *lieuDepart, char *lieuArrivee);
		// Mode d'emploi :
		//
		// Contrat :
		//

		void RechercherVoyageSimple(char *lieuDepart, char *lieuArrivee);
		// Mode d'emploi :
		//
		// Contrat :
		//

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
		void ParcoursProfondeur(Trajet *sommet, CollectionTrajets *listeTraitement,
			char *lieuDepart, char *lieuArrivee, int *nombreVoyagesTrouves);
		// Mode d'emploi :
		//
		// Contrat :
		//

		//----------------------------------------------------- Attributs privées
		CollectionTrajets *listeDeTrajets;
};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
