#include "Affichage.h"
#include "labyrinthes.h"


//=====================================================================//
// Fonction qui positionne le curseur à l'emplacement x,y sur l'écran  //
//                      construite à partir de conio.c                 //
//=====================================================================//
void FixePosCurseur(int x, int y)
{
    HANDLE Console=0;  // Stocke le numéro de la console affichée à l'écran
    COORD  Point;      // Gére la position du curseur sur la console

    Point.Y = y;       // Fixe les coordonnées du point
    Point.X = x;

    Console = GetStdHandle(STD_OUTPUT_HANDLE);         // Récupère le numéro de console pour obtenir les infos de la console
    SetConsoleCursorPosition (Console, Point);         // Fixe la position du curseur sur la console
}


//=================================================================//
// Fonction qui fixe une couleur à l'emplacement du curseur        //
//                     construite à partir de conio.c              //
//=================================================================//
void Couleur(int CouleurCaractere, int CouleurFond)
{
    HANDLE Console=0;  // Stocke le numéro de la console affichée à l'écran

    Console = GetStdHandle(STD_OUTPUT_HANDLE);           // Récupère le numéro de console pour obtenir les infos de la console

    SetConsoleTextAttribute (Console , CouleurCaractere+(CouleurFond*16)); // Fixe la couleur du fond et la couleur du caractère

///////////////////// A VOIR DEUXIEME SOLUTION ///////////////////////////
    void textattr(int _attr)
    {
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
    }

    void CouleurFondTexte(int _color)   // Change la couleur du fond d'écran
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
// Fonction qui vide l'écran ( on remplit l'écran avec une couleur noire)  //
//=========================================================================//


void effaceEcran()
{
    HANDLE Console=0;           // Stocke le numéro de la console affichée à l'écran
    COORD  Point =  {0,0};      // Gére la position du curseur sur la console et choisi la position en haut à gauche extrême (en dehors de l'écran
    DWORD dwWritten, dwSize;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    Console=GetStdHandle (STD_OUTPUT_HANDLE);           // Récupère le numéro de console pour obtenir les infos de la console

    if(GetConsoleScreenBufferInfo(Console, &Info))		// si on obtient les info concernant la console
    {

        // détermine le nombre de caractères total composant la console : nb caractères sur une ligne * nb lignes
        dwSize = Info.dwSize.X * Info.dwSize.Y ;

        // remplit l'écran avec des espaces en partant de la coordonnée x=0 et y=0
        FillConsoleOutputCharacter (Console, ' ', dwSize, Point, &dwWritten);

        // Fixe la couleur de remplissage pour chaque caractères de la console
        FillConsoleOutputAttribute (Console, Info.wAttributes, dwSize, Point, &dwWritten);

        // Place le curseur en haut à gauche
        FixePosCurseur(1, 1);
    }


        // ////////// Envoie la couleur d'un bloc
        FillConsoleOutputAttribute (Console, 15 + (0 << 4), 4000, (COORD) {0, 0}, &dwWritten);

        // //////////// remplit 4000 ' ' en partant de la coordonnée x=0, y=0
        FillConsoleOutputCharacter (Console, ' ', 4000, (COORD) {0, 0}, &dwWritten);

        // Place le curseur en haut à gauche
        FixePosCurseur(1, 1);


}

int selection()
{
    char choixDefilement,mur = 219;
    int defilement = 1,choix,x,y;

    Couleur(14,0);
    FixePosCurseur(35,25);
    puts("Veuillez choisir un labyrinthe");
    FixePosCurseur(31,26);
    puts("Defiler les labyrinthes avec (q) et (d)");
    FixePosCurseur(36,27);
    puts("ESPACE pour valider le choix");
    Couleur(15,0);

    while (defilement <= 10 && defilement >= 1)
    {
        while (choixDefilement != 'q' || choixDefilement != 'd')
        {
            if(defilement == 1)
            {
                for (y=0;y<=19;y++)
                {
                    FixePosCurseur(40,y);
                    for (x=0;x<=20;x++)
                    {
                        if (laby1[y][x] == 0)
                        printf(" ");
                        if (laby1[y][x] == 1)
                        printf("%c", mur);
                    }
                    printf("\n");
                }
            }
            if(defilement == 2)
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
            }
            if(defilement == 3)
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
            }
            if(defilement == 4)
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
            }
            if(defilement == 5)
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
            }
            if(defilement == 6)
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
            }
            if(defilement == 7)
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
            }
            if(defilement == 8)
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
            }
            if(defilement == 9)
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
            }
            if(defilement == 10)
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
            }
            choixDefilement = getch();
            if (choixDefilement == 'q')
            {
                if (defilement == 1)
                {
                    break;
                }
                defilement--;
                effaceEcran();
                Couleur(14,0);
                FixePosCurseur(35,25);
                puts("Veuillez choisir un labyrinthe");
                FixePosCurseur(31,26);
                puts("Defiler les labyrinthes avec (q) et (d)");
                FixePosCurseur(36,27);
                puts("ESPACE pour valider le choix");
                FixePosCurseur(0,0);
                Couleur(15,0);
            }
            if (choixDefilement == 'd')
            {
                if (defilement == 10)
                {
                    break;
                }
                defilement++;
                effaceEcran();
                Couleur(14,0);
                FixePosCurseur(35,25);
                puts("Veuillez choisir un labyrinthe");
                FixePosCurseur(31,26);
                puts("Defiler les labyrinthes avec (q) et (d)");
                FixePosCurseur(36,27);
                puts("ESPACE pour valider le choix");
                FixePosCurseur(0,0);
                Couleur(15,0);
            }
            if (choixDefilement == 32)
            {
                choix = defilement;
                effaceEcran();
                FixePosCurseur(0,0);
                return choix;
            }
        }
    }
}

int collision(int x,int y,int i)
{
    int obstacle;
    x = x - 40;

    if (i == 1)
    {
        if (laby1[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby1[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 2)
    {
        if (laby2[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby2[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 3)
    {
        if (laby3[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby3[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 4)
    {
        if (laby4[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby4[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 5)
    {
        if (laby5[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby5[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 6)
    {
        if (laby6[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby6[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 7)
    {
        if (laby7[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby7[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 8)
    {
        if (laby8[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby8[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 9)
    {
        if (laby9[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby9[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    if (i == 10)
    {
        if (laby10[y][x] == 0)
        {
            obstacle = 0;
        }
        if (laby10[y][x] == 1)
        {
            obstacle = 1;
        }
    }
    return obstacle;
}

void affichelaby(int i)
{
    int x,y,laby[hauteurLaby][largeurLaby];
    char mur = 219;

    if (i == 1)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby1[y][x];
            }
        }
    }
    if (i == 2)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby2[y][x];
            }
        }
    }
    if (i == 3)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby3[y][x];
            }
        }
    }
    if (i == 4)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby4[y][x];
            }
        }
    }
    if (i == 5)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby5[y][x];
            }
        }
    }
    if (i == 6)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby6[y][x];
            }
        }
    }
    if (i == 7)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby7[y][x];
            }
        }
    }
    if (i == 8)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby8[y][x];
            }
        }
    }
    if (i == 9)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby9[y][x];
            }
        }
    }
    if (i == 10)
    {
        for (y=0;y<=19;y++)
        {
            for (x=0;x<=20;x++)
            {
                laby[y][x] = laby10[y][x];
            }
        }
    }
    for (y=0;y<=19;y++)
    {
        FixePosCurseur(40,y);
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

void gameOver()
{
    effaceEcran();
    FixePosCurseur(46,22);
    printf("GAME OVER");
}

void win()
{
    effaceEcran();
    FixePosCurseur(30,22);
    printf("Felicitations, vous avez sauve la princesse");
}

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

    while (touche != 27)
    {
        touche = getch();
        if (touche == 27)
            break;
    }
}

void afficheScore(int nombrePas)
{
    int score = 0;

    score = nombrePas;
    FixePosCurseur(30,24);
    printf("Vous avez sauve la princesse en %d pas",score);
}

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
