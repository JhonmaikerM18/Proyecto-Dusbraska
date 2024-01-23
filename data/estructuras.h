#include "include.h"
int opcion, numDocentes, cantidad_de_lectura, numMaterias, temporal;
char nombre[13], apellido[5];

// Definici�n de la estructura de Docente

// FUNCIONES PROTOTIPO
void mostrar_docentes();
void random();
int comparador(const void *a, const void *b);
void mostrar_asignaciones();
void disponibilidad_de_horario(int, int);
int verificar_hora(int dia, int hora, int i, const char *nombre, const char *apellido);
int verificacion_de_realidad(char *numero, int x);
void limpia_linea(int y);
// PARTE DEL HORARIO ES ESTA
int horario_asig(int, int, int, int, int, int, char *, char *);
void gotoxy(int, int);
void horario_mostrar();
DWORD WINAPI hilos_docentes(LPVOID lpParam);
void HILOS_HORARIO();
void cursor(int);
int carga_de_datos_doc(int temporal);
void pantalla_carga(int x, int y, int z, int zz, int tiempo, int segundos);
void centrar_t(char *texto, int x, int y);
void cuadro(int xs, int ys, int xi, int yi);
void bloqueo_maximizar();
void precione_una_tecla_para_continuar();
int inicializar_configuracion();
int actualizar_configuracion();
int inicializar_horario();
int actualizar_horario();
int inicializar_materia();
int actualizar_materia();
void asignar_materia_doc();
void cargarMaterias();
int inicializar_docentes();
int actualizar_docentes();
void menu_est()
{
    do
    {
        HWND hwnd = GetConsoleWindow();
        SetConsoleTitle("HORARIO - MENU DE INICIO");
        system("mode con: cols=80 lines=25");
        bloqueo_maximizar();
        if ((inicializar_configuracion()) != 1)
        {
            actualizar_configuracion();
        }
        system("cls");
        printf("BIENVENIDO(a) \n");
        printf("Que desea realizar hoy?\n\n");
        printf("1.- CARGAR DATOS DE LOS DOCENTES\n");
        printf("2.- CARGAR DATOS DE LAS MATERIAS\n");
        printf("3.- MOSTRAR HORARIO\n");
        printf("4.- MOSTRAR DATOS DE LOS DOCENTES \n");
        printf("5.- MOSTRAR MATERIAS\n");
        printf("6.- MOSTRAR DOCENTES CON SU MATERIA ASIGNADA\n");
        printf("7.- MOSTRAR LA RELACION DE DOCENTES CON ESTUDIANTES INSCRITOS\n");
        printf("8.- ELIMINAR DATOS\n");
        printf("INGRESE OPCION A ESCOGER >>");

        gotoxy(2, 18);
        printf("Docentes cargados en sistema   >> %d", numDocentes);
        gotoxy(2, 20);
        printf("Materias cargadas en sistema   >> %d", numMaterias);
        gotoxy(2, 22);
        printf("Docentes con Materia asignadas >> %d", 0);
        cuadro(1, 17, 78, 23);
        gotoxy(28, 11);
        scanf("%d", &opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            SetConsoleTitle("HORARIO - CARGA DE DATOS DE LOS DOCENTES");
            printf("%cCuantos docentes van a quedar en registro? \n", signo);
            while (1)
            {
                if (scanf("%d", &temporal) != 1 || temporal < 1 || temporal > 42)
                {
                    if (temporal > 42)
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
                    numDocentes += temporal;
                    actualizar_configuracion();
                    carga_de_datos_doc(temporal);
                    break;
                }
            }
            break;
        case 2:
            cargarMaterias();
            break;
        case 3:
            HILOS_HORARIO();
            break;
        case 4:
            mostrar_docentes();
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
                mostrar_asignaciones();
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
                printf("Los Archivos de datos fue eliminado satifactoriamente\n");
                precione_una_tecla_para_continuar();
            }
            break;
        case 9:
            cursor(0);
            printf("QUE TENGA UN LINDO DIA :) ");
            return;
            break;
        case 10:
            HILOS_HORARIO();
            break;
        default:
            break;
        }
    } while (opcion != 9);
}

int carga_de_datos_doc(int temporal)
{
    system("cls");
    for (int i = 0; i < temporal; i++)
    {
        printf("\tIngrese los datos del docente %d\n\n", i + 1);
        printf("Nombre del docente > ");
        scanf("%s", docentes[i].nombre);
        fflush(stdin);
        printf("Apellido del docente > ");
        scanf("%s", docentes[i].apellido);
        fflush(stdin);
        printf("Semestre del docente > ");
        while (scanf("%d", &docentes[i].semestre) != 1 || docentes[i].semestre < 1 || docentes[i].semestre > 9)
        {
            printf("Error: Ingrese un número válido (1-9) > ");
            while (getchar() != '\n')
                ;
        }
        printf("Ingrese la cédula del docente > ");
        scanf("%s", docentes[i].cedula_d);
        while (!verificacion_de_realidad(docentes[i].cedula_d, 1))
        {
            printf("Ingrese nuevamente >> ");
            scanf("%s", docentes[i].cedula_d);
        }
        printf("Ingrese un número de teléfono > ");
        scanf("%s", docentes[i].telefono_d);
        while (!verificacion_de_realidad(docentes[i].telefono_d, 0))
        {
            printf("Error - Ingrese un número de teléfono correcto > ");
            scanf("%s", docentes[i].telefono_d);
        }
        random(docentes[i].insc_doc, 3);

        printf("\nLunes = 1  /  Martes  = 2  /  Miércoles = 3 / Jueves = 4  /  Viernes = 5\n");
        printf("Ingrese el día disponible del docente > ");
        strncpy(nombre, docentes[i].nombre, 12);
        strncpy(apellido, docentes[i].apellido, 4);
        for (int j = 0; j < 1; j++)
        {
            int dia;
            scanf("%d", &dia);
            inicializar_horario();
            if (dia >= 1 && dia <= 5)
            {
                if (horario[dia][1].entero && horario[dia][2].entero && horario[dia][3].entero && horario[dia][4].entero && horario[dia][5].entero && horario[dia][6].entero)
                {
                    printf("Horario lleno - Ingrese otro día > ");
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
    printf("DATOS AÑADIDOS SATISFACTORIAMENTE\n");
    precione_una_tecla_para_continuar();
    actualizar_docentes();
    return 0;
}

void mostrar_docentes()
{
    SetConsoleTitle("HORARIO - MOSTRAR DATOS DE LOS DOCENTES");
    inicializar_docentes();
    qsort(docentes, numDocentes, sizeof(struct docente), comparador); // Ordenar el arreglo de docentes por cédula
    printf("Mostrando datos de los docentes ordenados por CI\n");
    for (int j = 0; j < numDocentes; j++)
    {
        printf("Docente N(%d)\n", j + 1);
        printf("Nombre: %s\n", docentes[j].nombre);
        printf("Apellido: %s\n", docentes[j].apellido);
        printf("C%cdula: %s\n", e, docentes[j].cedula_d);
        printf("Semestre que pertenece: %d\n", docentes[j].semestre);
        printf("Tel%cfono: %s\n", e, docentes[j].telefono_d);
    }
    precione_una_tecla_para_continuar();
    return;
}
void disponibilidad_de_horario(int diaa, int i)
{
    struct docente docentes[numDocentes];
    int hora;
    system("cls");
    printf("    Ingrese el horario disponible del docente \n");
    printf("           El docente tiene 3 horas ");
    gotoxy(4, 3);
    printf("      HORA      %c    NUMERO  \n", 179);
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
            printf("Ingrese hora escogida número (%d) > ", y + 1);
            if (scanf("%d", &hora) != 1 || hora < 1 || hora > 6)
            {
                printf("Error de entrada - Intente nuevamente\n");
                while (getchar() != '\n')
                    ;
            }
        } while (hora < 1 || hora > 6 || verificar_hora(diaa - 1, hora - 1, i, nombre, apellido));
    }
    actualizar_horario();
    return;
}
int verificar_hora(int dia, int hora, int i, const char *nombre, const char *apellido)
{
    if ((inicializar_configuracion()) != 1)
    {
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
            cantidad_de_lectura += 1;
            // Guardar el horario en el archivo
            actualizar_configuracion();
            return 0;
        }
    }
    else
    {
        printf("HUBO UN ERROR\n");
        return 1;
    }
}

DWORD WINAPI hilos_docentes(LPVOID lpParam)
{
    char materia[] = "Fundamentos";
    char sede[] = "Villa asia";
    int x = 0, y = 3;
    for (int dia = 0; dia < 5; dia++)
    {
        for (int hora = 0; hora < 6; hora++)
        {
            // SE ESTA ABRIENDO UN TOTAL DE 30 VECES EN MENOS DE 1 MILISEGUNDO XD
            horario_asig(12 + x, y, dia, hora, 3, 13, materia, sede);
            y += 5;
        }
        x += 19;
        y = 3;
    }
    gotoxy(0, 33);
    precione_una_tecla_para_continuar();

    return 0;
}

int horario_asig(int x, int y, int dia, int hora, int secciones, int aula, char *materia, char *sede)
{
    if (horario[dia][hora].entero == 1)
    {
        gotoxy(x, y);
        printf("%s %s.", horario[dia][hora].nombre, horario[dia][hora].apellido);
        gotoxy(x, y + 1);
        printf("%s", materia);
        gotoxy(x, y + 2);
        printf("Secc %d - Au %d", secciones, aula);
        gotoxy(x, y + 3);
        printf("%s, %d , %d", sede, dia, hora);
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
    HICON hIcon = (HICON)LoadImage(NULL, "data/icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
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

// Función de comparación para qsort
int comparador(const void *a, const void *b)
{
    return strcmp(((struct docente *)a)->cedula_d, ((struct docente *)b)->cedula_d);
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
        printf("Error al abrir el archivo de horario\n");
        return 1;
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
    if (config == NULL) // Si el archivo no existe, inicializamos las estructuras y escribimos el valor de cantidad_de_lectura
    {
        config = fopen(configuraciones, "wb");
        struct ElementoHorario horario[5][6] = {0};
        struct docente docentes[100] = {0};
        struct materia materias[30] = {0};
        struct asignacion asignando[50] = {0};
        cantidad_de_lectura = 0;
        numDocentes = 0;
        numMaterias = 0;
        return 1;
    }
    fread(&cantidad_de_lectura, sizeof(int), 1, config);
    fread(&numDocentes, sizeof(int), 1, config);
    fread(&numMaterias, sizeof(int), 1, config);
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
    fwrite(&cantidad_de_lectura, sizeof(int), 1, config);
    fwrite(&numDocentes, sizeof(int), 1, config);
    fwrite(&numMaterias, sizeof(int), 1, config);
    fclose(config);
    return 0;
}
void random(int *k, int x)
{
    for (int j = 0; j < x; j++)
    {
        k[j] = ((rand() % 15) + 20);
    }
    srand(time(NULL));
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
        printf("%d.- %s", x + 1, docentes[x].nombre);
        j += 2;
        if (j >= 20)
        {
            i += 20;
            j = 4;
        }
    }
    gotoxy(0, 2);
    printf("Escoga un docente para asignarle una materia >> ");
    scanf("%d", &opcion1);
    system("cls");

    centrar_t("MATERIAS DISPONIBLES EN SISTEMA", 50, 0);
    if (numMaterias > 0)
    {
        i = 10, j = 4;
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
        gotoxy(0, 2);
        printf("¿Qué materia le va a asignar al docente? >> ");
        scanf("%d", &opcion2);
        strcpy(asignaciones[1].nombre_doc, docentes[opcion1].nombre);
        strcpy(asignaciones[1].nombre_mat, materias[opcion2].nombre);
        asignaciones->numAsignaciones++;
    }
    else
    {
        gotoxy(0, 2);
        printf("NO HAY MATERIAS INSCRITAS EN SISTEMA :v ");
    }
}

void cargarMaterias()
{
    SetConsoleTitle("HORARIO - CARGA DE DATOS DE LAS MATERIAS");
    system("cls");
    printf("\nIngrese el numero de materias a cargar: ");
    scanf("%d", &opcion);
    numMaterias = (opcion + numMaterias);
    if ((inicializar_materia()) == 0)
    {
        for (int i = 0; i < numMaterias; i++)
        {
            system("cls");
            printf("\nIngrese los datos de la materia %d:\n", i + 1);
            printf("Nombre: ");
            scanf("%s", materias[i].nombre);
            printf("Unidades de credito: ");
            scanf("%d", &materias[i].unidades);
            printf("Cupos: ");
            scanf("%d", &materias[i].cupos);
            printf("Prelacion: ");
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
        FILE *materia = fopen(F_materia, "w");
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
    FILE *reg_docentes = fopen(F_registros_doc, "r");
    if (reg_docentes == NULL)
    {
        FILE *materia = fopen(F_registros_doc, "w");
    }
    // Leer la estructura del archivo
    fread(docentes, sizeof(struct docente), numDocentes, reg_docentes);
    fclose(reg_docentes);
    return 0;
}

int actualizar_docentes()
{
    FILE *reg_docentes = fopen(F_registros_doc, "w");
    if (reg_docentes == NULL)
    {
        printf("Error al abrir el archivo de horario\n");
        return 1;
    }
    // Escribir la estructura en el archivo
    fwrite(docentes, sizeof(struct docente), numDocentes, reg_docentes);
    fclose(reg_docentes);
    return 0;
}

void mostrar_asignaciones()
{
    // Ordenar el arreglo de asignaciones alfabéticamente por nombre del docente
    for (int i = 0; i < asignaciones->numAsignaciones - 1; i++)
    {
        for (int j = i + 1; j < asignaciones->numAsignaciones; j++)
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
}