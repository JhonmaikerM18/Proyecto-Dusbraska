#include "include.h"
int temp = 0;
// Definici�n de la estructura de Docente
struct docente
{
    char nombre_doc[12], apellido_doc[12], telefono_d[13], cedula_d[10];
    int secciones_doc, disp_doc, insc_doc[4], opcion[0], disponibilidad[4];
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


int carga_de_datos_doc()
{
    struct docente docentes[16];
    printf("%cCuantos docentes van a quedar en registro? \n", signo);
    scanf("%d", &docentes[i].opcion[0]);
    fflush(stdin);
    if (docentes[i].opcion[0] > 0 && docentes[i].opcion[0] < 17)
    {
        system("cls");
        FILE *registros_docente;
        registros_docente = fopen("data/registros_doc", "wb");
        if (registros_docente)
        {
            for (i = 0; i < docentes[i].opcion[0]; i++)
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

                while (!verificar_numero(docentes[i].telefono_d))
                {
                    printf("Error: Ingrese un n%cmero de tel%cfono correcto: ", u, e);
                    scanf("%s", docentes[i].telefono_d);
                    fflush(stdin);
                }

                printf("\nIngrese la disponibilidad del docente - Un n%cmero entero por dia disponible > ", u);
                scanf("%d", &docentes[i].disp_doc);
                fflush(stdin);

                printf("Ingrese ahora los d%cas disponibles: \n", ai);
                printf("Lunes = 1    -    Martes  = 2    -    Mi%crcoles = 3\n", e);
                printf("Jueves = 4    -    Viernes = 5     \n");

                for (int j = 0; j < docentes[i].disp_doc; j++)
                {
                    int dia;
                    scanf("%d", &dia);
                    getchar();
                    switch (dia)
                    {
                    case 1:
                        docentes[i].disponibilidad[0] = 2; // Lunes
                        break;
                    case 2:
                        docentes[i].disponibilidad[1] = 1; // Martes
                        break;
                    case 3:
                        docentes[i].disponibilidad[2] = 1; // Miércoles
                        break;
                    case 4:
                        docentes[i].disponibilidad[3] = 1; // Jueves
                        break;
                    case 5:
                        docentes[i].disponibilidad[4] = 1; // Viernes
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

            fwrite(docentes, sizeof(struct docente), 16, registros_docente);
            fclose(registros_docente);
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
    }
    else if (docentes[i].opcion[0] > 16)
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
    struct docente docentes[16];

    registros_docentes = fopen("data/registros_doc", "rb");
    if (registros_docentes)
    {
        fread(docentes, sizeof(struct docente), 2, registros_docentes);
        fclose(registros_docentes);
        for (i = 0; i < docentes[i].opcion[0]; i++)
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
