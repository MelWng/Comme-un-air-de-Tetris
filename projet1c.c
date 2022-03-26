#include <stdio.h>
#include <stdlib.h>
#include "projet1c.h"
#include <time.h>

char** creer_tab2D_dyn(int L,int C){
    int i,j;
    char **tab;
    tab = malloc(sizeof(char*)*L);
    for(i=0;i<L;i++){
        tab[i] = malloc(sizeof(char)*C);
            for (j=0;j<C;j++){
            tab[i][j]=32;
        }
    }
    return tab;
}

  ///AFFICHE LE PLATEAU///
void AfficheP(char **tab, int L, int C){
    int i,j;
    printf("\n   ");
    for(i=0;i<C;i++){                 //Affiche toute la premiere ligne des lettres en minuscule
        printf(" %c",97+i);
        }
    printf("\n   -");
    for(i=0;i<C;i++){
    printf("--");
    }
    for(i=0;i<L;i++){
        printf("\n%c |",65+i);
        for(j=0;j<C;j++){
            printf(" %c",tab[i][j]);
        }
        printf(" |");               //Ferme le côté droit du plateau
    }
    printf("\n   -");
    for(i=0;i<C;i++){               //Ferme le plateau en bas
        printf("--");
    }
    printf("\n");
}

char ** Losange(char **tabL,int L,int C){
    int i,n,j,k,h;
    n=(C-1)/2;                        // Milieu de la colonne
    for(i=0;i<L;i++){
            tabL[i][n]=46;             //colonne du milieu = '.'
         if (i<(L/2)){                 //triangle supérieur
             k=n-i;                    // à partir du milieu on obtient le premier point le plus à gauche
             h=n+i;                    // à partir du millieu on obtient le premier point le plus à gauche
         for (j=k;j<=h;j++){             // on va du point le plus à gauche au point le plus à droite
            tabL[i][j]=46;             // 46 = code ASCII du point '.'
            }}

         else {                   //triangle inferieur
             k=i-n;               //côté gauche
             h=(C-k);             //côté droit
         for(j=k;j<h;j++){
            tabL[i][j]=46;

         }
         }
    }
return tabL;
}

char** Triangle(char**tabT, int L, int C){
    int i,n,k,h,j;
    n=(C-1)/2;
    for(i=0;i<L;i++){
            tabT[i][n]=46;             //Pour la colonne du milieu
                                       //triangle supérieur
             k=n-i;                     // côté gauche
             h=n+i;                     // côté droit
         for (j=k;j<=h;j++){
            tabT[i][j]=46;
            }}
    return tabT;
}

char** Cercle(char**tabC, int L, int C){
    int i,n,j,k,h,x,p;
    n=(C-1)/2;    // milieu
    x=(C-13)/2;      //pour les quatres coins
    for(i=0;i<x;i++){                 //en haut
        k=x-i;                        //Le point le plus à gauche
        h=C-x+i;                      //Le point le plus à droite
        tabC[i][n]=46;
        for(j=k;j<h;j++){
            tabC[i][j]=46;
        }
    }

    for(i=x;i<L-x;i++){             //milieu
        for(j=0;j<C;j++){
            tabC[i][j]=46;
        }
    }
    j=1;
    for(i=L-x;i<L;i++){
        p=0;
        while (p==0){                //on veut que la boucle ne tourne qu'une fois pour que i s'accrémente aussi
            h=C-j;                   //Avoir le coté en bas à droite
            for(k=j;k<h;k++){        // obtenir i tout en accrémentant j
                tabC[i][k]=46;
            }
            j++;
            p=1;
            }
        }
return tabC;
}

/// CONTIENT TOUS LES BLOCS ///
char***Blocs_tab (){

     /// TABLEAU 3D ///
     char ***tabTotal;
     int i,j,k;
     tabTotal = malloc(sizeof(char**)*57);   //Nombre total de block
     for(i=0;i<57;i++){
        tabTotal[i] = malloc(sizeof(char*)*5);
        for (j=0;j<5;j++){
               tabTotal[i][j] = malloc(sizeof(char)*5);
                for(k=0;k<5;k++){
                    tabTotal[i][j][k]=46;
                }
        }
    }

     /// BLOCK COMMUN ///
    for(i=0;i<20;i++){
        switch(i){

        case 0 :
            tabTotal[i][3][0]=254;
            tabTotal[i][4][0]=254;
            tabTotal[i][4][1]=254;
            break;
        case 1 :
            tabTotal[i][4][0]=254;
            tabTotal[i][4][1]=254;
            tabTotal[i][3][1]=254;
            break;
        case 2 :
           for(k=0;k<=2;k++){
                tabTotal[i][4][k]=254;
            }
            tabTotal[i][3][0]=254;
            break;
        case 3 :
            tabTotal[i][2][0]=254;
            for(j=2;j<=4;j++){
                tabTotal[i][j][1]=254;
            }
            break;
        case 4 :
            for(j=2;j<=4;j++){
                tabTotal[i][j][0]=254;
                }
            tabTotal[i][3][1]=254;
            break;
        case 5 :
            for(k=0;k<=2;k++){
                tabTotal[i][4][k]=254;
            }
            tabTotal[i][3][1]=254;
            break;
        case 6 :
            tabTotal[i][3][0]=254;
            tabTotal[i][3][1]=254;
            tabTotal[i][4][1]=254;
            tabTotal[i][4][2]=254;
            break;
        case 7 :
            tabTotal[i][2][0]=254;
            tabTotal[i][3][0]=254;
            tabTotal[i][3][1]=254;
            tabTotal[i][4][1]=254;
            break;
        case 8 :
            for(j=1;j<5;j++){
                tabTotal[i][j][0]=254;
            }
            break;
        case 9 :
            for(j=3;j<5;j++){
                for(k=0;k<2;k++){
                    tabTotal[i][j][k]=254;
                }
            }
            break;
        case 10 :
            tabTotal[i][3][0]=254;
            tabTotal[i][3][1]=254;
            tabTotal[i][4][1]=254;
            break;
        case 11 :
            tabTotal[i][3][0]=254;
            tabTotal[i][3][1]=254;
            tabTotal[i][4][0]=254;
            break;
        case 12 :
            for(k=0;k<=2;k++){
                tabTotal[i][4][k]=254;
            }
            tabTotal[i][3][2]=254;
            break;
        case 13 :
            for(j=2;j<=4;j++){
                tabTotal[i][j][0]=254;
                }
            tabTotal[i][4][1]=254;
            break;
        case 14 :
            tabTotal[i][3][0]=254;
            for(j=2;j<=4;j++){
                tabTotal[i][j][1]=254;
            }
            break;
        case 15 :
            for(k=0;k<=2;k++){
                tabTotal[i][3][k]=254;
            }
            tabTotal[i][4][1]=254;
            break;
        case 16 :
            tabTotal[i][3][2]=254;
            tabTotal[i][3][1]=254;
            tabTotal[i][4][1]=254;
            tabTotal[i][4][0]=254;
            break;
        case 17 :
            tabTotal[i][3][0]=254;
            tabTotal[i][4][0]=254;
            tabTotal[i][2][1]=254;
            tabTotal[i][3][1]=254;
            break;
        case 18 :
            tabTotal[i][4][0]=254;
            break;
        case 19 :
            for(k=0;k<4;k++){
                tabTotal[i][4][k]=254;
            }
            break;

        }
    }

    /// BLOCK CERCLE ///
    for(i=20;i<32;i++){
        switch(i){
        case 20 :
            for(j=1;j<5;j++){
                     for(k=0;k<4;k++){
                        tabTotal[i][j][k]=254;
                     }
                 }
              break;
        case 21 :
            for(j=1;j<5;j++){
                tabTotal[i][j][1]=254;
                tabTotal[i][j][2]=254;
            }
            for(k=0;k<4;k++){
                tabTotal[i][2][k]=254;
                tabTotal[i][3][k]=254;
            }
            break;
        case 22 :
            for(j=1;j<5;j++){
                tabTotal[i][j][3]=254;
                tabTotal[i][j][0]=254;
            }
            for(k=0;k<4;k++){
                tabTotal[i][4][k]=254;
            }
            break;
        case 23 :
            for(j=1;j<5;j++){
                tabTotal[i][j][3]=254;
            }
            for(k=0;k<4;k++){
                tabTotal[i][1][k]=254;
            }
            break;
        case 24 :
            for(k=0;k<4;k++){
                tabTotal[i][3][k]=254;
                tabTotal[i][4][k]=254;
            }   tabTotal[i][4][3]=46;
            break;
        case 25 :
            for(j=1;j<5;j++){
                tabTotal[i][j][2]=254;
            }
            for(k=0;k<2;k++){
                tabTotal[i][1][k]=254;
                tabTotal[i][4][k]=254;
            }
            break;
        case 26 :
            for(j=1;j<5;j++){
                tabTotal[i][j][1]=254;
                tabTotal[i][j][0]=254;
            }
            break;
        case 27 :
            for(k=0;k<4;k++){
                tabTotal[i][3][k]=254;
                tabTotal[i][4][k]=254;
            }
            break;
        case 28 :
            for(j=0;j<5;j++){
                tabTotal[i][j][0]=254;
            }
            break;
        case 29 :
            for(k=0;k<5;k++){
                tabTotal[i][4][k]=254;
            }
            break;
        case 30 :
            for(k=0;k<5;k++){
                tabTotal[i][3][k]=254;
            }
            tabTotal[i][4][4]=254;
            tabTotal[i][4][0]=254;
            break;
        case 31 :
             for(j=1;j<5;j++){
                tabTotal[i][j][3]=254;
                tabTotal[i][j][0]=254;
            }
            for(k=0;k<4;k++){
                tabTotal[i][4][k]=254;
            }   tabTotal[i][2][3]=46;
                tabTotal[i][1][3]=46;
            break;
        }
    }
    /// BLOCK LOSANGE ///
    for(i=32;i<46;i++){
        switch(i){
        case 32:
             j=4;
             k=0;
             while((j>0)&&(k<4)){
                tabTotal[i][j][k]=254;
                if(j<4){
                    tabTotal[i][j][k-1]=254;
                }
                j--;
                k++;
             }
            break;
         case 33:
            for(j=1;j<4;j++){
                for(k=0;k<4;k++){
                    if(k==j){
                        tabTotal[i][j][k]=254;
                        if(k<4){
                        tabTotal[i][j+1][k]=254;
                        }
                    }
                }
            }            tabTotal[i][1][0]=254;
             break;
         case 34:
              j=1;
              k=0;
              while((j<5)&&(k<4)){
                tabTotal[i][j][k]=254;
                j++;
                k++;
              }tabTotal[i][2][0]=254;
              tabTotal[i][3][1]=254;
              tabTotal[i][4][2]=254;
            break;
         case 35:
             j=4;
             k=0;
             while((j>0)&&(k<4)){
                tabTotal[i][j][k]=254;
                if(j<4){
                    tabTotal[i][j+1][k]=254;
                }
                j--;
                k++;
             }  tabTotal[i][0][3]=46;

             break;
        case 36:
            for(j=1;j<5;j++){
                tabTotal[i][j][1]=254;
                tabTotal[i][j][2]=254;
            }
            for(k=0;k<4;k++){
                tabTotal[i][1][k]=254;
            }
             break;
        case 37:
            for(j=0;j<5;j++){
                for(k=0;k<4;k++){
                    if(j==k){
                        tabTotal[i][j+1][k]=254;
                    }
                }
            }
            j=4;
            k=0;
            while((j>0)&&(k<4)){
                tabTotal[i][j][k]=254;
                j--;
                k++;
            }
             break;
        case 38:
             for(k=0;k<5;k++){
                tabTotal[i][2][k]=254;
             }
             for(k=1;k<4;k++){
                tabTotal[i][3][k]=254;
             }  tabTotal[i][4][2]=254;

             break;
        case 39:
            for(j=1;j<5;j++){
                     for(k=0;k<4;k++){
                        tabTotal[i][j][k]=254;
                     }
                 }
             break;
        case 40:
            for(j=0;j<5;j++){
                tabTotal[i][j][0]=254;
            }
             break;
        case 41:
            for(k=0;k<5;k++){
                tabTotal[i][4][k]=254;
            }
             break;
        case 42:
            for(k=0;k<4;k++){
                tabTotal[i][3][k]=254;
            }   tabTotal[i][2][3]=254;
                tabTotal[i][4][3]=254;
             break;
        case 43:
             for(k=0;k<4;k++){
                tabTotal[i][3][k]=254;
            }   tabTotal[i][4][3]=254;
             break;
        case 44:
            for(j=1;j<5;j++){
                tabTotal[i][j][1]=254;
            }   tabTotal[i][1][0]=254;
             break;
        case 45:
            for(j=1;j<5;j++){
                tabTotal[i][j][0]=254;
            }   tabTotal[i][1][1]=254;
             break;

        }
    }
    /// BLOCK TRIANGLE ///
    for(i=46;i<57;i++){
        switch(i){
        case 46:
            for(k=0;k<3;k++){
                tabTotal[i][3][k]=254;
            }
            tabTotal[i][2][0]=254;
            tabTotal[i][4][2]=254;
            break;
        case 47:
            for(j=2;j<5;j++){
                tabTotal[i][j][1]=254;
            }
            tabTotal[i][2][0]=254;
            tabTotal[i][4][2]=254;
            break;
        case 48:
            for(j=2;j<5;j++){
                tabTotal[i][j][1]=254;
            }   tabTotal[i][2][2]=254;
                tabTotal[i][4][0]=254;
            break;
        case 49:
            tabTotal[i][3][1]=254;
            tabTotal[i][2][2]=254;
            tabTotal[i][4][0]=254;
            break;
        case 50:
            tabTotal[i][3][1]=254;
            tabTotal[i][2][0]=254;
            tabTotal[i][4][2]=254;
            break;
        case 51:
            for(j=2;j<5;j++){
                tabTotal[i][j][0]=254;
            }
            break;
        case 52:
            for(k=0;k<3;k++){
                tabTotal[i][4][k]=254;
            }
            break;
        case 53:
            for(j=3;j<5;j++){
                tabTotal[i][j][0]=254;
            }
            break;
        case 54:
             for(k=0;k<2;k++){
                tabTotal[i][4][k]=254;
             }
            break;
        case 55:
            for(k=0;k<3;k++){
                tabTotal[i][3][k]=254;
            }   tabTotal[i][4][0]=254;
                tabTotal[i][2][2]=254;

            break;
        case 56:
            for(k=0;k<3;k++){
                tabTotal[i][3][k]=254;
            }   tabTotal[i][2][1]=254;
                tabTotal[i][4][1]=254;
            break;
        }

    }
 return tabTotal;
    }

 ///Choisie + Affiche 3 blocs ou tous les blocs + renvoie le block désiré ///
char** afficherBloc(char***tab3D, int TabB[],int N,int Dim, int Choix){
    int i,j,k,x,c;
    char** tab2D;
    int nb,tab[3];
    if (Choix==2){
    srand(time(NULL));    // La fonction srand initialise le générateur de nombres pseudo-aléatoire.
                          //rand() retourne un nombre aléatoire comprit entre 0 et N en fonction de la valeur de srand et du temps actuel => temps ecoulé.
    for (i=0;i<3;i++){
        nb=rand()%N;     // N = Taille des tab_cercle,tab_losange... ici nb = à valeur choisi au hasard entre 0 et N-1,  et TabB = à soit tab_cercle,tab_losange...
        nb=TabB[nb];     //nb prend la valeur de TabB[nb] qui correspond à l'indice d'un block dans le tableau 3D car TabB contient les indices des block du plateau associé
        tab[i]=nb;       // on stock les 3 indices au hasard
        for (j=0;j<5;j++){
          for(k=0;k<5;k++){
                if (tab3D[nb][j][k]==46){      //on affiche les points (46) deviennent des espaces (32) à l'affichage
                    tab3D[nb][j][k]=32;
                }
        printf("%c ", tab3D[nb][j][k]);
                }
            printf("\n");
    }
      printf("%d",i);
      printf("\n");
    }
    printf("Veuillez saisir le numero de bloc desire : ");
    while ((scanf("%d", &x) != 1)||(x<0)||(x>2)) {
        printf("Erreur. Veuillez re-saisir le numero de bloc desire : ");
		while ((c=getchar()) != '\n' && c != EOF);
    }

    x=tab[x];  // x = l'indice du block dans Tab3D ( tab[x] contenait les indices )
    }
    else {
        for(i=0;i<N;i++){                                      //On affiche tous les blocs du plateau choisi
            for(j=0;j<5;j++){
                for(k=0;k<5;k++){
                    if (tab3D[TabB[i]][j][k]==46){
                        tab3D[TabB[i]][j][k]=32;
                    }
                    printf("%c ", tab3D[TabB[i]][j][k]);
                }
                printf("\n");
            }
            printf("%d",i);
            printf("\n");
       }
    printf("Veuillez saisir le numero de bloc desire : ");
    while ((scanf("%d", &x) != 1)||(x<0)||(x>=N)) {
        printf("Erreur. Veuillez re-saisir le numero de bloc desire : ");
		while ((c=getchar()) != '\n' && c != EOF);
    }
    x=TabB[x];  // x = lindice du block 3D (TabB contient indices des block spécifiques au plateau)
    }

    tab2D = malloc(sizeof(char*)*Dim);                    //création tableau 2D avec le block choisi
    for(j=0;j<Dim;j++){
        tab2D[Dim-1-j] = malloc(sizeof(char)*Dim);        //on commence à copier à partir de en bas à gauche donc on commence à allouer en bas à gauche
            for (k=0;k<Dim;k++){
               if(tab3D[x][4-j][k]==32){                  //pour avoir le block avec des '.' et non des espaces + on prend 4 car les blocks du tab3D sont de taille fixe 5 (0,1,2,3,4)
                     tab2D[Dim-1-j][k]=46;
                }
               else {
                tab2D[Dim-1-j][k]=254;
                }
        }
    }


    return tab2D;
}

  /// DEPOSE + VERIFIE LE BLOC SUR LE PLATEAU ///
int DeposeB(int* XY, char**Plateau, char**Block, int dim){
    int i,j;
    if (XY[0]==-1){
        return 0;
    }
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
                if((Block[dim-1-i][j]!=46)&&(XY[0]-i)<0){      // vérifie si le bloc sort du plateau ( en haut )
                     printf("Votre coup n'est pas valide \n");
                     return -1;
                }
                if ((Block[dim-1-i][j]!=46)&&(Plateau[XY[0]-i][XY[1]+j]!=46)){ //Si dans Block c'est un carré (et non un point) et si la case du plateau est différent de '.'
                    printf("Votre coup n'est pas valide !! \n");                   //Vérifie si l'utilisateur supperpose des blocs ou si le bloc dépasse du plateau à droite
                       return -1;
                }

        }
    }
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            if (Block[dim-1-i][j]!=46){                   //ne copie que les blocs sur le plateau et non les '.'
         Plateau[XY[0]-i][XY[1]+j]=Block[dim-1-i][j];
            }
        }
    }
   return 0;
}


  /// SAISIE LES COORDONNEES ///
int *Coordonnees( char**Plateau){
     char a,b;
     int *XY=NULL;
     XY = malloc(sizeof(int*)*2);
     do{
     printf("Saisir une coordonnee verticale :\n");
     scanf(" %c", &a);
     printf("Saisir une coordonnee horizontale :\n");
     scanf(" %c", &b);}
     while( ( a<'A'|| a>'Z') || ( b<'a'|| b>'z'));

XY[0]=a-65;              // code ASCII de a=65 et A=97
XY[1]=b-97;
if ((Plateau[XY[0]][XY[1]]==254)&&(Plateau[XY[0]][XY[1]]!=46)){   //Si le côté en bas à gauche est = à 254(un cube) et
    printf("Votre coup n'est pas valide! \n");                    // que les coord saisies sont en dehors du plateau = invalide
    XY[0]=-1;
}
return XY;
}

  /// DETECTE COLONNE ET LIGNE SI ELLES SONT PLEINES + supprime directe la colonne ///
int Etat_LC(char ** Plateau,int L, int C){      //retourne le numéro de la ligne pleine ou 0
     int i,j,k;

     for(i=0;i<L;i++){                         //Detecte si une colonne est pleine
            k=0;
        for(j=0;j<C;j++){
            if(Plateau[j][i]!=46){
                k=k+1;
            }
        }
        if(k==L){                               //Supprime la colonne
            for(j=0;j<C;j++){
                if(Plateau[j][i]!=32){
                    Plateau[j][i]=46;
                }
            }
        }
     }

     for(i=0;i<L;i++){            //Verifie les lignes
        k=0;
        for(j=0;j<C;j++){
            if(Plateau[i][j]!=46){
                k=k+1;
            }
        }
        if (k==C){
            return i;
        }
    }

    return -1;
}

  /// SUPPRIME LES LIGNES PLEINES ///
void SupprimeL(char ** Plateau, int C,int Ligne){   // supprime la ligne pleine
       int j;
       for(j=0;j<C;j++){
           if(Plateau[Ligne][j]!=32){
                    Plateau[Ligne][j]=46;
           }
       }
}


  /// DECALE LES LIGNES VERS LE BAS ///
void Decaler_lignes(char ** Plateau, int C, int Ligne){
        int i,j;
        for(i=0;i<Ligne;i++){                  //Depuis la ligne supprimer je remonte donc -i
            for(j=0;j<C;j++){
               if(Plateau[Ligne-i-1][j]!=32){
                 if((Plateau[Ligne-i][j]==46)&&(Plateau[Ligne-1-i][j]!=46)) {  // Si la ligne ou nous sommes est un '.' et si la ligne du dessus est un carré
                        Plateau[Ligne-i][j]=254;                                // ligne du dessus = '.' et ligne d'en dessous = carré
                        Plateau[Ligne-1-i][j]=46;
                      }
                }

            }
        }
}

void FREE (int* XY, char** Block, char**Plateau,char***Tab3D,int C,int Dim){
 int i,j;
free(XY);
for(i=0;i<Dim;i++){
    free (Block[i]);
}
free (Block);

for(i=0;i<C;i++){               //FREE TABLEAU 2D
    free (Plateau[i]);
}
free (Plateau);
for(i=0;i<5;i++){               //FREE TABLEAU 3D
    for(j=0;j<5;j++){
        free(Tab3D[i][j]);
    }
    free(Tab3D[i]);
}
free(Tab3D);
}

