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
    switch(choix)
    {
        case 'i':
        break;

        case 'n':
        break;

        case 'o':
        break;

        case 27:
        return 0;
        break;
    }
    return choix;
}

int score(int round)
{
    round++;
    return round;
}

void afficheScore(int round)
{
    if(round == 3)
    {
        effaceEcran();
        printf("GAME OVER");
    }
}
