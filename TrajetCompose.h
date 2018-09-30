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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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

	    virtual void Afficher() const;
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
		TrajetCompose(unsigned int nbTrajetsM = NOMBRE_TRAJETS_MAX_DEFAUT);
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
		bool VerifierContrainte(const Trajet & trajet) const;

		//----------------------------------------------------- Attributs privées
		int nbTrajetsCourant;

		int nbTrajetsMax;

		Trajet** tableauTrajets;
};

//-------------------------------- Autres définitions dépendantes de TrajetCompose

#endif // TRAJETCOMPOSE_H
