#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Chevalet.h"
#include "Rail.h"
#include "vecteur.h"

typedef Vecteur motsUtiliser[TAILLE_RAIL];

/**
 * @brief Vérifie si le mot contenu dans le chevalet est présent dans le dictionnaire.
 * @param dico Fichier du dictionnaire ouvert en mode lecture.
 * @param chevalet Structure contenant le mot à vérifier.
 * @return 1 si le mot est trouvé dans le dictionnaire, 0 sinon.
 */
int verifierMot(FILE *dico, Chevalet* chevalet);

/**
 * @brief Vérifie si le fichier dictionnaire existe.
 *
 * Cette fonction vérifie si le fichier dictionnaire passé en paramètre peut être ouvert correctement.
 *
 * @param[in] dico Le pointeur vers le fichier dictionnaire à vérifier.
 * @return Retourne 1 si le fichier est valide, 0 sinon.
 */
void verifierDico(FILE *dico);

/**
 * @brief On regarde si le mot est deja utiliser ou non.
 * @return 1 si le mot est valide avec la possibilitée de poser le mot, 0 sinon.
*/
int verifierMotValide(char* utiliser, char* mot);


/**
 * @brief Ajoute un mot au vecteur des mots utilisés.
 *
 * Cette fonction ajoute un mot à la fin du vecteur `motsUtilises`, ce qui permet
 * de suivre les mots qui ont déjà été utilisés au cours de la partie.
 *
 * @param[out] motsUtilises Le vecteur qui contient les mots déjà utilisés.
 * @param[in] mot Le mot à ajouter au vecteur des mots utilisés.
 *
 */
void ajouterMotUtilise(Vecteur* motsUtilises, const char* mot);