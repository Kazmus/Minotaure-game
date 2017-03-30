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
    FixePosCurseur(0,22);
    puts("Veuillez choisir un labyrinthe deplacer les laby avec Q et D ensuite sur ESPACE pour valider le choix");
    while (defilement <= 10 && defilement >= 1)
    {
        while (choixDefilement != 'q' || choixDefilement != 'd')
        {
            if(defilement == 1)
            {
                for (y=0;y<=19;y++)
                {
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                    FixePosCurseur(28,y);
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
                FixePosCurseur(0,22);
                puts("Veuillez choisir un labyrinthe deplacer les laby avec Q et D ensuite sur ESPACE pour valider le choix");
                FixePosCurseur(0,0);
            }
            if (choixDefilement == 'd')
            {
                if (defilement == 10)
                {
                    break;
                }
                defilement++;
                effaceEcran();
                FixePosCurseur(0,22);
                puts("Veuillez choisir un labyrinthe deplacer les laby avec Q et D ensuite sur ESPACE pour valider le choix");
                FixePosCurseur(0,0);
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
    x = x - 28;

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
        FixePosCurseur(28,y);
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
    FixePosCurseur(32,12);
    printf("GAME OVER");
}

