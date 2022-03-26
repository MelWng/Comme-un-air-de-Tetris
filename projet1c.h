#ifndef PROJET1C_H_INCLUDED
#define PROJET1C_H_INCLUDED
#endif // PROJET1C_H_INCLUDED
#include <time.h>

char** creer_tab2D_dyn(int L,int C);
void AfficheP(char**tab, int L, int C);
char** Losange(char**tabL,int L,int C);
char** Triangle(char**tabT, int L, int C);
char** Cercle(char**tabC, int L, int C);
char*** Blocs_tab ();
char** afficherBloc(char***tab3D, int TabB[],int N,int Dim, int Choix);
int DeposeB(int *XY, char**Plateau, char**Block,int Dim);
int *Coordonnees( char** Plateau);
int Etat_LC(char ** Plateau,int L, int C);
void SupprimeL(char ** Plateau, int C,int Ligne);
void Decaler_lignes(char ** Plateau, int C, int Ligne);
void FREE (int* XY, char** Block, char**Plateau,char***Tab3D,int C,int Dim);
