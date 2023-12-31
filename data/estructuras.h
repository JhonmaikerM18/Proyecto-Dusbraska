#include "include.h"
int valido_doc;
int valido = 0;
int cantidad_doc;

// Definici�n de la estructura de Docente
struct docente
{
    char nombre_doc[12], apellido_doc[12], telefono_d[13], cedula_d[10];
    int secciones_doc, disp_doc, insc_doc[4], dia_disp[4];
    int uno[5], dos[5], tres[5], cuatro[5], cinco[5], seis[5];
};

struct ElementoHorario
{
    char *caracter;
    int entero;
};
struct ElementoHorario horario[5][6] = {{{0}}};
// FUNCIONES PROTOTIPO
void random();
void disponibilidad_de_horario();
int verificar_hora(int dia, int hora, char *nombre, struct ElementoHorario horario[5][6]);
int verificacion_de_realidad(char *numero, int x);
int verificar_numero(char *cadena);
// PARTE DEL HORARIO ES ESTA
int horario_asig(int x, int y, int dia, int hora, int seccion, int aula, char *nombre, char *materia, char *sede);
void gotoxy(int x, int y);
void horario_mostrar();
DWORD WINAPI hilos_docentes(LPVOID lpParam);
int HILOS_HORARIO();
// PARTE FINAL ARREGLO GRAFICOS NOMAS
void icon();

int carga_de_datos_doc()
{
    printf("%cCuantos docentes van a quedar en registro? \n", signo);
    while (valido == 0)
    {
        if (scanf("%d", &cantidad_doc) != 1)
        {
            printf("Error: entrada no v%clida - ", aa);
            printf("Ingrese nuevamente > ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            if (cantidad_doc < 1)
            {
                printf("Error: entrada no v%clida - ", aa);
                printf("Ingrese nuevamente > ");
            }
            else if (cantidad_doc > 32)
            {
                printf("No tenemos suficientes recursos para alojar esa cantidad \n");
                printf("Ingrese nuevamente > ");
            }
            else // EL QUE MANDA A LA CARGA DE DATOS
            {
                valido = 1;
                fflush(stdin);
            }
        }
    }

    system("cls");
    struct docente docentes[cantidad_doc];
    struct ElementoHorario horario[5][6];
    FILE *registros_docente;
    registros_docente = fopen("data/registros_doc", "wb");
    if (registros_docente)
    {
        for (i = 0; i < cantidad_doc; i++)
        {
            printf("\tIngrese los datos del docente %d\n\n", i + 1);
            printf("Nombre del docente > ");
            scanf("%s", docentes[i].nombre_doc);
            fflush(stdin);
            printf("Apellido del docente > ");
            scanf("%s", docentes[i].apellido_doc);
            fflush(stdin);
            printf("Ingrese la c%cdula del docente > ", e);
            scanf("%s", docentes[i].cedula_d);
            fflush(stdin);

            while (!verificacion_de_realidad(docentes[i].cedula_d, 1))
            {
                scanf("%s", docentes[i].cedula_d);
                fflush(stdin);
            }

            printf("Ingrese un n%cmero de tel%cfono > ", u, e);
            scanf("%s", docentes[i].telefono_d);
            fflush(stdin);

            while (!verificacion_de_realidad(docentes[i].telefono_d, 0))
            {
                printf("Error - Ingrese un n%cmero de tel%cfono correcto > ", u, e);
                scanf("%s", docentes[i].telefono_d);
                fflush(stdin);
            }

            random(docentes[i].insc_doc, 3);
            srand(time(NULL));

            fflush(stdin);

            printf("\nLunes = 1  /  Martes  = 2  /  Mi%crcoles = 3 / Jueves = 4  /  Viernes = 5\n", e);
            printf("Ingrese el d%ca disponible del docente > ", ai);

            for (int j = 0; j < 1; j++)
            {
                int dia;
                scanf("%d", &dia);
                fflush(stdin);
                switch (dia)
                {
                case 1:
                    docentes[i].dia_disp[0] = 1; // Lunes
                    if ((horario[1][1].entero && horario[1][2].entero && horario[1][3].entero && horario[1][4].entero && horario[1][5].entero && horario[1][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(3, docentes[i].dia_disp[0], i);
                    }
                    break;
                case 2:
                    docentes[i].dia_disp[1] = 2; // Martes
                    if ((horario[2][1].entero && horario[2][2].entero && horario[2][3].entero && horario[2][4].entero && horario[2][5].entero && horario[2][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(3, docentes[i].dia_disp[1], i);
                    }
                    break;
                case 3:
                    docentes[i].dia_disp[2] = 3; // Miércoles
                    if ((horario[3][1].entero && horario[3][2].entero && horario[3][3].entero && horario[3][4].entero && horario[3][5].entero && horario[3][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(3, docentes[i].dia_disp[2], i);
                    }
                    break;
                case 4:
                    docentes[i].dia_disp[3] = 4; // Jueves
                    if ((horario[4][1].entero && horario[4][2].entero && horario[4][3].entero && horario[4][4].entero && horario[4][5].entero && horario[4][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(3, docentes[i].dia_disp[3], i);
                    }
                    break;
                case 5:
                    docentes[i].dia_disp[4] = 5; // Viernes
                    if ((horario[5][1].entero && horario[5][2].entero && horario[5][3].entero && horario[5][4].entero && horario[5][5].entero && horario[5][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(3, docentes[i].dia_disp[4], i);
                    }
                    break;
                default:
                    printf("\nIntente nuevamente > ");
                    j--;
                    break;
                }
            }
            system("cls");
            printf("DATOS A%cADIDOS SATIFACTORIAMENTE\n", NN);
            // srand(time(NULL));
            valido = 0;
        }
        fwrite(docentes, sizeof(struct docente), 32, registros_docente);
        fclose(registros_docente);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
    return 0;
}

int verificacion_de_realidad(char *numero, int x)
{
    int longitud = strlen(numero);

    for (int i = 0; i < longitud; i++)
    {
        if (!isdigit(numero[i]))
        {
            return 0; // número incorrecto
        }
    }
    if (x == 0)
    {

        if (longitud != 11)
        {
            return 0; // número incorrecto
        }

        if (strncmp(numero, "0412", 4) != 0 && strncmp(numero, "0414", 4) != 0 && strncmp(numero, "0416", 4) != 0 && strncmp(numero, "0424", 4) != 0 && strncmp(numero, "0426", 4) != 0)
        {
            return 0; // número incorrecto
        }
    }
    else if (x == 1)
    {
        int num = atoi(numero);
        if (num > 6999999 && num < 30000000)
        {
            if (longitud != 8 && longitud != 7)
            {
                printf("Error - Ingrese su c%cdula nuevamente > ", e);
                return 0; // número incorrecto
            }
        }
        else if (num < 7000000)
        {
            printf("El docente no esta vivo :v - Ingrese nuevamente > ");
            return 0; // Número incorrecto
        }
        else if (num > 34999999)
        {
            printf("Personas con esa c%cdula todavia no existen - Ingrese nuevamente > ", e, o);
            return 0; // Número incorrecto
        }
        else
        {
            printf("Esa c%cdula es de una persona demasiado j%cven - Ingrese nuevamente > ", e, o);
            return 0; // Número incorrecto
        }
    }

    return 1; // número correctoo
}

void disponibilidad_de_horario(int horario_d, int diaa, int i)
{
    int hora;
    struct docente docentes[32];

    system("cls");
    printf("    Ingrese el horario disponible del docente \n");
    printf("           El docente tiene 3 horas \n");
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cs, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, cm, s, s, s, s, s, s, s, s, s, s, s, css);
    printf("   %c     HORA        %c   NUMERO  %c\n", d, d, d);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", d, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, mm, s, s, s, s, s, s, s, s, s, s, s, d);
    printf("   %c                 %c           %c\n", d, d, d);
    printf("   %c  7:50 A 8:40    %c    (1)    %c\n", d, d, d);
    printf("   %c  8:45 A 9:35    %c    (2)    %c\n", d, d, d);
    printf("   %c  9:35 A 10:30   %c    (3)    %c\n", d, d, d);
    printf("   %c 11:00 A 11:50   %c    (4)    %c\n", d, d, d);
    printf("   %c 11:55 A 12:40   %c    (5)    %c\n", d, d, d);
    printf("   %c 12:45 A 01:40   %c    (6)    %c\n", d, d, d);
    // printf("   %c 01:15 A 03:00   %c   (7)     %c\n", d, d, d);
    printf("   %c                 %c           %c\n", d, d, d);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", ds, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, dm, s, s, s, s, s, s, s, s, s, s, s, dss);
    int x = 0;
    for (int y = 0; y < horario_d; y++)
    {
        while (x == 0)
        {
            printf("Ingrese hora escogida n%cmero (%d) > ", u, y + 1);
            if (scanf("%d", &hora) != 1)
            {
                printf("Error de entrada - Intente nuevamente > ");
                while (getchar() != '\n')
                    ;
            }
            else
            {
                x = 1;
            }
        }

        switch (hora)
        {
        case 1:
            docentes[i].uno[diaa] = 1; // 7:50 A 8:40
            if (!verificar_hora(diaa, docentes[i].uno[diaa], docentes[i].nombre_doc, horario))
            {
                y--;
            }
            break;
        case 2:
            docentes[i].dos[diaa] = 2; // 8:45 A 9:35
            if (!verificar_hora(diaa, docentes[i].dos[diaa], docentes[i].nombre_doc, horario))
            {
                y--;
            }
            break;
        case 3:
            docentes[i].tres[diaa] = 3; // 9:40 A 10:25
            if (!verificar_hora(diaa, docentes[i].tres[diaa], docentes[i].nombre_doc, horario))
            {
                y--;
            }
            break;
        case 4:
            docentes[i].cuatro[diaa] = 4; // 10:30 A 11:20
            if (!verificar_hora(diaa, docentes[i].cuatro[diaa], docentes[i].nombre_doc, horario))
            {
                y--;
            }
            break;
        case 5:
            docentes[i].cinco[diaa] = 5; // 11:25 A 12:10
            if (!verificar_hora(diaa, docentes[i].cinco[diaa], docentes[i].nombre_doc, horario))
            {
                y--;
            }
            break;
        case 6:
            docentes[i].seis[diaa] = 6; // 12:15 A 01:30
            if (!verificar_hora(diaa, docentes[i].seis[diaa], docentes[i].nombre_doc, horario))
            {
                y--;
            }
            break;
        default:
            printf(" Error de numero. \n");
            y--;
            break;
        }
    }
    return;
}

int verificar_numero(char *cadena)
{
    int j = 0;
    while (isdigit(cadena[j]))
    {
        j++;
    }
    if (cadena[j] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void random(int *k, int x)
{
    int j = 0;
    for (j = 0; j < x; j++)
    {
        k[j] = ((rand() % 15) + 20);
    }
}

int verificar_hora(int dia, int hora, char *nombre, struct ElementoHorario horario[5][6])
{
    printf("%d", horario[dia][hora].entero);
    if (horario[dia][hora].entero == 0)
    {
        horario[dia][hora].entero = 1;
        printf("  El Docente fue asignado correctamente. \n");
        strcpy(horario[dia][hora].caracter, nombre);
        return 1;
    }
    else
    {
        printf("Hora ocupada - Escoja otra hora \n");
        return 0;
    }
}
// PARTE DEL HORARIOOOOOOOO ESTAAA

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
    printf("%c", cs);

    // LINEASSSSSS HORIZONTALESSS
    int x_posiciones[] = {0, 2, 7, 12, 17, 22, 27, 32};
    for (int x = 0; x < 8; x++)
    {
        for (int j = 1; j < 105; j++)
        {
            gotoxy(j, x_posiciones[x]);
            printf("%c\n", s);
        }
    }

    // LINEASSSSSS VERTICALESS
    int y_posiciones[] = {0, 11, 30, 49, 68, 87, 106};
    for (int y = 0; y < 7; y++)
    {
        for (int j = 1; j < 32; j++)
        {
            gotoxy(y_posiciones[y], j);
            printf("%c\n", d);
        }
    }

    /// DIA DE SEMANAAA
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

    // DIA DE LA SEMANA
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

    return;
}
char materia[] = "Fundamentos";
char sede[] = "Villa asia";

DWORD WINAPI hilos_docentes(LPVOID lpParam)
{
    // Pudiera crear un (FOR) > Para esto pero prefiero manejarlo asi
    // DIAAAAAAAAAAA LUNESSSSSSSSSS
    horario_asig(12, 3, 1, 1, 3, 13, horario[0][1].caracter, materia, sede);
    horario_asig(12, 8, 1, 2, 3, 13, horario[0][2].caracter, materia, sede);
    horario_asig(12, 13, 1, 3, 3, 13, horario[0][3].caracter, materia, sede);
    horario_asig(12, 18, 1, 4, 3, 13, horario[0][4].caracter, materia, sede);
    horario_asig(12, 23, 1, 5, 3, 13, horario[0][5].caracter, materia, sede);
    horario_asig(12, 28, 1, 6, 3, 13, horario[0][6].caracter, materia, sede);
    /*// DIAAAAAAAAAAA MARTESSSSSSSSSSSSSSSS
    horario_asig(31, 3, 2, 1, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(31, 8, 2, 2, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(31, 13, 2, 3, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(31, 18, 2, 4, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(31, 23, 2, 5, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(31, 28, 2, 6, 3, 13, docentes[i].nombre_doc, materia, sede);
    // DIAAAAAAAAAAA MIERCOLESSSSSSSSSSSSSSSSSS
    horario_asig(50, 3, 3, 1, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(50, 8, 3, 2, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(50, 13, 3, 3, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(50, 18, 3, 4, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(50, 23, 3, 5, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(50, 28, 3, 6, 3, 13, docentes[i].nombre_doc, materia, sede);
    // DIAAAAAAAAAAA JUEVESSSSSSSSSSSSSSSS
    horario_asig(69, 3, 4, 1, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(69, 8, 4, 2, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(69, 13, 4, 3, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(69, 18, 4, 4, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(69, 23, 4, 5, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(69, 28, 4, 6, 3, 13, docentes[i].nombre_doc, materia, sede);
    // DIAAAAAAAAAAA VIERNESSSSSSSSSSSSSSSSS
    horario_asig(88, 3, 5, 1, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(88, 8, 5, 2, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(88, 13, 5, 3, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(88, 18, 5, 4, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(88, 23, 5, 5, 3, 13, docentes[i].nombre_doc, materia, sede);
    horario_asig(88, 28, 5, 6, 3, 13, docentes[i].nombre_doc, materia, sede);*/
    // PARA EVITAR ESCRITURA INDEBIDAS
    gotoxy(0, 33);
    return 0;
}

int horario_asig(int x, int y, int dia, int hora, int seccion, int aula, char *nombre, char *materia, char *sede)
{

    if ((horario[dia][hora].entero) == 1)
    {
        gotoxy(x, y);
        printf("%s", nombre);
        gotoxy(x, y + 1);
        printf("%s", materia);
        gotoxy(x, y + 2);
        printf("Secc %d - Au %d", seccion, aula);
        gotoxy(x, y + 3);
        printf("%s", sede);
    }
    else
    {
        gotoxy(x, y + 1);
        printf("    HORARIO  ");
        gotoxy(x, y + 2);
        printf("  NO ASIGNADO");
    }
    return 0;
}

int HILOS_HORARIO()
{
    horario_mostrar();
    HANDLE threadHandle;
    DWORD threadId;
    threadHandle = CreateThread(NULL, 0, hilos_docentes, NULL, 0, &threadId);
    if (threadHandle == NULL)
    {
        printf("Error al crear el hilo\n");
        return 1;
    }
    WaitForSingleObject(threadHandle, INFINITE);
    CloseHandle(threadHandle);
    printf("Fin del programa principal\n\n");
    system("pause");
    return 0;
}

// PARTE MENOS IMPORTANTES ARREGLOS GRAFICOS
void icon()
{
    HWND hwnd = GetConsoleWindow();
    // Cargar el icono desde un archivo .ico
    HICON hIcon = (HICON)LoadImage(NULL, "data/icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
    // Establecer el nuevo icono para la ventana
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    return;
}