#include "jeu.h"
#include "Affichage.h"

// TIMER
void attendre(unsigned int secs)
{
    unsigned int retTime = time(0) + secs;   // prend le temps final.
    while (time(0) < retTime);               // boucle jusque obtenir le temps
}


// RENVOI UN CHOIX DU MENU
int choixMenu()
{
    FixePosCurseur(25,10);
    puts("===========================\n");
    FixePosCurseur(25,11);
    puts("|  (I) INTRODUCTION       |\n");
    FixePosCurseur(25,12);
    puts("|  (N) NOUVELLE PARTIE    |\n");
    FixePosCurseur(25,13);
    puts("|  (O) OPTIONS            |\n");
    FixePosCurseur(25,14);
    puts("|  (Esc) QUITTER LE JEU   |\n");
    FixePosCurseur(25,15);
    puts("===========================\n\n");

    int choix;

    while (choix != 'i' && choix != 'n' && choix != 'o' && choix != 27)
    {
    choix = getch();
    }
    switch(choix)
    {
        case 'i':
        break;

        case 'n':
        break;

        case 'o':
        break;

        case 27:
        break;
    }
    return choix;
}

int choixOptions()
{
    FixePosCurseur(19,9);
    puts("------------VOICI LES OPTIONS-------------");
    FixePosCurseur(19,10);
    puts("==========================================");
    FixePosCurseur(19,11);
    puts("|  (H)   Changer le nom du heros         |");
    FixePosCurseur(19,12);
    puts("|  (P)   Changer le nom de la princesse  |");
    FixePosCurseur(19,13);
    puts("|  (M)   Choix du mode de jeu            |");
    FixePosCurseur(19,14);
    puts("|  (Esc) Revenir au menu principal       |");
    FixePosCurseur(19,15);
    puts("==========================================");

    int choix;

    while (choix != 'h' && choix != 'p' && choix != 'm' && choix != 27)
    {
    choix = getch();
    }
    switch(choix)
    {
        case 'h':
        break;

        case 'p':
        break;

        case 'm':
        break;

        case 27:
        break;
    }
    effaceEcran();
    return choix;
}

int choixMode()
{
    int mode = 1,modeChoisi;
    char touche;

    FixePosCurseur(22,21);
    puts("Veuillez choisir un mode de jeu");
    FixePosCurseur(21,22);
    puts("deplacer les modes avec (q) et (d)");
    FixePosCurseur(22,23);
    puts("(espace) pour valider le choix");

    while (mode <= 3 && mode >= 1)
    {
        while (touche != 'q' || touche != 'd')
        {
            if (mode == 1)
            {
                FixePosCurseur(33,11);
                puts("Mode solo");
                FixePosCurseur(25,12);
                puts("Le minotaure ne bouge pas");
            }
            if (mode == 2)
            {
                FixePosCurseur(30,11);
                puts("Mode deux joueur");
                FixePosCurseur(23,12);
                puts("Un joueur incarne le minotaure");
            }
            if (mode == 3)
            {
                FixePosCurseur(30,11);
                puts("Mode contre IA");
                FixePosCurseur(13,12);
                puts("Une intelligence artificiel incarne le minotaure");
            }

            touche = getch();
            if (touche == 'q')
            {
                if (mode == 1)
                {
                    break;
                }
                mode--;
                effaceEcran();
                FixePosCurseur(22,21);
                puts("Veuillez choisir un mode de jeu");
                FixePosCurseur(21,22);
                puts("deplacer les modes avec (q) et (d)");
                FixePosCurseur(22,23);
                puts("(espace) pour valider le choix");
            }
            if (touche == 'd')
            {
                if (mode == 3)
                {
                    break;
                }
                mode++;
                effaceEcran();
                FixePosCurseur(22,21);
                puts("Veuillez choisir un mode de jeu");
                FixePosCurseur(21,22);
                puts("deplacer les modes avec (q) et (d)");
                FixePosCurseur(22,23);
                puts("(espace) pour valider le choix");
            }
            if (touche == 32)
            {
                modeChoisi = mode;
                effaceEcran();
                return modeChoisi;
            }
        }
    }
}


