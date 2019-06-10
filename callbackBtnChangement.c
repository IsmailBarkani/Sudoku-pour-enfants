
void fctChangementChoisit0(GtkWidget *ButtonExplore,gpointer data){

    _widgets *v_widgets = (_widgets*)data;
    if(v_widgets->imageChoisit){
        gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageChoisit),"./images/lorsDeJeu/boutonClickable/1.png");
        copieSudoko[v_widgets->indice/n][v_widgets->indice%n] = 1;
        v_widgets->imageChoisit=NULL;
    }

}

void fctChangementChoisit1(GtkWidget *ButtonExplore,gpointer data){

    _widgets *v_widgets = (_widgets*)data;
    if(v_widgets->imageChoisit){
        gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageChoisit),"./images/lorsDeJeu/boutonClickable/2.png");
        copieSudoko[v_widgets->indice/n][v_widgets->indice%n] = 2;
        v_widgets->imageChoisit=NULL;
    }

}

void fctChangementChoisit2(GtkWidget *ButtonExplore,gpointer data){

    _widgets *v_widgets = (_widgets*)data;
    if(v_widgets->imageChoisit){
        gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageChoisit),"./images/lorsDeJeu/boutonClickable/3.png");
        copieSudoko[v_widgets->indice/n][v_widgets->indice%n] = 3;
        v_widgets->imageChoisit=NULL;
    }

}

void fctChangementChoisit3(GtkWidget *ButtonExplore,gpointer data){

    _widgets *v_widgets = (_widgets*)data;
    if(v_widgets->imageChoisit){
        gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageChoisit),"./images/lorsDeJeu/boutonClickable/4.png");
        copieSudoko[v_widgets->indice/n][v_widgets->indice%n] = 4;
        v_widgets->imageChoisit=NULL;
    }

}

