#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

int collision(int x,int y)
{
    int obstacle;

    if (laby1[x][y] == 0)
    {
        obstacle = 0;
    }
    if (laby1[x][y] == 1)
    {
        obstacle = 1;
    }
    return obstacle;
}

void affichelaby(int x,int y)
{
    char mur = 219;

    for (y=0;y<=hauteurLaby;y++)
    {
        for (x=0;x<=largeurLaby;x++)
        {

            if (laby1[x][y] == 0)
            printf(" ");
            if (laby1[x][y] == 1)
            printf("%c", mur);
        }
            printf("\n");
    }

}

void gameOver()
{
    effaceEcran();
    FixePosCurseur(25,12);
    printf("GAME OVER");
}

