#pragma once

/**
 * @file Pioche.h
 * @brief Déclarations des fonctions et structures liées à la gestion d'une pioche de lettres.
 *
 * Ce fichier contient les définitions nécessaires pour la gestion d'une pioche,
 * incluant l'initialisation, le mélange et le tirage de lettres.
 */

/**
 * @brief Taille maximale de la pioche (nombre total de lettres disponibles).
 */
enum { NB_LETTRES_TOTAL = 88 };

/**
 * @brief Représente une pioche contenant les lettres disponibles.
 *
 * La structure Pioche contient un tableau dynamique des lettres et garde une
 * trace du nombre de lettres restantes dans la pioche.
 */
typedef struct {
    Vecteur *lettres; ///< Tableau dynamique des lettres disponibles dans la pioche.
    int nb_restantes; ///< Nombre de lettres restantes dans la pioche.
} Pioche;

/**
 * @brief Initialise la pioche avec toutes les lettres disponibles.
 *
 * Cette fonction initialise la pioche avec les lettres disponibles et les place dans un tableau dynamique.
 * Elle alloue de la mémoire pour le tableau et ajoute chaque lettre de manière ordonnée.
 *
 * @param[in] pioche Pointeur vers la pioche à initialiser.
 * @return 1 si l'initialisation réussie, 0 sinon.
 *
 * @pre La pioche doit être allouée avant d'appeler cette fonction.
 */
int init_pioche(Pioche *pioche);

/**
 * @brief Mélange les lettres restantes dans la pioche.
 *
 * Cette fonction mélange aléatoirement les lettres restantes dans la pioche.
 * Elle utilise la méthode de mélange de type Fisher-Yates pour assurer une bonne
 * distribution des lettres.
 *
 * @param[in,out] pioche Pointeur vers la pioche à mélanger.
 * @return 1 si le mélange a été effectué avec succès, 0 si la pioche est vide ou invalide.
 *
 * @pre La pioche doit être initialisée avant d'appeler cette fonction.
 */
int melanger_pioche(Pioche *pioche);

/**
 * @brief Tire une lettre aléatoire de la pioche.
 *
 * Cette fonction tire une lettre aléatoire de la pioche et la retire de la liste des lettres disponibles.
 * Elle réduit le nombre de lettres restantes et retourne la lettre tirée.
 *
 * @param[in,out] pioche Pointeur vers la pioche à modifier.
 * @return La lettre tirée. Si la pioche est vide, retourne un caractère d'espace (' ').
 *
 * @pre La pioche doit être initialisée et contenir des lettres avant d'appeler cette fonction.
 * @post Le nombre de lettres restantes dans la pioche est décrémenté.
 */
char tirer_lettre(Pioche *pioche);

/**
 * @brief Ajoute une lettre à la pioche.
 *
 * Cette fonction permet d'ajouter une lettre à la pioche, augmentant ainsi le nombre de lettres restantes.
 *
 * @param[in,out] pioche Pointeur vers la pioche où ajouter la lettre.
 * @param[in] lettre La lettre à ajouter dans la pioche.
 *
 * @pre La pioche doit être correctement initialisée avec un tableau d'éléments.
 * @post Le nombre de lettres restantes dans la pioche est incrémenté.
 */
void ajouterLettrePioche(Pioche* pioche, char lettre);

/**
 * @brief Teste les fonctionnalités de la gestion d'une pioche de lettres.
 *
 * Les vérifications incluent :
 * - Initialisation correcte de la pioche avec le nombre total de lettres.
 * - Tirage d'une lettre et réduction correcte du nombre de lettres restantes.
 * - Mélange de la pioche sans modifier le nombre total de lettres.
 * - Vidage complet de la pioche.
 * - Réinitialisation correcte de la pioche après vidange.
 *
 * @pre Les fonctions de gestion de pioche (init_pioche, tirer_lettre, melanger_pioche) doivent être
 * implémentées et fonctionner selon leurs spécifications.
 *
 * @post Aucune modification de l'état global ou des données en dehors de la pioche testée.
 */
void testPioche();
