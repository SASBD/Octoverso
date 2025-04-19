#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Chevalet.h"
#include "Rail.h"

int verifierMot(FILE *dico, Chevalet* chevalet) {
 char mot[TAILLE_RAIL];
 int motTrouve = 0;

 while (fgets(mot, sizeof(mot), dico)) {
  mot[strcspn(mot, "\n")] = '\0';

  if (strlen(mot) <= 8 && strcmp(mot, chevalet->lettres) == 0) {
   motTrouve = 1;
   break;
  }
 }

 return motTrouve;
}

int verifierDico(FILE *dico)
{
 if (dico == NULL)
  return 0;
}

int verifierMotValide(Vecteur* motsUtilises, const char* mot) {
 for (int i = 0; i < taille(motsUtilises); i++) {
  if (strcmp(obtenir(motsUtilises, i), mot) == 0) {
   return 0;
  }
 }
 return 1;
}

void ajouterMotUtilise(Vecteur* motsUtilises, const char* mot)
{
   ajouter(motsUtilises, mot);
}