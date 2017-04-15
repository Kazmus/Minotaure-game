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
    system("mode con lines=50 cols=100");     //Change la taille de la console

    // Declaration de divers variables qu'on utilisera dans le main
    int choix,choix2,mode,nombrePas = 0;    // Variables pour les differend retour de choix ainsi que le nombre de pas initialiser a 0
    int i,x,y,x2,y2,x3,y3;           // Les differentes coordonnees pour chaque personnage du jeu ainsi que un i pour la collision
    char joueur[15] = "Thesee",minotaure = 'M',princesse[15] = "Arianne";       // Creation de tableau pour les noms des perso sauf le minotaure qui garde juste son initial
    char touche;        // On declare une variable touche pour les appel de clavier
    srand(time(NULL));      // On initialise la fonction rand
    afficheMino();          // On affiche un jolie minotaure

    while(1)
    {

        effaceEcran();      // efface l'ecran
        choix = choixMenu();    // on fait appel a la fonction qui renvoi le choix du menu

        switch (choix)
        {
            case 'i':       // si choix => i
            {
                effaceEcran();      // on efface l'ecran
                introHistoire();    // on affiche la jolie introduction
                effaceEcran();      // on efface l'ecran
                break;
            }

            case 'o':      // si choix => o
            {
                while(1)        // permet de revenir dans les options apres un choix
                {
                    effaceEcran();      // on efface l'ecran
                    choix2 = choixOptions();      // on affiche les options et on renvoi le choix

                    if (choix2 == 'h')          //si choix ==> h
                    {
                        joueur[15] = changementNom(joueur);     //on fait appel a la fonction qui permet de changer le nom et on le retourne
                    }
                    if (choix2 == 'p')          //si choix ==> p
                    {
                        princesse[15] = changementNom(princesse);       //on fait appel a la fonction qui permet de changer le nom et on le retourne
                    }
                    if (choix2 == 27)       // si choix ==> 27 (escape)
                        break;              // on casse
                }
                break;          // et on revient au menu principal
            }

            case 'n':       // si choix => n
            {
                effaceEcran();              // on efface l'ecran
                mode = choixMode();         // choix du mode
                effaceEcran();              // on efface l'ecran
                choix = selection();        // choix du labyrinthe
                effaceEcran();              // on efface l'ecran
                affichelaby(choix);         // affichage du labyrinthe d'apres le choix

                FixePosCurseur(11,1);       // on fixe le curseur sur la console
                printf("|-- %s --|", joueur);       // et on affiche le nom du joueur(hero)
                FixePosCurseur(72,1);       // on fixe le curseur sur la console
                printf("|-- %s --|", princesse);    // et on affiche le nom de la princesse

                FixePosCurseur(0,3);
                afficheHero();
                affichePrincesse();

                Couleur(14,0);              // on met une couleur jaune pour tout ce qui est informations pour l'utilisateur
                FixePosCurseur(41,24);      // on affiche en bas du labyrinthe les instructions de jeu et si on a choisi le mode deux joueur affiche egalement des info supplementaires
                puts("---Commandes hero---");
                FixePosCurseur(23,25);
                puts("Utilisez les touches (z) pour monter, (s) pour descendre");
                FixePosCurseur(26,26);
                puts("(q) pour aller à gauche, (d) pour aller à droite");
                FixePosCurseur(32,28);
                puts("(Esc) pour revenir au menu principal");
                if (mode == 2)
                {
                    FixePosCurseur(38,30);
                    puts("---Commandes minotaure---");
                    FixePosCurseur(23,31);
                    puts("Utilisez les touches (i) pour monter, (k) pour descendre");
                    FixePosCurseur(26,32);
                    puts("(j) pour aller à gauche, (l) pour aller à droite");
                }

                // positionnement aleatoire des differends personnages
                do
                {
                    do // positionne aleatoirement notre heros
                    {
                        x = (rand() % (20 + 1) + 40);
                        y = (rand() % (19 + 1));
                        i = collision(x,y,choix);   // on verifie s'il y a un mur
                    }
                    while (i != 0); // si mur vrai on recommance

                    do // positionne aleatoirement notre minotaure
                    {
                        x2 = (rand() % (20 + 1) + 40);
                        y2 = (rand() % (19 + 1));
                        i = collision(x2,y2,choix); // on verifie s'il y a un mur
                    }
                    while (i != 0); // si mur vrai on recommance

                    do // positionne aleatoirement notre princesse
                    {
                        x3 = (rand() % (20 + 1) + 40);
                        y3 = (rand() % (19 + 1));
                        i = collision(x3,y3,choix); // on verifie s'il y a un mur
                    }

                    while (i != 0); // si mur vrai on recommance
                }
                while ((x == x2 && y == y2) || (x == x3 && y == y3) || (x2 == x3 && y2 ==y3)); // jusqua ce que les differents personnages ne sont pas sur la meme case

                // on affiche la 1ere lettre de chaque personnages
                Couleur(10,0);              // on lui donne une couleur vert clair
                FixePosCurseur(x,y);        // on prend les coordonnes generer aleatoirement au prealable et on fixe le curseur
                printf("%c", joueur[0]);    // on prend 1ere valeur du tableau joueur(hero)

                Couleur(12,0);              // on lui donne une couleur rouge clair
                FixePosCurseur(x2,y2);      // on prend les coordonnes generer aleatoirement au prealable et on fixe le curseur
                printf("%c", minotaure);

                Couleur(13,0);              // on donnne une couleur magenta
                FixePosCurseur(x3,y3);      // on prend les coordonnes generer aleatoirement au prealable et on fixe le curseur
                printf("%c", princesse[0]); // on prend 1ere valeur du tableau princesse

                Couleur(15,0);              // on remet la couleur par defaut

                while(1)                       // tant que vrai
                {
                    if(kbhit())                 // si touche enfoncer
                    {
                        //DELACEMENT JOUEUR UN peu importe quel mode------------------------------------///////////////////////////////////////////////////
                        do
                        {
                            do  // on repete jusqua ce que une des touches demander na pas ete appuyer
                            {
                                touche=getch();      // touche => touche qu'on appuye sans passer par enter
                            }
                            while(touche != 'z' && touche != 's' && touche != 'q' && touche != 'd' && touche != 27);

                            switch(touche)
                            {
                                //touche HAUT
                                case 'z':            // si touche => z
                                {
                                    // on verifie s'il y a un obstacle
                                    y--;
                                    i = collision(x,y,choix);
                                    y++;
                                    if(i == 0)  // si pas d'obstacle le personnage avance sinon ne fait rien
                                    {
                                        FixePosCurseur(x,y);
                                        printf(" ");    // on met un vide sur la case avant que le personnage n'avance
                                        y--;
                                        nombrePas++;    // on rajoute + 1 pour chaque case
                                    }
                                    break;  // on sort de la boucle et on passe le tour
                                }
                                //touche BAS
                                case 's':           // si touche => s
                                {
                                    // on verifie s'il y a un obstacle
                                    y++;
                                    i = collision(x,y,choix);
                                    y--;
                                    if(i == 0)  // si pas d'obstacle le personnage avance sinon ne fait rien
                                    {
                                        FixePosCurseur(x,y);
                                        printf(" ");    // on met un vide sur la case avant que le personnage n'avance
                                        y++;
                                        nombrePas++;    // on rajoute + 1 pour chaque case
                                    }
                                    break;  // on sort de la boucle et on passe le tour
                                }
                                //touche GAUCHE
                                case 'q':           // si touche => q
                                {
                                    // on verifie s'il y a un obstacle
                                    x--;
                                    i = collision(x,y,choix);
                                    x++;
                                    if(i == 0)  // si pas d'obstacle le personnage avance sinon ne fait rien
                                    {
                                        FixePosCurseur(x,y);
                                        printf(" ");    // on met un vide sur la case avant que le personnage n'avance
                                        x--;
                                        nombrePas++;    // on rajoute + 1 pour chaque case
                                    }
                                    break;  // on sort de la boucle et on passe le tour
                                }
                                // touche DROITE
                                case 'd':           // si touche => d
                                {
                                    // on verifie s'il y a un obstacle
                                    x++;
                                    i = collision(x,y,choix);
                                    x--;
                                    if(i == 0)  // si pas d'obstacle le personnage avance sinon ne fait rien
                                    {
                                        FixePosCurseur(x,y);
                                        printf(" ");    // on met un vide sur la case avant que le personnage n'avance
                                        x++;
                                        nombrePas++;    // on rajoute + 1 pour chaque case
                                    }
                                    break;  // on sort de la boucle et on passe le tour
                                }

                                case 27:
                                break;     // si on appuye sur Escape on casse
                            }
                        }
                        while (i == 1);    // repete tant que obstacle vrai

                        if (touche == 27)   // et on casse de nouveau et on reviens au menu principal
                            break;

                        if (x == x2 && y == y2)     // si la position est la meme que le minotaure
                        {
                            gameOver();             // on affiche GAME OVER et on casse apres 2 sec pour revenir au menu principal
                            attendre(2);
                            break;
                        }

                        if (x == x3 && y == y3)     // si la position est la meme que la princesse
                        {
                            win();                  // on affiche la victoire
                            afficheScore(nombrePas);// et on affiche le nombre de pas
                            nombrePas = 0;          // on remet le nombre de pas a 0 si jamais on recommance la partie
                            attendre(5);            // attend 5 sec avant de revenir au menu principal
                            break;
                        }

                        // on re-affiche l'initial du personnage apres le deplacement si aucune des conditions anterieur etait vrai
                        Couleur(10,0);
                        FixePosCurseur(x,y);
                        printf("%c", joueur[0]);
                        Couleur(15,0);

                        //MODE DEUX JOUEURS---------------------------------------------------////////////////////////////////////////////////////////////
                        //DEPLACEMENT JOUEUR DEUX---------------------------------------------////////////////////////////////////////////////////////////
                        if (mode == 2)
                        {
                            do
                            {
                                do  // on repete jusqua ce que une des touches demander na pas ete appuyer
                                {
                                touche=getch();         // touche => touche qu'on appuye sans passer par enter
                                }
                                while(touche != 'i' && touche != 'k' && touche != 'j' && touche != 'l' && touche != 27);

                                switch(touche)
                                {
                                    // touche HAUT
                                    case 'i':          // si touche => i
                                    {
                                        // on verifie s'il y a un obstacle
                                        y2--;
                                        i = collision(x2,y2,choix);
                                        y2++;
                                        if(i == 0)  // si pas d'obstacle le personnage avance sinon ne fait rien
                                        {
                                            FixePosCurseur(x2,y2);    // on fait y - 1 a chaque fois qu'on appuye sur z
                                            printf(" ");    // on met un vide sur la case avant que le personnage n'avance
                                            y2--;
                                        }
                                        break;  // on sort de la boucle et on passe le tour
                                    }
                                    // touche BAS
                                    case 'k':           // si touche => k
                                    {
                                        // on verifie s'il y a un obstacle
                                        y2++;
                                        i = collision(x2,y2,choix);
                                        y2--;
                                        if(i == 0)  // si pas d'obstacle le personnage avance sinon ne fait rien
                                        {
                                            FixePosCurseur(x2,y2);    // on fait y + 1 a chaque fois qu'on appuye sur z
                                            printf(" ");    // on met un vide sur la case avant que le personnage n'avance
                                            y2++;
                                        }
                                        break;  // on sort de la boucle et on passe le tour
                                    }
                                    // touche GAUCHE
                                    case 'j':           // si touche => j
                                    {
                                        // on verifie s'il y a un obstacle
                                        x2--;
                                        i = collision(x2,y2,choix);
                                        x2++;
                                        if(i == 0)  // si pas d'obstacle le personnage avance sinon ne fait rien
                                        {
                                            FixePosCurseur(x2,y2);    // on fait x - 1 a chaque fois qu'on appuye sur z
                                            printf(" ");    // on met un vide sur la case avant que le personnage n'avance
                                            x2--;
                                        }
                                        break;  // on sort de la boucle et on passe le tour
                                    }
                                    // touche DROITE
                                    case 'l':           // si touche => l
                                    {
                                        // on verifie s'il y a un obstacle
                                        x2++;
                                        i = collision(x2,y2,choix);
                                        x2--;
                                        if(i == 0)  // si pas d'obstacle le personnage avance sinon ne fait rien
                                        {
                                            FixePosCurseur(x2,y2);    // on fait x + 1 a chaque fois qu'on appuye sur z
                                            printf(" ");    // on met un vide sur la case avant que le personnage n'avance
                                            x2++;
                                        }
                                        break;  // on sort de la boucle et on passe le tour
                                    }

                                    case 27:
                                        break;     // si on appuye sur Esc on casse et quitte
                                }
                            }
                            while(i == 1);  // repete tant que obstacle vrai

                            if(touche == 27)
                            break;     // si on appuye sur Esc on casse et quitte

                            // si le joueur minotaure arrive sur la position du heros affiche GAME OVER avant de revenir au menu principal
                            if (x == x2 && y == y2)
                            {
                                gameOver();
                                attendre(2);
                                break;
                            }

                            // on re-affiche l'initial du personnage apres le deplacement si aucune des conditions anterieur etait vrai
                            Couleur(12,0);
                            FixePosCurseur(x2,y2);
                            printf("%c", minotaure);
                            Couleur(15,0);
                        }

                        //MODE CONTRE IA------------------------------------------------------////////////////////////////////////////////////////////////
                        //DEPLACEMENT IA------------------------------------------------------////////////////////////////////////////////////////////////
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
