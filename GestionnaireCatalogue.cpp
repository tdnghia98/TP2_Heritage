/*************************************************************************
                           GestionnaireCatalogue  -  description
                             -------------------
    début                : 04/10/2018
*************************************************************************/

//---------- Réalisation de la classe GestionnaireCatalogue (fichier GestionnaireCatalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "GestionnaireCatalogue.h"

//------------------------------------------------------------- Constantes
enum CHOIX_UTILISATEUR {AFFICHAGE_CATALOGUE = 1, AJOUT_TRAJET, RECHERCHE_VOYAGE_SIMPLE, RECHERCHE_VOYAGE_COMPOSE, FIN};
enum CREATION_TRAJET {TRAJET_SIMPLE = 1};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void GestionnaireCatalogue::LancerMenu()
// Algorithme :
//
{
	int saisieUtilisateur = 0;

	while (saisieUtilisateur != FIN)
	{
		AfficherMenuGestionnaire();
		saisieUtilisateur = SaisirChoix(AFFICHAGE_CATALOGUE, FIN);

		switch (saisieUtilisateur) {
			case AFFICHAGE_CATALOGUE:
				catalogue->Afficher();
				break;
			case AJOUT_TRAJET:
				AjouterTrajet();
				break;
			case RECHERCHE_VOYAGE_SIMPLE:
				RechercherVoyage(RECHERCHE_VOYAGE_SIMPLE);
				break;
			case RECHERCHE_VOYAGE_COMPOSE:
				RechercherVoyage(RECHERCHE_VOYAGE_COMPOSE);
				break;
		}
	}
}

void GestionnaireCatalogue::RechercherVoyage(int type)
// Algorithme :
//
{
	char lD[100], lA[100];
	char *lieuDepart, *lieuArrivee;

	cout << endl << "--- Recherche d'un voyage ---" << endl;
	cout << "Saisir le lieu de depart : ";
	cin >> lD;
	cout << "Saisir le lieu d'arrivee : ";
	cin >> lA;

	lieuDepart = new char[strlen(lD) + 1];
	strcpy(lieuDepart, lD);

	lieuArrivee = new char[strlen(lA) + 1];
	strcpy(lieuArrivee, lA);

	if (type == RECHERCHE_VOYAGE_SIMPLE)
	{
		catalogue->RechercherVoyageSimple(lieuDepart, lieuArrivee);
	}
	else
	{
		catalogue->RechercherVoyageCompose(lieuDepart, lieuArrivee);
	}
}

void GestionnaireCatalogue::AjouterTrajet()
// Algorithme :
//
{
	Trajet *t;
	int saisieUtilisateur;

	cout << "Type de trajet :" << endl;
	cout << "1 - Trajet simple" << endl;
	cout << "2 - Trajet compose" << endl;

	saisieUtilisateur = SaisirChoix(1, 2);

	if (saisieUtilisateur == TRAJET_SIMPLE)
	{
		t = CreerTrajetSimple();
	}
	else
	{
		t = CreerTrajetCompose();
	}

	catalogue->AjouterTrajet(t);
}

TrajetSimple* GestionnaireCatalogue::CreerTrajetSimple()
// Algorithme :
//
{
	TrajetSimple *ts;

	char lD[100], lA[100], mT[100];
	char *lieuDepart, *lieuArrivee, *moyenTransport;

	cout << endl << "--- Recherche d'un voyage ---" << endl;
	cout << "Saisir le lieu de depart : ";
	cin >> lD;
	cout << "Saisir le lieu d'arrivee : ";
	cin >> lA;
	cout << "Saisir le moyen de transport : ";
	cin >> mT;

	lieuDepart = new char[strlen(lD) + 1];
	strcpy(lieuDepart, lD);

	lieuArrivee = new char[strlen(lA) + 1];
	strcpy(lieuArrivee, lA);

	moyenTransport = new char[strlen(mT) + 1];
	strcpy(moyenTransport, mT);

	ts = new TrajetSimple(lieuDepart, lieuArrivee, moyenTransport);

	cout << endl << "Trajet cree : ";
	ts->Afficher();

	return ts;
}

TrajetCompose* GestionnaireCatalogue::CreerTrajetCompose()
// Algorithme :
//
{
	TrajetCompose *tc = new TrajetCompose;
	TrajetSimple *ts;
	int nombreTrajetsSimples = SaisirNombreTrajets();

	for (int iInsertion = 0; iInsertion < nombreTrajetsSimples; iInsertion++)
	{
		ts = CreerTrajetSimple();
		while (tc->AjouterTrajet(ts) == CONTRAINTE_NON_VERIFIEE)
		{
			cout << "/!\\ ERREUR : contrainte non verifiee. Resaisir." << endl;
			ts = CreerTrajetSimple();
		}
	}

	return tc;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
GestionnaireCatalogue::GestionnaireCatalogue(Catalogue *unCatalogue) : catalogue(unCatalogue)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur de GestionnaireCatalogue" << endl;
	#endif
} //----- Fin de GestionnaireCatalogue

GestionnaireCatalogue::~GestionnaireCatalogue()
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au destructeur de GestionnaireCatalogue" << endl;
	#endif
} //----- Fin de ~GestionnaireCatalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
void GestionnaireCatalogue::AfficherMenuGestionnaire() const
// Algorithme :
//
{
	cout << endl << "--- Menu de gestion d'un catalogue de voyage ---" << endl;
	cout << "1 - Afficher le catalogue" << endl;
	cout << "2 - Inserer un trajet" << endl;
	cout << "3 - Rechercher un voyage (simple)" << endl;
	cout << "4 - Rechercher un voyage (compose)" << endl;
	cout << "5 - Quitter" << endl << endl;
} //----- Fin de Méthode

int GestionnaireCatalogue::SaisirChoix(int borneInf, int borneSup)
// Algorithme :
//
{
	int saisieUtilisateur = 0;

	cout << "Saisir choix : ";
	cin >> saisieUtilisateur;

	while (saisieUtilisateur > borneSup || saisieUtilisateur < borneInf) //contrôle de la saisie
	{
		cout << "/!\\ ERREUR : mauvaise entree. Resaisir." << endl;
		cout << "Saisir choix : ";
		cin >> saisieUtilisateur;
	}

	return saisieUtilisateur;
}

int GestionnaireCatalogue::SaisirNombreTrajets()
// Algorithme :
//
{
	int saisieUtilisateur = 0;

	cout << "Nombre de trajets simples : ";
	cin >> saisieUtilisateur;

	while (saisieUtilisateur < 2) //contrôle de la saisie
	{
		cout << "/!\\ ERREUR : mauvaise entree (au moins 2 trajets simples). Resaisir." << endl;
		cout << "Saisir nombre : ";
		cin >> saisieUtilisateur;
	}

	return saisieUtilisateur;
}
