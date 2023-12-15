#include "data/include.h"
#include "data/login.h"
#include "data/estructuras.h"

int main()
{
    disponibilidad_de_horario();
    //login(); 
    //carga_de_datos_doc();
    //mostrar_datos_doc();

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



    system("pause>data/clear");
    return 0;
}