#include <iostream>
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
using namespace std;

int main() {

    // TRAJETS SIMPLE
    char departTS1[] = "Lyon", arriveeTS1[] = "Bordeaux", transportTS1[] = "Train";
    char departTS2[] = "Lyon", arriveeTS2[] = "Paris", transportTS2[] = "Auto";

    TrajetSimple *TS1 = new TrajetSimple(departTS1, arriveeTS1, transportTS1, 1);
    TS1->Afficher();

    TrajetSimple *TS2 = new TrajetSimple(departTS2, arriveeTS2, transportTS2, 2);
    TS2->Afficher();

    // TRAJET COMPOSE
    char departTC11[] = "Lyon", arriveeTC11[] = "Marseille", transportTC11[] = "Bateau";
    TrajetSimple *TC11 = new TrajetSimple(departTC11, arriveeTC11, transportTC11,11);

    char departTC12[] = "Marseille", arriveeTC12[] = "Paris", transportTC12[] = "Avion";
    TrajetSimple *TC12 = new TrajetSimple(departTC12, arriveeTC12, transportTC12,12);

    TrajetCompose *TC1 = new TrajetCompose(2,1);
    TC1->AjouterTrajet(TC11);
    TC1->AjouterTrajet(TC11);
    TC1->AjouterTrajet(TC12);
    TC1->Afficher();
    Catalogue* c;
    c = new Catalogue(3);
    c->ajouterTrajet(TS1);
    c->ajouterTrajet(TS2);
    c->ajouterTrajet(TC1);
    c->Afficher();
    return 0;
}