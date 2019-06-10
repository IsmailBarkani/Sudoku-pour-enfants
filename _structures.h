

typedef struct {
    GtkWidget   *window;
    GtkWidget   *layout;

    GtkWidget   *btnControlle[5];
    GtkWidget   *imageControlle[6];
    GtkWidget   *btnGrille[16];
    GtkWidget   *imageGrille[16];
    GtkWidget   *btnChangement[4];
    GtkWidget   *imageChangement[4];
    GtkWidget   *imageChoisit;
    gint        indice;
    GtkWidget *zoneTexte[3];
}_widgets;



typedef	struct {
	 char pseudo[100];
	 char mdp[100];
	 int  score;
	 bool  save;
	 int saveSudoko[4][4];
}_joueur;




