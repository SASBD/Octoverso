#include <stdio.h>
#include <time.h>

#include "Jeu.h"
#include "Pioche.h"
#include "Dico.h"

int main()
{
    srand(time(NULL));
    char mot1[PREMIER_MOT];
    char mot2[PREMIER_MOT];
    scanf("%s", mot1);
    scanf("%s", mot2);

    FILE* dictonnaire;

    //Init La pioche
    Pioche pioche;
    init_pioche(&pioche);
    //Init rail
    Rail rail;
    //Init Les joueurs
    Chevalet joueur1, joueur2;
    initPartie(&joueur1, &joueur2, &pioche, &rail, dictonnaire);



    /*initchevalet(&joueur1, &pioche);
        initchevalet(&joueur2, &pioche);
        //On affiche les lettres des joueurs respectivement
        afficher_chevalet(&joueur1);
        afficher_chevalet(&joueur2);
    */

    /* do
    {
        //On prend les mots des joueurs
        printf(">");
        char motDepart;
        scanf("%s", &motDepart);
        poser_mot(&joueur1, &motDepart);

        printf(">");
        char motDepart2;
        scanf("%s", &motDepart2);
        poser_mot(&joueur2, &motDepart2);

        //On initialise le rail en fonction des mots posé par les joueur afin d'en decider de l'ordre.
        initRail(&rail, mot1, mot2);
        //On affiche la partie
        afficher_chevalet(&joueur1);
        afficher_chevalet(&joueur2);
        afficher_rails(&rail);
        pivoter_rail(&rail);
        afficher_rails(&rail);
    }while (joueur1.nb_lettres != 0 || joueur2.nb_lettres != 0);
    / Boucle while tant que aucun joueur gagnant ou impossibiliter de jouer tour 1
    */
}
