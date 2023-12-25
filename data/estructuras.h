#include "include.h"
int valido = 0;
int horario[5][6];
int cantidad_doc;
// Definici�n de la estructura de Docente
struct docente
{
    char nombre_doc[12], apellido_doc[12], telefono_d[13], cedula_d[10];
    int secciones_doc, disp_doc, insc_doc[4], dia_disp[4];
    int uno[5], dos[5], tres[5], cuatro[5], cinco[5], seis[5];
};

void random();
void disponibilidad_de_horario();
int verificar_hora(int diaa, int hora, int limpio);
int verificacion_de_realidad(char *numero, int x);
int verificar_numero(char *cadena);

int carga_de_datos_doc(int cantidad_doc)
{
    struct docente docentes[32];
    verificar_hora(0, 0, 0); // Limpiar los horarios para evitar Problemas xD

    system("cls");
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

            /*printf("\nIngrese la dia_disp del docente - Un n%cmero entero por dia disponible > ", u);
            scanf("%d", &docentes[i].disp_doc);
            while (valido == 1)
            {
                printf("Ingrese las secciones asignadas > ");
                scanf("%d", &docentes[i].secciones_doc);
                getchar();

                if (docentes[i].secciones_doc > 0 && docentes[i].secciones_doc < 4)
                {
                    random(docentes[i].insc_doc, docentes[i].secciones_doc);
                    valido = 2;
                    fflush(stdin);
                }
                else
                {
                    printf("Cantidad v%clida entre 1 a 3. El M%cximo de secciones es 3 por docente.\n", aa, aa);
                }
            fflush(stdin);
            }*/

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
                    if ((horario[1][1] && horario[1][2] && horario[1][3] && horario[1][4] && horario[1][5] && horario[1][6]) == 1)
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
                    if ((horario[2][1] && horario[2][2] && horario[2][3] && horario[2][4] && horario[2][5] && horario[2][6]) == 1)
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
                    if ((horario[3][1] && horario[3][2] && horario[3][3] && horario[3][4] && horario[3][5] && horario[3][6]) == 1)
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
                    if ((horario[4][1] && horario[4][2] && horario[4][3] && horario[4][4] && horario[4][5] && horario[4][6]) == 1)
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
                    if ((horario[5][1] && horario[5][2] && horario[5][3] && horario[5][4] && horario[5][5] && horario[5][6]) == 1)
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

int mostrar_datos_doc(int cantidad_doc)
{

    FILE *registros_docentes;
    struct docente docentes[32];

    registros_docentes = fopen("data/registros_doc", "rb");
    if (registros_docentes)
    {
        fread(docentes, sizeof(struct docente), cantidad_doc, registros_docentes);
        fclose(registros_docentes);
        for (i = 0; i < cantidad_doc; i++)
        {
            printf("\t------------ Datos del docente %d ------------ \n\n", i + 1);
            printf("Nombre del docente > %s\n", docentes[i].nombre_doc);
            printf("El Apellido del docente > %s\n", docentes[i].apellido_doc);
            printf("Ingrese la c%cdula del docente > %s \n", e, docentes[i].cedula_d);
            printf("Ingrese el tel%cfono del docente > %s \n\n", e, docentes[i].telefono_d);
            printf("La dia_disp del docente son los d%cas > ", ai);

            if (docentes[i].dia_disp[0] == 1)
            {
                printf("Lunes ");
            }
            if (docentes[i].dia_disp[1] == 2)
            {
                printf("Martes ");
            }
            if (docentes[i].dia_disp[2] == 3)
            {
                printf("Mi%crcoles ", e);
            }
            if (docentes[i].dia_disp[3] == 4)
            {
                printf("Jueves ");
            }
            if (docentes[i].dia_disp[4] == 5)
            {
                printf("Viernes ");
            }

            printf("\n\nLas secciones asignadas > %d \n", docentes[i].secciones_doc);
            for (int j = 0; j < docentes[i].secciones_doc; j++)
            {
                printf("La cantidad de inscritos en la secci%cn %d > %d \n", o, j + 1, docentes[i].insc_doc[j]);
            }
        }
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

    if (x = 0)
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
    else
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
    char s = 196;
    char d = 179;
    char ds = 192;
    char dm = 193;
    char dss = 217;
    char cs = 218;
    char cm = 194;
    char css = 191;
    char mm = 197;
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
    printf("   %c    DESCANSO     %c     -     %c\n", d, d, d);
    printf("   %c 11:00 A 11:50   %c    (4)    %c\n", d, d, d);
    printf("   %c 11:55 A 12:40   %c    (5)    %c\n", d, d, d);
    printf("   %c 12:45 A 01:40   %c    (6)    %c\n", d, d, d);
    // printf("   %c 01:15 A 03:00   %c   (7)     %c\n", d, d, d);
    printf("   %c                 %c           %c\n", d, d, d);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", ds, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, dm, s, s, s, s, s, s, s, s, s, s, s, dss);

    for (int y = 0; y < horario_d; y++)
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

        getchar();
        switch (hora)
        {
        case 1:
            docentes[i].uno[diaa] = 1; // 7:50 A 8:40
            if (!verificar_hora(diaa, docentes[i].uno[diaa], 1))
            {
                y--;
            }
            break;
        case 2:
            docentes[i].dos[diaa] = 2; // 8:45 A 9:35
            if (!verificar_hora(diaa, docentes[i].dos[diaa], 1))
            {
                y--;
            }
            break;
        case 3:
            docentes[i].tres[diaa] = 3; // 9:40 A 10:25
            if (!verificar_hora(diaa, docentes[i].tres[diaa], 1))
            {
                y--;
            }
            break;
        case 4:
            docentes[i].cuatro[diaa] = 4; // 10:30 A 11:20
            if (!verificar_hora(diaa, docentes[i].cuatro[diaa], 1))
            {
                y--;
            }
            break;
        case 5:
            docentes[i].cinco[diaa] = 5; // 11:25 A 12:10
            if (!verificar_hora(diaa, docentes[i].cinco[diaa], 1))
            {
                y--;
            }
            break;
        case 6:
            docentes[i].seis[diaa] = 6; // 12:15 A 01:30
            if (!verificar_hora(diaa, docentes[i].seis[diaa], 1))
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

int verificar_hora(int dia, int hora, int limpio)
{
    if (limpio == 0)
    {
        for (dia = 0; dia < 5; dia++)
        {
            for (hora = 0; hora < 6; hora++)
            {
                horario[dia][hora] = 0;
            }
        }
    }
    if (limpio == 1)
    {
        if (horario[dia][hora] == 0)
        {
            horario[dia][hora] = 1;
            printf("  El Docente fue asignado correctamente. \n");
            return 1;
        }
        else
        {
            printf("Hora ocupada - Escoja otra hora \n");
            return 0;
        }
    }
}