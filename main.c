#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define aa 160
#define e 130
#define ai 161
#define o 162
#define u 163
#define NN 165    // La Ñ
#define signo 168 // El signo ¿

#define s 196
#define Hora_x_doc 3

// UBICACIONES DE DATOS DE LOS FICHEROS
#define F_registros_doc "registros_doc"
#define F_horario_dat "horario"
#define configuraciones "config"
#define F_materia "reg_de_materias"
#define pause "pause>clear"

struct docente
{
    char nombre[40], apellido[40], telefono_d[13], cedula_d[40], materia[30];
    int secciones_doc, disp_doc, insc_doc[4];
};
struct ElementoHorario
{
    char nombre[12], materia[30];
    char apellido[12];
    int entero;
};
struct materia
{
    char nombre[60], sede[12];
    int unidades, codigo, cupos, prelacion, secciones, pertenece, horas, semestre, alumnos_inscritos, docentes[3];
};
struct asignacion
{
    char nombre_doc[30], nombre_mat[30];
    int numAsignaciones;
};
// Estructurassss
struct materia materias[30];
struct asignacion asignaciones[50];
struct ElementoHorario horario[5][6];
struct docente docentes[100];

int opcion, numDocentes, horas_anadidas, numMaterias, numAsignaciones, temporal;
char nombre[13], apellido[5];

// Definici�n de la estructura de Docente

// FUNCIONES PRINCIPALES

// void mostrar_asignaciones();
void menu_est();
int carga_de_datos_doc();
void asignar_materia_doc();
void imprimirEstructura(struct docente *docentes, int i, int y);
void mostrar_datos_completos_docentes();
void mostrar_datos_completos_materias();
// FUNCIONES PRINCIPALES ->>> PARTE DEL HORARIO ES ESTA
int horario_asig(int, int, int, int, int, int, char *);
DWORD WINAPI hilos_docentes(LPVOID lpParam);
void disponibilidad_de_horario(int, int);
void HILOS_HORARIO();
void horario_mostrar();
int verificar_hora(int dia, int hora, int i, const char *nombre, const char *apellido);
// ACTUALIZAR FICHEROS
int actualizar_configuracion();
int actualizar_horario();
int actualizar_materia();
int actualizar_docentes();
// INICIALIZAR FICHEROS
int inicializar_configuracion();
int inicializar_horario();
int inicializar_materia();
int inicializar_docentes();
void inicializar_todo();
// FUNCIONES DE ADORNOS
void limpia_linea(int y);
void cursor(int);
void centrar_t(char *texto, int x, int y);
void cuadro(int xs, int ys, int xi, int yi);
void bloqueo_maximizar();
void cargarMaterias();
void materia_mostrar();
void icon();
void gotoxy(int, int);
void pantalla_carga(int x, int y, int z, int zz, int tiempo, int segundos);
void precione_una_tecla_para_continuar();
// FUNCIONES DE COMPARACION
int comparar_cedula(const void *a, const void *b);
int comparar_unidades_credito(const void *a, const void *b);
int verificacion_de_realidad(char *numero, int x);
// VARIADASSS
void random();

int main()
{
    icon();
    cuadro(30, 5, 50, 9);
    centrar_t("BIENVENIDO", 40, 7);
    pantalla_carga(40, 20, 6, 71, 1, 700);
    menu_est();
    return 0;
}

void menu_est()
{
    do
    {
        HWND hwnd = GetConsoleWindow();
        SetConsoleTitle("HORARIO - MENU DE INICIO");
        system("mode con: cols=80 lines=25");
        bloqueo_maximizar();
        if ((inicializar_configuracion()) == 0)
        {
            inicializar_todo();
            actualizar_configuracion();
        }
        system("cls");
        centrar_t("BIENVENIDO(A)\n\n", 40, 0);
        printf("1.- CARGAR DATOS DE LOS DOCENTES\n");
        printf("2.- CARGAR DATOS DE LAS MATERIAS\n");
        printf("3.- MOSTRAR HORARIO\n");
        printf("4.- MOSTRAR DATOS DE LOS DOCENTES \n");
        printf("5.- MOSTRAR MATERIAS\n");
        printf("6.- MOSTRAR DOCENTES CON SU MATERIA ASIGNADA\n");
        printf("7.- MOSTRAR LA RELACION DE DOCENTES CON ESTUDIANTES INSCRITOS\n");
        printf("8.- ELIMINAR DATOS\n");
        printf("9.- SALIR DEL PROGRAMA\n\n");
        printf("INGRESE OPCION A ESCOGER >>");

        gotoxy(23, 16);
        printf("INFORMACION DE DATOS EN SISTEMA");
        gotoxy(2, 18);
        printf("Docentes cargados en sistema    >>  %d", numDocentes);
        gotoxy(2, 20);
        printf("Materias cargadas en sistema    >>  %d", numMaterias);
        gotoxy(2, 22);
        printf("Docentes con Materia asignadas  >>  %d", 0);
        cuadro(1, 15, 78, 23);
        gotoxy(28, 12);
        scanf("%d", &opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            carga_de_datos_doc();
            break;
        case 2:
            cargarMaterias();
            break;
        case 3:
            HILOS_HORARIO();
            break;
        case 4:
            mostrar_datos_completos_docentes();
            break;
        case 5:
            mostrar_datos_completos_materias();
            break;
        case 6:
            printf("Para asignar al docente >> ");
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                asignar_materia_doc();
            }
            else if (opcion == 2)
            {
                // mostrar_asignaciones();
            }

            break;
        case 8:
            system("cls");
            printf("%cESTA SEGURO QUE DESEA ELIMINAR LOS DATOS A%cADIDOS?\n", signo, NN);
            printf("Ingrese (0) = NO (1) = SI \n>> ");
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                remove(F_horario_dat);
                remove(configuraciones);
                remove(F_registros_doc);
                remove(F_materia);
                printf("Los Archivos de datos fue eliminado satifactoriamente\n");
                precione_una_tecla_para_continuar();
            }
            break;
        case 9:
            cursor(0);
            printf("QUE TENGA UN LINDO DIA :) ");
            Sleep(3000);
            return;
            break;
        default:
            printf("Entrda no v%clida - Intente nuevamente\n", aa);
            precione_una_tecla_para_continuar();
            break;
        }
    } while (opcion != 9);
}

int carga_de_datos_doc()
{
    opcion = 0;
    SetConsoleTitle("HORARIO - CARGA DE DATOS DE LOS DOCENTES");
    for (int dia = 0; dia < 5; dia++)
    {
        if (horario[dia][1].entero && horario[dia][2].entero && horario[dia][3].entero && horario[dia][4].entero && horario[dia][5].entero && horario[dia][6].entero)
        {
            printf("Horario lleno - No se puede a%cadir a m%c docentes \nDisculpe los incovenientes", 164, aa);
            return 1;
        }
    }
    printf("%cCu%cntos docentes van a hacer a%cadidos en el registro?\n>> ", signo, aa, 164);
    while (1)
    {
        if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 42)
        {
            if (opcion > 42)
            {
                printf("No tenemos suficientes recursos para alojar esa cantidad. \nIngrese nuevamente > ");
            }
            else
            {
                printf("Error: entrada no v%clida - Ingrese nuevamente > ", aa);
            }
        }
        else // EL QUE MANDA A LA CARGA DE DATOS
        {
            inicializar_horario();
            temporal = (numDocentes + opcion); 
            break;
        }
    }
    system("cls");
    for (int i = numDocentes; i < temporal; i++)
    {
        printf("\tIngrese los datos del docente %d\n\n", i + 1);
        printf("Nombre del docente >> ");
        scanf("%s", docentes[i].nombre);
        fflush(stdin);
        printf("Apellido del docente >> ");
        scanf("%s", docentes[i].apellido);
        fflush(stdin);

        printf("Ingrese la c%cdula del docente >> ", e);
        scanf("%s", docentes[i].cedula_d);
        while (!verificacion_de_realidad(docentes[i].cedula_d, 1))
        {
            printf("Ingrese nuevamente >> ");
            scanf("%s", docentes[i].cedula_d);
        }
        printf("Ingrese un n%cmero de tel%cfono >> ", u, e);
        scanf("%s", docentes[i].telefono_d);
        while (!verificacion_de_realidad(docentes[i].telefono_d, 0))
        {
            printf("Error - Ingrese un n%cmero de tel%cfono correcto >> ", u, e);
            scanf("%s", docentes[i].telefono_d);
        }
        random(docentes[i].insc_doc, i, 3);

        printf("\nLunes = 1  /  Martes  = 2  /  Mi%crcoles = 3 / Jueves = 4  /  Viernes = 5\n", e);
        printf("Ingrese el d%ca disponible del docente >> ", ai);
        strncpy(nombre, docentes[i].nombre, 12);
        strncpy(apellido, docentes[i].apellido, 4);
        for (int j = 0; j < 1; j++)
        {
            int dia;
            scanf("%d", &dia);
            docentes[i].disp_doc = dia;
            inicializar_horario();
            dia--;
            if (dia >= 0 && dia <= 4)
            {
                if (horario[dia][1].entero && horario[dia][2].entero && horario[dia][3].entero && horario[dia][4].entero && horario[dia][5].entero && horario[dia][6].entero)
                {
                    printf("Horario lleno - Ingrese otro d%ca >> ", ai);
                    j--;
                }
                else
                {
                    disponibilidad_de_horario(dia, i);
                }
            }
            else
            {
                printf("\nIntente nuevamente (1-5) >> ");
                j--;
            }
        }
        system("cls");
    }
    printf("DATOS A%cADIDOS SATISFACTORIAMENTE\n", NN);
    numDocentes++;
    actualizar_configuracion();
    actualizar_docentes();
    precione_una_tecla_para_continuar();
    return 0;
}

void disponibilidad_de_horario(int diaa, int i)
{
    struct docente docentes[numDocentes];
    int hora;
    system("cls");
    printf("    Ingrese el horario disponible del docente \n");
    printf("           El docente tiene 3 horas ");
    gotoxy(4, 3);
    printf("      HORA      %c    NûMERO  \n", 179);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, 197, s, s, s, s, s, s, s, s, s, s, s, s, s, s, 179);
    printf("                    %c           \n", 179);
    printf("      7:50 A 8:40   %c    (1)    \n", 179);
    printf("      8:45 A 9:35   %c    (2)    \n", 179);
    printf("      9:35 A 10:30  %c    (3)    \n", 179);
    printf("     11:00 A 11:50  %c    (4)    \n", 179);
    printf("     11:55 A 12:40  %c    (5)    \n", 179);
    printf("     12:45 A 01:40  %c    (6)    \n", 179);
    printf("                    %c           \n", 179);
    cuadro(3, 2, 34, 13);
    gotoxy(0, 15);
    for (int y = 0; y < Hora_x_doc; y++)
    {
        do
        {
            printf("Ingrese hora escogida n%cmero (%d) > ", u, y + 1);
            if (scanf("%d", &hora) != 1 || hora < 1 || hora > 6)
            {
                printf("Error de entrada - Intente nuevamente\n");
                while (getchar() != '\n')
                    ;
            }
        } while (hora < 1 || hora > 6 || verificar_hora(diaa, hora - 1, i, nombre, apellido));
    }

    return;
}
int verificar_hora(int dia, int hora, int i, const char *nombre, const char *apellido)
{
    inicializar_horario();
    if (horario[dia][hora].entero != 0)
    {
        printf("Hora ocupada - Escoja otra hora\n");
        return 1;
    }
    else
    {
        strncpy(horario[dia][hora].nombre, nombre, 11);
        strncpy(horario[dia][hora].apellido, apellido, 3);
        horario[dia][hora].entero = 1;
        horas_anadidas += 1;
        // Guardar el horario en el archivo
        actualizar_configuracion();
        actualizar_horario();
        return 0;
    }
}

DWORD WINAPI hilos_docentes(LPVOID lpParam)
{
    char sede[] = "Villa Asia";
    int x = 0, y = 3;
    for (int dia = 0; dia < 5; dia++)
    {
        for (int hora = 0; hora < 6; hora++)
        {
            // SE ESTA ABRIENDO UN TOTAL DE 30 VECES EN MENOS DE 1 MILISEGUNDO XD
            horario_asig(12 + x, y, dia, hora, 3, 13, sede);
            y += 5;
        }
        x += 19;
        y = 3;
    }
    gotoxy(0, 33);
    precione_una_tecla_para_continuar();

    return 0;
}

int horario_asig(int x, int y, int dia, int hora, int secciones, int aula, char *sede)
{
    inicializar_horario();
    if (horario[dia][hora].entero == 1)
    {
        gotoxy(x, y);
        printf("%s %s.", horario[dia][hora].nombre, horario[dia][hora].apellido);
        gotoxy(x, y + 1);
        printf("%s", horario[dia][hora].materia);
        gotoxy(x, y + 2);
        printf("Secc %d - Au %d", secciones, aula);
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
void HILOS_HORARIO()
{
    SetConsoleTitle("HORARIO - MOSTRANDO HORARIO DE CLASE");
    horario_mostrar();
    HANDLE threadHandle;
    DWORD threadId;
    threadHandle = CreateThread(NULL, 0, hilos_docentes, NULL, 0, &threadId);
    if (threadHandle == NULL)
    {
        printf("Error al crear el hilo\n");
        return;
    }
    WaitForSingleObject(threadHandle, INFINITE);
    CloseHandle(threadHandle);
    return;
}
// PARTE MENOS IMPORTANTES ARREGLOS GRAFICOS
void icon()
{
    HWND hwnd = GetConsoleWindow();
    system("mode con: cols=80 lines=25");
    // Cargar el icono desde un archivo .ico
    HICON hIcon = (HICON)LoadImage(NULL, "icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
    // Establecer el nuevo icono para la ventana
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    return;
}
void pantalla_carga(int x, int y, int z, int zz, int tiempo, int segundos)
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
    }
    limpia_linea(y + 2);
    limpia_linea(y);
    centrar_t("CARGA COMPLETADA", x, y);
    for (int i = 3; i >= 1; i--)
    {
        gotoxy(x - 9, y + 2);
        printf("SERA ENVIADO EN (%d)", i);
        Sleep(segundos);
        limpia_linea(y + 2);
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
        for (int i = 0; i < longitud; i++)
        {
            if (!isdigit(numero[i]))
            {
                limpia_linea(5);
                printf("La cedula no puede contener letras\n");
                return 0; // número incorrecto
            }
        }
        if (num > 6999999 && num < 30000000)
        {
            if (longitud != 8 && longitud != 7)
            {
                limpia_linea(5);
                return 0; // número incorrecto
            }
        }
        else if (num < 5000000)
        {
            limpia_linea(5);
            printf("El docentes no debe estar vivo\n");
            return 0; // Número incorrecto
        }
        else
        {
            limpia_linea(5);
            printf("El docente no tiene una edad acta\n");
            return 0; // Número incorrecto
        }
    }
    return 1; // número correcto
}

void limpia_linea(int y)
{
    gotoxy(0, y);
    printf("                                                                                                                                               ");
    gotoxy(0, y);
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
void precione_una_tecla_para_continuar()
{
    cursor(0);
    printf(">> Precione una tecla para continuar <<\n");
    system(pause);
    system("cls");
    cursor(1);
}

int inicializar_horario()
{
    FILE *horario_dat = fopen(F_horario_dat, "r");
    if (horario_dat == NULL)
    {
        horario_dat = fopen(F_horario_dat, "w");
    }
    // Leer la estructura del archivo
    fread(horario, sizeof(struct ElementoHorario), 5 * 6, horario_dat);
    fclose(horario_dat);
    return 0;
}

int actualizar_horario()
{
    FILE *horario_dat = fopen(F_horario_dat, "w");
    if (horario_dat == NULL)
    {
        printf("Error al abrir el archivo de horario\n");
        return 1;
    }
    // Escribir la estructura en el archivo
    fwrite(horario, sizeof(struct ElementoHorario), 5 * 6, horario_dat);
    fclose(horario_dat);
    return 0;
}
int inicializar_configuracion()
{
    FILE *config = fopen(configuraciones, "rb");
    if (config == NULL) // Si el archivo no existe, inicializamos las estructuras y escribimos el valor de horas_anadidas
    {
        config = fopen(configuraciones, "wb");
        struct ElementoHorario horario[5][6] = {0};
        struct docente docentes[100] = {0};
        struct materia materias[30] = {0};
        horas_anadidas = 0;
        numDocentes = 0;
        numMaterias = 0;
        return 1;
    }
    fread(&horas_anadidas, sizeof(int), 1, config);
    fread(&numDocentes, sizeof(int), 1, config);
    fread(&numMaterias, sizeof(int), 1, config);
    fread(&numAsignaciones, sizeof(int), 1, config);
    fclose(config);
    return 0;
}

int actualizar_configuracion()
{
    FILE *config = fopen(configuraciones, "wb");
    if (config == NULL)
    {
        printf("Error al abrir el archivo de configuración\n");
        return 1;
    }
    fwrite(&horas_anadidas, sizeof(int), 1, config);
    fwrite(&numDocentes, sizeof(int), 1, config);
    fwrite(&numMaterias, sizeof(int), 1, config);
    fwrite(&numAsignaciones, sizeof(int), 1, config);
    fclose(config);
    return 0;
}
void random(int *k, int i, int x)
{
    for (int j = 0; j < x; j++)
    {
        k[j] = ((rand() % 15) + 20);
        docentes[i].insc_doc[j] = k[j];
        srand(time(NULL));
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
            printf("%c\n", 179);
        }
    }
    // HORAS
    char horas[19][20] = {"HORA", "7:50 ", "8:40", "8:45 ", "9:35", "9:35 ", "10:30", "11:00 ", "11:50", "11:55 ", "12:40", "12:45 ", "01:40", " A", " A", " A", "  A", "  A", "  A"};
    int pos_y[19] = {1, 3, 5, 8, 10, 13, 15, 18, 20, 23, 25, 28, 30, 4, 9, 14, 19, 24, 29};
    for (int i = 0; i < 19; i++)
    {
        gotoxy(3, pos_y[i]);
        printf("%s", horas[i]);
    }
    // DIAS DE LA SEMANA
    char dias[5][10] = {"LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES"};
    int pos_x[5] = {17, 36, 54, 74, 93};
    for (int i = 0; i < 5; i++)
    {
        gotoxy(pos_x[i], 1);
        printf("%s", dias[i]);
    }
    // Para evitar escritura mal debida
    gotoxy(0, 33);
    return;
}

void asignar_materia_doc()
{
    inicializar_horario();
    inicializar_docentes();
    inicializar_materia();
    int opcion1, opcion2;
    system("mode con: cols=100 lines=50");
    centrar_t("DOCENTES DISPONIBLES EN SISTEMA", 50, 0);

    if (numDocentes == 0)
    {
        printf("\nNO HAY DOCENTES EN SISTEMA\n");
        precione_una_tecla_para_continuar();
        return;
    }

    int i = 10, j = 4;
    for (int x = 0; x < numDocentes; x++)
    {
        gotoxy(i, j);
        printf("%d.- %s %s", x + 1, docentes[x].nombre, docentes[x].apellido);
        j += 2;
        if (j >= 20)
        {
            i += 20;
            j = 4;
        }
    }
    printf("Escoga un docente para asignarle una materia >> ");
    scanf("%d", &opcion1);
    system("cls");

    centrar_t("MATERIAS DISPONIBLES EN SISTEMA", 50, 0);

    if (numMaterias > 0)
    {
        int i = 10, j = 4;
        for (int x = 0; x < numMaterias; x++)
        {
            gotoxy(i, j);
            printf("%d.- %s", x + 1, materias[x].nombre);
            j += 2;
            if (j >= 20)
            {
                i += 20;
                j = 4;
            }
        }

        printf("\n\n¿Qué materia le va a asignar al docente? >> ");
        scanf("%d", &opcion2);
        int x, z;
        for (x = 0; x < 0; x++)
        {
            for (z = 0; z < 0; z++)
            {
                if (strcmp(horario[x][z].nombre, docentes[opcion - 1].nombre) == 0) // Comparar cadena de caracteres
                {
                    strcpy(horario[x][z].nombre, materias[opcion2 - 1].nombre);
                }
            }
        }

        numAsignaciones++;
        actualizar_configuracion();
        actualizar_horario();
    }
    else
    {
        printf("NO HAY MATERIAS INSCRITAS EN SISTEMA :v ");
    }
}

void cargarMaterias()
{
    SetConsoleTitle("HORARIO - CARGA DE DATOS DE LAS MATERIAS");
    system("cls");
    printf("\nIngrese el n%cmero de materias a cargar: ", u);
    scanf("%d", &opcion);
    numMaterias += opcion;
    if ((inicializar_materia()) == 0)
    {
        actualizar_configuracion();
        for (int i = 0; i < opcion; i++)
        {
            system("cls");
            printf("\nIngrese los datos de la materia %d:\n", i + 1);
            printf("Nombre: ");
            scanf("%s", materias[i].nombre);
            printf("Unidades de credito: ");
            scanf("%d", &materias[i].unidades);
            printf("C%cdigo: ", o);
            scanf("%d", &materias[i].codigo);
            printf("Horas: ");
            scanf("%d", &materias[i].horas);
            printf("Cupos: ");
            scanf("%d", &materias[i].cupos);
            printf("Prelaci%cn: ", o);
            scanf("%d", &materias[i].prelacion);
            printf("\nSedes VILLA ASIA = 1 o ATLANTICO = 2 \nOpci%cn >> ", o);
            scanf("%d", &materias[i].secciones);

            if (materias[i].secciones == 1)
            {
                strcpy(materias[i].sede, "VILLA ASIA");
            }
            else if (materias[i].secciones == 2)
            {
                strcpy(materias[i].sede, "ATLANTICO");
            }
            printf("Secciones: ");
            scanf("%d", &materias[i].secciones);
            printf("Semestre: ");
            scanf("%d", &materias[i].semestre);
            system("cls");
        }
    }
    actualizar_materia();
}

int inicializar_materia()
{
    FILE *materia = fopen(F_materia, "r");
    if (materia == NULL)
    {
        materia = fopen(F_materia, "w");
    }
    // Leer la estructura del archivo
    fread(materias, sizeof(struct materia), numMaterias, materia);
    fclose(materia);
    return 0;
}

int actualizar_materia()
{
    FILE *materia = fopen(F_materia, "w");
    if (materia == NULL)
    {
        printf("Error al abrir el archivo de horario\n");
        return 1;
    }
    // Escribir la estructura en el archivo
    fwrite(materias, sizeof(struct materia), 50, materia);
    fclose(materia);
    return 0;
}

int inicializar_docentes()
{
    FILE *reg_docentes = fopen(F_registros_doc, "rb");
    if (reg_docentes == NULL)
    {
        // El archivo no existe, crearlo y abrirlo en modo de escritura
        reg_docentes = fopen(F_registros_doc, "wb");
        if (reg_docentes == NULL)
        {
            printf("Error al abrir o crear el archivo de registros de docentes\n");
            return 1;
        }
    }
    else
    {
        // Leer la estructura del archivo
        fread(docentes, sizeof(struct docente), numDocentes, reg_docentes);
    }
    fclose(reg_docentes);
    return 0;
}

int actualizar_docentes()
{
    FILE *reg_docentes = fopen(F_registros_doc, "wb");
    if (reg_docentes == NULL)
    {
        printf("Error al abrir el archivo de registros de docentes\n");
        return 1;
    }
    // Escribir la estructura en el archivo
    fwrite(docentes, sizeof(struct docente), numDocentes, reg_docentes);
    fclose(reg_docentes);
    return 0;
}

/*void mostrar_asignaciones()
{
    // Ordenar el arreglo de asignaciones alfabéticamente por nombre del docente
    for (int i = 0; i < numAsignaciones - 1; i++)
    {
        for (int j = i + 1; j < numAsignaciones; j++)
        {
            if (strcmp(asignaciones[i].nombre_doc, asignaciones[j].nombre_doc) > 0)
            {
                struct asignacion temp = asignaciones[i];
                asignaciones[i] = asignaciones[j];
                asignaciones[j] = temp;
            }
        }
    }
    // Mostrar las asignaciones ordenadas por materia y docente
    for (int i = 0; i < asignaciones->numAsignaciones; i++)
    {
        printf("Materia: %s\n", asignaciones[i].nombre_mat);
        printf("Docente: %s\n", asignaciones[i].nombre_doc);
    }
}*/

void mostrar_datos_completos_docentes()
{
    system("mode con: cols=120 lines=37");
    inicializar_configuracion();
    inicializar_docentes();
    // Ordenar los docentes por número de cédula
    qsort(docentes, numDocentes, sizeof(struct docente), comparar_cedula);
    printf("Datos completos de los docentes del semestre activo:\n\n");
    materia_mostrar();
    int j = 5;
    for (int i = 0; i < numDocentes; i++)
    {
        imprimirEstructura(docentes, i, j);
        j += 2;
    }
    gotoxy(0, 26);
    precione_una_tecla_para_continuar();
}

void mostrar_datos_completos_materias()
{
    system("mode con: cols=120 lines=37");
    inicializar_materia();
    inicializar_configuracion();
    // Ordenar las materias por unidades de crédito de menor a mayor
    qsort(materias, numMaterias, sizeof(struct materia), comparar_unidades_credito);
    system("mode con: cols=86 lines=32");
    centrar_t("Datos de las materias inscritas", 43, 0);
    printf("\n                   Ordenadas por unidades de cr%cdito de menor a mayor:\n\n", e);

    for (int i = 0; i < numMaterias; i++)
    {
        printf("-- Materia N: (%d) --\n", i + 1);
        printf("Nombre: %s\n", materias[i].nombre);
        printf("Unidades de cr%cdito: %d\n", e, materias[i].unidades);
        printf("C%cdigo: %d\n", o, materias[i].codigo);
        printf("Cupos: %d\n", materias[i].cupos);
        printf("Prelaci%cn: %d\n", o, materias[i].prelacion);
        printf("Secciones: %d\n", materias[i].secciones);
        printf("Pertenece: %d\n", materias[i].pertenece);
        printf("Horas: %d\n", materias[i].horas);
        printf("Semestre: %d\n", materias[i].semestre);
        printf("Alumnos inscritos: %d\n\n", materias[i].alumnos_inscritos);
    }

    precione_una_tecla_para_continuar();
}

int comparar_cedula(const void *a, const void *b) {
    const struct docente *docenteA = (const struct docente *)a;
    const struct docente *docenteB = (const struct docente *)b;
    return strcmp(docenteA->cedula_d, docenteB->cedula_d);
}

int comparar_unidades_credito(const void *a, const void *b)
{
    return ((struct materia *)a)->unidades - ((struct materia *)b)->unidades;
}

void materia_mostrar()
{
    // LINEASSSSSS HORIZONTALESSS
    int y_posiciones[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
    for (int y = 0; y < 12; y++)
    {
        for (int j = 1; j < 119; j++)
        {
            gotoxy(j, y_posiciones[y]);
            printf("%c\n", s);
        }
    }
    // LINEASSSSSS VERTICALESS
    int x_posiciones[] = {0, 6, 35, 48, 61, 74, 94, 118};
    for (int x = 0; x < 8; x++)
    {
        for (int j = 3; j < 24; j++)
        {
            gotoxy(x_posiciones[x], j);
            printf("%c\n", 179);
        }
    }
    gotoxy(2, 3);
    printf("N ");

    gotoxy(15, 3);
    printf("NOMBRE");

    gotoxy(37, 3);
    printf("C%cDULA", 144);

    gotoxy(50, 3);
    printf("TELEFONO");

    gotoxy(63, 3);
    printf("SECCIONES");

    gotoxy(80, 3);
    printf("INSCRITOS");

    gotoxy(100, 3);
    printf("DISPONIBLE");

    // ESQUINAS
    gotoxy(0, 2);
    printf("%c", 218);
    gotoxy(118, 24);
    printf("%c", 217);
    gotoxy(118, 2);
    printf("%c", 191);
    gotoxy(0, 24);
    printf("%c", 192);
}
void imprimirEstructura(struct docente *docentes, int i, int y)
{
    gotoxy(2, y);
    printf("%d", i + 1);
    gotoxy(8, y);
    printf("%s %s", docentes[i].nombre, docentes[i].apellido);
    gotoxy(36, y);
    printf("%s", docentes[i].cedula_d);
    gotoxy(49, y);
    printf("%s", docentes[i].telefono_d);
    gotoxy(66, y);
    printf("%d", 3);
    gotoxy(75, y);
    printf("S1:%d S2:%d S3:%d", docentes[i].insc_doc[0], docentes[i].insc_doc[1], docentes[i].insc_doc[2]);
    gotoxy(97, y);
    if (docentes[i].disp_doc == 1)
    {
        printf("DIA >> LUNES");
    }
    else if (docentes[i].disp_doc == 2)
    {
        printf("DIA >> MARTES");
    }
    else if (docentes[i].disp_doc == 3)
    {
        printf("DIA >> MI%CRCOLES", 144);
    }
    else if (docentes[i].disp_doc == 4)
    {
        printf("DIA >> JUEVES");
    }
    else if (docentes[i].disp_doc == 5)
    {
        printf("DIA >> VIERNES");
    }
    else
    {
        printf("ERROR >> FALLO ");
    }
}
void inicializar_todo()
{
    int inicializar_configuracion();
    int inicializar_horario();
    int inicializar_materia();
    int inicializar_docentes();
}
void actualizar_todo()
{
    int actualizar_configuracion();
    int actualizar_horario();
    int actualizar_materia();
    int actualizar_docentes();
}