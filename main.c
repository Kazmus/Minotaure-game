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
    system("mode con lines=50 cols=100");
    int choix,choix2,mode,nombrePas = 0;
    int i,x,y,x2,y2,x3,y3;            // on declare un entier x et y
    char joueur[20] = "Thesee",minotaure = 'M',princesse[20] = "Arianne";
    char touche;        // on declare un char touche
    srand(time(NULL));
    afficheMino();

    while(1)
    {

        effaceEcran();      // efface l'ecran
        choix = choixMenu();    // on fait appel a la fonction qui renvoi le choix du menu

        switch (choix)
        {
            case 'i':       // si choix => i
            {
                effaceEcran();      // on efface l'ecran
                introHistoire();
                effaceEcran();
                break;
            }

            case 'o':      // si choix => o
            {
                while(1)
                {
                    effaceEcran();      // on efface l'ecran
                    choix2 = choixOptions();

                    if (choix2 == 'h')
                    {
                        joueur[20] = changementNom(joueur);
                    }
                    if (choix2 == 'p')
                    {
                        princesse[20] = changementNom(princesse);
                    }
                    if (choix2 == 27)
                        break;
                }
                break;
            }

            case 'n':       // si choix => n
            {
                effaceEcran();
                mode = choixMode();
                effaceEcran();
                choix = selection();             // on efface l'ecran
                effaceEcran();
                affichelaby(choix);             // affichage labyrinthe
                FixePosCurseur(15,0);
                printf("%s", joueur);
                FixePosCurseur(76,0);
                printf("%s", princesse);
                Couleur(14,0);
                FixePosCurseur(23,25);        // on fixe le curseur tout en haut a gauche de la console
                puts("Utilisez les touches (z) pour monter, (s) pour descendre");
                FixePosCurseur(26,26);
                puts("(q) pour aller à gauche, (d) pour aller à droite");
                FixePosCurseur(32,27);
                puts("(Esc) pour revenir au menu principal");

                do
                {
                    do // positionne aleatoirement notre heros
                    {
                        x = (rand() % (20 + 1) + 40);
                        y = (rand() % (19 + 1));
                        i = collision(x,y,choix);
                    }
                    while (i != 0);

                    do // positionne aleatoirement notre minotaure
                    {
                        x2 = (rand() % (20 + 1) + 40);
                        y2 = (rand() % (19 + 1));
                        i = collision(x2,y2,choix);
                    }
                    while (i != 0);

                    do // positionne aleatoirement notre princesse
                    {
                        x3 = (rand() % (20 + 1) + 40);
                        y3 = (rand() % (19 + 1));
                        i = collision(x3,y3,choix);
                    }

                    while (i != 0);
                }
                while ((x == x2 && y == y2) || (x == x3 && y == y3) || (x2 == x3 && y2 ==y3));

                Couleur(10,0);
                FixePosCurseur(x,y);        // on fixe le cusreur avec les valeurs qu'on a mis dans la ligne precedente
                printf("%c", joueur[0]);                // on affiche la 1ere lettre de notre heros sur la position du curseur
                Couleur(15,0);

                Couleur(12,0);
                FixePosCurseur(x2,y2);
                printf("%c", minotaure);
                Couleur(15,0);

                Couleur(13,0);
                FixePosCurseur(x3,y3);
                printf("%c", princesse[0]);
                Couleur(15,0);


                FixePosCurseur(0,0);

                while(1)                       // tant que 1
                {
                    if(kbhit())                 // si touche enfoncer
                    {
                        //DELACEMENT JOUEUR UN peu importe quel mode------------------------------------/////////////////////////////////////////////////////////////////////////////////////
                        do
                        {
                            do
                            {
                                touche=getch();             // touche => touche qu'on appuye sans passer par enter
                            }
                            while(touche != 'z' && touche != 's' && touche != 'q' && touche != 'd' && touche != 27);

                            switch(touche)
                            {
                                case 'z':          // si touche => z
                                {
                                    y--;
                                    i = collision(x,y,choix);
                                    y++;
                                    if(i == 0)
                                    {
                                        FixePosCurseur(x,y);    // on fait y - 1 a chaque fois qu'on appuye sur z
                                        printf(" ");
                                        y--;
                                        nombrePas++;
                                    }
                                    break;
                                }
                                case 's':
                                {
                                    y++;
                                    i = collision(x,y,choix);
                                    y--;
                                    if(i == 0)
                                    {
                                        FixePosCurseur(x,y);    // on fait y + 1 a chaque fois qu'on appuye sur z
                                        printf(" ");
                                        y++;
                                        nombrePas++;
                                    }
                                    break;
                                }
                                case 'q':
                                {
                                    x--;
                                    i = collision(x,y,choix);
                                    x++;
                                    if(i == 0)
                                    {
                                        FixePosCurseur(x,y);    // on fait x - 1 a chaque fois qu'on appuye sur z
                                        printf(" ");
                                        x--;
                                        nombrePas++;
                                    }
                                    break;
                                }
                                case 'd':
                                {
                                    x++;
                                    i = collision(x,y,choix);
                                    x--;
                                    if(i == 0)
                                    {
                                        FixePosCurseur(x,y);    // on fait x + 1 a chaque fois qu'on appuye sur z
                                        printf(" ");
                                        x++;
                                        nombrePas++;
                                    }
                                    break;
                                }

                                case 27:
                                break;     // si on appuye sur Esc on casse et quitte
                            }
                        }
                        while (i == 1);

                        if (touche == 27)
                            break;

                        if (x == x2 && y == y2)
                        {
                            gameOver();
                            attendre(2);
                            break;
                        }

                        if (x == x3 && y == y3)
                        {
                            win();
                            afficheScore(nombrePas);
                            nombrePas = 0;
                            attendre(5);
                            break;
                        }

                        Couleur(10,0);
                        FixePosCurseur(x,y);        // pour chaque deplacement l'initiale du heros ce deplace egalement vers la direction qu'on a appuyer
                        printf("%c", joueur[0]);
                        Couleur(15,0);

                        //MODE DEUX JOUEURS---------------------------------------------------/////////////////////////////////////////////////////////////////////////
                        //DEPLACEMENT JOUEUR DEUX---------------------------------------------/////////////////////////////////////////////////////////////////////////
                        if (mode == 2)
                        {
                            do
                            {
                                do
                                {
                                touche=getch();             // touche => touche qu'on appuye sans passer par enter
                                }
                                while(touche != 'i' && touche != 'k' && touche != 'j' && touche != 'l' && touche != 27);

                                switch(touche)
                                {
                                    case 'i':          // si touche => z
                                    {
                                        y2--;
                                        i = collision(x2,y2,choix);
                                        y2++;
                                        if(i == 0)
                                        {
                                            FixePosCurseur(x2,y2);    // on fait y - 1 a chaque fois qu'on appuye sur z
                                            printf(" ");
                                            y2--;
                                        }
                                        break;
                                    }
                                    case 'k':
                                    {
                                        y2++;
                                        i = collision(x2,y2,choix);
                                        y2--;
                                        if(i == 0)
                                        {
                                            FixePosCurseur(x2,y2);    // on fait y + 1 a chaque fois qu'on appuye sur z
                                            printf(" ");
                                            y2++;
                                        }
                                        break;
                                    }
                                    case 'j':
                                    {
                                        x2--;
                                        i = collision(x2,y2,choix);
                                        x2++;
                                        if(i == 0)
                                        {
                                            FixePosCurseur(x2,y2);    // on fait x - 1 a chaque fois qu'on appuye sur z
                                            printf(" ");
                                            x2--;
                                        }
                                        break;
                                    }
                                    case 'l':
                                        {
                                        x2++;
                                        i = collision(x2,y2,choix);
                                        x2--;
                                        if(i == 0)
                                        {
                                            FixePosCurseur(x2,y2);    // on fait x + 1 a chaque fois qu'on appuye sur z
                                            printf(" ");
                                            x2++;
                                        }
                                        break;
                                    }

                                    case 27:
                                        break;     // si on appuye sur Esc on casse et quitte
                                }
                            }
                            while(i == 1);

                            if(touche == 27)
                            break;     // si on appuye sur Esc on casse et quitte

                            if (x == x2 && y == y2)
                            {
                                gameOver();
                                attendre(2);
                                break;
                            }


                            Couleur(12,0);
                            FixePosCurseur(x2,y2);
                            printf("%c", minotaure);
                            Couleur(15,0);
                        }

                        //MODE CONTRE IA------------------------------------------------------/////////////////////////////////////////////////////////////////////////
                        //DEPLACEMENT IA------------------------------------------------------/////////////////////////////////////////////////////////////////////////
                        if (mode == 3)
                        {
                            do
                            {
                                if(y < y2)           // si touche => z
                                {
                                    y2--;
                                    i = collision(x2,y2,choix);
                                    y2++;
                                    if(i == 0)
                                    {
                                        FixePosCurseur(x2,y2);    // on fait y - 1 a chaque fois qu'on appunye sur z
                                        printf(" ");
                                        y2--;
                                    }
                                }
                                if(y > y2)
                                {
                                    y2++;
                                    i = collision(x2,y2,choix);
                                    y2--;
                                    if(i == 0)
                                    {
                                        FixePosCurseur(x2,y2);    // on fait y + 1 a chaque fois qu'on appuye sur z
                                        printf(" ");
                                        y2++;
                                    }
                                }
                                if(x < x2)
                                {
                                    x2--;
                                    i = collision(x2,y2,choix);
                                    x2++;
                                    if(i == 0)
                                    {
                                        FixePosCurseur(x2,y2);    // on fait x - 1 a chaque fois qu'on appuye sur z
                                        printf(" ");
                                        x2--;
                                    }
                                }
                                if(x > x2)
                                {
                                    x2++;
                                    i = collision(x2,y2,choix);
                                    x2--;
                                    if(i == 0)
                                    {
                                        FixePosCurseur(x2,y2);    // on fait x + 1 a chaque fois qu'on appuye sur z
                                        printf(" ");
                                        x2++;
                                    }
                                }
                            }
                            while (i == 1);

                            if (x == x2 && y == y2)
                            {
                                gameOver();
                                attendre(2);
                                break;
                            }
                            Couleur(12,0);
                            FixePosCurseur(x2,y2);
                            printf("%c", minotaure);
                            Couleur(15,0);
                        }
                    }
                }
                break;
            }
            case 27:
            {
                return 0;
            }
            break;
        }
    }
}
