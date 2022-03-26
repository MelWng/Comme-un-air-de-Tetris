#include <stdio.h>
#include <stdlib.h>
#include "projet1c.h"
#include <time.h>

int main(){

    int L,C,n,N=0,choix,ligne,Score=0;
    int Tab_Cercle[32]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
    int Tab_Losange[34]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
    int Tab_Triangle[31]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,46,47,48,49,50,51,52,53,54,55,56};
    int *XY=NULL;                     // qui contient les coordonnées
    int DimB;                         //dimension block
    char **tabP=NULL;              //Plateau qui varie en fonction des choix
    char **Block=NULL;             //Contient le bloc choisie par l'utilisateur
    char***tabTotal=NULL;          //Avec tous les blocs
    int c;
     do{
        printf("Entrez 1 pour connaitre les regles du jeu, 2 pour commencer a jouer ! : ");
        while (scanf("%d", &n) != 1) {                                    //Si la saisie est un entier scanf renvoie 1
              printf("Erreur. Veuillez entrez 1 pour connaitre les regles du jeu, 2 pour commencer a jouer ! : ");  //Sinon on vide le buffer (zone de mémoire)
		      while ((c=getchar()) != '\n' && c != EOF);   //tant que "c" n'est pas vide , //va lire jusqu'a qu'il y a \n ou EOF
	    }                                                  //ignore tous les caractères jusqu'au prochain saut de ligne ou EOF soit atteint.
                 //EOF end of file                                          //Si ce n'est pas le cas, le caractère suivant est extrait, et ainsi de suite.
        if (n==1){
        printf("\nRegles du jeu : Le jeu presente 3 plateaux contenant chacun un ensemble de blocs specifiques,\n");
        printf("le joueur devra placer les blocs tour a tour sur la surface du plateau en saississant les\n");
        printf("coordonees de l'endroit ou il veut les inserer. Le but est d'avoir un plateau non plein le\n");
        printf("plus longtemps possible. Il faut donc placer chaque bloc a l'emplacement qui permet d'eliminer\n");
        printf("un maximum de lignes et/ou de colonnes.\n");
        printf("Le joueur dispose de 3 tentatives pour saisir des coordonnees valides. Apres 3 tentatives invalides,\n");
        printf("c'est GAME OVER !\n");
        printf("Les coordonnees sont valides si les cases du bloc choisi peuvent etre toutes placees sur les cases\n");
        printf("vides se trouvant sur la surface valide du jeu\n");
        printf("\n");
        }
    }
    while(n!=2);

    printf("Saisir 1 pour Plateau Triangle, 2 pour Losange et 3 pour Cercle : ");
    while ((scanf("%d", &n) != 1)||(n<1)||(n>3)) {
        printf("Erreur. Veuillez re-saisir 1 pour Plateau Triangle, 2 pour Losange et 3 pour Cercle : ");
		while ((c=getchar()) != '\n' && c != EOF);
    }

    printf("Saisir la dimension du plateau, qui doit etre superieur ou egale a 21: ");
    while ((scanf("%d", &L) != 1)||(L<21)||(L>26)) {
        printf("Erreur. Veuillez re-saisir la dimension du plateau, qui doit etre superieur ou egale a 21: ");
		while ((c=getchar()) != '\n' && c != EOF);
    }

    printf("Entrez 1 pour afficher tous les blocs, 2 pour seulement 3 blocs aleatoirement : ");
    while ((scanf("%d", &choix) != 1)||((choix!=1)&&(choix!=2))) {
        printf("Erreur. Veuillez entrez 1 pour afficher tous les blocs, 2 pour seulement 3 blocs aleatoirement :");
		while ((c=getchar()) != '\n' && c != EOF);
    }

    C=L;
    XY = malloc(sizeof(int*)*2); // Coordonée
    tabP=creer_tab2D_dyn(L,C);

    /// TRIANGLE ///
    if (n==1){
        L=L/2;
        DimB=4;
        tabP=Triangle(tabP,L,C);
        tabTotal=Blocs_tab(); // Tableau 3D
         while (N<3 ) {
              AfficheP(tabP,L,C);
              Block=afficherBloc(tabTotal,Tab_Triangle,31,DimB,choix); // contient bloc desiré
              XY=Coordonnees(tabP);
              if ((N<3)&&(XY[0]==-1)){
                    N=N+1;
              }
              else if (DeposeB(XY, tabP, Block,DimB)==-1){
                    N=N+1;
              }
              else {
                Score=Score+500;                         //Si l'utilisateur reussi a poser le bloc
              }
              ligne=Etat_LC(tabP,L,C);
              while(ligne!=-1){
                    AfficheP(tabP,L,C);                 // Boucle while car
                    SupprimeL(tabP, C,ligne);           // si en supprimant et en décalant il y a encore une ligne pleine la boucle va
                    Decaler_lignes(tabP,C,ligne);       // supprime et décaler jusqu'à qu'il n'y a plus de ligne à supprimer
                    ligne=Etat_LC(tabP,L,C);
                    Score=Score+1000;
              }
              printf("Score : %d",Score);
        }
    }

    /// LOSANGE ///
    if(n==2){
        DimB=5;
        tabP=Losange(tabP,L,C);
        tabTotal=Blocs_tab(); // Tableau 3D
        while (N<3 ) {
              AfficheP(tabP,L,C);
              Block=afficherBloc(tabTotal,Tab_Losange,34,DimB,choix); // contient bloc desiré
              XY=Coordonnees(tabP);
              if ((N<3)&&(XY[0]==-1)){
                  N=N+1;
              }
              else if (DeposeB(XY, tabP, Block,DimB)==-1){
                  N=N+1;
              }
              else {
                Score=Score+500;                         //Si l'utilisateur reussi a poser le bloc
              }
              ligne=Etat_LC(tabP,L,C);
              while(ligne!=-1){
                    AfficheP(tabP,L,C);                   // Boucle while car
                    SupprimeL(tabP, C,ligne);           // si en supprimant et en décalant il y a encore une ligne pleine la boucle va
                    Decaler_lignes(tabP,C,ligne);       // supprime et décaler jusqu'à qu'il n'y a plus de ligne à supprimer
                    ligne=Etat_LC(tabP,L,C);
                    Score=Score+1000;
              }
              printf("Score : %d",Score);
        }
    }

    /// CERCLE ///
    if (n==3){
        DimB=5;
        tabP=Cercle(tabP,L,C);
        tabTotal=Blocs_tab(); // Tableau 3D
        while (N<3) {
              AfficheP(tabP,L,C);

              Block=afficherBloc(tabTotal,Tab_Cercle,32,DimB,choix); // contient bloc desiré
              XY=Coordonnees(tabP);

              if ((N<3)&&(XY[0]==-1)){
                  N=N+1;
              }
              else if (DeposeB(XY, tabP, Block,DimB)==-1){
                  N=N+1;
              }
              else {
                Score=Score+500;                         //Si l'utilisateur reussi a poser le bloc
              }
              ligne=Etat_LC(tabP,L,C);
              while(ligne!=-1){                          // Boucle while car
                    AfficheP(tabP,L,C);
                    SupprimeL(tabP, C,ligne);           // si en supprimant et en décalant il y a encore une ligne pleine la boucle va
                    Decaler_lignes(tabP,C,ligne);       // supprime et décaler jusqu'à qu'il n'y a plus de ligne à supprimer
                    ligne=Etat_LC(tabP,L,C);
                    Score=Score+1000;
              }
              printf("Score : %d\n",Score);
        }
    }
    printf("\nGAME OVER!!");

FREE (XY, Block, tabP, tabTotal,C,DimB);
return 0;
}



