#include "jeu.h"
#include "Affichage.h"

//=========================================================================//
//            Fonction qui fait attendre X temps en seconde                //
//=========================================================================//

void attendre(unsigned int secs)    // on prend en parametre la ou les seconde(s)
{
    unsigned int retTime = time(0) + secs;   // prend le temps final.
    while (time(0) < retTime);               // boucle jusqua obtenir le temps
}

//=========================================================================//
//         Fonction qui permet de changer le nom des personnages           //
//=========================================================================//

int changementNom(char nom[15])     // on prend en parametre le personnage concerner
{

    effaceEcran();
    FixePosCurseur(20,19);
    printf("Veuillez saisir votre nom et appuyer sur Enter pour valider");
    FixePosCurseur(36,21);
    scanf("%s", nom);               // on saisi au clavier le nom et on appuye sur enter

    return nom; // retourne le nom
}

//=========================================================================//
//            Fonction qui affiche et retourne le choix du menu            //
//=========================================================================//

int choixMenu()
{
    // affiche menu
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

    while (choix != 'i' && choix != 'n' && choix != 'o' && choix != 27) // tant que la touche n'est pas celle demander
    {
    choix = getch();  // on appuye sans passer par enter et on met la valeur dans la variable
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

//=========================================================================//
//          Fonction qui affiche et retourne le choix des options          //
//=========================================================================//

int choixOptions()
{
    // affiche le menu des options
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

    while (choix != 'h' && choix != 'p' && choix != 27) // tant que la touche n'est pas celle demander
    {
    choix = getch();    // on appuye sans passer par enter et on met la valeur dans la variable
    }
    switch(choix)
    {
        case 'h':
        break;

        case 'p':
        break;

        case 27:
        break;
    }
    return choix;   // on retourne le choix
}

//=========================================================================//
//       Fonction qui affiche et defile les differents modes de jeux       //
//=========================================================================//
int choixMode()
{
    int mode = 1,modeChoisi;
    char touche;

    // on affiche les commandes
    Couleur(14,0);
    FixePosCurseur(33,23);
    puts("Veuillez choisir un mode de jeu");
    FixePosCurseur(32,24);
    puts("Defiler les modes avec (q) et (d)");
    FixePosCurseur(33,25);
    puts("(espace) pour valider le choix");
    Couleur(15,0);

    while (mode <= 3 && mode >= 1)  // tant que le plus petit ou egal a 3 et plus grand ou egal a 1
    {
        while (touche != 'q' || touche != 'd') // et tant que on appuye sur les touches concerner
        {
            switch(mode)    // on affiche les differend modes respectifs en fonction de la valeur actuel
            {
                case 1:
                {
                    FixePosCurseur(44,11);
                    puts("Mode solo");
                    FixePosCurseur(36,13);
                    puts("Le minotaure ne bouge pas");
                    break;
                }
                case 2:
                {
                    FixePosCurseur(41,11);
                    puts("Mode deux joueur");
                    FixePosCurseur(34,13);
                    puts("Un joueur incarne le minotaure");
                    break;
                }
                case 3:
                {
                    FixePosCurseur(42,11);
                    puts("Mode contre IA");
                    FixePosCurseur(25,13);
                    puts("Une intelligence artificiel incarne le minotaure");
                    break;
                }
            }

            touche = getch();   // On appuye sur la touche sans passer par Enter

            switch(touche)
            {
                //GAUCHE
                case 'q':
                {
                    if (mode == 1)  // si mode deja a 1 ne fait rien
                    {
                        break;
                    }
                    mode--;         // mode - 1
                    effaceEcran();
                    Couleur(14,0);          // on re-affiche les instructions
                    FixePosCurseur(33,23);
                    puts("Veuillez choisir un mode de jeu");
                    FixePosCurseur(32,24);
                    puts("Defiler les modes avec (q) et (d)");
                    FixePosCurseur(33,25);
                    puts("(espace) pour valider le choix");
                    Couleur(15,0);
                    break;
                }
                //DROITE
                case 'd':
                {
                    if (mode == 3)  // si mode deja a 3 ne fait rien
                    {
                        break;
                    }
                    mode++;         // mode + 1
                    effaceEcran();
                    Couleur(14,0);          // on re-affiche les instructions
                    FixePosCurseur(33,23);
                    puts("Veuillez choisir un mode de jeu");
                    FixePosCurseur(32,24);
                    puts("Defiler les modes avec (q) et (d)");
                    FixePosCurseur(33,25);
                    puts("(espace) pour valider le choix");
                    Couleur(15,0);
                    break;
                }
                case 32:            // on appuye sur ESPACE pour valider le modeChoisi actuel
                {
                    modeChoisi = mode;
                    effaceEcran();
                    return modeChoisi;
                }
            }
        }
    }
}
