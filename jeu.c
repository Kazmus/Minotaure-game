#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "jeu.h"
#include "menu.h"

// TIMER
void attendre(unsigned int secs)
{
    unsigned int retTime = time(0) + secs;   // prend le temps final.
    while (time(0) < retTime);               // boucle jusque obtenir le temps
}

// AFFICHAGE DU MENU
void afficheMenu()
{
    puts("===========================\n");
    puts(" |  (I) INTRODUCTION       |\n");
    puts(" |  (N) NOUVELLE PARTIE    |\n");
    puts(" |  (O) OPTIONS            |\n");
    puts(" |  (Esc) QUITTER LE JEU   |\n");
    puts(" ===========================\n\n");
}

// RENVOI UN CHOIX DU MENU
int choixMenu()
{
    int choix;

    while (choix != 'i' && choix != 'n' && choix != 'o' && choix != 27)
    {
    choix = getch();
    }
    if (choix == 'i')
    puts("HELLO");
    return choix;

    if (choix == 'n')
    puts("GAME");
    return choix;

    if (choix == 'o')
    puts("OPTION");
    return choix;

    if (choix == 27)
    puts("BYE BYE");
    return 0;
}
