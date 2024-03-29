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
    char nombre[12], apellido[12], materia[30], sede[20];
    int entero;
};
struct materia
{
    char nombre[30], sede[12], nombre_doc[6][30], apellido_doc[6][30], unidades[5], codigo[7], cupos[2], prelacion[7], pertenece[1], horas[1], semestre[1];
    int docentes[6], n_materia, alumnos_inscritos[5], secciones, color[20];
};

// Estructurassss
struct materia materias[30];
struct ElementoHorario horario[5][6];
struct docente docentes[100];

// VARIABLES GLOBALES
int opcion, numDocentes, horas_anadidas, numMaterias, numAsignaciones, temporal, colores_asignados[16];

// Definici�n de la estructura de Docente

// FUNCIONES PRINCIPALES
void menu_est();
int carga_de_docentes();
void cargar_de_materia();
void asignar_materia_doc();
void mostrar_asignaciones();
void mostrar_docentes();
void mostrar_datos_completos_docentes();
void mostrar_datos_completos_materias();
// FUNCIONES PRINCIPALES ->>> PARTE DEL HORARIO ES ESTA
void horario_asig(int, int, int, int, int, int);
void hilos_docentes();
void disponibilidad_de_horario(int, int);
void horario_mostrar();
int verificar_hora(int, int, int, const char *, const char *, const char *, const char *);
// ACTUALIZAR FICHEROS
int actualizar_configuracion();
int actualizar_horario();
int actualizar_materias();
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
void docente_mostrar_cuadro();
void materia_mostrar_cuadro();
void icon();
void gotoxy(int, int);
void pantalla_carga(int, int, int, int, int, int);
void precione_una_tecla_para_continuar();
// FUNCIONES DE COMPARACION
int comparar_cedula(const void *a, const void *b);
int comparar_unidades_credito(const void *a, const void *b);
int verificacion_de_realidad(char *numero, int x);
int SoloNumeros(char *cadena);
int SoloLetras(char *cadena);
// VARIADASSS
void random();
void asignar_color_materia(const char *materia);
int obtener_color_unico();
int color_repetido(int color);
void imprimir_Docentes(struct docente *docentes, int i, int y);
void imprimir_Materias(struct materia *materias, int i, int y);

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
        printf("3.- ASIGNARLE DOCENTE UNA MATERIA\n");
        printf("4.- MOSTRAR HORARIO\n");
        printf("5.- MOSTRAR DATOS DE LOS DOCENTES \n");
        printf("6.- MOSTRAR MATERIAS\n");
        printf("7.- MOSTRAR DOCENTES CON SU MATERIA ASIGNADA\n");
        // printf("8.- MOSTRAR LA RELACION DE DOCENTES CON ESTUDIANTES INSCRITOS\n");
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
        printf("Docentes con materia asignadas  >>  %d", numAsignaciones);
        gotoxy(42, 18);
        printf("Horas a%cadidas en el horario >>  %d", 164, horas_anadidas);
        cuadro(1, 15, 78, 23);
        gotoxy(28, 12);
        scanf("%d", &opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            carga_de_docentes();
            break;
        case 2:
            cargar_de_materia();
            break;
        case 3:
            asignar_materia_doc();
            break;
        case 4:
            hilos_docentes();
            // HILOS_HORARIO();
            break;
        case 5:
            mostrar_datos_completos_docentes();
            break;
        case 6:
            mostrar_datos_completos_materias();
            break;
        case 7:
            mostrar_asignaciones();
            break;
        case 8:
            system("cls");
            remove(F_horario_dat);
            remove(configuraciones);
            remove(F_registros_doc);
            remove(F_materia);
            remove(pause);
            printf("Los Archivos de datos fue eliminado satifactoriamente\n");
            precione_una_tecla_para_continuar();
            break;
        case 9:
            cursor(0);
            printf("QUE TENGA UN LINDO DIA :) ");
            Sleep(2000);
            return;
            break;
        default:
            printf("Entrda no v%clida - Intente nuevamente\n", aa);
            precione_una_tecla_para_continuar();
            break;
        }
    } while (opcion != 9);
}

int carga_de_docentes()
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
        system("cls");
        numDocentes++;
        actualizar_configuracion();
    }
    printf("DATOS A%cADIDOS SATISFACTORIAMENTE\n", NN);

    actualizar_docentes();
    precione_una_tecla_para_continuar();
    return 0;
}

void disponibilidad_de_horario(int i, int x)
{
    int dia, hora;
    char nombre[13], apellido[5], materia[30], sede[30];
    inicializar_todo();
    system("cls");
    printf("Ingrese el d%ca disponible del docente >> ", ai);
    printf("\nLunes = 1  /  Martes  = 2  /  Mi%crcoles = 3 / Jueves = 4  /  Viernes = 5\n>> ", e);
    strncpy(nombre, docentes[i].nombre, 12);
    strncpy(apellido, docentes[i].apellido, 4);
    strcpy(materia, materias[x].nombre);
    strcpy(sede, materias[x].sede);
    for (int j = 0; j < 1; j++)
    {
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
            // Hace el pase aca de autorizacion
        }
        else
        {
            printf("\nIntente nuevamente (1-5) >> ");
            j--;
        }
    }
    system("cls");
    printf("    Ingrese el horario disponible del docente \n");
    printf("           El docente tiene 3 horas ");
    gotoxy(1, 3);
    printf("         HORA      %c    N%cMERO  \n", 179, 154);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, 197, s, s, s, s, s, s, s, s, s, s, s, s, s, s, 179);
    printf("                    %c           \n", 179);
    printf("      7:50 A 8:40   %c    (1)    \n", 179);
    printf("      8:45 A 9:35   %c    (2)    \n", 179);
    printf("      9:35 A 10:30  %c    (3)    \n", 179);
    printf("      X DESCANSO X  %c           \n", 179);
    printf("     11:00 A 11:50  %c    (4)    \n", 179);
    printf("     11:55 A 12:40  %c    (5)    \n", 179);
    printf("     12:45 A 01:40  %c    (6)    \n", 179);
    printf("                    %c           \n", 179);
    cuadro(3, 2, 34, 14);
    gotoxy(0, 16);
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
        } while (hora < 1 || hora > 6 || verificar_hora(dia, hora - 1, i, nombre, apellido, materia, sede));
    }
    return;
}
int verificar_hora(int dia, int hora, int i, const char *nombre, const char *apellido, const char *materia, const char *sede)
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
        strncpy(horario[dia][hora].materia, materia, 26);
        strcpy(horario[dia][hora].sede, sede);

        horario[dia][hora].entero = 1;
        horas_anadidas += 1;
        // Guardar el horario en el archivo
        actualizar_configuracion();
        actualizar_horario();
        return 0;
    }
}
void hilos_docentes()
{
    SetConsoleTitle("HORARIO - MOSTRANDO HORARIO DE CLASE");
    system("mode con: cols=120 lines=37");
    horario_mostrar();
    int x = 0, y = 3;
    for (int dia = 0; dia < 5; dia++)
    {
        for (int hora = 0; hora < 6; hora++)
        {
            // SE ESTA ABRIENDO UN TOTAL DE 30 VECES EN MENOS DE 1 MILISEGUNDO XD
            horario_asig(12 + x, y, dia, hora, 3, 13);
            y += 5;
        }
        x += 19;
        y = 3;
    }
    gotoxy(0, 33);
    precione_una_tecla_para_continuar();
    return;
}

void horario_asig(int x, int y, int dia, int hora, int secciones, int aula)
{
    inicializar_horario();
    if (horario[dia][hora].entero == 1)
    {
        asignar_color_materia(horario[dia][hora].materia); // Llamar a la función para asignar un color único a la materia

        gotoxy(x, y);
        printf("%s %s.", horario[dia][hora].nombre, horario[dia][hora].apellido);
        gotoxy(x, y + 1);
        printf("%s", horario[dia][hora].materia);
        gotoxy(x, y + 2);
        printf("Secc %d - Au %d", secciones, aula);
        gotoxy(x, y + 3);
        printf("%s", horario[dia][hora].sede);

        // Restaurar el color predeterminado
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else
    {
        gotoxy(x, y + 1);
        printf("    HORARIO  ");
        gotoxy(x, y + 2);
        printf("  NO ASIGNADO");
    }
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
        int colores_asignados[16] = {0};
        horas_anadidas = 0;
        numDocentes = 0;
        numMaterias = 0;
        numAsignaciones = 0;
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
void asignar_color_materia(const char *materia)
{
    int color = 0;
    for (int i = 0; i < 15; i++)
    {
        if (strcmp(materias[i].nombre, materia) == 0)
        {
            if (colores_asignados[i] == 0)
            {
                color = obtener_color_unico();
                colores_asignados[i] = color;
            }
            else
            {
                color = colores_asignados[i];
            }
            break;
        }
    }
    // Usar el color asignado para la materia
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int obtener_color_unico()
{
    int color = 0;
    do
    {
        color = (rand() % 15) + 1; // Generar un número de color aleatorio entre 1 y 15
    } while (color_repetido(color));
    return color;
}

int color_repetido(int color)
{
    for (int i = 1; i < 15; i++)
    {
        if (colores_asignados[i] == color)
        {
            return 1; // Color repetido
        }
    }
    return 0; // Color único
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

    gotoxy(106, 0);
    printf("%c", 191);
    gotoxy(0, 32);
    printf("%c", 192);
    gotoxy(106, 32);
    printf("%c", 217);

    // Para evitar escritura mal debida
    gotoxy(0, 33);
    return;
}
void mostrar_docentes()
{
    inicializar_todo();
    system("mode con: cols=100 lines=50");
    centrar_t("DOCENTES DISPONIBLES EN SISTEMA", 50, 0);

    if (numDocentes == 0)
    {
        printf("\n\nNO HAY DOCENTES EN SISTEMA\n\n");
        precione_una_tecla_para_continuar();
        return;
    }

    int i = 10, j = 2;
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
    gotoxy(0, 20);
}

void asignar_materia_doc()
{
    mostrar_docentes();
    int opcion1, opcion2;
    char materia[30];
    if (numDocentes == 0)
    {
        return;
    }
    printf("Escoja un docente para asignarle una materia >> ");
    scanf("%d", &opcion1);
    system("cls");
    centrar_t("MATERIAS DISPONIBLES EN SISTEMA", 50, 0);

    if (numMaterias > 0)
    {
        int i = 10, j = 2;
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
        gotoxy(0, 20);
        printf("%cQu%c materia le va a asignar al docente? >> ", signo, e);
        scanf("%d", &opcion2);
        opcion1--;
        opcion2--;
        for (int i = 0; i < 6; i++)
        {
            if (materias[opcion2].docentes[i] == 0)
            {
                materias[opcion2].docentes[i] = i + 1;
                strcpy(materias[opcion2].apellido_doc[i], docentes[opcion1].apellido);
                strcpy(materias[opcion2].nombre_doc[i], docentes[opcion1].nombre);
                strcpy(docentes[opcion1].materia, materias[opcion2].nombre);
                strcpy(materia, docentes[opcion1].materia);
                break;
            }
        }
        disponibilidad_de_horario(opcion1, opcion2);
        // strcpy(asignaciones[numAsignaciones].nombre_mat, materias[opcion2].nombre);
        numAsignaciones++;
        actualizar_configuracion();
        actualizar_materias();
        system("cls");
        printf("DATOS A%cADIDOS SATIFACTORIAMENTE\n", 165);
        precione_una_tecla_para_continuar();
    }
    else
    {
        printf("\n\nNO HAY MATERIAS INSCRITAS EN SISTEMA\n");
        precione_una_tecla_para_continuar();
    }
}

void cargar_de_materia()
{
    SetConsoleTitle("HORARIO - CARGA DE DATOS DE LAS MATERIAS");
    system("cls");
    printf("Ingrese el n%cmero de materias a cargar: ", u);
    scanf("%d", &opcion);
    if ((inicializar_materia()) == 0)
    {
        temporal = (numMaterias + opcion);
        for (int i = numMaterias; i < temporal; i++)
        {
            char nombre[30] = " ";
            system("cls");
            printf("                 Ingrese los datos de la materia (%d)\n\n", i + 1);
            materias[i].n_materia = numMaterias;
            printf("Nombre >> ");
            scanf("%s", materias[i].nombre);
            fflush(stdin);
            printf("Unidades de credito >> ");
            scanf("%s", materias[i].unidades);
            fflush(stdin);
            while ((SoloNumeros(materias[i].unidades)) == 1)
            {
                scanf("%s", materias[i].unidades);
            }
            printf("C%cdigo >> ", o);
            scanf("%s", materias[i].codigo);
            fflush(stdin);
            while ((SoloNumeros(materias[i].codigo)) == 1)
            {
                scanf("%s", materias[i].codigo);
            }
            fflush(stdin);
            printf("Horas >> ");
            scanf("%s", materias[i].horas);
            fflush(stdin);
            while ((SoloNumeros(materias[i].horas)) == 1)
            {
                scanf("%s", materias[i].horas);
            }
            fflush(stdin);
            printf("Cupos >> ");
            scanf("%s", materias[i].cupos);
            fflush(stdin);
            while ((SoloNumeros(materias[i].cupos)) == 1)
            {
                scanf("%s", materias[i].cupos);
            }
            printf("Prelaci%cn >> ", o);
            scanf("%s", materias[i].prelacion);
            fflush(stdin);
            while ((SoloNumeros(materias[i].prelacion)) == 1)
            {
                scanf("%s", materias[i].prelacion);
            }
            printf("\nSedes: VILLA ASIA = 1 o ATLANTICO = 2 \nOpci%cn >> ", o);
            scanf("%d", &materias[i].secciones);

            if (materias[i].secciones == 1)
            {
                strcpy(materias[i].sede, "VILLA ASIA");
            }
            else if (materias[i].secciones == 2)
            {
                strcpy(materias[i].sede, "ATLANTICO");
            }

            printf("Secciones >> ");
            scanf("%d", &materias[i].secciones);
            if (materias[i].secciones < 1 || materias[i].secciones > 3)
            {
                if (materias[i].secciones > 3)
                {
                    printf("Demaciadas secciones - Intente poner menos\n>> ");
                }
                else
                {
                    printf("Intente nuevamente\n>> ");
                }
                scanf("%d", &materias[i].secciones);
            }

            fflush(stdin);
            printf("Semestre >> ");
            scanf("%s", materias[i].semestre);
            while ((SoloNumeros(materias[i].semestre)) == 1)
            {
                scanf("%s", materias[i].semestre);
            }
            system("cls");
            numMaterias++;
            actualizar_materias();
            actualizar_configuracion();
        }
    }
}

int SoloNumeros(char *cadena)
{
    for (int i = 0; i < strlen(cadena); i++)
    {
        if (!isdigit(cadena[i]))
        {
            printf("Ingrese nuevamente >> ");
            return 1;
        }
    }
    return 0;
}

int validar_cadena(char cadena[50])
{
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

int actualizar_materias()
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

void mostrar_asignaciones()
{
    system("cls");
    // Mostrar las asignaciones ordenadas por materia y docente
    for (int i = 0; i < numAsignaciones; i++)
    {
        printf("Materia: %s\n", materias[i].nombre);
        for (int j = 0; j < 6; j++)
        {
            if (materias[i].docentes[j] != 0)
            {
                printf("(%d) Docente: %s %s\n", materias[i].docentes[j], materias[i].nombre_doc[j], materias[i].apellido_doc[j]);
            }
        }
        printf("\n");
    }
    gotoxy(0, 20);
    precione_una_tecla_para_continuar();
}

void mostrar_datos_completos_docentes()
{
    system("mode con: cols=120 lines=37");
    inicializar_configuracion();
    inicializar_docentes();
    // Ordenar los docentes por número de cédula
    qsort(docentes, numDocentes, sizeof(struct docente), comparar_unidades_credito);
    printf("Datos completos de los docentes del semestre activo:\n\n");
    docente_mostrar_cuadro();
    int j = 5;
    for (int i = 0; i < numDocentes; i++)
    {
        imprimir_Docentes(docentes, i, j);
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
    centrar_t("Datos de las materias inscritas", 60, 0);
    gotoxy(34, 1);
    printf("Ordenadas por unidades de cr%cdito de menor a mayor", e);
    materia_mostrar_cuadro();
    int j = 5;
    for (int i = 0; i < numMaterias; i++)
    {
        imprimir_Materias(materias, i, j);
        j += 2;
    }
    gotoxy(0, 26);
    precione_una_tecla_para_continuar();
}

int comparar_cedula(const void *a, const void *b)
{
    const struct docente *docenteA = (const struct docente *)a;
    const struct docente *docenteB = (const struct docente *)b;
    return strcmp(docenteA->cedula_d, docenteB->cedula_d);
}

int comparar_unidades_credito(const void *a, const void *b)
{
    return ((struct materia *)a)->unidades - ((struct materia *)b)->unidades;
}

void docente_mostrar_cuadro()
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
void materia_mostrar_cuadro()
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
    int x_posiciones[] = {0, 6, 35, 41, 53, 68, 82, 95, 107, 118};
    for (int x = 0; x < 10; x++)
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
    printf("MATERIA");

    gotoxy(37, 3);
    printf("U.C");

    gotoxy(45, 3);
    printf("CODIGO");

    gotoxy(56, 3);
    printf("PRELACION");

    gotoxy(72, 3);
    printf("SEDE");

    gotoxy(84, 3);
    printf("SECCIONES");

    gotoxy(98, 3);
    printf("CUPOS");

    gotoxy(109, 3);
    printf("SEMESTRE");

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
void imprimir_Docentes(struct docente *docentes, int i, int y)
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
    for (int y = 0; y < 3; y++)
    {
        if (docentes[i].insc_doc[y] > 0)
        {
            printf("S%d:%d ", y + 1, docentes[i].insc_doc[y]);
        }
        if ((docentes[i].insc_doc[0] || docentes[i].insc_doc[1] || docentes[i].insc_doc[2]) == 0)
        {
            printf(" X ");
        }
    }
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
        printf("NO ASIGNADO");
    }
}
void imprimir_Materias(struct materia *materias, int i, int y)
{
    // LINEASSSSSS VERTICALESS
    int x_posiciones[] = {0, 6, 35, 41, 53, 68, 82, 95, 107, 118};

    gotoxy(3, y);
    printf("%d", i + 1);
    gotoxy(8, y);
    printf("%s", materias[i].nombre);
    gotoxy(38, y);
    printf("%s", materias[i].unidades);
    gotoxy(42, y);
    printf("%s", materias[i].codigo);
    gotoxy(54, y);
    printf("%s", materias[i].prelacion);
    gotoxy(70, y);
    printf("%s", materias[i].sede);
    gotoxy(88, y);
    printf("%d", materias[i].secciones);
    gotoxy(100, y);
    printf("%s", materias[i].cupos);
    gotoxy(112, y);
    printf("%s", materias[i].semestre);
}

void inicializar_todo()
{
    inicializar_configuracion();
    inicializar_horario();
    inicializar_materia();
    inicializar_docentes();
}
void actualizar_todo()
{
    actualizar_configuracion();
    actualizar_horario();
    actualizar_materias();
    actualizar_docentes();
}