#include "include.h"

int temp = 0;
// Definici�n de la estructura de Docente
struct docente
{
    char nombre_doc[12], apellido_doc[12], telefono_d[13], cedula_d[10];
    int secciones_doc, disp_doc, insc_doc[3], opcion[0], disponibilidad[5];
};

// Función int que verifica si una cadena es un número válido y devuelve 1 si lo es, y 0 si no lo es
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

int carga_de_datos_doc()
{
    struct docente docentes[16];

    printf("%cCuantos docentes van a quedar en registro? \n", signo);
    scanf("%d", &docentes[0].opcion[0]);
    fflush(stdin);
    if (docentes[0].opcion[0] > 0 | docentes[0].opcion[0] < 17)
    {
        system("cls");
        FILE *registros_docente;
        registros_docente = fopen("data/registros_doc", "wb");
        if (registros_docente)
        {
            for (i = 0; i < docentes[0].opcion[0]; i++)
            {
                printf("%d", docentes[0].opcion[0]);
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
                    int dia = 0;
                    scanf("%d", &dia);
                    getchar();
                    fflush(stdin);
                    switch (dia)
                    {
                    case 1:
                        docentes[i].disponibilidad[0] = 1; // Lunes
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
                printf("Ingrese las secciones asignadas > ");
                scanf("%d", &docentes[i].secciones_doc);
                getchar();
                int valido = 0;
                while (valido == 0)
                {
                    if (docentes[i].secciones_doc < 4)
                    {
                        for (int j = 0; j < docentes[i].secciones_doc; j++)
                        {
                            printf("Ingrese la cantidad inscritos en la secci%cn %d > ", o, j + 1);
                            scanf("%d", &docentes[i].insc_doc[j]);
                            getchar();
                            valido = 1;
                        }
                    }
                    else if (docentes[i].secciones_doc > 3)
                    {
                        printf("La maxima cantidad de secciones por docentes es 3.\n");
                    }
                    else
                    {
                        printf("Ingrese una cantidad valida.\n");
                    }
                }
            }

            fwrite(docentes, sizeof(struct docente), i, registros_docente);
            fclose(registros_docente);
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
    }
    else if (docentes[0].opcion[0] > 16)
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
        for (i = 0; i < docentes[0].opcion[0]; i++)
        {
            printf("\t------------ Datos del docente %d ------------ \n\n", i + 1);
            printf("Nombre del docente > %s", docentes[i].nombre_doc);
            printf("El Apellido del docente > %s", docentes[i].apellido_doc);
            printf("Ingrese la c%cdula del docente > %s \n", e, docentes[i].cedula_d);
            printf("Ingrese el tel%cfono del docente > %s \n\n", e, docentes[i].telefono_d);
            printf("La disponibilidad del docente son los d%cas > ", ai);

            if (docentes[i].disponibilidad[0] == 1)
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
