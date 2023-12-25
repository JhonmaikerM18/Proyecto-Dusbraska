#include "include.h"

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void horario_mostrar()
{
    int x;
    int y;
    int j;

    printf("%c", cs);

    for (x = 0; x < 90; x++)
    {
        printf("%c", s);
    }
    printf("%c", css);

    // Lineas Horizontales

    gotoxy(1, 2); // HORA LINEA HORIZONTAL
    for (x = 0; x < 90; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 7); // HORA LINEA HORIZONTAL 1
    for (x = 0; x < 90; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 12); // HORA LINEA HORIZONTAL 2
    for (x = 0; x < 90; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 17); // HORA LINEA HORIZONTAL 3
    for (x = 0; x < 90; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 22); // HORA LINEA HORIZONTAL 4
    for (x = 0; x < 90; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 27); // HORA LINEA HORIZONTAL 5
    for (x = 0; x < 90; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 32); // HORA LINEA HORIZONTAL 6
    for (x = 0; x < 90; x++)
    {
        printf("%c", s);
    }
    // LINEAS VERTICALES
    gotoxy(0, 1);
    for (y = 0; y < 31; y++)
    {
        printf("%c\n", d);
    }
    for (j = 1; j < 32; j++)
    {
        gotoxy(11, j); // HORA LINEA VERTICAL 1
        printf("%c\n", d);
    }

    for (j = 1; j < 32; j++)
    {
        gotoxy(27, j); // HORA LINEA VERTICAL 2
        printf("%c\n", d);
    }
    for (j = 1; j < 32; j++)
    {
        gotoxy(43, j); // HORA LINEA VERTICAL 3
        printf("%c\n", d);
    }
    for (j = 1; j < 32; j++)
    {
        gotoxy(59, j); // HORA LINEA VERTICAL 4
        printf("%c\n", d);
    }
    for (j = 1; j < 32; j++)
    {
        gotoxy(75, j); // HORA LINEA VERTICAL 5
        printf("%c\n", d);
    }

    // ULTIMA LINEA
    for (j = 1; j < 32; j++)
    {
        gotoxy(91, j);
        printf("%c\n", d);
    }

    return;
}

int main()
{
    horario_mostrar();
    system("pause>clear");
    return 0;
}