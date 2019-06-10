


void fctViderDesCases(int sudoko[n][n]){
	int position;
	int nb;
	int i;

	srand(time(0));
	nb = rand()%(MAXCASE+1);
	do{
		if(nb<MINCASE) nb++;
	}while(nb<MINCASE);
	for(i=0;i<nb;i++){
		position = rand()%(n*n);
		while(sudoko[position/n][position%n] == 0){
			if(position==(n*n)) position=-1;
			position++;
			position = position%(n*n);
		}
		sudoko[position/n][position%n] = 0;
	}

}

void fctCopieSudoko(int copie[n][n],int origine[n][n]){
	int i;
	int j;
	for (i = 0; i < n; ++i)
		for(j=0;j<n;j++)
			copie[i][j] = origine[i][j];
}

void fctCreationGrilleAlgorithme(){
    fctCopieSudoko(sudoko,origine);
	fctViderDesCases(sudoko);
	fctCopieSudoko(copieSudoko,sudoko);
}

void fctColor(int couleurDuTexte,int couleurDeFond) /*fonction d'affichage de couleurs*/{
	HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void fctAfficher(int sudoko[n][n]){
	int i=0;
	int j;
	printf("\t ********* SUDOKO *********\n");
	fctColor(12,0);
	printf("\t\t |");
	for(j=0;j<n;j++)
		printf(((j+1)%2) ? "%d " : "%d|",j+1);
	fctColor(10,0);
	printf("\n\t\t ---------\n");
	for(i=0;i<n;i++){
		fctColor(12,0);
		printf("\t\t%d",i+1);
		fctColor(10,0);
		printf("|");
		for(j=0;j<n;j++)
			printf(((j+1)%2) ? "%d " : "%d|",sudoko[i][j]);
		if(i==1) printf("\n\t\t ---------");
		printf("\n");
	}
	printf("\t\t ---------\n");

}

// si le trouve la repetition il va retourner false
bool fctVerification(int ligne, int colonne, int val){
	int i=0;
	int j=0;
	int ni;
	int nj;	int cpt=0;

/* Verification de la ligne */
    cpt=0;
	for(j=0; j<n; j++)
		if(copieSudoko[ligne][j] == val){
			cpt++;
			if(cpt == 2) return false;
		}

/* verifcation de la colonnes */
    cpt=0;
	for(i=0; i<n; i++)
		if(copieSudoko[i][colonne] == val){
			cpt++;
			if(cpt == 2) return false;
		}

/* verification de la region */
    cpt=0;
	i = ligne-(ligne%(n/2));
	ni = i+(n/2);
	for(; i < ni; i++){
		j = colonne-(colonne%(n/2));
		nj = j+(n/2);
		for(; j < nj; j++)
			if(copieSudoko[i][j] == val){
				cpt++;
				if(cpt == 2) return false;
		}
	}
	return true;

}

bool fctSudokoValide(){
	int i;
	int j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(!fctVerification(i,j,copieSudoko[i][j]))
				return false;

	return true;
}

bool fctSudokoPlein(){
	int i,j;
	for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(copieSudoko[i][j]==0)
                return false;
	}
	return true;
}

