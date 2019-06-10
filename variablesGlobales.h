#ifndef VARIABLESGLOBALES_H_INCLUDED
#define VARIABLESGLOBALES_H_INCLUDED



#endif // VARIABLESGLOBALES_H_INCLUDED


int origine[n][n]={
	{4,2,3,1},
	{3,1,2,4},
	{2,4,1,3},
	{1,3,4,2}
};
int sudoko[n][n] = {
	{4,2,3,1},
	{3,1,2,4},
	{2,4,1,3},
	{1,3,4,2}
};

_joueur v_joueurs[MAXJOUEURS];
int copieSudoko[n][n];
int indiceJoueur;
int nbjoueur=0;
bool validation = false;
