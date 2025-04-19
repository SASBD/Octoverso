#include <stdio.h>

#include "Jeu.h"
#include "Pioche.h"
#include "Chevalet.h"
#include "Rail.h"
#include "Dico.h"


void initPartie(Chevalet *joueurs1,Chevalet *joueurs2, Pioche *pioche, FILE *dictonnaire)
{
    init_pioche(pioche);
    melanger_pioche(pioche);
    initchevalet(joueurs1, pioche);
    initchevalet(joueurs2, pioche);

    //premierMot( choisir ordre);

    dictonnaire = fopen("ods4.txt", "r");
    verifierDico(dictonnaire);
}
