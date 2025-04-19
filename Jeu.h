#pragma once

#include "chevalet.h"
#include "Rail.h"

/**
 * @brief Initialise une partie.
 * @param[out] La main du premier puis second joueur.
 * @param[out] Affichage du rail.
 */
void initPartie(Chevalet *joueurs1,Chevalet *joueurs2, Pioche *pioche, FILE *dictonnaire);

/**
 * @brief Tour du joueur.
 * @param[in] ordre Joueur 1 ou 2.
 * @param[in,out] chevalet Pointeur vers le chevalet (La main) du joueur.
 */
void tourJoueur(int ordre, Chevalet *chevalet);
