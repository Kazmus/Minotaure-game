#include "jeu.h"

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




