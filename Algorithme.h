#ifndef ALGORITHME_H_INCLUDED
#define ALGORITHME_H_INCLUDED
#include "Algorithme.c"



#endif // ALGORITHME_H_INCLUDED

void fctviderDesCases();
void fctCopieSudoko(int copie[n][n],int origine[n][n]);
void fctCreationGrilleAlgorithme();
void fctColor(int couleurDuTexte,int couleurDeFond);
void fctAfficher(int sudoko[n][n]);
bool fctVerification(int ligne, int colonne, int val);
bool fctSudokoValide();
bool fctSudokoPlein();

