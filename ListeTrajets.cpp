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
void ListeTrajets::Afficher() const
// Algorithme :
//
{
	cout << "{" << endl;
	for (int curseur = 0; curseur < nombreTrajetsCourant; curseur++)
	{
		//cout << "\t";
		(*trajets[curseur]).Afficher();
	}
	cout << "}" << endl;
} //----- Fin de Méthode

bool ListeTrajets::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
	if (nombreTrajetsCourant < nombreTrajetsMax)
	{
		//if (ContrainteLieuEstVerifiee(*trajet))
		//{
		trajets[nombreTrajetsCourant++] = trajet;
		return true;
		//}
	}

	return false;
} //----- Fin de Méthode

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
