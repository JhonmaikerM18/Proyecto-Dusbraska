#include "include.h"
int valido_doc;
int valido = 0;
int cantidad_doc;
char nombre_doc[40];
char apellido_doc[40];

// Definici�n de la estructura de Docente
struct docente
{
    char nombre_doc[40], apellido_doc[40], telefono_d[13], cedula_d[10];
    int secciones_doc, disp_doc, insc_doc[4], dia[4], semestre;
};
struct ElementoHorario
{
    char nombre[12];
    int entero;
    char apellido[12];
};
struct ElementoHorario horario[5][6];
// FUNCIONES PROTOTIPO
void random();
void disponibilidad_de_horario(int, int, char *, char *);
int verificar_hora();
int verificacion_de_realidad(char *numero, int x);
int verificar_numero(char *cadena);
// PARTE DEL HORARIO ES ESTA
int horario_asig(int, int, int, int, int, int, char *, char *, char *, char *, struct ElementoHorario horario[5][6]);
void gotoxy(int, int);
void horario_mostrar();
DWORD WINAPI hilos_docentes(LPVOID lpParam);
int HILOS_HORARIO();
void cursor(int);
void pantalla_carga(int x, int y, int xx, int z, int zz, int tiempo, int segundos);
void centrar_t(char *texto, int x, int y);
void cuadro(int xs, int ys, int xi, int yi);
int carga_de_datos_doc(int cantidad_doc, struct ElementoHorario horario[5][6])
{
    int i;
    system("cls");
    struct docente docentes[cantidad_doc];
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
            printf("Semestre del docente > ");
            do
            {
                if (scanf("%d", &docentes[i].semestre) != 1)
                {
                    printf("Error: Entrada no v%clida - Ingrese nuevamente > ", aa);
                    while (getchar() != '\n')
                        ;
                }
                else if (docentes[i].semestre < 1 || docentes[i].semestre > 9)
                {
                    printf("Error: N%cmero no v%clido - Ingrese nuevamente > ", u, aa);
                }
            } while (docentes[i].semestre < 1 || docentes[i].semestre > 9);
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
            strncpy(nombre_doc, docentes[i].nombre_doc, 12);
            fflush(stdin);
            strncpy(apellido_doc, docentes[i].apellido_doc, 4);
            fflush(stdin);
            for (int j = 0; j < 1; j++)
            {

                int dia;
                scanf("%d", &dia);
                fflush(stdin);
                switch (dia)
                {
                case 1:
                    if ((horario[1][1].entero && horario[1][2].entero && horario[1][3].entero && horario[1][4].entero && horario[1][5].entero && horario[1][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(1, i, nombre_doc, apellido_doc);
                    }
                    break;
                case 2:
                    if ((horario[2][1].entero && horario[2][2].entero && horario[2][3].entero && horario[2][4].entero && horario[2][5].entero && horario[2][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(2, i, nombre_doc, apellido_doc);
                    }
                    break;
                case 3:
                    if ((horario[3][1].entero && horario[3][2].entero && horario[3][3].entero && horario[3][4].entero && horario[3][5].entero && horario[3][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(3, i, nombre_doc, apellido_doc);
                    }
                    break;
                case 4:

                    if ((horario[4][1].entero && horario[4][2].entero && horario[4][3].entero && horario[4][4].entero && horario[4][5].entero && horario[4][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(4, i, nombre_doc, apellido_doc);
                    }
                    break;
                case 5:

                    if ((horario[5][1].entero && horario[5][2].entero && horario[5][3].entero && horario[5][4].entero && horario[5][5].entero && horario[5][6].entero) == 1)
                    {
                        printf("Horario lleno - Ingrese otro dia > ");
                        j--;
                    }
                    else
                    {
                        disponibilidad_de_horario(5, i, nombre_doc, apellido_doc);
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
        }
        fwrite(docentes, sizeof(struct docente), 42, registros_docente);
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
                return 0; // número incorrecto
            }
        }
        else if (num < 7000000)
        {
            return 0; // Número incorrecto
        }
        else if (num > 34999999)
        {
            return 0; // Número incorrecto
        }
        else
        {
            return 0; // Número incorrecto
        }
    }
    for (int i = 0; i < longitud; i++)
    {
        if (!isdigit(numero[i]))
        {
            return 0; // número incorrecto
        }
    }
    return 1; // número correcto
}
void disponibilidad_de_horario(int diaa, int i, char *nombre_doc, char *apellido_doc)
{
    struct docente docentes[cantidad_doc];
    int hora;
    system("cls");
    printf("    Ingrese el horario disponible del docente \n");
    printf("           El docente tiene 3 horas ");
    gotoxy(4,3);
    printf("      HORA      %c    NUMERO  \n",  d);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", d, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, mm, s, s, s,s,s,s, s, s, s, s, s, s, s, s, d);
    printf("                    %c           \n",  d);
    printf("      7:50 A 8:40   %c    (1)    \n",  d);
    printf("      8:45 A 9:35   %c    (2)    \n",  d);
    printf("      9:35 A 10:30  %c    (3)    \n",  d);
    printf("     11:00 A 11:50  %c    (4)    \n",  d);
    printf("     11:55 A 12:40  %c    (5)    \n",  d);
    printf("     12:45 A 01:40  %c    (6)    \n",  d);
    // printf("   %c 01:15 A 03:00   %c   (7)     %c\n", d, d, d);
    printf("                    %c           \n", d);
    cuadro(3,2,34,13);
    gotoxy(0,15);
    for (int y = 0; y < Hora_x_doc; y++)
    {
        do
        {
            printf("Ingrese hora escogida n%cmero (%d) > ", u, y + 1);
            if (scanf("%d", &hora) != 1)
            {
                printf("Error de entrada - Intente nuevamente > ");
                while (getchar() != '\n')
                    ;
            }
        } while (0);
        if (hora >= 1 && hora <= 6)
        {
            if (!verificar_hora(diaa, hora, nombre_doc, apellido_doc, horario))
            {
                y--;
            }
        }
        else
        {
            printf(" Error de numero. \n");
            y--;
        }
    }
    return;
}
int verificar_hora(int dia, int hora, char *nombre, char *apellido, struct ElementoHorario horario[5][6])
{
    if ((horario[dia][hora].entero == 0))
    {
        horario[dia][hora].entero = 1;
        strncpy(horario[dia][hora].nombre, nombre, 12);
        strncpy(horario[dia][hora].apellido, apellido, 3);
        fflush(stdin);
        return 1;
    }
    else
    {
        printf("Hora ocupada - Escoja otra hora \n");
        return 0;
    }
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
    for (int j = 0; j < x; j++)
    {
        k[j] = ((rand() % 15) + 20);
    }
}
void horario_mostrar()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
    system("mode con: cols=120 lines=37");
    printf("%c", 218);
    // LINEASSSSSS HORIZONTALESSS
    int x_posiciones[] = {0, 2, 7, 12, 17, 22, 27, 32};
    for (int x = 0; x < 8; x++)
    {
        for (int j = 1; j < 106; j++)
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
DWORD WINAPI hilos_docentes(LPVOID lpParam)
{
    char materia[] = "Fundamentos";
    char sede[] = "Villa asia";
    // Pudiera crear un (FOR) > Para esto pero prefiero manejarlo asi
    // DIAAAAAAAAAAA LUNESSSSSSSSSS
    horario_asig(12, 3, 1, 1, 3, 13, horario[1][1].nombre, horario[1][1].apellido, materia, sede, horario);
    horario_asig(12, 8, 1, 2, 3, 13, horario[1][2].nombre, horario[1][2].apellido, materia, sede, horario);
    horario_asig(12, 13, 1, 3, 3, 13, horario[1][3].nombre, horario[1][3].apellido, materia, sede, horario);
    horario_asig(12, 18, 1, 4, 3, 13, horario[1][4].nombre, horario[1][4].apellido, materia, sede, horario);
    horario_asig(12, 23, 1, 5, 3, 13, horario[1][5].nombre, horario[1][5].apellido, materia, sede, horario);
    horario_asig(12, 28, 1, 6, 3, 13, horario[1][6].nombre, horario[1][6].apellido, materia, sede, horario);
    // DIAAAAAAAAAAA MARTESSSSSSSSSSSSSSSS
    horario_asig(31, 3, 2, 1, 3, 13, horario[2][1].nombre, horario[2][1].apellido, materia, sede, horario);
    horario_asig(31, 8, 2, 2, 3, 13, horario[2][2].nombre, horario[2][2].apellido, materia, sede, horario);
    horario_asig(31, 13, 2, 3, 3, 13, horario[2][3].nombre, horario[2][3].apellido, materia, sede, horario);
    horario_asig(31, 18, 2, 4, 3, 13, horario[2][4].nombre, horario[2][4].apellido, materia, sede, horario);
    horario_asig(31, 23, 2, 5, 3, 13, horario[2][5].nombre, horario[2][5].apellido, materia, sede, horario);
    horario_asig(31, 28, 2, 6, 3, 13, horario[2][6].nombre, horario[2][6].apellido, materia, sede, horario);
    // DIAAAAAAAAAAA MIERCOLESSSSSSSSSSSSSSSSSS
    horario_asig(50, 3, 3, 1, 3, 13, horario[3][1].nombre, horario[3][1].apellido, materia, sede, horario);
    horario_asig(50, 8, 3, 2, 3, 13, horario[3][2].nombre, horario[3][2].apellido, materia, sede, horario);
    horario_asig(50, 13, 3, 3, 3, 13, horario[3][3].nombre, horario[3][3].apellido, materia, sede, horario);
    horario_asig(50, 18, 3, 4, 3, 13, horario[3][4].nombre, horario[3][4].apellido, materia, sede, horario);
    horario_asig(50, 23, 3, 5, 3, 13, horario[3][5].nombre, horario[3][5].apellido, materia, sede, horario);
    horario_asig(50, 28, 3, 6, 3, 13, horario[3][6].nombre, horario[3][6].apellido, materia, sede, horario);
    // DIAAAAAAAAAAA JUEVESSSSSSSSSSSSSSSS
    horario_asig(69, 3, 4, 1, 3, 13, horario[4][1].nombre, horario[4][1].apellido, materia, sede, horario);
    horario_asig(69, 8, 4, 2, 3, 13, horario[4][2].nombre, horario[4][2].apellido, materia, sede, horario);
    horario_asig(69, 13, 4, 3, 3, 13, horario[4][3].nombre, horario[4][3].apellido, materia, sede, horario);
    horario_asig(69, 18, 4, 4, 3, 13, horario[4][4].nombre, horario[4][4].apellido, materia, sede, horario);
    horario_asig(69, 23, 4, 5, 3, 13, horario[4][5].nombre, horario[4][5].apellido, materia, sede, horario);
    horario_asig(69, 28, 4, 6, 3, 13, horario[4][6].nombre, horario[4][6].apellido, materia, sede, horario);
    // DIAAAAAAAAAAA VIERNESSSSSSSSSSSSSSSSS
    horario_asig(88, 3, 5, 1, 3, 13, horario[5][1].nombre, horario[5][1].apellido, materia, sede, horario);
    horario_asig(88, 8, 5, 2, 3, 13, horario[5][2].nombre, horario[5][2].apellido, materia, sede, horario);
    horario_asig(88, 13, 5, 3, 3, 13, horario[5][3].nombre, horario[5][3].apellido, materia, sede, horario);
    horario_asig(88, 18, 5, 4, 3, 13, horario[5][4].nombre, horario[5][4].apellido, materia, sede, horario);
    horario_asig(88, 23, 5, 5, 3, 13, horario[5][5].nombre, horario[5][5].apellido, materia, sede, horario);
    horario_asig(88, 28, 5, 6, 3, 13, horario[5][6].nombre, horario[5][6].apellido, materia, sede, horario);
    // PARA EVITAR ESCRITURA INDEBIDAS
    gotoxy(0, 33);
    return 0;
}
int horario_asig(int x, int y, int dia, int hora, int seccion, int aula, char *nombre, char *apellido, char *materia, char *sede, struct ElementoHorario horario[5][6])
{
    if ((horario)[dia][hora].entero == 1)
    {
        gotoxy(x, y);
        printf("%s", nombre);
        gotoxy(x + 12, y);
        printf(" %s.", apellido);
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
    SetConsoleTitle("Horario de clases");
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
    system("pause>clear");
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
void pantalla_carga(int x, int y, int xx, int z, int zz, int tiempo, int segundos)
{
    cursor(0);
    centrar_t("CARGANDO.   - ESPERE UN MOMENTO ", x, y);
    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
        {
            centrar_t("CARGANDO..  - ESPERE UN MOMENTO ", x, y);
        }
        if (i == 2)
        {
            centrar_t("CARGANDO... - ESPERE UN MOMENTO ", x, y);
        }

        for (int i = z; i < zz; i++)
        {
            gotoxy(i, y + 2);
            printf("%c", 177);
        }
        for (int i = z; i < zz; i++)
        {
            gotoxy(i, y + 2);
            printf("%c", 219);
            Sleep(tiempo);
        }
        Sleep(50);
    }
    for (int i = z; i < zz; i++)
    {
        gotoxy(i, y + 2);
        printf(" ");
    }
    centrar_t("                                      ", x, y);
    centrar_t("CARGA COMPLETADA", x, y);
    for (int i = 3; i >= 1; i--)
    {
        gotoxy(x - 9, y + 2);
        printf("SERA ENVIADO EN (%d)", i);
        Sleep(segundos);
        centrar_t("                      ", x, y + 2);
    }
    gotoxy(0, 0);
    system("cls");
    cursor(1);
    return;
}
void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
void centrar_t(char *texto, int x, int y)
{
    int longitud = strlen(texto);
    gotoxy(x - (longitud / 2), y);
    printf(texto);
}
void cursor(int x)
{
    if (x == 0)
    {
        printf("\e[?25l");
    }
    if (x == 1)
    {
        printf("\e[?25h");
    }
}
void bloqueo_maximizar()
{
    HWND consoleWindow;
    consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

// Función de comparación para qsort
int comparador(const void *a, const void *b)
{
    return strcmp(((struct docente *)a)->cedula_d, ((struct docente *)b)->cedula_d);
}

void mostrar_docentes(int cantidad_doc)
{
    FILE *registros_docentes;
    struct docente docentes[42];
    registros_docentes = fopen("data/registros_doc", "rb");
    if (registros_docentes)
    {
        fread(docentes, sizeof(struct docente), 42, registros_docentes);
        fclose(registros_docentes);
        qsort(docentes, cantidad_doc, sizeof(struct docente), comparador); // Ordenar el arreglo de docentes por cédula
        printf("Mostrando datos de los docentes ordenados por CI\n");
        for (int j = 0; j < cantidad_doc; j++)
        {
            printf("Docente N(%d)\n", j + 1);
            printf("Nombre: %s\n", docentes[j].nombre_doc);
            printf("Apellido: %s\n", docentes[j].apellido_doc);
            printf("C%cdula: %s\n", e, docentes[j].cedula_d);
            printf("Semestre que pertenece: %d\n", docentes[j].semestre);
            printf("Tel%cfono: %s\n", e, docentes[j].telefono_d);
        }
    }
    else
    {
        printf("NULL - Error archivo no encontrado\n");
    }
    return;
}
struct materias
{
    char nombre[50];
    int unidades, prelacion, cupos, sede, semestre;
};

int carga_de_materia()
{
    int i;
    system("cls");
    struct materias materias[12];
    printf("Ingrese nombre de la materia > ");
    scanf("%s", &materias[i].nombre);
    fflush(stdin);
    printf("Semestre al que pertenece > ");
    do
    {
        if (scanf("%d", &materias[i].semestre) != 1)
        {
            printf("Error: Entrada no v%clida - Ingrese nuevamente > ", aa);
            while (getchar() != '\n')
                ;
        }
        else if (materias[i].semestre < 1 || materias[i].semestre > 9)
        {
            printf("Error: N%cmero no v%clido - Ingrese nuevamente > ", u, aa);
        }
    } while (materias[i].semestre < 1 || materias[i].semestre > 9);
    printf("Ingrese unidades de creditos > ");
    scanf("%d", &materias[i].unidades);
    printf("Ingrese la prelaci%cn > ", o);
    scanf("%d", &materias[i].prelacion);
    printf("Cantidad de cupos de la materia >");
    scanf("%d", &materias[i].cupos);
    printf("Sede donde se dictara la materia > ");
    scanf("%d", &materias[i].sede);
    return 0;
}
void cuadro(int xs, int ys, int xi, int yi)
{
    for (int i = xs; i < xi; i++)
    {
        gotoxy(i, ys);
        printf("%c", 196);
        gotoxy(i, yi);
        printf("%c", 196);
    }
    for (int i = ys; i <= yi; i++)
    {
        gotoxy(xs, i);
        printf("%c", 179);
        gotoxy(xi, i);
        printf("%c", 179);
    }
    gotoxy(xs, ys);
    printf("%c", 218);
    gotoxy(xi, yi);
    printf("%c", 217);
    gotoxy(xi, ys);
    printf("%c", 191);
    gotoxy(xs, yi);
    printf("%c", 192);
}