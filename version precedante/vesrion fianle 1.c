#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

GtkWidget   *window;
GtkWidget   *layout;
GtkWidget   *btnMenuInitiale[3];
GtkWidget   *imageMenuInitiale[4];



static void fctSeConnecter(GtkWidget *ButtonExplore, gpointer data);
static void fctMenuPrincipale(GtkWidget *ButtonExplore, gpointer data);
static void fctIscrire(GtkWidget *ButtonExplore, gpointer data);
static void fctAvantDeJouer(GtkWidget *ButtonExplore, gpointer data);
static void fctTop10(GtkWidget *ButtonExplore, gpointer data);
static void fctLorsDeJeu(GtkWidget *ButtonExplore, gpointer data);



int main( int argc, char *argv[]){


    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 460, 580);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), layout);
    gtk_widget_show(layout);

    imageMenuInitiale[3] = gtk_image_new_from_file("./images/MenuInitiale/background.png");
    gtk_layout_put(GTK_LAYOUT(layout), imageMenuInitiale[3], 0, 0);




    btnMenuInitiale[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[0]),GTK_RELIEF_NONE);
    imageMenuInitiale[0] = gtk_image_new_from_file("./images/MenuInitiale/connecter.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[0]),imageMenuInitiale[0]);
    gtk_layout_put(GTK_LAYOUT(layout), btnMenuInitiale[0], 132, 150 );
    gtk_widget_set_size_request(btnMenuInitiale[0], 190, 78);

    btnMenuInitiale[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[1]),GTK_RELIEF_NONE);
    imageMenuInitiale[1] = gtk_image_new_from_file("./images/MenuInitiale/inscrire.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[1]),imageMenuInitiale[1]);
    gtk_layout_put(GTK_LAYOUT(layout), btnMenuInitiale[1], 132, 228);
    gtk_widget_set_size_request(btnMenuInitiale[1], 190, 78);

    btnMenuInitiale[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[2]),GTK_RELIEF_NONE);
    imageMenuInitiale[2] = gtk_image_new_from_file("./images/MenuInitiale/quitter.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[2]),imageMenuInitiale[2]);
    gtk_layout_put(GTK_LAYOUT(layout), btnMenuInitiale[2], 132, 306);
    gtk_widget_set_size_request(btnMenuInitiale[2], 190, 78);



    g_signal_connect(G_OBJECT(btnMenuInitiale[0]), "clicked", G_CALLBACK(fctSeConnecter), window);
    g_signal_connect(G_OBJECT(btnMenuInitiale[1]), "clicked", G_CALLBACK(fctIscrire), window);
    g_signal_connect(G_OBJECT(btnMenuInitiale[2]), "clicked",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();

    return 0;
}

void fctSeConnecter(GtkWidget *ButtonExplore, gpointer data){
    GtkWidget   *imageSeConnecter[3];
    GtkWidget   *zoneTexte[2];
    GtkWidget   *btnSeConnecter[2];
    int i;



    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(data),layout);
    layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(data),layout);

    //#############################################################

    // creation de background ::
    imageSeConnecter[2] = gtk_image_new_from_file("./images/SeConnecter/background.png");
    gtk_layout_put(GTK_LAYOUT(layout),imageSeConnecter[2],0,0);

    // creation des zoneDeTexte ::
    for(i=0;i<2;i++)
        zoneTexte[i] = gtk_entry_new();
    gtk_layout_put(GTK_LAYOUT(layout),zoneTexte[0],121,258);
    gtk_widget_set_size_request(zoneTexte[0], 221, 28);
    gtk_layout_put(GTK_LAYOUT(layout),zoneTexte[1],121,309);
    gtk_widget_set_size_request(zoneTexte[1], 221, 28);

    // creation des bouton retour/seConnecter
    btnSeConnecter[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnSeConnecter[0]),GTK_RELIEF_NONE);
    imageSeConnecter[0] = gtk_image_new_from_file("./images/SeConnecter/valider.png");
    gtk_container_add(GTK_CONTAINER(btnSeConnecter[0]),imageSeConnecter[0]);
    gtk_layout_put(GTK_LAYOUT(layout),btnSeConnecter[0],193,380);
    gtk_widget_set_size_request(btnSeConnecter[0], 60 ,60);

    btnSeConnecter[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnSeConnecter[1]),GTK_RELIEF_NONE);
    imageSeConnecter[1] = gtk_image_new_from_file("./images/SeConnecter/retourner.png");
    gtk_container_add(GTK_CONTAINER(btnSeConnecter[1]),imageSeConnecter[1]);
    gtk_layout_put(GTK_LAYOUT(layout),btnSeConnecter[1],19,488);
    gtk_widget_set_size_request(btnSeConnecter[1], 60, 60);

    //###########################################################

    g_signal_connect(G_OBJECT(btnSeConnecter[0]), "clicked", G_CALLBACK(fctAvantDeJouer), data);
    g_signal_connect(G_OBJECT(btnSeConnecter[1]), "clicked", G_CALLBACK(fctMenuPrincipale), data);
    gtk_widget_show_all(window);

}

void fctMenuPrincipale(GtkWidget *ButtonExplore, gpointer data){

    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(data),layout);
    layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(data),layout);

    //#############################################################


    imageMenuInitiale[3] = gtk_image_new_from_file("./images/MenuInitiale/background.png");
    gtk_layout_put(GTK_LAYOUT(layout), imageMenuInitiale[3], 0, 0);

    btnMenuInitiale[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[0]),GTK_RELIEF_NONE);
    imageMenuInitiale[0] = gtk_image_new_from_file("./images/MenuInitiale/connecter.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[0]),imageMenuInitiale[0]);
    gtk_layout_put(GTK_LAYOUT(layout), btnMenuInitiale[0], 132, 150 );
    gtk_widget_set_size_request(btnMenuInitiale[0], 190, 78);

    btnMenuInitiale[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[1]),GTK_RELIEF_NONE);
    imageMenuInitiale[1] = gtk_image_new_from_file("./images/MenuInitiale/inscrire.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[1]),imageMenuInitiale[1]);
    gtk_layout_put(GTK_LAYOUT(layout), btnMenuInitiale[1], 132, 228);
    gtk_widget_set_size_request(btnMenuInitiale[1], 190, 78);

    btnMenuInitiale[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnMenuInitiale[2]),GTK_RELIEF_NONE);
    imageMenuInitiale[2] = gtk_image_new_from_file("./images/MenuInitiale/quitter.png");
    gtk_container_add(GTK_CONTAINER(btnMenuInitiale[2]),imageMenuInitiale[2]);
    gtk_layout_put(GTK_LAYOUT(layout), btnMenuInitiale[2], 132, 306);
    gtk_widget_set_size_request(btnMenuInitiale[2], 190, 78);

    g_signal_connect(G_OBJECT(btnMenuInitiale[0]), "clicked", G_CALLBACK(fctSeConnecter), data);
    g_signal_connect(G_OBJECT(btnMenuInitiale[1]), "clicked", G_CALLBACK(fctIscrire), data);
    g_signal_connect(G_OBJECT(btnMenuInitiale[2]), "clicked",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

}

void fctIscrire(GtkWidget *ButtonExplore, gpointer data){
    GtkWidget   *imageInscrire[3];
    GtkWidget   *zoneTexte[3];
    GtkWidget   *btnIscrire[2];
    int i;

   // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(data),layout);
    layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(data),layout);

    //#############################################################

    // creation de Widgets:: //
    // creation de background ::
    imageInscrire[2] = gtk_image_new_from_file("./images/inscrire/background.png");
    gtk_layout_put(GTK_LAYOUT(layout),imageInscrire[2],0,0);

    // creation des zoneDeTexte ::
    for(i=0;i<3;i++)
        zoneTexte[i] = gtk_entry_new();
    gtk_layout_put(GTK_LAYOUT(layout),zoneTexte[0],120,230);
    gtk_widget_set_size_request(zoneTexte[0], 221, 28);
    gtk_layout_put(GTK_LAYOUT(layout),zoneTexte[1],120,286);
    gtk_widget_set_size_request(zoneTexte[1], 221, 28);
    gtk_layout_put(GTK_LAYOUT(layout),zoneTexte[2],120,346);
    gtk_widget_set_size_request(zoneTexte[2], 221, 28);

    // creation des bouton retour/seConnecter
    btnIscrire[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnIscrire[0]),GTK_RELIEF_NONE);
    imageInscrire[0] = gtk_image_new_from_file("./images/inscrire/valider.png");
    gtk_container_add(GTK_CONTAINER(btnIscrire[0]),imageInscrire[0]);
    gtk_layout_put(GTK_LAYOUT(layout),btnIscrire[0],193,380);
    gtk_widget_set_size_request(btnIscrire[0], 60 ,60);

    btnIscrire[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnIscrire[1]),GTK_RELIEF_NONE);
    imageInscrire[1] = gtk_image_new_from_file("./images/inscrire/retourner.png");
    gtk_container_add(GTK_CONTAINER(btnIscrire[1]),imageInscrire[1]);
    gtk_layout_put(GTK_LAYOUT(layout),btnIscrire[1],19,488);
    gtk_widget_set_size_request(btnIscrire[1], 60, 60);

    //###########################################################

    g_signal_connect(G_OBJECT(btnIscrire[0]), "clicked", G_CALLBACK(fctMenuPrincipale), data);
    g_signal_connect(G_OBJECT(btnIscrire[1]), "clicked", G_CALLBACK(fctMenuPrincipale), data);
    gtk_widget_show_all(window);
}

void fctAvantDeJouer(GtkWidget *ButtonExplore, gpointer data){
    GtkWidget   *imageAvantDeJouer[8];
    GtkWidget   *btnAvantDeJouer[7];

    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(data),layout);
    layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(data),layout);

    //#############################################################

    // creation de background ::
    imageAvantDeJouer[5] = gtk_image_new_from_file("./images/avantDeJouer/background.png");
    gtk_layout_put(GTK_LAYOUT(layout),imageAvantDeJouer[5],0,0);

    // creation d'autre widget les boutons ::
    btnAvantDeJouer[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnAvantDeJouer[0]),GTK_RELIEF_NONE);
    imageAvantDeJouer[0] = gtk_image_new_from_file("./images/avantDeJouer/commencerJeu.png");
    gtk_container_add(GTK_CONTAINER(btnAvantDeJouer[0]),imageAvantDeJouer[0]);
    gtk_layout_put(GTK_LAYOUT(layout),btnAvantDeJouer[0],136,142);
    gtk_widget_set_size_request(btnAvantDeJouer[0], 186 ,58);

    btnAvantDeJouer[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnAvantDeJouer[1]),GTK_RELIEF_NONE);
    imageAvantDeJouer[1] = gtk_image_new_from_file("./images/avantDeJouer/top10.png");
    gtk_container_add(GTK_CONTAINER(btnAvantDeJouer[1]),imageAvantDeJouer[1]);
    gtk_layout_put(GTK_LAYOUT(layout),btnAvantDeJouer[1],136,192);
    gtk_widget_set_size_request(btnAvantDeJouer[1], 186, 60);

    btnAvantDeJouer[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnAvantDeJouer[2]),GTK_RELIEF_NONE);
    imageAvantDeJouer[2] = gtk_image_new_from_file("./images/avantDeJouer/modifier.png");
    gtk_container_add(GTK_CONTAINER(btnAvantDeJouer[2]),imageAvantDeJouer[2]);
    gtk_layout_put(GTK_LAYOUT(layout),btnAvantDeJouer[2],136,245);
    gtk_widget_set_size_request(btnAvantDeJouer[2], 186, 60);

    btnAvantDeJouer[3] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnAvantDeJouer[3]),GTK_RELIEF_NONE);
    imageAvantDeJouer[3] = gtk_image_new_from_file("./images/avantDeJouer/profile.png");
    gtk_container_add(GTK_CONTAINER(btnAvantDeJouer[3]),imageAvantDeJouer[3]);
    gtk_layout_put(GTK_LAYOUT(layout),btnAvantDeJouer[3],136,295);
    gtk_widget_set_size_request(btnAvantDeJouer[3], 186, 60);

    btnAvantDeJouer[4] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnAvantDeJouer[4]),GTK_RELIEF_NONE);
    imageAvantDeJouer[4] = gtk_image_new_from_file("./images/avantDeJouer/deconnexion.png");
    gtk_container_add(GTK_CONTAINER(btnAvantDeJouer[4]),imageAvantDeJouer[4]);
    gtk_layout_put(GTK_LAYOUT(layout),btnAvantDeJouer[4],136,340);
    gtk_widget_set_size_request(btnAvantDeJouer[4], 186, 60);

    g_signal_connect(G_OBJECT(btnAvantDeJouer[0]), "clicked", G_CALLBACK(fctLorsDeJeu), data);
    g_signal_connect(G_OBJECT(btnAvantDeJouer[1]), "clicked", G_CALLBACK(fctTop10), data);
    g_signal_connect(G_OBJECT(btnAvantDeJouer[4]), "clicked", G_CALLBACK(fctSeConnecter), data);

    gtk_widget_show_all(window);

}














void fctTop10(GtkWidget *ButtonExplore, gpointer data){

    GtkWidget   *imageTop10[2];
    GtkWidget   *btnTop10[1];

    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(data),layout);
    layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(data),layout);

    //#############################################################

    // creation de background ::
    imageTop10[0] = gtk_image_new_from_file("./images/top10/background.png");
    gtk_layout_put(GTK_LAYOUT(layout),imageTop10[0],0,0);

     // creation d'autre widget et les boutons ::
    btnTop10[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnTop10[1]),GTK_RELIEF_NONE);
    imageTop10[1] = gtk_image_new_from_file("./images/top10/menu.png");
    gtk_container_add(GTK_CONTAINER(btnTop10[1]),imageTop10[1]);
    gtk_layout_put(GTK_LAYOUT(layout),btnTop10[1],193,377);
    gtk_widget_set_size_request(btnTop10[1], 65, 65);

    gtk_widget_show_all(window);
}


void fctLorsDeJeu(GtkWidget *ButtonExplore, gpointer data){
    GtkWidget   *imageLorsDeJeu[24];
    GtkWidget   *btnLorsDeJeu[7];

    // Supprission et creation de layout
    gtk_container_remove(GTK_CONTAINER(data),layout);
    layout = gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(data),layout);

    //#############################################################
    // creation de background ::
    imageLorsDeJeu[3] = gtk_image_new_from_file("./images/lorsDeJeu/background.png");
    gtk_layout_put(GTK_LAYOUT(layout),imageLorsDeJeu[3],0,0);

     // creation d'autre widget et les boutons ::
    btnLorsDeJeu[0] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnLorsDeJeu[0]),GTK_RELIEF_NONE);
    imageLorsDeJeu[0] = gtk_image_new_from_file("./images/lorsDeJeu/renitialiser.png");
    gtk_container_add(GTK_CONTAINER(btnLorsDeJeu[0]),imageLorsDeJeu[0]);
    gtk_layout_put(GTK_LAYOUT(layout),btnLorsDeJeu[0],156,377);
    gtk_widget_set_size_request(btnLorsDeJeu[0], 65, 65);

    btnLorsDeJeu[1] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnLorsDeJeu[1]),GTK_RELIEF_NONE);
    imageLorsDeJeu[1] = gtk_image_new_from_file("./images/lorsDeJeu/valider.png");
    gtk_container_add(GTK_CONTAINER(btnLorsDeJeu[1]),imageLorsDeJeu[1]);
    gtk_layout_put(GTK_LAYOUT(layout),btnLorsDeJeu[1],230,377);
    gtk_widget_set_size_request(btnLorsDeJeu[1], 65, 65);

    btnLorsDeJeu[2] = gtk_button_new();
    gtk_button_set_relief(GTK_BUTTON(btnLorsDeJeu[2]),GTK_RELIEF_NONE);
    imageLorsDeJeu[2] = gtk_image_new_from_file("./images/lorsDeJeu/retourner.png");
    gtk_container_add(GTK_CONTAINER(btnLorsDeJeu[2]),imageLorsDeJeu[2]);
    gtk_layout_put(GTK_LAYOUT(layout),btnLorsDeJeu[2],19,488);
    gtk_widget_set_size_request(btnLorsDeJeu[2], 65, 65);

    g_signal_connect(G_OBJECT(btnLorsDeJeu[1]), "clicked", G_CALLBACK(fctAvantDeJouer), data);
    g_signal_connect(G_OBJECT(btnLorsDeJeu[2]), "clicked", G_CALLBACK(fctAvantDeJouer), data);


    gtk_widget_show_all(window);
}

