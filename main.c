#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define VALEUR_INIT 0
#include <string.h>
#define TOUCHE -1
#define RATE -2
#include "fichierScoresGrilles.h"

int bateauCoule(int grilleBateaux[][10],int numeroBateau);
int plusBateaux(int grilleBateaux[][10]);
void afficheGrille(char grille[][10]);
int menu();
void scores();
void aide();
void login(char pseudo[10]);
void initTabChar(char grilleVide[][10]);
void initTabInt(int grilleBateaux[][10]);

int main()
{
    lireScores();


    int numeroBateau;
    int nombreCoups = VALEUR_INIT;
    int a,b;
    int ligne,colonne;
    int choixMenu = VALEUR_INIT;
    int choixQuitter;
    int quitter = 1;
    char pseudo[10]="";
    char grilleVide[10][10];
    int grilleBateaux[10][10];/*= {{0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,1,1,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0}};*/

    initTabChar(grilleVide);
    initTabInt(grilleBateaux);

//Ceci est un commentaire 2


do{

    //Affichage du menu et choix joueur
    choixMenu=menu();
            system("cls");

    switch (choixMenu){

    case 1 :
        if(strlen(pseudo)==0){
            login(pseudo);
        }
        else{
        printf ("\nBONNE CHANCE !\n\n ");// Fonction jouer à la bataille navale
        nombreCoups=0;
        initTabChar(grilleVide);
        initTabInt(grilleBateaux);
        grilleBateaux[0][0]=2;
        grilleBateaux[0][1]=2;
        grilleBateaux[0][2]=3;
        grilleBateaux[0][3]=3;
        grilleBateaux[0][4]=3;


        do{

            afficheGrille(grilleVide);
            nombreCoups++;

            printf("\t\t\t\tA vous de jouer : %s",pseudo);// Affiche le pseudo dans la fenêtre de jeu
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\tVotre nombre d'essais : %d\n\n",nombreCoups);
            printf("\nEntrez la colonne svp :");
            scanf("%d",&colonne);// Choix de la ligne
            printf("\nEntrez la ligne svp :");
            scanf("%d",&ligne);//Choix de la colonne

            //si touché
            if (grilleBateaux[ligne][colonne]>0){

                grilleVide[ligne][colonne]='x';
                numeroBateau=grilleBateaux[ligne][colonne];
                grilleBateaux[ligne][colonne]=TOUCHE;
                system("cls");
                afficheGrille(grilleVide);
                printf("\nTouche");
            if (bateauCoule(grilleBateaux,numeroBateau)==1){
                printf(" Coule");
            }

            }
            else if(grilleBateaux[ligne][colonne]<0){
                printf("Vous avez deja vise ici\n");
                Sleep(2000);
            }
            else{
                grilleVide[ligne][colonne]='o';
                grilleBateaux[ligne][colonne]=RATE;
                printf("\nRate");
            }
            fflush(stdin);


            Sleep(1000);
            system("cls");


        }while ( (plusBateaux(grilleBateaux)==0) && (nombreCoups<40));
        if (nombreCoups>40){
            printf("Dommage pour cette fois\n");
        }
        else
            printf("Bravo ! Belle victoire\n");

        Sleep(3000);
        system("cls");
        fflush(stdin);

    }
    break;
    case 2 :
    login(pseudo);
        break;
    case 3 :
        aide();

        break;
    case 4 :
      Scores();

        break;
    case 5 :
        printf ("\nAu revoir\n");// Quitter le jeux
        quitter = 1;

    default :
        break;

    }
    fflush(stdin);

}while(choixMenu!=5);

    return EXIT_SUCCESS;
}
void afficheGrille(char grille[][10]){
    int i,j;// Variable de la grille
    printf("\n     0   1   2   3   4   5   6   7   8   9");
    printf("\n   |---|---|---|---|---|---|---|---|---|---|");
    for (i=0;i<10;i++){
        printf ("\n  %d| ",i);
        for (j=0;j<10;j++){
            printf("%c | ", grille[i][j]);
        }
       printf("\n   |---|---|---|---|---|---|---|---|---|---|");
    }

}
int menu() {
    int choixMenu;
    printf ("\t\t\t\t\t\t ===============\n");
    printf ("\t\t\t\t\t\t Bataille navale \n");
    printf ("\t\t\t\t\t\t ===============\n");
    printf ("\t\t\t\t\t\t    BIENVENUE \n");
    printf ("\n\n");
    printf ("\t\t\t\t1.Jouer ");
    printf ("2.Login ");
    printf ("3 Aide ");
    printf ("4.Scores ");
    printf ("5.Quitter ");
    printf ("\nVotre choix : ");
    fflush(stdin);
    scanf ("%d",&choixMenu);
    fflush(stdin);
    return choixMenu;
}
/** \brief
 *
 * \param pseudo[10] char
 * \return void
 *
 */
void login(char pseudo[10]){
    int choixQuitter=0;
        do{
            printf ("IDENTIFICATION\n");// Identifiant joueur   ATTENTION finir de gerer les erreur !!!!!!!!!!
            printf ("Votre identifiant : ");
            scanf ("%s",pseudo);
            printf ("\nBonne chance :D : %s\n",pseudo);
            printf("\n\nCela vous convient ?\n Oui = 1\n Non = 2\n");
            scanf("%d",&choixQuitter);
            system("cls");}
        while(choixQuitter!=1);
        choixQuitter=0;
}
void Scores(){
    int choixQuitter=0;
    do{
        printf ("\nSCORES\n");// Scores précédents
        printf("\n\nRetour au menu ?\n Oui = 1\n Non = 2\n");
            scanf("%d",&choixQuitter);
            system("cls");}
        while(choixQuitter!=1);
        choixQuitter=0;

}
void aide(){
    int choixQuitter=0;
    do{
        printf ("\nAIDE\n");// Aide du jeux
        printf ("\nLes regles du jeu sont les suivantes :\n");
        printf ("\n1. Vous devez couler tout les bateaux de la grille\n");
        printf ("\n2. Vous devez entrer le choix de la colonne et le choix de la ligne\n");
        printf ("\n3. Vous avez 50 tentatives max pour couler tout les bateaux: Touche = x | Rate = o\n");
        printf ("\n4. Si vous n'y parvenez pas en 40 tentatives c'est perdu !\n");
        printf ("\n\nVous avez tout compris ?\nOui = 1\nNon = 2\n");
        scanf("%d",&choixQuitter);
        fflush(stdin);
        system("cls");
        }while (choixQuitter!=1);
        choixQuitter=0;
}

int plusBateaux(int grilleBateaux[][10]){
    int x,y;
    for (x=0;x<10;x++){
        for(y=0;y<10;y++){
            if(grilleBateaux[x][y]>0)return 0;
        }
    }
    return 1;
}
void initTabChar(char grilleVide[][10]){
    for (int a=0;a<10;a++){
        for (int b=0;b<10;b++)
           grilleVide[a][b]=' ';
    }
}
void initTabInt(int grilleBateaux[][10]){
    for (int a=0;a<10;a++){
        for (int b=0;b<10;b++)
           grilleBateaux[a][b]=0;
    }
}
int bateauCoule(int grilleBateaux[][10],int numeroBateau){
    int x,y;
    for (x=0;x<10;x++){
        for(y=0;y<10;y++){
            if(grilleBateaux[x][y] == numeroBateau)return 0;
        }
    }
    return 1;
}

