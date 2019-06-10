

void fctTriCroissantScore();
void fctExporter();
void fctSauvgarder();
void fctCreerJoueur(const gchar *login,const gchar *mdp);
void fctImporter();



void fctTriCroissantScore(){
	int i;
	int j;
	_joueur v_tmpJoueur;
	for(i=0;i<nbjoueur-1;i++){
        for(j=i+1;j<nbjoueur;j++)
            if(v_joueurs[i].score < v_joueurs[j].score){
                v_tmpJoueur = v_joueurs[i];
                v_joueurs[i] = v_joueurs[j];
                v_joueurs[j]=v_tmpJoueur;
            }
        if(strcmp(v_joueurs[indiceJoueur].pseudo,v_joueurs[i].pseudo)==0) indiceJoueur=i;
	}
}

void fctExporter(){
	int i;
	FILE *fichier=fopen("ListeCompte.bin","wb");
	if(fichier){
			for(i=0;i<nbjoueur;i++){
				fwrite(v_joueurs+i,sizeof(_joueur),1,fichier);
			}
		fclose(fichier);
	}
}

void fctSauvgarder(){
    fctExporter();
    gtk_main_quit();


}

void fctCreerJoueur(const gchar *login,const gchar *mdp){
    if(nbjoueur<MAXJOUEURS){
        indiceJoueur=nbjoueur;
        strcpy(v_joueurs[nbjoueur].pseudo,login);
        strcpy(v_joueurs[nbjoueur].mdp,mdp);
        v_joueurs[nbjoueur].score=0;
        v_joueurs[nbjoueur].save=false;
        nbjoueur++;
    }
}

void fctImporter(){
	if(nbjoueur==0){
            FILE *fichier=fopen("ListeCompte.bin","rb");
            if(fichier){
                while(fread(v_joueurs+nbjoueur,sizeof(_joueur),1,fichier)){
                        nbjoueur++;
                    }
                fclose(fichier);
        }
	}

}


