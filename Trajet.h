/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Interface de la classe Trajet (fichier Trajet.h) ----------------
#if ! defined (TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Trajet
//
//
//------------------------------------------------------------------------

class Trajet
{
	//----------------------------------------------------------------- PUBLIC

	public:
		//----------------------------------------------------- Méthodes publiques
		virtual char* GetLieuDepart() const = 0;
		// Mode d'emploi :
		//
		// Contrat :
		//
		virtual char* GetLieuArrivee() const = 0;
		// Mode d'emploi :
		//
		// Contrat :
		//

		virtual void Afficher() const = 0;
		// Mode d'emploi :
		//
		// Contrat :
		//

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
	    virtual ~Trajet();
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

};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJET_H
