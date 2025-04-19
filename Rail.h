#pragma once

#include "vecteur.h"

/**
 * @brief Taille maximale d'un rail, du premier mot et de la longueur max d'un mot
 */
enum { TAILLE_RAIL = 9, PREMIER_MOT = 5, MOT_MAX = 6 };

/**
 * @brief Alias de type, un rail devient un vecteur de caractères.
 */
typedef Vecteur Rail;  // <=== C'est ici que vous mettez l'alias

/**
 * @brief Fonction pour détecter un mot (en tenant compte des parenthèses).
 */
char* detecterMot(const char* mot1);

/**
 * @brief Compare deux mots et retourne le mot le plus petit.
 * @param[in] mot1 Le premier mot à comparer.
 * @param[in] mot2 Le deuxième mot à comparer.
 * @return 1 si le premier mot est plus petit, 2 si le deuxième mot est plus petit, 0 si les mots sont égaux.
 */
int premierMot(const char *mot1, const char *mot2);

/**
 * @brief Ajoute un mot au rail.
 * @param[in,out] rail Le rail auquel ajouter le mot.
 * @param[in] mot Le mot à ajouter.
 * @return 1 si l'ajout a réussi, 0 sinon.
 */
int ajouterMot(Rail* rail, const char* mot);

/**
 * @brief Recherche un mot dans le rail.
 *
 * Cette fonction parcourt le rail et vérifie si le mot spécifié est présent dans une des
 * positions possibles du rail.
 *
 * @param[in] mot Le mot à rechercher dans le rail.
 * @param[in] rail Le rail dans lequel rechercher le mot.
 *
 * @return 1 si le mot est trouvé, 0 sinon.
 */
int motValide(char* mot, Rail rail);


/**
 * @brief Initialise un rail avec deux mots donnés.
 * @param[in] mot1 Le premier mot.
 * @param[in] mot2 Le deuxième mot.
 * @return Un rail initialisé.
 */
Rail initRail(const char* mot1, const char* mot2);

/**
 * @brief Insère un mot dans un rail existant.
 * @param[in] cote 'R' pour recto, 'V' pour verso.
 * @param[in] mot Le mot à insérer.
 * @param[in,out] rail Le rail à mettre à jour.
 * @return 1 si le mot a été inséré, 0 sinon.
 */
int insererMot(char cote, const char* mot, Rail* rail);

/**
 * @brief Met à jour le rail avec une nouvelle configuration.
 * @param[in] cote 'R' pour recto, 'V' pour verso.
 * @param[in] nouveau_rail Chaîne de caractères représentant le nouveau rail.
 */
void mettre_a_jour_rail(char cote, const char *nouveau_rail);

/**
 * @brief Pivote le rail (inverse recto et verso).
 * @param[in] rail Le rail à pivoter.
 * @return Un rail pivoté.
 */
Rail pivoter_rail(const Rail *rail);

/**
 * @brief Affiche le rail recto et verso.
 * @param[in] rail Le rail à afficher.
 */
void afficher_rails(Rail *rail);
