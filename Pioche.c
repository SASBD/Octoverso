#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "vecteur.h"
#include "Pioche.h"


// ✔️
const char lettres[] = {
    'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
    'B',
    'C', 'C',
    'D', 'D', 'D',
    'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E',
    'F',
    'G',
    'H',
    'I', 'I', 'I', 'I', 'I', 'I', 'I',
    'J',
    'L', 'L', 'L', 'L', 'L',
    'M', 'M', 'M',
    'N', 'N', 'N', 'N', 'N', 'N',
    'O', 'O', 'O', 'O', 'O',
    'P', 'P',
    'Q',
    'R', 'R', 'R', 'R', 'R', 'R',
    'S', 'S', 'S', 'S', 'S', 'S', 'S',
    'T', 'T', 'T', 'T', 'T', 'T',
    'U', 'U', 'U', 'U', 'U',
    'V', 'V'
};

// ✔️
int init_pioche(Pioche *pioche)
{
    if (!initVecteur(&pioche->lettres, NB_LETTRES_TOTAL)) {
        return 0; //
    }

    for (int i = 0; i < NB_LETTRES_TOTAL; i++) {
        if (!ajouter(&pioche->lettres, lettres[i])) {
            detruireVecteur(&pioche->lettres);
            return 0;
        }
    }


    pioche->nb_restantes = NB_LETTRES_TOTAL;
    return 1;
}

// Mélange la pioche ✔️
int  melanger_pioche(Pioche *pioche){
    if (pioche->lettres == NULL) {
        return 0;
    }
    srand(time(NULL));
    for (int i = pioche->nb_restantes - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = pioche->lettres->elements[i];
        pioche->lettres->elements[i] = pioche->lettres->elements[j];
        pioche->lettres->elements[j] = temp;
    }
}

void ajouterLettrePioche(Pioche *pioche, char lettre)
{
    pioche->lettres->elements[pioche->nb_restantes] = lettre;
    pioche->nb_restantes++;
}

// ️️✔️
char tirer_lettre(Pioche *pioche)
{
    if (pioche->lettres == NULL) {
        return ' ';
    }
    int i = rand() % pioche->nb_restantes;
    char lettre = pioche->lettres->elements[i];
    pioche->lettres->elements[i] = pioche->lettres->elements[pioche->nb_restantes - 1];
    pioche->nb_restantes--;
    return lettre;
}

void testPioche() {
    Pioche pioche;
    init_pioche(&pioche);
    assert(pioche.nb_restantes == NB_LETTRES_TOTAL);

    char lettre = tirer_lettre(&pioche);
    assert(pioche.nb_restantes == NB_LETTRES_TOTAL - 1);
    assert(lettre != ' ');

    melanger_pioche(&pioche);
    assert(pioche.nb_restantes == NB_LETTRES_TOTAL);
    char lettre1 = pioche.lettres->elements[0];
    melanger_pioche(&pioche);
    assert(pioche.lettres->elements[0] != lettre1);

    while (pioche.nb_restantes > 0) {
        tirer_lettre(&pioche);
    }
    assert(pioche.nb_restantes == 0);

    init_pioche(&pioche);
    assert(pioche.nb_restantes == NB_LETTRES_TOTAL);
}
