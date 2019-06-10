#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "constantes.h"
#include "_structures.h"
#include "variablesGlobales.h"
#include "Algorithme.h"
#include "callbackBtnChangement.h"
#include "callbackCaseChoisit.h"
#include "jeu.h"
#include "avantJeuAlgorithme.c"
#include "avantJeu.h"





void fctCreationWindow(_widgets *v_widgets){

    v_widgets->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(v_widgets->window), 460, 580);
    gtk_window_set_position(GTK_WINDOW(v_widgets->window), GTK_WIN_POS_CENTER);

    v_widgets->layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(v_widgets->window), v_widgets->layout);
    gtk_widget_show(v_widgets->layout);

}


int main( int argc, char *argv[]){
    _widgets *v_widgets = (_widgets*)malloc(sizeof(_widgets));

    gtk_init(&argc, &argv);
    fctCreationWindow(v_widgets);

    fctPrincipale(v_widgets);

    gtk_widget_show_all(v_widgets->window);
    g_signal_connect(G_OBJECT(v_widgets->window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();

    return 0;
}




