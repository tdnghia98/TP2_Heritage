/*************************************************************************
                           CollectionTrajets  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Réalisation de la classe CollectionTrajets (fichier CollectionTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "CollectionTrajets.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void CollectionTrajets::Afficher(int profondeur) const
// Algorithme :
//
{
	for (int iProfondeur = 0; iProfondeur < profondeur; iProfondeur++)
	{
		cout << "\t";
	}
	cout << "{" << endl;

	for (int curseur = 0; curseur < nombreTrajetsCourant; curseur++)
	{
		(*trajets[curseur]).Afficher(profondeur + 1);
	}

	for (int iProfondeur = 0; iProfondeur < profondeur; iProfondeur++)
	{
		cout << "\t";
	}
	cout << "}" << endl;
} //----- Fin de Méthode

void CollectionTrajets::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
	if (nombreTrajetsCourant == nombreTrajetsMax)
	{
		Ajuster();
	}

	trajets[nombreTrajetsCourant++] = trajet;
} //----- Fin de Méthode

void CollectionTrajets::RetirerDernierTrajet()
// Algorithme :
//
{
	if (nombreTrajetsCourant > 0)
	{
		//delete trajets[--nombreTrajetsCourant];
		nombreTrajetsCourant--;
	}
}

Trajet* CollectionTrajets::GetPremierTrajet() const
// Algorithme :
//
{
	return trajets[0];
}

Trajet* CollectionTrajets::GetDernierTrajet() const
// Algorithme :
//
{
	return trajets[nombreTrajetsCourant - 1];
}

int CollectionTrajets::GetNombreTrajetsCourant() const
// Algorithme :
//
{
	return nombreTrajetsCourant;
}

Trajet* CollectionTrajets::GetTrajet(int indice) const
// Algorithme :
//
{
	Trajet *trajet;

	if (indice <= nombreTrajetsCourant)
	{
		trajet = trajets[indice];
	}

	return trajet;
}

bool CollectionTrajets::EstVide() const
// Algorithme :
//
{
	return nombreTrajetsCourant == 0;
}

bool CollectionTrajets::EstDans(Trajet *trajet) const
{
	for (int iTrajet = 0; iTrajet < nombreTrajetsCourant; iTrajet++)
	{
		if (trajet == trajets[iTrajet])
		{
			return true;
		}
	}
	return false;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
CollectionTrajets::CollectionTrajets(unsigned int capaciteMax)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur de CollectionTrajets" << endl;
	#endif

	trajets = new Trajet*[capaciteMax];
	nombreTrajetsMax = capaciteMax;
	nombreTrajetsCourant = 0;
} //----- Fin de CollectionTrajets

CollectionTrajets::~CollectionTrajets()
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au destructeur de CollectionTrajets" << endl;
	#endif

	for (int curseur = 0; curseur < nombreTrajetsCourant; curseur++)
    {
        delete trajets[curseur];
    }

    delete [] trajets;
} //----- Fin de ~CollectionTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
void CollectionTrajets::Ajuster()
// Algorithme :
//
{
	Trajet **nouvelleListe;
	int nouvelleTaille;

	nombreTrajetsMax *= 2;
	nouvelleListe = new Trajet*[nombreTrajetsMax];
	for (int iCurseur = 0; iCurseur < nombreTrajetsCourant; iCurseur++)
	{
		nouvelleListe[iCurseur] = trajets[iCurseur];
	}

	delete [] trajets;
	trajets = nouvelleListe;
}
