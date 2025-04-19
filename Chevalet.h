#pragma once
#include "pioche.h"
#include "vecteur.h"
/**
 * @brief "TAILLE_CHEVALET_MAX" Taille maximale d'un chevalet (8 lettres de base + 8 supplémentaires).
 * @brief "MAX_DISTRIBUTION_LETTRES" Nombre maximal de lettres distribuées à un joueur.
 */
enum { TAILLE_CHEVALET_MAX = 16, MAX_DISTRIBUTION_LETTRES = 12 };

/**
 * @brief Représente un chevalet (une main) contenant des lettres.
 */
typedef struct {
    Vecteur lettres; ///< Lettres actuelles sur le chevalet.
    int nb_lettres;                    ///<Nombre actuel de lettres sur le chevalet.
    int idJoueur;                      ///< Identifiant du joueur possédant le chevalet.
} Chevalet;

/**
 * @brief Initialise un chevalet avec une liste de lettres donnée.
* @param[out] chevalet Pointeur vers le chevalet à initialiser.
 * @param[in] pioche La ou ce trouve les lettres a mettre dans la main des joueurs.
 */
void initchevalet(Chevalet *chevalet, Pioche *pioche);

/**
 * @brief Vérifie si un mot peut être formé à partir des lettres présentes sur le chevalet.
 *
 * Cette fonction vérifie si toutes les lettres du mot donné sont présentes sur le chevalet du joueur.
 * Elle parcourt chaque lettre du mot et recherche si elle existe dans les lettres du chevalet.
 *
 * @param[in] chevalet Pointeur vers le chevalet contenant les lettres du joueur.
 * @param[in] mot Chaîne de caractères représentant le mot à vérifier.
 * @return 1 si toutes les lettres du mot sont présentes sur le chevalet, 0 sinon.
 */
int verifierChevalet(Chevalet *chevalet, const char *mot);

/**
 * @brief Échange une lettre du chevalet avec une lettre tirée de la pioche.
 *
 * Cette fonction permet à un joueur d'échanger une lettre de son chevalet contre
 * une nouvelle lettre tirée de la pioche. Si la lettre à remplacer est présente
 * dans le chevalet, elle sera retirée et remplacée par une lettre tirée au hasard
 * de la pioche.
 *
 * @param[in,out] chevalet Pointeur vers le chevalet du joueur. Le chevalet sera modifié
 *                         avec la nouvelle lettre après l'échange.
 * @param[in] lettre_a_remplacer La lettre dans le chevalet que l'on souhaite remplacer.
 * @param[in,out] pioche Pointeur vers la pioche qui sera modifiée en conséquence
 *                       (la lettre échangée est remise dans la pioche).
 * @return 1 si l'échange a eu lieu avec succès, 0 si la lettre n'a pas été trouvée
 *         dans le chevalet.
 */
int echangerlettre(Chevalet *chevalet, char lettre_a_remplacer, Pioche *pioche);

/**
 * @brief Pose un mot en retirant les lettres correspondantes du chevalet.
* @param[in,out] chevalet Pointeur vers le chevalet à modifier.
 * @param[in] mot Chaîne de caractères représentant le mot à poser.
 */
void poser_mot(Chevalet *chevalet, const char *mot);

/**
 * @brief Affiche les lettres du chevalet.
 * @param[in] chevalet Pointeur vers le chevalet à afficher.
 */
void afficher_chevalet(const Chevalet *chevalet);
