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
#define NN 165 // La Ñ
#define signo 168 // El signo ¿
int i;

#define s 196
#define d 179
#define ds  192
#define dm  193
#define dss 217
#define cs  218
#define cm  194
#define css 191
#define mm  197

struct docente
{
    char nombre_doc[12], apellido_doc[12], telefono_d[13], cedula_d[10];
    int secciones_doc, disp_doc, insc_doc[4], dia_disp[4];
    int uno[5], dos[5], tres[5], cuatro[5], cinco[5], seis[5];
};


















/*
                printf("%s\n"), docentes[i].nombre_doc;
                printf("%s\n"), docentes[i].apellido_doc;
                printf("%s\n"), docentes[i].cedula_d;
                printf("%s\n"), docentes[i].telefono_d;
                printf("%d\n"), docentes[i].secciones_doc;
                printf("%d\n"), docentes[i].secc_asig;
                printf("%d\n"), docentes[i].insc_doc;
                printf("%d\n"), docentes[i].disponibilidad;*/

    // login(); system("cls");
    /*do
    {
        /*printf("\t ---------------- Bienvenido a la UNEG ----------------\n\n");
        printf("%cQue desea realizar?\n", signo);
        printf("Cargar los datos de los docentes\n");
        printf("Cargar las materias inscritas\n");
        printf("Mostrar Horarios\n");
        printf("Mostrar los datos de los docentes activos\n");
        printf("Mostrar los datos de las materias inscritas\n");
        printf("Mostrar la docentes asignados por materias\n");
        printf("Mostrar la cantidad de secciones y la cantidad de estudiantes por Docentes\n");
        printf("Salir\n\n");
        printf("Ingrese una opci%cn: > ",o);
        while (scanf("%d", &caso) != 1)
        {
            printf("Opci%cn no v%clida. Por favor ingrese un n%cmero entero: ", o,aa,u);
            getchar();
            //while (getchar() != '\n'); // Limpiar el buffer del teclado
        }
        
        switch (caso)
        {
        case 1:
            system("cls");
            carga_de_datos_doc();
            break;
        case 4:
            mostrar_datos_doc();
            break;

        default:
            break;
        }

    } while (caso == 10);*/