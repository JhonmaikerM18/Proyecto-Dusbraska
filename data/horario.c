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
    int c;

    printf("%c", cs);

    for (x = 0; x < 105; x++)
    {
        printf("%c", s);
    }
    printf("%c", css);

    // Lineas Horizontales

    gotoxy(1, 2); // HORA LINEA HORIZONTAL
    for (x = 0; x < 105; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 7); // HORA LINEA HORIZONTAL 1
    for (x = 0; x < 105; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 12); // HORA LINEA HORIZONTAL 2
    for (x = 0; x < 105; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 17); // HORA LINEA HORIZONTAL 3
    for (x = 0; x < 105; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 22); // HORA LINEA HORIZONTAL 4
    for (x = 0; x < 105; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 27); // HORA LINEA HORIZONTAL 5
    for (x = 0; x < 105; x++)
    {
        printf("%c", s);
    }
    gotoxy(1, 32); // HORA LINEA HORIZONTAL 6
    for (x = 0; x < 105; x++)
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
        gotoxy(27 + 3, j); // HORA LINEA VERTICAL 2
        printf("%c\n", d);
    }
    for (j = 1; j < 32; j++)
    {
        gotoxy(43 + 6, j); // HORA LINEA VERTICAL 3
        printf("%c\n", d);
    }
    for (j = 1; j < 32; j++)
    {
        gotoxy(59 + 9, j); // HORA LINEA VERTICAL 4
        printf("%c\n", d);
    }
    for (j = 1; j < 32; j++)
    {
        gotoxy(75 + 12, j); // HORA LINEA VERTICAL 5
        printf("%c\n", d);
    }

    // ULTIMA LINEA
    for (j = 1; j < 32; j++)
    {
        gotoxy(106, j);
        printf("%c\n", d);
    }
    /// dIA DE SEMANAAA
    gotoxy(3, 1);
    printf("HORA");

    gotoxy(3, 3);
    printf("7:50 \n%c   A \n%c  8:40", d, d); // 1
    gotoxy(3, 8);
    printf("8:45 \n%c   A \n%c  9:35", d, d); // 2
    gotoxy(3, 13);
    printf("9:35 \n%c   A \n%c 10:30", d, d); // 3
    gotoxy(3, 18);
    printf("11:00 \n%c    A \n%c  11:50", d, d); // 4
    gotoxy(3, 23);
    printf("11:55 \n%c    A \n%c  12:40", d, d); // 5
    gotoxy(3, 28);
    printf("12:45 \n%c    A \n%c  01:40", d, d); // 6

    gotoxy(17, 1);
    printf("LUNES");

    gotoxy(36, 1);
    printf("MARTES");

    gotoxy(54, 1);
    printf("MIERCOLES");

    gotoxy(74, 1);
    printf("JUEVES");

    gotoxy(93, 1);
    printf("VIERNES");

    //////// HORARIO FORMADO

    x = 3;
    c = 13;

    // BASE DE ASIGNACIONNN
    for (c; c < 100; c++)
    {

        for (x; x < 33; x++)
        {
            gotoxy(c , x + 1);
            printf("    HORARIO");
            gotoxy(c, x + 2);
            printf("  NO ASIGNADO");
            x = x + 4;
        }
        if (x > 30)
        {
            c = c + 18;
            x = 3;  
        }
    }

     // DIA LUNESSSSSSSSSSSSSSSSS
        gotoxy(13, x);
        printf("Jhonmaiker Mac.");
        gotoxy(13, x + 1);
        printf("Nro. 04128417031");
        gotoxy(12, x + 2);
        printf("Secci%cn %d - Au 15", o, 1);
        gotoxy(15, x + 3);
        printf("Atlantico");
    


    return;
}

int main()
{
    horario_mostrar();
    system("pause>clear");
    return 0;
}