#include "Affichage.h"
#include "labyrinthes.h"


//=====================================================================//
// Fonction qui positionne le curseur � l'emplacement x,y sur l'�cran  //
//                      construite � partir de conio.c                 //
//=====================================================================//
void FixePosCurseur(int x, int y)
{
    HANDLE Console=0;  // Stocke le num�ro de la console affich�e � l'�cran
    COORD  Point;      // G�re la position du curseur sur la console

    Point.Y = y;       // Fixe les coordonn�es du point
    Point.X = x;

    Console = GetStdHandle(STD_OUTPUT_HANDLE);         // R�cup�re le num�ro de console pour obtenir les infos de la console
    SetConsoleCursorPosition (Console, Point);         // Fixe la position du curseur sur la console
}


//=================================================================//
// Fonction qui fixe une couleur � l'emplacement du curseur        //
//                     construite � partir de conio.c              //
//=================================================================//
void Couleur(int CouleurCaractere, int CouleurFond)
{
    HANDLE Console=0;  // Stocke le num�ro de la console affich�e � l'�cran

    Console = GetStdHandle(STD_OUTPUT_HANDLE);           // R�cup�re le num�ro de console pour obtenir les infos de la console

    SetConsoleTextAttribute (Console , CouleurCaractere+(CouleurFond*16)); // Fixe la couleur du fond et la couleur du caract�re

///////////////////// A VOIR DEUXIEME SOLUTION ///////////////////////////
    void textattr(int _attr)
    {
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
    }

    void CouleurFondTexte(int _color)   // Change la couleur du fond d'�cran
    {
        CONSOLE_SCREEN_BUFFER_INFO Info ;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info) ;
        textattr((Info.wAttributes & 0x0F) | (_color<<4));
    }

    void CouleurTexte(int _color)      // Change la couleur du texte
    {
        CONSOLE_SCREEN_BUFFER_INFO Info ;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info) ;
        textattr((Info.wAttributes & 0xF0) | _color);
    }



}

//=========================================================================//
// Fonction qui vide l'�cran ( on remplit l'�cran avec une couleur noire)  //
//=========================================================================//


void effaceEcran()
{
    HANDLE Console=0;           // Stocke le num�ro de la console affich�e � l'�cran
    COORD  Point =  {0,0};      // G�re la position du curseur sur la console et choisi la position en haut � gauche extr�me (en dehors de l'�cran
    DWORD dwWritten, dwSize;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    Console=GetStdHandle (STD_OUTPUT_HANDLE);           // R�cup�re le num�ro de console pour obtenir les infos de la console

    if(GetConsoleScreenBufferInfo(Console, &Info))		// si on obtient les info concernant la console
    {

        // d�termine le nombre de caract�res total composant la console : nb caract�res sur une ligne * nb lignes
        dwSize = Info.dwSize.X * Info.dwSize.Y ;

        // remplit l'�cran avec des espaces en partant de la coordonn�e x=0 et y=0
        FillConsoleOutputCharacter (Console, ' ', dwSize, Point, &dwWritten);

        // Fixe la couleur de remplissage pour chaque caract�res de la console
        FillConsoleOutputAttribute (Console, Info.wAttributes, dwSize, Point, &dwWritten);

        // Place le curseur en haut � gauche
        FixePosCurseur(1, 1);
    }


        // ////////// Envoie la couleur d'un bloc
        FillConsoleOutputAttribute (Console, 15 + (0 << 4), 4000, (COORD) {0, 0}, &dwWritten);

        // //////////// remplit 4000 ' ' en partant de la coordonn�e x=0, y=0
        FillConsoleOutputCharacter (Console, ' ', 4000, (COORD) {0, 0}, &dwWritten);

        // Place le curseur en haut � gauche
        FixePosCurseur(1, 1);


}

//=========================================================================//
// Fonction qui permet de selectionner un labyrinthe en le faisant defiler //
//=========================================================================//

int selection()
{
    char choixDefilement,mur = 219;
    int defilement = 1,choix,x,y;

    // affiche les commandes
    Couleur(14,0);
    FixePosCurseur(35,25);
    puts("Veuillez choisir un labyrinthe");
    FixePosCurseur(31,26);
    puts("Defiler les labyrinthes avec (q) et (d)");
    FixePosCurseur(36,27);
    puts("ESPACE pour valider le choix");
    Couleur(15,0);

    while (defilement <= 10 && defilement >= 1) // tant que le defilement est plus petit ou egal a 10 et plus grand ou egal a 1
    {
        while (choixDefilement != 'q' || choixDefilement != 'd')  // et tant que on appuye pas sur les touches demander
        {
            // Pour chaque deplacement on verifie et affiche le tableau de ca valeur respective
            switch(defilement)
            {
                case 1:
                {
                    // on affiche le tableau
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y); // permet de afficher le tableau au centre de la console
                        for (x=0;x<=20;x++)
                        {
                            if (laby1[y][x] == 0)
                            printf(" ");
                            if (laby1[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 2:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby2[y][x] == 0)
                            printf(" ");
                            if (laby2[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 3:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby3[y][x] == 0)
                            printf(" ");
                            if (laby3[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 4:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby4[y][x] == 0)
                            printf(" ");
                            if (laby4[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 5:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby5[y][x] == 0)
                            printf(" ");
                            if (laby5[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 6:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby6[y][x] == 0)
                            printf(" ");
                            if (laby6[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 7:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby7[y][x] == 0)
                            printf(" ");
                            if (laby7[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 8:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby8[y][x] == 0)
                            printf(" ");
                            if (laby8[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 9:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby9[y][x] == 0)
                            printf(" ");
                            if (laby9[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 10:
                {
                    for (y=0;y<=19;y++)
                    {
                        FixePosCurseur(40,y);
                        for (x=0;x<=20;x++)
                        {
                            if (laby10[y][x] == 0)
                            printf(" ");
                            if (laby10[y][x] == 1)
                            printf("%c", mur);
                        }
                        printf("\n");
                    }
                    break;
                }
            }

            choixDefilement = getch();          // on defile avec les touches sans passer par enter

            switch(choixDefilement)
            {
                // GAUCHE
                case 'q':
                {
                    if (defilement == 1)        // si deja a 1 ne fait rien
                    {
                        break;
                    }
                    defilement--;               // on fait - 1 dans la variable
                    effaceEcran();
                    Couleur(14,0);              // on re-affiche les commandes pour chaque deplacment
                    FixePosCurseur(35,25);
                    puts("Veuillez choisir un labyrinthe");
                    FixePosCurseur(31,26);
                    puts("Defiler les labyrinthes avec (q) et (d)");
                    FixePosCurseur(36,27);
                    puts("ESPACE pour valider le choix");
                    FixePosCurseur(0,0);
                    Couleur(15,0);
                    break;
                }
                // DROITE
                case 'd':
                {
                    if (defilement == 10)       // si deja a 10 ne fait rien
                    {
                        break;
                    }
                    defilement++;               // on fait + 1 dans la variable
                    effaceEcran();
                    Couleur(14,0);              // on re-affiche les commandes pour chaque deplacment
                    FixePosCurseur(35,25);
                    puts("Veuillez choisir un labyrinthe");
                    FixePosCurseur(31,26);
                    puts("Defiler les labyrinthes avec (q) et (d)");
                    FixePosCurseur(36,27);
                    puts("ESPACE pour valider le choix");
                    FixePosCurseur(0,0);
                    Couleur(15,0);
                    break;
                }
                case 32:                        // on valide le choix avec ESPACE
                {
                    choix = defilement;
                    effaceEcran();
                  //  FixePosCurseur(0,0);
                    return choix;
                }
            }
        }
    }
}

//=========================================================================//
// Fonction qui verifie s'il y a un obstacle et retourne la valeur 0 ou 1  //
//=========================================================================//

int collision(int x,int y,int i) // on prend en parametre les coordonnes x,y et le choix(i) du labyrinthe qu'on avait choisi auparavant
{
    int obstacle;
    x = x - 40; // on fait comme si les labyrinthe etaient aux coordonnees 0,0 pour nous faciliter la tache

    switch(i)   // en fonction du labyrinthe qu'on avait choisi, on verifie les murs du labyrinthe concerner
    {
        case 1:
        {
            if (laby1[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby1[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 2:
        {
            if (laby2[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby2[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 3:
        {
            if (laby3[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby3[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 4:
        {
            if (laby4[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby4[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 5:
        {
            if (laby5[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby5[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 6:
        {
            if (laby6[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby6[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 7:
        {
            if (laby7[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby7[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 8:
        {
            if (laby8[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby8[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 9:
        {
            if (laby9[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby9[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
        case 10:
        {
            if (laby10[y][x] == 0)
            {
                obstacle = 0;
            }
            if (laby10[y][x] == 1)
            {
                obstacle = 1;
            }
            break;
        }
    }
    return obstacle; // on retourne 0 si pas de mur ou 1 si c'est le cas
}

//=========================================================================//
//                Fonction qui affiche le labyrinthe choisi                //
//=========================================================================//

void affichelaby(int i) // on prend en parametre le choix qu'on a fait au prealable
{
    int x,y,laby[hauteurLaby][largeurLaby]; // on va creer un tableau qui servira pour l'affichage
    char mur = 219;

    switch(i)    // en fonction du labyrinthe qu'on avait choisi, on copie le labyrinthe choisi dans un tableau vide qu'on a declarer avant avec la meme taille
    {
        case 1:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby1[y][x];
                }
            }
            break;
        }
        case 2:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby2[y][x];
                }
            }
            break;
        }
        case 3:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby3[y][x];
                }
            }
            break;
        }
        case 4:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby4[y][x];
                }
            }
            break;
        }
        case 5:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby5[y][x];
                }
            }
            break;
        }
        case 6:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby6[y][x];
                }
            }
            break;
        }
        case 7:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby7[y][x];
                }
            }
            break;
        }
        case 8:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby8[y][x];
                }
            }
            break;
        }
        case 9:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby9[y][x];
                }
            }
            break;
        }
        case 10:
        {
            for (y=0;y<=19;y++)
            {
                for (x=0;x<=20;x++)
                {
                    laby[y][x] = laby10[y][x];
                }
            }
            break;
        }
    }

    for (y=0;y<=19;y++)             // une fois qu'on a copier le tableau choisi on l'affiche
    {
        FixePosCurseur(40,y);       // on centre le tableau
        for (x=0;x<=20;x++)
        {
            if (laby[y][x] == 0)
            printf(" ");
            if (laby[y][x] == 1)
            printf("%c", mur);
        }
        printf("\n");
    }
}

//=========================================================================//
//                      Fonction qui affiche la defaite                    //
//=========================================================================//

void gameOver()
{
    effaceEcran();
    afficheMino2();
    attendre(3);
    effaceEcran();
    FixePosCurseur(46,22);
    printf("GAME OVER");
}

//=========================================================================//
//                     Fonction qui affiche la victoire                    //
//=========================================================================//

void win()
{
    effaceEcran();
    afficheHPwin();
}

//=========================================================================//
//                   Fonction qui affiche l'introduction                   //
//=========================================================================//

void introHistoire()
{
    char touche;

    FixePosCurseur(27,19);
    printf("Il y avait fort longtemps, dans un pays lointain,");
    attendre(2);
    FixePosCurseur(39,20);
    printf("Une ravissante princesse.");
    attendre(2);
    FixePosCurseur(19,21);
    printf("Elle etait aimee par le peuple de par sa beaute et sa gentillesse.");
    attendre(2);
    FixePosCurseur(19,22);
    printf("Malheureusement, la princesse aimee de tous, fut un jour kidnappe!");
    attendre(2);
    FixePosCurseur(17,23);
    printf("Le rois eprit d'une grande tristesse demanda a de valeureux chevalier,");
    attendre(2);
    FixePosCurseur(36,24);
    printf("De bien vouloir sauve sa fille.");
    attendre(2);
    FixePosCurseur(21,25);
    printf("Un jeune chevalier, qui aimait la princesse de tout son coeur,");
    attendre(2);
    FixePosCurseur(28,26);
    printf("Demanda au Roi ou etait emprisonnee sa bien-aimee.");
    attendre(2);
    FixePosCurseur(17,27);
    printf("Ma precieuse fille a ete emmenee par le vil Minautore, disait le roi,");
    attendre(2);
    FixePosCurseur(36,28);
    printf("Tu la trouvera dans sa demeure.");
    attendre(2);
    FixePosCurseur(20,29);
    printf("Mais prend garde jeune heros sa demeure est un vrai labyrinthe");
    attendre(2);

    Couleur(14,0);
    FixePosCurseur(19,31);
    printf("Veuillez appuyez sur la touche ESC pour revenir au menu principal");
    Couleur(15,0);

    while (touche != 27)    // permet de revenir au menu principal en appuyant sur Escape
    {
        touche = getch();
        if (touche == 27)
            break;
    }
}

//=========================================================================//
//                       Fonction qui affiche le score                     //
//=========================================================================//

void afficheScore(int nombrePas)  // on prend en parametre le nombre de pas total
{
    int score = 0;

    score = nombrePas;
    FixePosCurseur(30,26);
    printf("Vous avez sauve la princesse en %d pas",score);
}

//=========================================================================//
//         Fonction qui affiche le superbe et terrifiant minotaure         //
//=========================================================================//

void afficheMino()
{

puts("  MMMM                                                                                       MMMM  ");
puts(" :MMMM                                                                                       MMMMH ");
puts(" MMMMM                                                                                       MMMMM ");
puts(" MMMMM                                                                                       MMMMM ");
puts(" MMMMM                                                                                       MMMMM ");
puts(".MMMMMH                                                                                     :MMMMM:");
puts(".MMMMMM                                                                                     MMMMMMI");
puts(" MMMMMMH                                                                                   IMMMMMM ");
puts(" MMMMMMM                              .MMMMMM .MMMMM. MMMMMM.                              MMMMMMM ");
puts(" MMMMMMMM              MMMMMM  MM  IMMMMMMMMMMMMMMMMMMMMMMMMMMMI  MM  MMMMMM.             MMMMMMMM ");
puts(" IMMMMMMMM:          MMMMMMMMMM MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMM          :MMMMMMMMM ");
puts("  MMMMMMMMMMMM   IMMMMMMMMMMMMMM MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMH   MMMMMMMMMMMM  ");
puts("   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   ");
puts("   .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMHMMMMMMMMMMMMMHMMMMMMM MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:   ");
puts("     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM     ");
puts("      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMIMMMMMMMMMMMMMMMMMMMMMMMMMMMHMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.     ");
puts("       .MMMMMMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMMMMMMMMMM:       ");
puts("         .MMMMMMMMMMMMMMMM.   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHMMMMM   .MMMMMMMMMMMMMMMM:         ");
puts("            MMMMMMMMM            MMMMMM MMMMMMMMMMMMMMMMMMM MMMMMM            MMMMMMMMM            ");
puts("                                MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                                ");
puts("                               .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:                               ");
puts("                                 IMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMI                                 ");
puts("                                 MMM       MMMMMMMMMMMMM       MMM                                 ");
puts("                               MMMM         MMMMMMMMMMM         MMMM                               ");
puts("                              MMMMMM       MMMMMMMMMMMMM       MMMMMM                              ");
puts("                              MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                              ");
puts("                               MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                               ");
puts("                               MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                               ");
puts("                               MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMI                               ");
puts("                              MM MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM MM                              ");
puts("                              MMM MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM MMM                              ");
puts("                              MMMM MMMMMMMMMMMMMMMMMMMMMMMMMMMMM.MMMM                              ");
puts("                             MMMMMM MMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMM                             ");
puts("                             MMMMMMM.MMMM MMMMMMMMMMMMMMM.MMMM MMMMMMM                             ");
puts("                            MMMMMMMMM.MM MMMMMMMMMMMMMMMMM.MM MMMMMMMMM                            ");
puts("                            MMMM MMMMMMMMMMIMMMMMMMMMMM:MMMM:MMMMM MMMM                            ");
puts("                           MMMMMHMMMMMM.MMMMMMMMMMMMMMMMHMM.MMMMMMIMMMMM                           ");
puts("                          MMMMMMM MMMMMMMMMMMMMMMMMMMMMMMMMHMMMMM.MMMMMMM                          ");
puts("                        MMMMMMMMM.MMMMM:MM MMMMMMMMMMMMM MM.MMMMM MMMMMMMMM.                       ");
puts("                      .MMMMMMMMMMMIMMMM.MM.MMMMMMMMMMMMM.MM MMMMMMMMMMMMMMMM.                      ");
puts("                    MMMMMMMMMMMMMM MMMM MMMMMMMMMMMMMMMMMMM MMMM.MMMMMMMMMMMMMM                    ");
puts("                ..MMMMMMMMMMMMMMMMM:MMMM:MM MMMMMMMMMMM MMHMMMMHMMMMMMMMMMMMMMMMM.                 ");
puts("              MMMMMMMMMMMMMMMMMMMMM MMMMMMMMM IMMMMMI MMMMMMMMM MMMMMMMMMMMMMMMMMMMMM              ");
puts("        .MMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMM.MMMMMMMMMMMMM MMMMM MMMMMMMMMMMMMMMMMMMMMMMMMMM.        ");
puts("MMMMM.    MMMMMMMMMMMMMMMMMMM MMMMMM.MMMMMMMMMMMMMMMMMMMHMMMMM.MMMMMM MMMMMMMMMMMMMMMMMMM    .MMMMM");
puts("MMMMMMMMM  :MMMMMMMMMMMMMMMMMMM MMMMM MMIMMMMMMMMMMMMMMMMMMMM MMMMM MMMMMMMMMMMMMMMMMMMH  IMMMMMMMM");
puts("MMMMMMMMMM..MMMMMMMMMMMMMMMMMMMM MMMMM MMMMM.MMMMMMMMM.MMMMM MMMMM MMMMMMMMMMMMMMMMMMMM. MMMMMMMMMM");
puts("MMMMMMMMMMM MMMMMMMMMMMMMMMMMMMMMM MMMIMMMMMMM MMMMM MMMMMMM:MMM.MMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMM");


                                        // J'ai mis un effet special qui illumine les yeux du minotaure
attendre(3);
Couleur(0,4);
FixePosCurseur(36,22);
puts("       ");
FixePosCurseur(35,23);
puts("         ");
FixePosCurseur(36,24);
puts("       ");

FixePosCurseur(56,22);
puts("       ");
FixePosCurseur(55,23);
puts("         ");
FixePosCurseur(56,24);
puts("       ");

Couleur(15,0);
attendre(2);

}

void afficheHero()
{
    Couleur(10,0);
    puts("              .:I:MM.");
    puts("             MMMMI:HMH");
    puts("              MM:M MMM");
    puts("               MH:.:MM");
    puts("                :HMMM:H");
    puts("               MMMMMMMMHM");
    puts("              MMIMMMMMM");
    puts("            MMMMMMMMMMHM");
    puts("         HMMMMMMMMMMM :I");
    puts("        MMMMMMMMMIMM. I:");
    puts("        MMMMMMMMMMMMMMMI.");
    puts("         MMMMMMMMMMMMMMM.");
    puts("          MMMMMMMMMMM: MI.");
    puts("          .MMMMMMM MI:   I .");
    puts("           .M I:H .MH   . I .");
    puts("               ::. M:I     .:");
    puts("              MMMM MMMM");
    puts("               MMM .MMMM");
    puts("             .MMM  MMMM");
    puts("             MHHMMM  MMM");
    puts("            MMMM    MMMM");
    Couleur(15,0);
}

void affichePrincesse()
{
    Couleur(13,0);
    FixePosCurseur(66,3);
    puts("                 MMMI");
    FixePosCurseur(66,4);
    puts("                .HI:M");
    FixePosCurseur(66,5);
    puts("               IMM:.M");
    FixePosCurseur(66,6);
    puts("              MMIM:. .");
    FixePosCurseur(66,7);
    puts("             .I .IH:HII");
    FixePosCurseur(66,8);
    puts("               :.IHMMHM :I");
    FixePosCurseur(66,9);
    puts("               I. MMMMIM");
    FixePosCurseur(66,10);
    puts("             .I   MMH:");
    FixePosCurseur(66,11);
    puts("            ::  HIHM::");
    FixePosCurseur(66,12);
    puts("         .:H   MI:.::H");
    FixePosCurseur(66,13);
    puts("          .   .:..:::I");
    FixePosCurseur(66,14);
    puts("              ..:.HMM:");
    FixePosCurseur(66,15);
    puts("             ..:.:IHM.");
    FixePosCurseur(66,16);
    puts("           . .:..HIIM");
    FixePosCurseur(66,17);
    puts("         .  .:...I:I:");
    FixePosCurseur(66,18);
    puts("     I:..  :....IHHI.");
    FixePosCurseur(66,19);
    puts("     . . ::.  .::II:");
    FixePosCurseur(66,20);
    puts("     :HI...: .I:II::");
    FixePosCurseur(66,21);
    puts("      I..:.. .:H:.....");
    FixePosCurseur(66,22);
    puts("     ..:I:...I:  .I.:::...");
    FixePosCurseur(66,23);
    puts("      ...::IIIHHHHHI:....");
    Couleur(15,0);
}

void afficheMino2()
{
    FixePosCurseur(27,10);
    puts("    ...:                          M.");
    FixePosCurseur(27,11);
    puts("   H..M                             M.M");
    FixePosCurseur(27,12);
    puts("  :...                               M..");
    FixePosCurseur(27,13);
    puts("  :...                               M..:");
    FixePosCurseur(27,14);
    puts("  I...:                              M...");
    FixePosCurseur(27,15);
    puts("  :.....H.                         .M..:I");
    FixePosCurseur(27,16);
    puts("  M.:......MMMMMH                 M:....:");
    FixePosCurseur(27,17);
    puts("   :M:....MMMMMMMMMMMMMMMMM......H....I.M");
    FixePosCurseur(27,18);
    puts("    HM:..:MMMMMMMMMMMMMMMMH..........M.:");
    FixePosCurseur(27,19);
    puts("   M. IM.MMMMMMMMMMMMMMMMMM.....:.I.:HM");
    FixePosCurseur(27,20);
    puts("    MMMMMMMMMMMMMMMMMMMMMMMMM..IH.M:M    M");
    FixePosCurseur(27,21);
    puts("     MMMMMMMMMMMMMMMMMMMMMMMMH:MMMMMM:HMMM");
    FixePosCurseur(27,22);
    puts("      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
    FixePosCurseur(27,23);
    puts("       MMMMMHHMMMMMMM..MMHMHMMMMMMMMMMMM.");
    FixePosCurseur(27,24);
    puts("       .MMMMMMMMMMMMMMMMMMMHMMMMMMMMMM");
    FixePosCurseur(27,25);
    puts("      MMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
    FixePosCurseur(27,26);
    puts("     MMMMMHMMMMMMMMMMMMMMMMMHM");
    FixePosCurseur(27,27);
    puts("     IMMMMMMHIMMMMMMMMMMMMMMMM");
    FixePosCurseur(27,28);
    puts("    :HMMMMMMMIIMMM:IHMMMMMMMMM");
    FixePosCurseur(27,29);
    puts("    IMMMMMMMMIIMM:.MMMMMMMMMM");
    FixePosCurseur(27,30);
    puts("    IIM..:.MM:HM..MHHMMMMMMM");
    FixePosCurseur(27,31);
    puts("    MIII...:IIM.:HHHHMMMMMM");
    FixePosCurseur(27,32);
    puts("      MIMMMIMM..:IIHH:MMMM");
    FixePosCurseur(27,33);
    puts("HA             .:MIIM.MMMM");
    FixePosCurseur(27,34);
    puts("  HA          .:MMIM.IMMM.");
    FixePosCurseur(27,35);
    puts("    HA        M:MIM:MMMMM");
    FixePosCurseur(27,36);
    puts("      HA      :.:.:HIMMMM");
    FixePosCurseur(27,37);
    puts("        HA    MMMMMMMMMM");
}

void afficheHPwin()
{
    Couleur(10,0);
    FixePosCurseur(27,1);
    puts("          HIHI::::");
    Couleur(10,0);
    FixePosCurseur(27,2);
    puts("      IIIIH::::II::");
    Couleur(10,0);
    FixePosCurseur(27,3);
    puts("     IIIH::I::...I:::");
    Couleur(13,0);
    FixePosCurseur(48,3);
    puts("     IIIII");
    Couleur(10,0);
    FixePosCurseur(27,4);
    puts("    IIIII::II.:I:.:I .");
    Couleur(13,0);
    FixePosCurseur(49,4);
    puts("  HIIHIIIII");
    Couleur(10,0);
    FixePosCurseur(27,5);
    puts("    IIII:::I:...I..:. :");
    Couleur(13,0);
    FixePosCurseur(49,5);
    puts(" ..HIIHIHIIII");
    Couleur(10,0);
    FixePosCurseur(27,6);
    puts("    IIII:I::I:.....");
    Couleur(13,0);
    FixePosCurseur(46,6);
    puts("    .M..IIHIIIIHH");
    Couleur(10,0);
    FixePosCurseur(27,7);
    puts("   .IIIHII.I:.....");
    Couleur(13,0);
    FixePosCurseur(45,7);
    puts("    ..:..I.:. HII:");
    Couleur(10,0);
    FixePosCurseur(27,8);
    puts("   HIIHMH:..:::..:");
    Couleur(13,0);
    FixePosCurseur(45,8);
    puts("     .....IH.:HIIII");
    Couleur(10,0);
    FixePosCurseur(27,9);
    puts("   HIIII:.....:..");
    Couleur(13,0);
    FixePosCurseur(44,9);
    puts("     I....I:IHIIIIH");
    Couleur(10,0);
    FixePosCurseur(27,10);
    puts(" IIIIIIH ..:.:.:");
    Couleur(13,0);
    FixePosCurseur(43,10);
    puts("       ..::I...IIIII");
    Couleur(10,0);
    FixePosCurseur(27,11);
    puts("IIIIIH. IHHHHI.I");
    Couleur(13,0);
    FixePosCurseur(43,11);
    puts("        II:....:IIII:");
    Couleur(10,0);
    FixePosCurseur(27,12);
    puts("IIII    IIIIIIIHH");
    Couleur(13,0);
    FixePosCurseur(44,12);
    puts("       I I ....:IHII:");
    Couleur(10,0);
    FixePosCurseur(27,13);
    puts("I      HIIIIIIIHIH");
    Couleur(13,0);
    FixePosCurseur(45,13);
    puts("      H . .::II.MIIII");
    Couleur(10,0);
    FixePosCurseur(27,14);
    puts("...    IIIIIIIIIIII");
    Couleur(13,0);
    FixePosCurseur(46,14);
    puts("     . I.I:::II:MIIHI");
    Couleur(10,0);
    FixePosCurseur(27,15);
    puts("  .....IIIIIIIIIIIM");
    Couleur(13,0);
    FixePosCurseur(46,15);
    puts("     M H.::::II: HIIIII");
    Couleur(10,0);
    FixePosCurseur(27,16);
    puts("...   .IIHIIIIHIIII");
    Couleur(13,0);
    FixePosCurseur(46,16);
    puts("     . IHHHIIIII: HHHHII");
    Couleur(10,0);
    FixePosCurseur(27,17);
    puts(" ......IIIMIIIIHIHIH");
    Couleur(13,0);
    FixePosCurseur(47,17);
    puts("    MI.IH:::::H: .HHHIII");
    Couleur(10,0);
    FixePosCurseur(27,18);
    puts(" ..   ..IIIMIIIIMHIHH");
    Couleur(13,0);
    FixePosCurseur(48,18);
    puts("   ::I::::HH::.  IHMHHIHII");
    Couleur(10,0);
    FixePosCurseur(27,19);
    puts("     ..  IIIIIHMIHHHI..");
    Couleur(13,0);
    FixePosCurseur(49,19);
    puts(".I::.:H:::IH.    :MMMHIHH");
    Couleur(10,0);
    FixePosCurseur(27,20);
    puts("         IIIMM:..:.I.  ");
    Couleur(13,0);
    FixePosCurseur(50,20);
    puts(".:I:HHIMMMIII           HMH");
    Couleur(10,0);
    FixePosCurseur(27,21);
    puts("          HIIII....H.I..");
    Couleur(13,0);
    FixePosCurseur(51,21);
    puts("  I:I:I..  I             HI");
    Couleur(10,0);
    FixePosCurseur(27,22);
    puts("           IIIHH......");
    Couleur(13,0);
    FixePosCurseur(47,22);
    puts(" ....::II.  .II.             .");
    Couleur(10,0);
    FixePosCurseur(27,23);
    puts("          IIIMHHH........");
    Couleur(13,0);
    FixePosCurseur(52,23);
    puts("  .:III   II::::.          .");
    Couleur(10,0);
    FixePosCurseur(27,24);
    puts("          IIIIIIH....HMM");
    Couleur(13,0);
    FixePosCurseur(51,24);
    puts("   ..I. . .HI    ::..:.     :");
    Couleur(15,0);
}
