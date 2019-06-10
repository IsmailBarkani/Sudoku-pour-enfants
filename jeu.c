
void fctSolution(GtkWidget *ButtonExplore, gpointer data);
void fctSauvgarderGrille(GtkWidget *ButtonExplore, gpointer data);
void fctAvantJeu(GtkWidget *ButtonExplore, gpointer data);
void fctRenitialiser(GtkWidget *ButtonExplore,gpointer data);
void fctValider(GtkWidget *ButtonExplore,gpointer data);
void fctInitialiserWidgetParNull(_widgets *v_widgets);
void fctInsertionWidgetsControlle(_widgets *v_widgets);
void fctInsertionWidgetsChangement(_widgets *v_widgets);
void fctCreationGrilleGtk(_widgets *v_widgets);
void fctLorsDeJeu(GtkWidget *ButtonExplore,gpointer data);


void fctSolution(GtkWidget *ButtonExplore, gpointer data){
    _widgets *v_widgets = (_widgets*)data;
    GtkWidget *message;
    message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                        ,GTK_MESSAGE_INFO,GTK_BUTTONS_OK
                                        ,"Il faut choisir une case vide\nensuite choisir une bouton en dessous");
    gtk_dialog_run(GTK_DIALOG(message));
    gtk_widget_destroy(message);

}

void fctSauvgarderGrille(GtkWidget *ButtonExplore, gpointer data){
    v_joueurs[indiceJoueur].save = true;
    fctCopieSudoko(v_joueurs[indiceJoueur].saveSudoko,copieSudoko);
}

void fctRenitialiser(GtkWidget *ButtonExplore,gpointer data){
    int i,j;
    _widgets *v_widgets = (_widgets*)data;

    fctCopieSudoko(copieSudoko,sudoko);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            switch(copieSudoko[i][j]){
                case 0  :
                            gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageGrille[i*n+j]),"./images/lorsDeJeu/00.png");
                    break;

                case 1  :
                            gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageGrille[i*n+j]),"./images/lorsDeJeu/boutonClickable/1.png");
                    break;

                case 2  :
                            gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageGrille[i*n+j]),"./images/lorsDeJeu/boutonClickable/2.png");

                    break;

                case 3  :
                            gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageGrille[i*n+j]),"./images/lorsDeJeu/boutonClickable/3.png");
                    break;

                case 4  :
                            gtk_image_set_from_file(GTK_IMAGE(v_widgets->imageGrille[i*n+j]),"./images/lorsDeJeu/boutonClickable/4.png");
                    break;

           }
        }
    }

}

void fctValider(GtkWidget *ButtonExplore,gpointer data){
    _widgets *v_widgets = (_widgets*)data;
    GtkWidget *message;
    if(fctSudokoPlein()) {
        if(fctSudokoValide()){
            v_joueurs[indiceJoueur].score++;
            message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                            ,GTK_MESSAGE_INFO,GTK_BUTTONS_OK
                                            ,"Bravo :) vous avez reussit\n votre nouvelle score est\n%d"
                                            ,v_joueurs[indiceJoueur].score);
            gtk_dialog_run(GTK_DIALOG(message));
            gtk_widget_destroy(message);
            fctLorsDeJeu(ButtonExplore,data);
        }
        else {
            message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                            ,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Desole le sudoku n'est pas valide\nMerci de corriger");
            gtk_dialog_run(GTK_DIALOG(message));
            gtk_widget_destroy(message);
        }
    }
    else {
        message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                            ,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Il faut remplir tous les cases");
        gtk_dialog_run(GTK_DIALOG(message));
        gtk_widget_destroy(message);
    }
}

void fctInitialiserWidgetParNull(_widgets *v_widgets){
    int i;
    v_widgets->imageChoisit = NULL;
    for(i=0;i<16;i++){
        v_widgets->btnGrille[i] = gtk_button_new();
    }
    for(i=0;i<16;i++){
        v_widgets->imageGrille[i] = NULL;
    }

}

void fctInsertionWidgetsControlle(_widgets *v_widgets){
    v_widgets->imageControlle[5] = gtk_image_new_from_file("./images/lorsDeJeu/background.png");
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->imageControlle[5],0,0);

    v_widgets->btnControlle[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnControlle[0]),GTK_RELIEF_NONE);
    v_widgets->imageControlle[0] = gtk_image_new_from_file("./images/lorsDeJeu/renitialiser.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnControlle[0]),v_widgets->imageControlle[0]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnControlle[0],138,382);
    gtk_widget_set_size_request(v_widgets->btnControlle[0], 50, 50);

    v_widgets->btnControlle[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnControlle[1]),GTK_RELIEF_NONE);
    v_widgets->imageControlle[1] = gtk_image_new_from_file("./images/lorsDeJeu/help.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnControlle[1]),v_widgets->imageControlle[1]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnControlle[1],193,381);
    gtk_widget_set_size_request(v_widgets->btnControlle[1], 50, 50);

    v_widgets->btnControlle[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnControlle[2]),GTK_RELIEF_NONE);
    v_widgets->imageControlle[2] = gtk_image_new_from_file("./images/lorsDeJeu/valider.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnControlle[2]),v_widgets->imageControlle[2]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnControlle[2],248,380);
    gtk_widget_set_size_request(v_widgets->btnControlle[2], 50, 50);

    v_widgets->btnControlle[3] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnControlle[3]),GTK_RELIEF_NONE);
    v_widgets->imageControlle[3] = gtk_image_new_from_file("./images/lorsDeJeu/retourner.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnControlle[3]),v_widgets->imageControlle[3]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnControlle[3],9,517);
    gtk_widget_set_size_request(v_widgets->btnControlle[3], 59, 59);

    v_widgets->btnControlle[4] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnControlle[4]),GTK_RELIEF_NONE);
    v_widgets->imageControlle[4] = gtk_image_new_from_file("./images/lorsDeJeu/save.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnControlle[4]),v_widgets->imageControlle[4]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnControlle[4],75,517);
    gtk_widget_set_size_request(v_widgets->btnControlle[4], 59, 59);
}

void fctInsertionWidgetsChangement(_widgets *v_widgets){

    v_widgets->btnChangement[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnChangement[0]),GTK_RELIEF_NONE);
    v_widgets->imageChangement[0] = gtk_image_new_from_file("./images/lorsDeJeu/boutonClickable/1.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnChangement[0]),v_widgets->imageChangement[0]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnChangement[0],147,494);
    gtk_widget_set_size_request(v_widgets->btnChangement[0], 38, 32);

    v_widgets->btnChangement[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnChangement[1]),GTK_RELIEF_NONE);
    v_widgets->imageChangement[1] = gtk_image_new_from_file("./images/lorsDeJeu/boutonClickable/2.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnChangement[1]),v_widgets->imageChangement[1]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnChangement[1],180,494);
    gtk_widget_set_size_request(v_widgets->btnChangement[1], 38, 32);

    v_widgets->btnChangement[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnChangement[2]),GTK_RELIEF_NONE);
    v_widgets->imageChangement[2] = gtk_image_new_from_file("./images/lorsDeJeu/boutonClickable/3.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnChangement[2]),v_widgets->imageChangement[2]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnChangement[2],218,494);
    gtk_widget_set_size_request(v_widgets->btnChangement[2], 38, 32);

    v_widgets->btnChangement[3] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(v_widgets->btnChangement[3]),GTK_RELIEF_NONE);
    v_widgets->imageChangement[3] = gtk_image_new_from_file("./images/lorsDeJeu/boutonClickable/4.png");
    gtk_container_add(GTK_CONTAINER(v_widgets->btnChangement[3]),v_widgets->imageChangement[3]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnChangement[3],256,494);
    gtk_widget_set_size_request(v_widgets->btnChangement[3], 38, 32);

}

void fctCreationGrilleGtk(_widgets *v_widgets){
    int i,j;
    int di,dj;
    if(v_joueurs[indiceJoueur].save){
        v_joueurs[indiceJoueur].save=false;
        fctCopieSudoko(copieSudoko,v_joueurs[indiceJoueur].saveSudoko);
    }
    else{
        fctCreationGrilleAlgorithme();
    }

    for(i=0;i<n;i++){
        di=0;
        if(i>1) di=6;
        for(j=0;j<n;j++){
            dj=0;
            if(j>1) dj=14;
            switch(copieSudoko[i][j]){
                case 0  :
                            //v_widgets->btnGrille[i*n+j] = gtk_button_new();
                            gtk_button_set_relief(GTK_BUTTON(v_widgets->btnGrille[i*n+j]),GTK_RELIEF_NONE);
                            v_widgets->imageGrille[i*n+j] = gtk_image_new_from_file("./images/lorsDeJeu/00.png");
                            gtk_container_add(GTK_CONTAINER(v_widgets->btnGrille[i*n+j]),v_widgets->imageGrille[i*n+j]);
                            gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->btnGrille[i*n+j],(130+42*j)+dj,(209+39*i)+di);
                            gtk_widget_set_size_request(v_widgets->btnGrille[i*n+j], 38, 38);
                    break;

                case 1  :
                            v_widgets->imageGrille[i*n+j] = gtk_image_new_from_file("./images/lorsDeJeu/boutonClickable/1.png");
                            gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->imageGrille[i*n+j],(130+42*j)+dj,(209+39*i)+di);
                            gtk_widget_set_size_request(v_widgets->imageGrille[i*n+j], 38, 38);
                    break;

                case 2  :
                            v_widgets->imageGrille[i*n+j] = gtk_image_new_from_file("./images/lorsDeJeu/boutonClickable/2.png");
                            gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->imageGrille[i*n+j],(130+42*j)+dj,(209+39*i)+di);
                            gtk_widget_set_size_request(v_widgets->imageGrille[i*n+j], 38, 38);

                    break;

                case 3  :
                            v_widgets->imageGrille[i*n+j] = gtk_image_new_from_file("./images/lorsDeJeu/boutonClickable/3.png");
                            gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->imageGrille[i*n+j],(130+42*j)+dj,(209+39*i)+di);
                            gtk_widget_set_size_request(v_widgets->imageGrille[i*n+j], 38, 38);
                    break;

                case 4  :
                            v_widgets->imageGrille[i*n+j] = gtk_image_new_from_file("./images/lorsDeJeu/boutonClickable/4.png");
                            gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->imageGrille[i*n+j],(130+42*j)+dj,(209+39*i)+di);
                            gtk_widget_set_size_request(v_widgets->imageGrille[i*n+j], 38, 38);
                    break;

           }
        }
    }
}

void fctLorsDeJeu(GtkWidget *ButtonExplore,gpointer data){
    _widgets *v_widgets = (_widgets*)data;
    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(v_widgets->window),v_widgets->layout);
    v_widgets->layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(v_widgets->window),v_widgets->layout);

    //#############################################################

    fctInitialiserWidgetParNull(v_widgets);
    fctInsertionWidgetsControlle(v_widgets);
    fctInsertionWidgetsChangement(v_widgets);
    fctCreationGrilleGtk(v_widgets);

    // callback des cases choisits
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[0]), "clicked",G_CALLBACK(fctCaseChoisit0), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[1]), "clicked",G_CALLBACK(fctCaseChoisit1), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[2]), "clicked",G_CALLBACK(fctCaseChoisit2), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[3]), "clicked",G_CALLBACK(fctCaseChoisit3), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[4]), "clicked",G_CALLBACK(fctCaseChoisit4), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[5]), "clicked",G_CALLBACK(fctCaseChoisit5), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[6]), "clicked",G_CALLBACK(fctCaseChoisit6), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[7]), "clicked",G_CALLBACK(fctCaseChoisit7), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[8]), "clicked",G_CALLBACK(fctCaseChoisit8), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[9]), "clicked",G_CALLBACK(fctCaseChoisit9), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[10]), "clicked",G_CALLBACK(fctCaseChoisit10), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[11]), "clicked",G_CALLBACK(fctCaseChoisit11), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[12]), "clicked",G_CALLBACK(fctCaseChoisit12), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[13]), "clicked",G_CALLBACK(fctCaseChoisit13), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[14]), "clicked",G_CALLBACK(fctCaseChoisit14), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnGrille[15]), "clicked",G_CALLBACK(fctCaseChoisit15), v_widgets);

    // --- callback des boutons de changement ---
    g_signal_connect (G_OBJECT(v_widgets->btnChangement[0]), "clicked",G_CALLBACK(fctChangementChoisit0), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnChangement[1]), "clicked",G_CALLBACK(fctChangementChoisit1), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnChangement[2]), "clicked",G_CALLBACK(fctChangementChoisit2), v_widgets);
    g_signal_connect (G_OBJECT(v_widgets->btnChangement[3]), "clicked",G_CALLBACK(fctChangementChoisit3), v_widgets);

    // ---- boutons de controlles
    g_signal_connect(G_OBJECT(v_widgets->btnControlle[0]), "clicked",G_CALLBACK(fctRenitialiser), v_widgets);
    g_signal_connect(G_OBJECT(v_widgets->btnControlle[1]), "clicked",G_CALLBACK(fctSolution), v_widgets);
    g_signal_connect(G_OBJECT(v_widgets->btnControlle[2]), "clicked",G_CALLBACK(fctValider), v_widgets);
    g_signal_connect(G_OBJECT(v_widgets->btnControlle[3]), "clicked",G_CALLBACK(fctAvantJeu), v_widgets);
    g_signal_connect(G_OBJECT(v_widgets->btnControlle[4]), "clicked",G_CALLBACK(fctSauvgarderGrille), v_widgets);




    gtk_widget_show_all(v_widgets->window);
}
