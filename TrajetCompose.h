/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Interface de la classe TrajetCompose (fichier TrajetCompose.h) ----------------
#if ! defined (TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum CODE_RETOUR_AJOUT {PLEIN, CONTRAINTE_NON_VERIFIEE, AJOUTE};

//------------------------------------------------------------------------
// Rôle de la classe TrajetCompose
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
	//----------------------------------------------------------------- PUBLIC

	public:
		//----------------------------------------------------- Méthodes publiques
		int AjouterTrajet(Trajet *trajet);
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

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

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
		TrajetCompose(unsigned int capaciteMax = NOMBRE_TRAJETS_MAX_DEFAUT);
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

	    virtual ~TrajetCompose();
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
		bool ContrainteLieuEstVerifiee(const Trajet & trajet) const;

		//----------------------------------------------------- Attributs privées
		ListeTrajets *listeDeTrajets;
};

//-------------------------------- Autres définitions dépendantes de TrajetCompose

#endif // TRAJETCOMPOSE_H
