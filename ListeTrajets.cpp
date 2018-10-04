/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : 27/09/2018
*************************************************************************/

//---------- Réalisation de la classe ListeTrajets (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ListeTrajets::Afficher(int profondeur) const
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

void ListeTrajets::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
	if (nombreTrajetsCourant == nombreTrajetsMax)
	{
		Ajuster();
	}

	trajets[nombreTrajetsCourant++] = trajet;
} //----- Fin de Méthode

void ListeTrajets::RetirerDernierTrajet()
// Algorithme :
//
{
	if (nombreTrajetsCourant > 0)
	{
		//delete trajets[--nombreTrajetsCourant];
		nombreTrajetsCourant--;
	}
}

Trajet* ListeTrajets::GetPremierTrajet() const
// Algorithme :
//
{
	return trajets[0];
}

Trajet* ListeTrajets::GetDernierTrajet() const
// Algorithme :
//
{
	return trajets[nombreTrajetsCourant - 1];
}

int ListeTrajets::GetNombreTrajetsCourant() const
// Algorithme :
//
{
	return nombreTrajetsCourant;
}

Trajet* ListeTrajets::GetTrajet(int indice) const
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

bool ListeTrajets::EstVide() const
// Algorithme :
//
{
	return nombreTrajetsCourant == 0;
}

bool ListeTrajets::EstDans(Trajet *trajet) const
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
ListeTrajets::ListeTrajets(unsigned int capaciteMax)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur de ListeTrajets" << endl;
	#endif

	trajets = new Trajet*[capaciteMax];
	nombreTrajetsMax = capaciteMax;
	nombreTrajetsCourant = 0;
} //----- Fin de ListeTrajets

ListeTrajets::~ListeTrajets()
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au destructeur de ListeTrajets" << endl;
	#endif

	for (int curseur = 0; curseur < nombreTrajetsCourant; curseur++)
    {
        delete trajets[curseur];
    }

    delete [] trajets;
} //----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
void ListeTrajets::Ajuster()
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
