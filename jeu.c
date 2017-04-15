#include "jeu.h"
#include "Affichage.h"

// TIMER
void attendre(unsigned int secs)
{
    unsigned int retTime = time(0) + secs;   // prend le temps final.
    while (time(0) < retTime);               // boucle jusque obtenir le temps
}

int changementNom(char nom[20])
{

    effaceEcran();
    FixePosCurseur(36,19);
    printf("Veuillez choisir votre nom");
    FixePosCurseur(36,21);
    scanf("%s", nom);

    return nom;
}


// RENVOI UN CHOIX DU MENU
int choixMenu()
{
    FixePosCurseur(36,19);
    puts("-------MENU PRINCIPAL-------");
    FixePosCurseur(36,20);
    puts("============================");
    FixePosCurseur(36,21);
    puts("|   (i) INTRODUCTION       |");
    FixePosCurseur(36,22);
    puts("|   (n) NOUVELLE PARTIE    |");
    FixePosCurseur(36,23);
    puts("|   (o) OPTIONS            |");
    FixePosCurseur(36,24);
    puts("|   (Esc) QUITTER LE JEU   |");
    FixePosCurseur(36,25);
    puts("============================");

    char choix;

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
    FixePosCurseur(29,19);
    puts("------------VOICI LES OPTIONS-------------");
    FixePosCurseur(29,20);
    puts("==========================================");
    FixePosCurseur(29,21);
    puts("|  (h)   Changer le nom du heros         |");
    FixePosCurseur(29,22);
    puts("|  (p)   Changer le nom de la princesse  |");
    FixePosCurseur(29,23);
    puts("|  (Esc) Revenir au menu principal       |");
    FixePosCurseur(29,24);
    puts("==========================================");

    char choix;

    while (choix != 'h' && choix != 'p' && choix != 27)
    {
    choix = getch();
    }
    switch(choix)
    {
        case 'h':
            choix = 'h';
        break;

        case 'p':
            choix = 'p';
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
    Couleur(14,0);
    FixePosCurseur(33,23);
    puts("Veuillez choisir un mode de jeu");
    FixePosCurseur(32,24);
    puts("Defiler les modes avec (q) et (d)");
    FixePosCurseur(33,25);
    puts("(espace) pour valider le choix");
    Couleur(15,0);

    while (mode <= 3 && mode >= 1)
    {
        while (touche != 'q' || touche != 'd')
        {
            if (mode == 1)
            {
                FixePosCurseur(44,11);
                puts("Mode solo");
                FixePosCurseur(36,13);
                puts("Le minotaure ne bouge pas");
            }
            if (mode == 2)
            {
                FixePosCurseur(41,11);
                puts("Mode deux joueur");
                FixePosCurseur(34,13);
                puts("Un joueur incarne le minotaure");
            }
            if (mode == 3)
            {
                FixePosCurseur(42,11);
                puts("Mode contre IA");
                FixePosCurseur(25,13);
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
                Couleur(14,0);
                FixePosCurseur(33,23);
                puts("Veuillez choisir un mode de jeu");
                FixePosCurseur(32,24);
                puts("Defiler les modes avec (q) et (d)");
                FixePosCurseur(33,25);
                puts("(espace) pour valider le choix");
                Couleur(15,0);
            }
            if (touche == 'd')
            {
                if (mode == 3)
                {
                    break;
                }
                mode++;
                effaceEcran();
                Couleur(14,0);
                FixePosCurseur(33,23);
                puts("Veuillez choisir un mode de jeu");
                FixePosCurseur(32,24);
                puts("Defiler les modes avec (q) et (d)");
                FixePosCurseur(33,25);
                puts("(espace) pour valider le choix");
                Couleur(15,0);
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
