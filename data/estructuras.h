#include "include.h"
// Definici�n de la estructura de Docente
struct docente
{
    char nombre_doc[12], apellido_doc[12], telefono_d[13], cedula_d[10];
    int secciones_doc, disp_doc, insc_doc[4], opcion[0], disponibilidad[4];
};

struct horario_doc
{
    int uno[5], dos[5], tres[5], cuatro[5], cinco[5], seis[5], siete[5];
};

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
        k[j] = ((rand() % 25) + 10);
    }
}
void disponibilidad_de_horario();
int verificar_telefono(char *numero);

int carga_de_datos_doc()
{
    struct docente docentes[32];

    printf("%cCuantos docentes van a quedar en registro? \n", signo);
    do
    {
        if (scanf("%d", &docentes[0].opcion[0]) != 1)
        {
            printf("Error: entrada no v%clida\n", aa);
            while (getchar() != '\n')
                ;
        }
    } while (0);

    fflush(stdin);

    if (docentes[0].opcion[0] > 0 && docentes[0].opcion[0] < 33)
    {
        system("cls");
        FILE *registros_docente;
        registros_docente = fopen("data/registros_doc", "wb");
        if (registros_docente)
        {
            for (i = 0; i < docentes[0].opcion[0]; i++)
            {
                printf("\tIngrese los datos del docente %d\n", i + 1);
                printf("Nombre del docente > ");
                scanf("%s", docentes[i].nombre_doc);
                fflush(stdin);
                printf("Apellido del docente > ");
                scanf("%s", docentes[i].apellido_doc);
                fflush(stdin);
                printf("Ingrese la c%cdula del docente > ", e);
                scanf("%s", docentes[i].cedula_d);
                fflush(stdin);

                while (!verificar_numero(docentes[i].cedula_d))
                {
                    printf("Error: Ingrese su c%cdula nuevamente > ", e);
                    scanf("%s", docentes[i].cedula_d);
                    fflush(stdin);
                }

                printf("Ingrese un n%cmero de tel%cfono > ", u, e);
                scanf("%s", docentes[i].telefono_d);
                fflush(stdin);

                while (!verificar_telefono(docentes[i].telefono_d))
                {
                    printf("Error: Ingrese un n%cmero de tel%cfono correcto: ", u, e);
                    scanf("%s", docentes[i].telefono_d);
                    fflush(stdin);
                }

                /*printf("\nIngrese la disponibilidad del docente - Un n%cmero entero por dia disponible > ", u);
                scanf("%d", &docentes[i].disp_doc);
                fflush(stdin);*/

                printf("Ingrese ahora el d%ca disponibles: \n", ai);
                printf("Lunes = 1    -    Martes  = 2    -    Mi%crcoles = 3\n", e);
                printf("Jueves = 4    -    Viernes = 5     \n");

                for (int j = 0; j < 1; j++)
                {
                    int dia;
                    scanf("%d", &dia);
                    getchar();
                    switch (dia)
                    {
                    case 1:
                        docentes[i].disponibilidad[0] = 2; // Lunes
                        disponibilidad_de_horario();
                        break;
                    case 2:
                        docentes[i].disponibilidad[1] = 1; // Martes
                        disponibilidad_de_horario();
                        break;
                    case 3:
                        docentes[i].disponibilidad[2] = 1; // Miércoles
                        disponibilidad_de_horario();
                        break;
                    case 4:
                        docentes[i].disponibilidad[3] = 1; // Jueves
                        disponibilidad_de_horario();
                        break;
                    case 5:
                        docentes[i].disponibilidad[4] = 1; // Viernes
                        disponibilidad_de_horario();
                        break;
                    default:
                        printf("\nPerdi%c un intento de disponibilidad", o);
                        break;
                    }
                }
                system("cls");
                srand(time(NULL));
                int valido = 0;

                while (valido == 0)
                {
                    printf("Ingrese las secciones asignadas > ");
                    scanf("%d", &docentes[i].secciones_doc);
                    getchar();

                    if (docentes[i].secciones_doc > 0 && docentes[i].secciones_doc < 4)
                    {
                        random(docentes[i].insc_doc, docentes[i].secciones_doc);
                        valido = 1;
                    }
                    else
                    {
                        printf("Cantidad v%clida entre 1 a 3. El M%cximo de secciones es 3 por docente.\n", aa, aa);
                    }
                }

                fflush(stdin);
            }

            fwrite(docentes, sizeof(struct docente), 32, registros_docente);
            fclose(registros_docente);
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
    }
    else if (docentes[0].opcion[0] > 32)
    {
        printf("No tenemos suficientes recursos para alojar esa cantidad");
    }
    else
    {
        printf("Ingrese una cantidad correcta en sistema");
    }

    return 0;
}

int mostrar_datos_doc()
{

    FILE *registros_docentes;
    struct docente docentes[32];

    registros_docentes = fopen("data/registros_doc", "rb");
    if (registros_docentes)
    {
        fread(docentes, sizeof(struct docente), 2, registros_docentes);
        fclose(registros_docentes);
        for (i = 0; i < docentes[0].opcion[0]; i++)
        {
            printf("\t------------ Datos del docente %d ------------ \n\n", i + 1);
            printf("Nombre del docente > %s\n", docentes[i].nombre_doc);
            printf("El Apellido del docente > %s\n", docentes[i].apellido_doc);
            printf("Ingrese la c%cdula del docente > %s \n", e, docentes[i].cedula_d);
            printf("Ingrese el tel%cfono del docente > %s \n\n", e, docentes[i].telefono_d);
            printf("La disponibilidad del docente son los d%cas > ", ai);

            if (docentes[i].disponibilidad[0] == 2)
            {
                printf("Lunes ");
            }
            if (docentes[i].disponibilidad[1] == 1)
            {
                printf("Martes ");
            }
            if (docentes[i].disponibilidad[2] == 1)
            {
                printf("Mi%crcoles ", e);
            }
            if (docentes[i].disponibilidad[3] == 1)
            {
                printf("Jueves ");
            }
            if (docentes[i].disponibilidad[4] == 1)
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

int verificar_telefono(char *numero)
{
    int longitud = strlen(numero);

    if (longitud != 11)
    {
        return 0; // número incorrecto
    }

    for (int i = 0; i < longitud; i++)
    {
        if (!isdigit(numero[i]))
        {
            return 0; // número incorrecto
        }
    }

    if (strncmp(numero, "0412", 4) != 0 && strncmp(numero, "0414", 4) != 0 && strncmp(numero, "0416", 4) != 0 && strncmp(numero, "0424", 4) != 0 && strncmp(numero, "0426", 4) != 0)
    {
        return 0; // número incorrecto
    }

    return 1; // número correctoo
}

void disponibilidad_de_horario()
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
    struct horario_doc horario[32];
    FILE *horario_reg;
    horario_reg = fopen("data/registro_horario_doc", "wb");

    if (horario_reg)
    {
        system("cls");
        printf(" \tIngrese el horario disponible del docente \n");
        printf(" El docente tiene maximo de 3 horas - Salir quita una hora del docente a escojer\n");
        printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cs, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, cm, s, s, s, s, s, s, s, s, s, s, s, css);
        printf("   %c     HORA        %c  NUMERO   %c\n", d, d, d);
        printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", d, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, mm, s, s, s, s, s, s, s, s, s, s, s, d);
        printf("   %c 7:50 A 8:40     %c   (1)     %c\n", d, d, d);
        printf("   %c 8:45 A 9:35     %c   (2)     %c\n", d, d, d);
        printf("   %c 9:40 A 10:25    %c   (3)     %c\n", d, d, d);
        printf("   %c10:30 A 11:20    %c   (4)     %c\n", d, d, d);
        printf("   %c11:25 A 12:10    %c   (5)     %c\n", d, d, d);
        printf("   %c12:15 A 01:10    %c   (6)     %c\n", d, d, d);
        printf("   %c01:15 A 03:00    %c   (7)     %c\n", d, d, d);
        printf("   %c    Salir        %c   (9)     %c\n", d, d, d);
        printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", ds, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, dm, s, s, s, s, s, s, s, s, s, s, s, dss);
        printf("Ingrese las horas disponibles del docente \n");

        for (int j = 0; j < 3; j++)
        {  
            do
                {
                    if (scanf("%d", &hora) != 1)
                    {
                        printf("Error: entrada no v%clida\n", aa);
                        while (getchar() != '\n')
                            ;
                    }
                } while (0);

            getchar();
            switch (hora)
            {
            case 1:
                horario[i].uno[0] = 2; // 7:50 A 8:40
                break;
            case 2:
                horario[i].dos[0] = 2; // 8:45 A 9:35
                break;
            case 3:
                horario[i].tres[0] = 2; // 9:40 A 10:25
                break;
            case 4:
                horario[i].cuatro[0] = 2; // 10:30 A 11:20
                break;
            case 5:
                horario[i].cinco[0] = 2; // 11:25 A 12:10
                break;
            case 6:
                horario[i].seis[0] = 2; // 12:15 A 01:10
                break;
            case 7:
                horario[i].siete[0] = 2; // 01:15 A 03:00
                break;
             case 9:
                printf("Una hora menos del dia\n");
                break;
            default:
                printf("\nError de numero\n", o);
                break;
            }
        }

        fwrite(horario, sizeof(struct horario_doc), 32, horario_reg);
        fclose(horario_reg);
    }
    else
    {
        printf("Error de lectura del archivo\n");
    }
    return;
}