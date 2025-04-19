#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Chevalet.h"
#include "Pioche.h"

void initChevalet(Chevalet *chevalet, Pioche *pioche) {
    initVecteur(&chevalet->lettres, TAILLE_CHEVALET_MAX);
    chevalet->nb_lettres = 0;

    for (int i = 0; i < MAX_DISTRIBUTION_LETTRES; i++) {
        char lettre = tirer_lettre(pioche);
        ItemV lettre_item = { lettre };
        ajouter(&chevalet->lettres, lettre_item);
        chevalet->nb_lettres++;
    }
}

int verifierChevalet(Chevalet *chevalet, const char *mot) {
    int mot_len = strlen(mot);

    for (int i = 0; i < mot_len; i++) {
        int trouve = 0;

        for (int j = 0; j < chevalet->nb_lettres; j++) {
            if (chevalet->lettres.elements[j] == mot[i]) {
                trouve = 1;
                break;
            }
        }

        if (!trouve) {
            return 0;
        }
    }

    return 1;
}



int echangerlettre(Chevalet *chevalet, char lettre_a_remplacer, Pioche *pioche)
{
    int trouve = 0;
    int i = 0;

    while (i < chevalet->nb_lettres && !trouve)
    {
        if (obtenir(&chevalet->lettres, i) == lettre_a_remplacer)
        {
            trouve = 1;
        }
        i++;
    }

    if (!trouve)
    {
        return 0;
    }

    char nouvelle_lettre = tirer_lettre(pioche);

    ajouterLettrePioche(pioche, lettre_a_remplacer);

    modifier(&chevalet->lettres, i, nouvelle_lettre);

    return 1;
}



void poser_mot(const Chevalet chevalet, const char *mot)
{

}

void afficher_chevalet(const Chevalet *chevalet)
{
    printf("%d : ", chevalet->idJoueur);
    for (int i = 0; i < chevalet->nb_lettres; i++)
    {
        printf("%c", chevalet->lettres.elements[i]);
    }
    printf("\n");
}

void testChevalet(void)
{
    Pioche pioche;
    init_pioche(&pioche);

    Chevalet chevalet;
    initChevalet(&chevalet, &pioche);

    assert(chevalet.nb_lettres == MAX_DISTRIBUTION_LETTRES);
    for (int i = 0; i < chevalet.nb_lettres; i++) {
        assert(chevalet.lettres.elements[i] >= 'A' && chevalet.lettres.elements[i] <= 'Z');
    }

    assert(verifierChevalet(&chevalet, "EXAMPLE") == 1);
    assert(verifierChevalet(&chevalet, "INVALID") == 0);

    char lettre_a_remplacer = chevalet.lettres.elements[0];

    int result = echangerlettre(&chevalet, lettre_a_remplacer, &pioche);
    assert(result == 1);

    assert(chevalet.lettres.elements[0] != lettre_a_remplacer);
    assert(chevalet.nb_lettres == MAX_DISTRIBUTION_LETTRES);
    assert(pioche.nb_restantes == NB_LETTRES_TOTAL);

    ajouterLettrePioche(&pioche, 'X');

    assert(pioche.nb_restantes == NB_LETTRES_TOTAL + 1);
    assert(pioche.lettres->elements[pioche.nb_restantes - 1] == 'X');
}