#include "Materias.h"
#include "estructuras.h"
void imprimirEstructura(struct materia m, int);
int mostrar_datos_doc();
void llenar_materia(struct materia m);
struct materia;
int main()
{
    mostrar_datos_doc();
    system("pause>clear");
    return 0;
}
void materia_mostrar()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);

    
    // LINEASSSSSS HORIZONTALESSS
    int x_posiciones[] = {0, 2, 5, 8, 11, 14, 17, 20, 23};
    for (int x = 0; x < 9; x++)
    {
        for (int j = 1; j < 121; j++)
        {
            gotoxy(j, x_posiciones[x]);
            printf("%c\n", s);
        }
    }
    // LINEASSSSSS VERTICALESS
    int y_posiciones[] = {0, 6, 35, 48, 61, 74, 86, 98, 110, 121};
    for (int y = 0; y < 10; y++)
    {
        for (int j = 1; j < 23; j++)
        {
            gotoxy(y_posiciones[y], j);
            printf("%c\n", d);
        }
    }
    gotoxy(2, 1);
    printf("N ");

    gotoxy(15, 1);
    printf("NOMBRE");

    gotoxy(37, 1);
    printf("UNIDADES");

    gotoxy(52, 1);
    printf("CODIGO");

    gotoxy(66, 1);
    printf("SEDE");

    gotoxy(78, 1);
    printf("CUPOS");

    gotoxy(88, 1);
    printf("PRELACION");

    gotoxy(102, 1);
    printf("HORAS");

    gotoxy(112, 1);
    printf("APROBADO");
    //ESQUINAS
    gotoxy(0,0);
    printf("%c", 218);
    gotoxy(121, 23);
    printf("%c", 217);
    gotoxy(121, 0);
    printf("%c", 191);
    gotoxy(0, 23);
    printf("%c", 192);
}
int mostrar_datos_doc()
{

    int semestre;
    printf("De que semestre > ");
    scanf("%d", &semestre);
    for (int i = 0; i < 1; i++)
    {
        // llenar_materia(matematica_4);
        system("cls");
        switch (semestre)
        {
        case 1:
            imprimirEstructura(compresion,  3);
            imprimirEstructura(orientacion,6);
            imprimirEstructura(Tecnica_est,9);
            imprimirEstructura(matematica_1,12);
            imprimirEstructura(quimica,15);
            imprimirEstructura(funda_inform,18);
            imprimirEstructura(lo_compu,21);
            materia_mostrar();
            break;
            case 2:
                imprimirEstructura(fisica_1,3);
                imprimirEstructura(matematica_2,6);
                imprimirEstructura(dibujo,9);
                imprimirEstructura(tecnicas_programacion_1,12);
                imprimirEstructura(ingles_1,15);
                imprimirEstructura(algebra_lineal,18);
                imprimirEstructura(intro_a_la_admi,21);
                materia_mostrar();
                break;
            case 3:
                imprimirEstructura(desarrollo_humano,3);
                imprimirEstructura(fisica_2,6);
                imprimirEstructura(laboratorio_fisica_1,9);
                imprimirEstructura(ingles_tecnico,12);
                imprimirEstructura(matematica_3,15);
                imprimirEstructura(matematica_discreta,18);
                imprimirEstructura(tecnicas_programacion_2,21);
                materia_mostrar();
                break;
            case 4:
                imprimirEstructura(matematica_4,3);
                imprimirEstructura(estadistica_1,6);
                imprimirEstructura(tecnicas_programacion_3,9);
                imprimirEstructura(csd,12);
                imprimirEstructura(laboratorio_fisica_2,15);
                imprimirEstructura(estructura_de_datos,18);
                materia_mostrar();
                break;
            case 5:
                imprimirEstructura(estadistica_2,3);
                imprimirEstructura(base_de_datos_1,6);
                imprimirEstructura(A_computador,9);
                imprimirEstructura(C_numerico,12);
                imprimirEstructura(finanzas,15);
                imprimirEstructura(algebra_de_estructuras,18);
                materia_mostrar();
                break;
            case 6:
                imprimirEstructura(investigacion_de_operaciones,3);
                imprimirEstructura(sistemas_de_operaciones,6);
                imprimirEstructura(ingenieria_en_software_1,9);
                imprimirEstructura(base_de_datos_2,12);
                imprimirEstructura(informatica_industrial,15);
                imprimirEstructura(innovacion_desarrollo,18);
                materia_mostrar();
                break;
            case 7:
                imprimirEstructura(seminario_de_investigacion,3);
                imprimirEstructura(redes_de_computadoras_1,6);
                imprimirEstructura(ingenieria_en_software_2,9);
                imprimirEstructura(lenguajes_y_compiladores,12);
                imprimirEstructura(tendencias_informaticas,15);
                imprimirEstructura(pasantias,18);
                materia_mostrar();
                break;
            case 8:
                imprimirEstructura(sistemas_calidad,3);
                imprimirEstructura(ingenieria_economica,6);
                imprimirEstructura(atsi,9);
                imprimirEstructura(telecomunicaciones_1,12);
                imprimirEstructura(sistemas_distribuidos,15);
                materia_mostrar();
                break;
            default:
                printf("Numero no correcto\n");
                break;
        }
    }

    return 0;
}

void imprimirEstructura(struct materia m, int y)
{
    char sede[25];
    if (m.sede == 0)
    {
        strncpy(sede, "Villa Asia", 25);
    }
    if (m.sede == 1)
    {
        strncpy(sede, "Atlantico", 25);
    }
    if (m.sede == 2)
    {
        strncpy(sede, "Villa Asia - Atlantico", 25);
    }
    char nombre[50];
    strncpy(nombre, m.nombre, 25);

    fflush(stdin);
    gotoxy(2, y);
    printf("%d", m.nmateria);
    gotoxy(7, y);
    printf("%s", nombre);
    gotoxy(40, y);
    printf("%d", m.unidad);
    gotoxy(51, y);
    printf("%d", m.codigo);
    gotoxy(63, y);
    printf("%s", sede);
    gotoxy(79, y);
    printf("%d", m.cupos);
    gotoxy(88, y);
    printf("%d", m.prelacion);
    gotoxy(103, y);
    printf("%d", m.horas);
}
char *prelacion(struct materia *m, int prelacion)
{
    for (int i = 0; i < 50; i++)
    {
        if (prelacion == 0)
        {
            return "NO POSEE PRELACION\n";
        }
        if (m[i].codigo == prelacion)
        {
            return m[i].nombre;
        }
    }
    return "No encontrada";
}

void llenar_materia(struct materia m)
{
    struct materia materias[] = {compresion, orientacion, Tecnica_est, matematica_1, quimica, funda_inform, lo_compu, fisica_1, matematica_2, dibujo, tecnicas_programacion_1, ingles_1, algebra_lineal, intro_a_la_admi, desarrollo_humano, fisica_2, laboratorio_fisica_1, ingles_tecnico, matematica_3, matematica_discreta, tecnicas_programacion_2, matematica_4, estadistica_1, tecnicas_programacion_3, csd, laboratorio_fisica_2, estructura_de_datos, estadistica_2, base_de_datos_1, A_computador, C_numerico, finanzas, algebra_de_estructuras, investigacion_de_operaciones, sistemas_de_operaciones, ingenieria_en_software_1, base_de_datos_2, informatica_industrial, innovacion_desarrollo, seminario_de_investigacion, redes_de_computadoras_1, ingenieria_en_software_2, lenguajes_y_compiladores, tendencias_informaticas, pasantias, sistemas_calidad, ingenieria_economica, atsi, telecomunicaciones_1, sistemas_distribuidos};
    char *nombre = prelacion(materias, m.prelacion);

    printf("N%cmero de materia: %d\n", u, m.nmateria);
    printf("Nombre: %s \n", m.nombre);
    printf("Unidades de Creditos: ");
    scanf("%d", &m.unidad);
    printf("Codigo: %d \n", m.codigo);
    printf("Cupos: ");
    scanf("%d", &m.cupos);
    printf("Prelacion: %d - %s\n", m.prelacion, nombre);

    printf("Sede (0 Villa Asia) (1 Atlantico)\nIngrese la sede > ");
    scanf("%d", &m.sede);
    printf("Pertenece: %d\n", m.pertenece);
    printf("Horas de Clase > ");
    scanf("%d", &m.horas);
}
