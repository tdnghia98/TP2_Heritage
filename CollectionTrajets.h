/*************************************************************************
                           CollectionTrajets  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Interface de la classe CollectionTrajets (fichier CollectionTrajets.h) ----------------
#if ! defined (LISTETRAJETS_H)
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe CollectionTrajets
//
//
//------------------------------------------------------------------------

class CollectionTrajets
{
	//----------------------------------------------------------------- PUBLIC

	public:
		//----------------------------------------------------- Méthodes publiques
	    void AjouterTrajet(Trajet *trajet);
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

		void RetirerDernierTrajet();
		// Mode d'emploi :
		//
		// Contrat :
		//

		void Afficher(int profondeur = 0) const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		Trajet* GetPremierTrajet() const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		Trajet* GetDernierTrajet() const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		int GetNombreTrajetsCourant() const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		Trajet* GetTrajet(int indice) const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool EstVide() const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool EstDans(Trajet *trajet) const;
		// Mode d'emploi :
		//
		// Contrat :
		//

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
	    CollectionTrajets(unsigned int capaciteMax = NOMBRE_TRAJETS_MAX_DEFAUT);
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

	    virtual ~CollectionTrajets();
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
		void Ajuster();
		// Mode d'emploi :
		//
		// Contrat :
		//

		//----------------------------------------------------- Attributs privées
		int nombreTrajetsCourant;

		int nombreTrajetsMax;

		Trajet** trajets;

};

//-------------------------------- Autres définitions dépendantes de CollectionTrajets

#endif // LISTETRAJETS_H
