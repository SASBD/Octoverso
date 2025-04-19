#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Rail.h"
#include "vecteur.h"

int premierMot(const char* mot1, const char* mot2) {
    for (int i = 0; i < PREMIER_MOT; i++) {
        if (mot1[i] != mot2[i]) {
            return (mot1[i] < mot2[i]) ? 1 : 2;
        }
    }
    return 0;
}

int insererMot(char cote, const char* mot1, const char* mot2, Rail* rail) {
    // Détecter le mot à garder
    char motRail[MOT_MAX];

    strcpy(motRail, (mot1[0] == '(') ? detecterMot(mot1) : detecterMot(mot2));

    if (!motValide(motRail, *rail))
    {
        return 0;
    }


    if (cote == 'R') {
        // Recto : ajouter à droite
        Rail nouveau_rail;
        initVecteur(&nouveau_rail, taille(rail) + strlen(motRail));

        // Copier le contenu actuel du rail à gauche
        for (int i = 0; i < taille(rail); ++i) {
            ajouter(&nouveau_rail, obtenir(rail, i));
        }

        // Ajouter le mot à garder à droite
        ajouterMot(&nouveau_rail, motRail);

        // Mettre à jour le rail
        detruireVecteur(rail);
        *rail = nouveau_rail;
    }
    else if (cote == 'V') {
        // Verso : ajouter à droite dans l'ordre inversé
        Rail nouveau_rail;
        initVecteur(&nouveau_rail, taille(rail) + strlen(motRail));

        // Copier le contenu actuel du rail inversé (verso)
        for (int i = taille(rail) - 1; i >= 0; --i) {
            ajouter(&nouveau_rail, obtenir(rail, i));
        }

        // Ajouter le mot à garder à droite dans l'ordre inversé
        ajouterMot(&nouveau_rail, motRail);

        // Mettre à jour le rail
        detruireVecteur(rail);
        *rail = nouveau_rail;
    } else {
        return 0; // Côté invalide
    }

    return 1;
}

int motValide(char* mot, Rail rail) {
    size_t mot_len = strlen(mot);
    int trouve = 0;

    for (int i = 0; i <= TAILLE_RAIL - mot_len; i++) {
        trouve = 1;

        for (int j = 0; j < mot_len; j++) {
            if (mot[j] != obtenir(&rail, i + j)) {
                trouve = 0;
                break;
            }
        }

        if (trouve) {
            return 1;
        }
    }

    return 0;
}



int ajouterMot(Rail* rail, const char* mot) {
    for (size_t i = 0; i < strlen(mot); ++i) {
        if (!ajouter(rail, mot[i])) {
            return 0;
        }
    }
    return 1;
}


char* detecterMot(const char* mot1)
{
    char mot[MOT_MAX];
    for (int i = 1; i < strlen(mot1); i++) {
        mot[i] = mot1[i];
    }
}

Rail pivoterRail(const Rail* rail) {
    Rail rail_pivote;
    initVecteur(&rail_pivote, taille(rail));
    for (int i = taille(rail) - 1; i >= 0; --i) {
        ajouter(&rail_pivote, obtenir(rail, i));
    }
    return rail_pivote;
}


void afficherRail(const Rail* rail) {
    printf("Recto : ");
    for (int i = 0; i < taille(rail); ++i) {
        printf("%c", obtenir(rail, i));
    }
    printf("\n");

    printf("Verso : ");
    Rail rail_pivote = pivoterRail(rail);
    for (int i = 0; i < taille(&rail_pivote); ++i) {
        printf("%c", obtenir(&rail_pivote, i));
    }
    printf("\n");
    detruireVecteur(&rail_pivote);
}

