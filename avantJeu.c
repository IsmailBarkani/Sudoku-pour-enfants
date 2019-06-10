


void fctTop10(GtkWidget *ButtonExplore, gpointer data);
void fctSeConnecter(GtkWidget *ButtonExplore, gpointer data);
void fctPrincipale(_widgets *v_widgets);
void fctPrincipale1(GtkWidget *ButtonExplore, gpointer data);
void fctVerifierSeConnecter(GtkWidget *ButtonExplore, gpointer data);
void fctAvantJeu(GtkWidget *ButtonExplore, gpointer data);
void fctverifierInscrire(GtkWidget *ButtonExplore, gpointer data);
void fctIscrire(GtkWidget *ButtonExplore, gpointer data);



void fctTop10(GtkWidget *ButtonExplore, gpointer data){
    _widgets *v_widgets=(_widgets*)data;
    GtkWidget   *imageTop10[2];
    GtkWidget   *btnTop10[1];
    GtkWidget   *label[10];
    int vide;
    char ch[100];
    char scoreToString[150];
    int teen=5;
    int i;
    int j;

    fctTriCroissantScore();
    if(nbjoueur<teen ) teen = nbjoueur;

    for(i=0;i<teen;i++){
        vide=40;
        strcpy(ch,v_joueurs[i].pseudo);
        vide = vide - strlen(ch);
        for(j=0;j<vide;j++) strcat(ch,"-");
        sprintf(scoreToString,"%s%d",ch,v_joueurs[i].score);
        label[i] = gtk_label_new(scoreToString);
    }


    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(v_widgets->window),v_widgets->layout);
    v_widgets->layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(v_widgets->window),v_widgets->layout);

    //#############################################################

    // creation de background ::
    imageTop10[1] = gtk_image_new_from_file("./images/top10/background.png");
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),imageTop10[1],0,0);


    // creation des lebel ::
    for(i=0;i<teen;i++){
        gtk_layout_put(GTK_LAYOUT(v_widgets->layout),label[i],110,215+(i*26));
    }

    // creation d'autre widget et les boutons ::
    btnTop10[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnTop10[0]),GTK_RELIEF_NONE);
    imageTop10[0] = gtk_image_new_from_file("./images/top10/menu.png");
    gtk_container_add(GTK_CONTAINER(btnTop10[0]),imageTop10[0]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),btnTop10[0],189,369);
    gtk_widget_set_size_request(btnTop10[0], 70, 70);

    g_signal_connect(G_OBJECT(btnTop10[0]), "clicked", G_CALLBACK(fctAvantJeu), v_widgets);

    gtk_widget_show_all(v_widgets->window);
}

void fctverifierInscrire(GtkWidget *ButtonExplore, gpointer data){
    _widgets *v_widgets=(_widgets*)data;
    GtkWidget *message;
    const gchar *login = gtk_entry_get_text(GTK_ENTRY(v_widgets->zoneTexte[0]));
    const gchar *mdp = gtk_entry_get_text(GTK_ENTRY(v_widgets->zoneTexte[1]));
    const gchar *confMdp = gtk_entry_get_text(GTK_ENTRY(v_widgets->zoneTexte[2]));
    int i=0;

    if(strcmp(login,"")!=0 && strcmp(mdp,"")!=0 && strcmp(confMdp,"")!=0){
        if(strcmp(mdp,confMdp)==0){
            i=0;
            while(i<nbjoueur && strcmp(v_joueurs[i].pseudo,login)!=0) i++;
            if(i<nbjoueur) {
                message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                            ,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Se compte exsite deja");
                gtk_dialog_run(GTK_DIALOG(message));
                gtk_widget_destroy(message);
            }
            else{
                fctCreerJoueur(login,mdp);
                fctAvantJeu(ButtonExplore,data);

            }
        }
        else{
            message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                            ,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Confirmation de mot de passe\n est incorrecte");
            gtk_dialog_run(GTK_DIALOG(message));
            gtk_widget_destroy(message);
        }
    }
    else{
        message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                            ,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Il faut remplir tous les champs");
        gtk_dialog_run(GTK_DIALOG(message));
        gtk_widget_destroy(message);
    }





}

void fctIscrire(GtkWidget *ButtonExplore, gpointer data){
    _widgets *v_widgets = (_widgets*)data;
    GtkWidget   *imageInscrire[3];
    GtkWidget   *btnIscrire[2];
    int i;

   // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(v_widgets->window),v_widgets->layout);
    v_widgets->layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(v_widgets->window),v_widgets->layout);

    //#############################################################

    // creation de Widgets:: //
    // creation de background ::
    imageInscrire[2] = gtk_image_new_from_file("./images/inscrire/background.png");
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),imageInscrire[2],0,0);

    // creation des zoneDeTexte ::
    for(i=0;i<3;i++)
        v_widgets->zoneTexte[i] = gtk_entry_new();

    gtk_entry_set_visibility(GTK_ENTRY(v_widgets->zoneTexte[1]), FALSE);
    gtk_entry_set_visibility(GTK_ENTRY(v_widgets->zoneTexte[2]), FALSE);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->zoneTexte[0],105,221);
    gtk_widget_set_size_request(v_widgets->zoneTexte[0], 230, 28);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->zoneTexte[1],105,284);
    gtk_widget_set_size_request(v_widgets->zoneTexte[1], 230, 28);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->zoneTexte[2],105,351);
    gtk_widget_set_size_request(v_widgets->zoneTexte[2], 230, 28 );

    // creation des bouton retour/seConnecter
    btnIscrire[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnIscrire[0]),GTK_RELIEF_NONE);
    imageInscrire[0] = gtk_image_new_from_file("./images/inscrire/valider.png");
    gtk_container_add(GTK_CONTAINER(btnIscrire[0]),imageInscrire[0]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),btnIscrire[0],193,385);
    gtk_widget_set_size_request(btnIscrire[0], 62 ,62);

    btnIscrire[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnIscrire[1]),GTK_RELIEF_NONE);
    imageInscrire[1] = gtk_image_new_from_file("./images/inscrire/retourner.png");
    gtk_container_add(GTK_CONTAINER(btnIscrire[1]),imageInscrire[1]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),btnIscrire[1],19,488);
    gtk_widget_set_size_request(btnIscrire[1], 60, 60);

    //###########################################################

    g_signal_connect(G_OBJECT(btnIscrire[0]), "clicked", G_CALLBACK(fctverifierInscrire), v_widgets);
    g_signal_connect(G_OBJECT(btnIscrire[1]), "clicked", G_CALLBACK(fctPrincipale1), v_widgets);

    gtk_widget_show_all(v_widgets->window);
}

void fctAvantJeu(GtkWidget *ButtonExplore, gpointer data){
    _widgets *v_widgets = (_widgets*)data;
    GtkWidget   *imageAvantDeJouer[4];
    GtkWidget   *btnAvantDeJouer[3];

    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(v_widgets->window),v_widgets->layout);
    v_widgets->layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(v_widgets->window),v_widgets->layout);

    //#############################################################

    // creation de background ::
    imageAvantDeJouer[3] = gtk_image_new_from_file("./images/avantDeJouer/background.png");
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),imageAvantDeJouer[3],0,0);

    // creation d'autre widget les boutons ::
    btnAvantDeJouer[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnAvantDeJouer[0]),GTK_RELIEF_NONE);
    imageAvantDeJouer[0] = gtk_image_new_from_file("./images/avantDeJouer/commencerJeu.png");
    gtk_container_add(GTK_CONTAINER(btnAvantDeJouer[0]),imageAvantDeJouer[0]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),btnAvantDeJouer[0],101,151);
    gtk_widget_set_size_request(btnAvantDeJouer[0], 232 ,73);

    btnAvantDeJouer[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnAvantDeJouer[1]),GTK_RELIEF_NONE);
    imageAvantDeJouer[1] = gtk_image_new_from_file("./images/avantDeJouer/top10.png");
    gtk_container_add(GTK_CONTAINER(btnAvantDeJouer[1]),imageAvantDeJouer[1]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),btnAvantDeJouer[1],101,224);
    gtk_widget_set_size_request(btnAvantDeJouer[1], 232, 73);

    btnAvantDeJouer[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnAvantDeJouer[2]),GTK_RELIEF_NONE);
    imageAvantDeJouer[2] = gtk_image_new_from_file("./images/avantDeJouer/deconnexion.png");
    gtk_container_add(GTK_CONTAINER(btnAvantDeJouer[2]),imageAvantDeJouer[2]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),btnAvantDeJouer[2],101,297);
    gtk_widget_set_size_request(btnAvantDeJouer[2], 232, 73);


    g_signal_connect(G_OBJECT(btnAvantDeJouer[0]), "clicked", G_CALLBACK(fctLorsDeJeu), v_widgets);
    g_signal_connect(G_OBJECT(btnAvantDeJouer[1]), "clicked", G_CALLBACK(fctTop10), v_widgets);
    g_signal_connect(G_OBJECT(btnAvantDeJouer[2]), "clicked", G_CALLBACK(fctSeConnecter), v_widgets);


    gtk_widget_show_all(v_widgets->window);

}

void fctVerifierSeConnecter(GtkWidget *ButtonExplore, gpointer data){

    _widgets *v_widgets=(_widgets*)data;
    GtkWidget *message;
    const gchar *login = gtk_entry_get_text(GTK_ENTRY(v_widgets->zoneTexte[0]));
    const gchar *mdp = gtk_entry_get_text(GTK_ENTRY(v_widgets->zoneTexte[1]));
    int i=0;


    if(strcmp(login,"")!=0 && strcmp(mdp,"")!=0){
        i=0;
        while(i<nbjoueur &&((strcmp(v_joueurs[i].pseudo,login)!=0)||(strcmp(v_joueurs[i].mdp,mdp)!=0))) i++;

        if(i==nbjoueur) {
            message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                            ,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Se compte est inexistant");
            gtk_dialog_run(GTK_DIALOG(message));
            gtk_widget_destroy(message);
        }
        else{
            indiceJoueur = i;
            fctAvantJeu(ButtonExplore,data);
        }
    }else{
        message = gtk_message_dialog_new (GTK_WINDOW(v_widgets->window),GTK_DIALOG_MODAL
                                        ,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"il faut remplir tous les champs");
        gtk_dialog_run(GTK_DIALOG(message));
        gtk_widget_destroy(message);
    }

}

void fctSeConnecter(GtkWidget *ButtonExplore, gpointer data){
    _widgets *v_widgets = (_widgets*)data;
    GtkWidget *imageSeConnecter[3];
    GtkWidget *btnSeConnecter[2];
    int i;


    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(v_widgets->window),v_widgets->layout);
    v_widgets->layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(v_widgets->window),v_widgets->layout);

    //#############################################################

    // creation de background ::
    imageSeConnecter[2] = gtk_image_new_from_file("./images/SeConnecter/background.png");
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),imageSeConnecter[2],0,0);

    // creation des zoneDeTexte ::
    for(i=0;i<2;i++)
        v_widgets->zoneTexte[i] = gtk_entry_new();

    gtk_entry_set_visibility(GTK_ENTRY(v_widgets->zoneTexte[1]), FALSE);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->zoneTexte[0],105,219);
    gtk_widget_set_size_request(v_widgets->zoneTexte[0], 230, 28);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),v_widgets->zoneTexte[1],105,283);
    gtk_widget_set_size_request(v_widgets->zoneTexte[1], 230, 28);

    // creation des bouton retour/seConnecter
    btnSeConnecter[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnSeConnecter[0]),GTK_RELIEF_NONE);
    imageSeConnecter[0] = gtk_image_new_from_file("./images/SeConnecter/valider.png");
    gtk_container_add(GTK_CONTAINER(btnSeConnecter[0]),imageSeConnecter[0]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),btnSeConnecter[0],193,386);
    gtk_widget_set_size_request(btnSeConnecter[0], 60 ,60);

    btnSeConnecter[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnSeConnecter[1]),GTK_RELIEF_NONE);
    imageSeConnecter[1] = gtk_image_new_from_file("./images/SeConnecter/retourner.png");
    gtk_container_add(GTK_CONTAINER(btnSeConnecter[1]),imageSeConnecter[1]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout),btnSeConnecter[1],19,488);
    gtk_widget_set_size_request(btnSeConnecter[1], 62, 62);

    //###########################################################

    g_signal_connect(G_OBJECT(btnSeConnecter[0]), "clicked", G_CALLBACK(fctVerifierSeConnecter),v_widgets);
    g_signal_connect(G_OBJECT(btnSeConnecter[1]), "clicked", G_CALLBACK(fctPrincipale1), v_widgets);

    gtk_widget_show_all(v_widgets->window);

}

void fctPrincipale(_widgets *v_widgets){

    GtkWidget   *imageMenuInitiale[4];
    GtkWidget   *btnMenuInitiale[3];

    fctImporter();

    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(v_widgets->window),v_widgets->layout);
    v_widgets->layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(v_widgets->window),v_widgets->layout);

    //#############################################################


    imageMenuInitiale[3] = gtk_image_new_from_file("./images/MenuInitiale/background.png");
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout), imageMenuInitiale[3], 0, 0);

    btnMenuInitiale[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[0]),GTK_RELIEF_NONE);
    imageMenuInitiale[0] = gtk_image_new_from_file("./images/MenuInitiale/connecter.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[0]),imageMenuInitiale[0]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout), btnMenuInitiale[0], 108, 150 );
    gtk_widget_set_size_request(btnMenuInitiale[0], 219, 80);

    btnMenuInitiale[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[1]),GTK_RELIEF_NONE);
    imageMenuInitiale[1] = gtk_image_new_from_file("./images/MenuInitiale/inscrire.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[1]),imageMenuInitiale[1]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout), btnMenuInitiale[1], 108, 228);
    gtk_widget_set_size_request(btnMenuInitiale[1], 219, 80);

    btnMenuInitiale[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[2]),GTK_RELIEF_NONE);
    imageMenuInitiale[2] = gtk_image_new_from_file("./images/MenuInitiale/quitter.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[2]),imageMenuInitiale[2]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout), btnMenuInitiale[2], 108, 306);
    gtk_widget_set_size_request(btnMenuInitiale[2], 219, 80);

    g_signal_connect(G_OBJECT(btnMenuInitiale[0]), "clicked", G_CALLBACK(fctSeConnecter), v_widgets);
    g_signal_connect(G_OBJECT(btnMenuInitiale[1]), "clicked", G_CALLBACK(fctIscrire), v_widgets);
    g_signal_connect(G_OBJECT(btnMenuInitiale[2]), "clicked", G_CALLBACK(fctSauvgarder), NULL);
    g_signal_connect(G_OBJECT(v_widgets->window), "destroy", G_CALLBACK(fctSauvgarder), NULL);



}

void fctPrincipale1(GtkWidget *ButtonExplore, gpointer data){
    _widgets *v_widgets = (_widgets*)data;
    GtkWidget   *imageMenuInitiale[4];
    GtkWidget   *btnMenuInitiale[3];

    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(v_widgets->window),v_widgets->layout);
    v_widgets->layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(v_widgets->window),v_widgets->layout);

    //#############################################################


    imageMenuInitiale[3] = gtk_image_new_from_file("./images/MenuInitiale/background.png");
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout), imageMenuInitiale[3], 0, 0);

    btnMenuInitiale[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[0]),GTK_RELIEF_NONE);
    imageMenuInitiale[0] = gtk_image_new_from_file("./images/MenuInitiale/connecter.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[0]),imageMenuInitiale[0]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout), btnMenuInitiale[0], 108, 150 );
    gtk_widget_set_size_request(btnMenuInitiale[0], 219, 80);

    btnMenuInitiale[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[1]),GTK_RELIEF_NONE);
    imageMenuInitiale[1] = gtk_image_new_from_file("./images/MenuInitiale/inscrire.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[1]),imageMenuInitiale[1]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout), btnMenuInitiale[1], 108, 228);
    gtk_widget_set_size_request(btnMenuInitiale[1], 219, 80);

    btnMenuInitiale[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[2]),GTK_RELIEF_NONE);
    imageMenuInitiale[2] = gtk_image_new_from_file("./images/MenuInitiale/quitter.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[2]),imageMenuInitiale[2]);
    gtk_layout_put(GTK_LAYOUT(v_widgets->layout), btnMenuInitiale[2], 108, 306);
    gtk_widget_set_size_request(btnMenuInitiale[2], 219, 80);

    g_signal_connect(G_OBJECT(btnMenuInitiale[0]), "clicked", G_CALLBACK(fctSeConnecter), v_widgets);
    g_signal_connect(G_OBJECT(btnMenuInitiale[1]), "clicked", G_CALLBACK(fctIscrire), v_widgets);
    g_signal_connect(G_OBJECT(btnMenuInitiale[2]), "clicked", G_CALLBACK(fctSauvgarder), NULL);
    g_signal_connect(G_OBJECT(v_widgets->window), "destroy", G_CALLBACK(fctSauvgarder), NULL);

    gtk_widget_show_all(v_widgets->window);


}







