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
	    void Afficher()
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

		int AjouterTrajet(Trajet *trajet);
		// Mode d'emploi :
	    //
	    // Contrat :
	    //

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
		Catalogue(int nbTrajetsM = NOMBRE_TRAJETS_MAX_DEFAUT);
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
		int nbTrajetsCourant;

		int nbTrajetsMax;

		Trajet** tableauTrajets;
};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
