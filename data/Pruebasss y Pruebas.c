#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
} Docente;

typedef struct
{
    char nombre[50];
    Docente docentes[3]; // Suponemos que cada materia tiene hasta 3 docentes
} Materia;

int compararDocentes(const void *a, const void *b)
{
    Docente *docenteA = (Docente *)a;
    Docente *docenteB = (Docente *)b;
    return strcmp(docenteA->nombre, docenteB->nombre);
}

int main()
{
    int opcion = 0, numero = 0;
    while (opcion != 99)
    {
        printf("Ingrese numero >> ");
        scanf("%d", &opcion);
        numero += opcion;
    }
    printf("Numero total sumado >> %d\n\n", numero);


    Materia materia;

    // Ingresar el nombre de la materia
    printf("Ingrese el nombre de la materia: ");
    fgets(materia.nombre, 50, stdin);
    materia.nombre[strcspn(materia.nombre, "\n")] = 0; // Eliminar el salto de línea del final

    // Ingresar los nombres de los docentes
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese el nombre del docente %d: ", i + 1);
        fgets(materia.docentes[i].nombre, 50, stdin);
        materia.docentes[i].nombre[strcspn(materia.docentes[i].nombre, "\n")] = 0; // Eliminar el salto de línea del final
    }

    // Ordenar los docentes alfabéticamente para la materia
    qsort(materia.docentes, 3, sizeof(Docente), compararDocentes);

    // Mostrar los docentes ordenados por materia
    printf("\nMateria: %s\n", materia.nombre);
    printf("Docentes:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s\n", i + 1, materia.docentes[i].nombre);
    }
    printf("\n\n");
    system("pause");
    return 0;
}