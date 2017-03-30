/*////////////////////////////////////////////////////////////////////////////////////////////////////
 PROJET DU MINOTAURE PAR GIRLANDO MAURIZIO, DAMIEN VANSTIPPEN, DEBORAH VANSTIPPEN ET ALLOUBI HICHAM.
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "jeu.h"
#include "Affichage.h"


int main()
{
    int choix;
    int i,x,y;            // on declare un entier x et y
    char joueur = 'T';
    char touche;        // on declare un char touche
    srand(time(NULL));
    while(1)
    {
        FixePosCurseur(32,12);
        puts("CHARGEMENT\n"); // pseudo chargement
        attendre(3);          // qui dure 3 sec

        effaceEcran();      // efface l'ecran
        choix = choixMenu();    // on fait appel a la fonction qui renvoi le choix du menu

        if (choix == 'i')       // si choix => i
        {
            effaceEcran();      // on efface l'ecran
            puts("Bienvenue dans le jeu du labyrinthe du Minotaure\n"); // INTRODUCTION
            puts("Appuyez sur une touche pour revenir au menu principal");   // on demande d'appuyer sur enter
            choix = getch();            // on rentre la touche
        }
        if (choix == 'o')       // si choix => o
        {
            effaceEcran();      // on efface l'ecran
            puts("VOICI LES OPTIONS");  // ici faudra mettre les options EN COURS DE DEVELOPPEMENT
            puts("Appuyez sur une touche pour revenir au menu principal");   // on demande d'appuyer sur enter
            choix = getch();            // on rentre la touche
        }

        if (choix == 'n')       // si choix => n
        {
            effaceEcran();
            choix = selection();             // on efface l'ecran
            effaceEcran();
            FixePosCurseur(28,0);
            affichelaby(choix);             // affichage labyrinthe
            FixePosCurseur(0,22);        // on fixe le curseur tout en haut a gauche de la console
            printf("Utilisez les touches z pour monter, s pour descendre,\n q pour aller à gauche, d pour aller à droite et Esc pour revenir au menu principal\n\n\n");

            do // positionne aleatoirement notre heros
            {
                x = (rand() % (19 - 1 + 1) + 29);
                y = (rand() % (18 - 1 + 1) + 1);
                i = collision(x,y,choix);
            }
            while (i != 0);

            FixePosCurseur(x,y);        // on fixe le cusreur avec les valeurs qu'on a mis dans la ligne precedente
            printf("%c", joueur);                // on affiche la 1ere lettre de notre heros sur la position du curseur
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


                    if(touche == 27)
                    break;     // si on appuye sur Esc on casse et quitte

                    FixePosCurseur(x,y);        // pour chaque deplacement l'initiale du heros ce deplace egalement vers la direction qu'on a appuyer
                    printf("%c", joueur);

                    //FixePosCurseur(46,19);
                   // printf("M");

                    /*if (x == 46 && y == 19)
                    {
                        gameOver();
                        attendre(2);
                        break;
                    }*/
                }
            }



        /// Ici faudra rajouter : gestion du score, du déplacement du minotaure, de la rencontre Thésée et Ariane ou Thésée et le Minotaure (après déplacement de Thésée ou du minotaure)
        }
        if (choix == 27)
            return 0;
    }
}
