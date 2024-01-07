#include "Materias.h"
#include "estructuras.h"
int semestre;
void imprimirEstructura(struct materia m);
int mostrar_datos_doc();

int main()
{
    mostrar_datos_doc();
    system("pause>clear");
    return 0;
}

int mostrar_datos_doc()
{

    FILE *registros_docentes;
    struct docente docentes[42];
    registros_docentes = fopen("registros_doc", "rb");
    if (registros_docentes)
    {
        fread(docentes, sizeof(struct docente), 42, registros_docentes);
        for (i = 0; i < 3; i++)
        {
            printf("\t------------ Datos del docente %d ------------ \n", i + 1);
            printf("Nombre del docente > %s\n", docentes[i].nombre_doc);
            printf("El Apellido del docente > %s\n", docentes[i].apellido_doc);
            printf("De que semestre sera el docente?");
            scanf("%d", &semestre);
            switch (semestre)
            {
            case 1:
                printf("Materia %d \n\n", 1);
                imprimirEstructura(compresion);
                printf("Materia %d \n\n", 2);
                imprimirEstructura(orientacion);
                printf("Materia %d \n\n", 3);
                imprimirEstructura(Tecnica_est);
                printf("Materia %d \n\n", 4);
                imprimirEstructura(matematica_1);
                printf("Materia %d \n\n", 5);
                imprimirEstructura(quimica);
                printf("Materia %d \n\n", 6);
                imprimirEstructura(funda_inform);
                printf("Materia %d \n\n", 7);
                imprimirEstructura(lo_compu);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;

            default:
                break;
            }
        }
        fclose(registros_docentes);
    }
    else
    {
        printf("NULLLLLLLLLLL");
    }

    return 0;
}

void imprimirEstructura(struct materia m)
{
    printf("Nombre: %s\nUnidad: %d\nCodigo: %d\nCupos: %d\nPrelacion: %d\nPrelacion_2: %d\nPrelacion_3: %d\nTexto: %s\nSede: %s\nSede_1: %s\nPertenece: %s\nHoras: %d\nRandom: %d\n",
           m.nombre, m.unidad, m.codigo, m.cupos, m.prelacion, m.prelacion_2, m.prelacion_3, m.texto, m.sede, m.sede_1, m.pertenece, m.horas, m.random);
}