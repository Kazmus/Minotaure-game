#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "jeu.h"
#include "menu.h"
#include "Affichage.h"


int main()
{
    int choix;

    puts("CHARGEMENT\n"); // pseudo chargement
    attendre(3);          // qui dure 3 sec


        effaceEcran();      // efface l'ecran
        choix = choixMenu();    // on fait appel a la fonction qui renvoi le choix du menu

        if (choix == 'i')       // si choix => i
        {
            effaceEcran();      // on efface l'ecran
            puts("Bienvenue dans le jeu du labyrinthe du Minotaure\n"); // INTRODUCTION
            puts("Appuyez sur Enter pour revenir au menu principal");   // on demande d'appuyer sur enter
            choix = getch();            // on rentre la touche
            if (choix == 13)            // si choix => enter
            {
                effaceEcran();          // efface l'ecran
                choix = choixMenu();    // on fait appel a la fonction qui renvoi le choix du menu
            }
        }
        if (choix == 'o')       // si choix => o
        {
            effaceEcran();      // on efface l'ecran
            puts("VOICI LES OPTIONS");  // ici faudra mettre les options EN COURS DE DEVELOPPEMENT
        }

    if (choix == 'n')       // si choix => n
    {
        int i,x,y;            // on declare un entier x et y
        char touche;        // on declare un char touche

        effaceEcran();              // on efface l'ecran
        FixePosCurseur(0,0);
        affichelaby(x,y); // affichage labyrinthe
        FixePosCurseur(0,25);        // on fixe le curseur tout en haut a gauche de la console
        printf("Utilisez les touches z pour monter, s pour descendre,\n q pour aller à gauche, d pour aller à droite et Esc pour quitter\n\n\n"); //C'est ecrit dessus ce que ca veut dire



        x=10;y=10; // x => 10 et y => 10 temporaire A MODIFIER PAR LA SUITE UNE FOIS LE LABYRINTHE MIS

        FixePosCurseur(x,y);        // on fixe le cusreur avec les valeurs qu'on a mis dans la ligne precedente

        printf("T");                // on affiche la 1ere lettre de notre heros sur la position du curseur

        while(1)                       // tant que 1
        {
            if(kbhit())                 // si touche enfoncer
            {
                touche=getch();             // touche => touche qu'on appuye sans passer par enter
                if(touche == 'z')           // si touche => z
                {
                    y--;
                    i = collision(x,y);
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
                    i = collision(x,y);
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
                    i = collision(x,y);
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
                    i = collision(x,y);
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
                printf("T");


            }
        }

        /// Ici faudra rajouter : gestion du score, du déplacement du minotaure, de la rencontre Thésée et Ariane ou Thésée et le Minotaure (après déplacement de Thésée ou du minotaure)



    }

    return 0;
}
