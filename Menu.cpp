/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : 30/10/2018
*************************************************************************/

//---------- Réalisation du module Menu (fichier Menu.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Menu.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum CHOIX_UTILISATEUR {AFFICHAGE_CATALOGUE = 1, AJOUT_TRAJET, RECHERCHE_VOYAGE, FIN};
enum CREATION_TRAJET {TRAJET_SIMPLE = 1};

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
{
	int saisieUtilisateur = 0;
	Catalogue *catalogue = new Catalogue;

	while (saisieUtilisateur != FIN)
	{
		AfficherChoix();
		saisieUtilisateur = SaisirChoix(1, 4);

		switch (saisieUtilisateur) {
			case AFFICHAGE_CATALOGUE:
				catalogue->Afficher();
				break;
			case AJOUT_TRAJET:
				CreerTrajet(catalogue);
				break;
			case RECHERCHE_VOYAGE:
				RechercherVoyage(catalogue);
				break;
		}
	}

	return 0;
}

void RechercherVoyage(Catalogue *catalogue)
// Algorithme :
//
{	
	char *lieuDepart = new char[100],
	*lieuArrivee = new char[100];

	cout << endl << "--- Recherche d'un voyage ---" << endl;
	cout << "Saisir le lieu de depart : ";
	cin >> lieuDepart;
	cout << "Saisir le lieu d'arrivee : ";
	cin >> lieuArrivee;

	catalogue->RechercherTrajet(lieuDepart, lieuArrivee);
}

void CreerTrajet(Catalogue *catalogue)
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
		saisieUtilisateur = SaisirNombreTrajets();
		t = CreerTrajetCompose(saisieUtilisateur);
	}

	catalogue->AjouterTrajet(t);
}

TrajetCompose* CreerTrajetCompose(int nombreTrajetsSimples)
// Algorithme :
//
{
	TrajetCompose *tc = new TrajetCompose;
	TrajetSimple *ts;

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

int SaisirNombreTrajets()
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

TrajetSimple* CreerTrajetSimple()
// Algorithme :
//
{
	TrajetSimple *ts;

	char *lieuDepart = new char[100],
	*lieuArrivee = new char[100],
	*moyenTransport = new char[100];

	cout << endl << "--- Creation d'un trajet simple ---" << endl;
	cout << "Saisir le lieu de depart : ";
	cin >> lieuDepart;
	cout << "Saisir le lieu d'arrivee : ";
	cin >> lieuArrivee;
	cout << "Saisir le moyen de transport : ";
	cin >> moyenTransport;

	ts = new TrajetSimple(lieuDepart, lieuArrivee, moyenTransport);

	cout << endl << "Trajet cree : ";
	ts->Afficher();

	return ts;
}

void AfficherChoix()
// Algorithme :
//
{
	cout << endl << "--- Menu de gestion d'un catalogue de voyage ---" << endl;
	cout << "1 - Afficher le catalogue" << endl;
	cout << "2 - Inserer un trajet" << endl;
	cout << "3 - Rechercher un voyage" << endl;
	cout << "4 - Quitter" << endl << endl;
} //----- fin de AfficherMenu

int SaisirChoix(int borneInf, int borneSup)
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
} //----- fin de SaisirChoix
