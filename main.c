/*////////////////////////////////////////////////////////////////////////////////////////////////////
  PROJET DU MINOTAURE PAR GIRLANDO MAURIZIO, VANSTIPPEN DAMIEN, VANSTIPPEN DEBORAH ET ALLOUBI HICHAM
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Affichage.h"
#include "jeu.h"

int main()
{
    int choix,mode,option;
    int i,j,k,x,y;            // on declare un entier x et y
    char joueur = 'T',minotaure = 'M';
    char touche;        // on declare un char touche
    srand(time(NULL));

    while(1)
    {
        FixePosCurseur(32,12);
        puts("CHARGEMENT"); // pseudo chargement
        //attendre(3);          // qui dure 3 sec

        effaceEcran();      // efface l'ecran
        choix = choixMenu();    // on fait appel a la fonction qui renvoi le choix du menu

        if (choix == 'i')       // si choix => i
        {
            effaceEcran();      // on efface l'ecran
            puts("Bienvenue dans le jeu du labyrinthe du Minotaure"); // INTRODUCTION
            puts("Appuyez sur une touche pour revenir au menu principal");   // on demande d'appuyer sur enter
            choix = getch();            // on rentre la touche
            effaceEcran();
        }
        if (choix == 'o')       // si choix => o
        {
            effaceEcran();      // on efface l'ecran
            option = choixOptions();
            if (option == 'm')
            {
            mode = choixMode();
            }
        }

        if (choix == 'n')       // si choix => n
        {
            effaceEcran();
            choix = selection();             // on efface l'ecran
            effaceEcran();
            FixePosCurseur(28,0);
            affichelaby(choix);             // affichage labyrinthe
            FixePosCurseur(11,21);        // on fixe le curseur tout en haut a gauche de la console
            puts("Utilisez les touches (z) pour monter, (s) pour descendre");
            FixePosCurseur(14,22);
            puts("(q) pour aller à gauche, (d) pour aller à droite");
            FixePosCurseur(20,23);
            puts("(Esc) pour revenir au menu principal");

            while (x != j && y != k)
            {
                do // positionne aleatoirement notre heros
                {
                    x = (rand() % (19 - 1 + 1) + 29);
                    y = (rand() % (18 - 1 + 1) + 1);
                    i = collision(x,y,choix);
                }
                while (i != 0);

                do // positionne aleatoirement notre minotaure
                {
                    j = (rand() % (19 - 1 + 1) + 29);
                    k = (rand() % (18 - 1 + 1) + 1);
                    i = collision(x,y,choix);
                }
                while (i != 0);
            }

            FixePosCurseur(x,y);        // on fixe le cusreur avec les valeurs qu'on a mis dans la ligne precedente
            printf("%c", joueur);                // on affiche la 1ere lettre de notre heros sur la position du curseur

            FixePosCurseur(j,k);
            printf("%c", minotaure);

            FixePosCurseur(0,0);

            while(1)                       // tant que 1
            {
                if(kbhit())                 // si touche enfoncer
                {
                    touche=getch();             // touche => touche qu'on appuye sans passer par enter
                    if(touche == 'z')           // si touche => z
                    {
                        y--;
                        i = collision(x,y,choix);
                        y++;
                        if(i == 0)
                        {
                            FixePosCurseur(x,y);    // on fait y - 1 a chaque fois qu'on appuye sur z
                            printf(" ");
                            y--;
                        }
                    }
                    if(touche == 's')
                    {
                        y++;
                        i = collision(x,y,choix);
                        y--;
                        if(i == 0)
                        {
                            FixePosCurseur(x,y);    // on fait y + 1 a chaque fois qu'on appuye sur z
                            printf(" ");
                            y++;
                        }
                    }
                    if(touche == 'q')
                    {
                        x--;
                        i = collision(x,y,choix);
                        x++;
                        if(i == 0)
                        {
                            FixePosCurseur(x,y);    // on fait x - 1 a chaque fois qu'on appuye sur z
                            printf(" ");
                            x--;
                        }
                    }
                    if(touche == 'd')
                    {
                        x++;
                        i = collision(x,y,choix);
                        x--;
                        if(i == 0)
                        {
                            FixePosCurseur(x,y);    // on fait x + 1 a chaque fois qu'on appuye sur z
                            printf(" ");
                            x++;
                        }
                    }
                    if (x == j && y == k)
                    {
                        gameOver();
                        attendre(2);
                        break;
                    }

                    if(touche == 27)
                    break;     // si on appuye sur Esc on casse et quitte



                    FixePosCurseur(x,y);        // pour chaque deplacement l'initiale du heros ce deplace egalement vers la direction qu'on a appuyer
                    printf("%c", joueur);

                    if (mode == 2)
                    {
                        touche=getch();             // touche => touche qu'on appuye sans passer par enter
                        if(touche == 'z')           // si touche => z
                        {
                            k--;
                            i = collision(j,k,choix);
                            k++;
                            if(i == 0)
                            {
                                FixePosCurseur(j,k);    // on fait y - 1 a chaque fois qu'on appuye sur z
                                printf(" ");
                                k--;
                            }
                        }
                        if(touche == 's')
                        {
                            k++;
                            i = collision(j,k,choix);
                            k--;
                            if(i == 0)
                            {
                                FixePosCurseur(j,k);    // on fait y + 1 a chaque fois qu'on appuye sur z
                                printf(" ");
                                k++;
                            }
                        }
                        if(touche == 'q')
                        {
                            j--;
                            i = collision(j,k,choix);
                            j++;
                            if(i == 0)
                            {
                                FixePosCurseur(j,k);    // on fait x - 1 a chaque fois qu'on appuye sur z
                                printf(" ");
                                j--;
                            }
                        }
                        if(touche == 'd')
                        {
                            j++;
                            i = collision(j,k,choix);
                            j--;
                            if(i == 0)
                            {
                                FixePosCurseur(j,k);    // on fait x + 1 a chaque fois qu'on appuye sur z
                                printf(" ");
                                j++;
                            }
                        }
                   // FixePosCurseur(j,k);
                   // printf("M");
                    }
                }
            }



        /// Ici faudra rajouter : gestion du score, du déplacement du minotaure, de la rencontre Thésée et Ariane ou Thésée et le Minotaure (après déplacement de Thésée ou du minotaure)
        }
        if (choix == 27)
            return 0;
    }
}
