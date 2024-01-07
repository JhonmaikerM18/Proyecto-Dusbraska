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
    struct materia;
    for (i = 0; i < 1; i++)
    {
        printf("De que semestre > ");
        scanf("%d", &semestre);
        system("cls");
        switch (semestre)
        {
        case 1:
            imprimirEstructura(compresion);
            imprimirEstructura(orientacion);
            imprimirEstructura(Tecnica_est);
            imprimirEstructura(matematica_1);
            imprimirEstructura(quimica);
            imprimirEstructura(funda_inform);
            imprimirEstructura(lo_compu);
            break;
        case 2:
            imprimirEstructura(fisica_1);
            imprimirEstructura(matematica_2);
            imprimirEstructura(dibujo);
            imprimirEstructura(tecnicas_programacion_1);
            imprimirEstructura(ingles_1);
            imprimirEstructura(algebra_lineal);
            imprimirEstructura(intro_a_la_admi);
            break;
        case 3:
            imprimirEstructura(desarrollo_humano);
            imprimirEstructura(fisica_2);
            imprimirEstructura(laboratorio_fisica_1);
            imprimirEstructura(ingles_tecnico);
            imprimirEstructura(matematica_3);
            imprimirEstructura(matematica_discreta);
            imprimirEstructura(tecnicas_programacion_2);
            break;
        case 4:
            imprimirEstructura(matematica_4);
            imprimirEstructura(estadistica_1);
            imprimirEstructura(tecnicas_programacion_3);
            imprimirEstructura(csd);
            imprimirEstructura(laboratorio_fisica_2);
            imprimirEstructura(estructura_de_datos);
            break;
        case 5:
            imprimirEstructura(estadistica_2);
            imprimirEstructura(base_de_datos_1);
            imprimirEstructura(A_computador);
            imprimirEstructura(C_numerico);
            imprimirEstructura(finanzas);
            imprimirEstructura(algebra_de_estructuras);
            break;
        case 6:
            imprimirEstructura(investigacion_de_operaciones);
            imprimirEstructura(sistemas_de_operaciones);
            imprimirEstructura(ingenieria_en_software_1);
            imprimirEstructura(base_de_datos_2);
            imprimirEstructura(informatica_industrial);
            imprimirEstructura(innovacion_desarrollo);
            break;
        case 7:
            imprimirEstructura(seminario_de_investigacion);
            imprimirEstructura(redes_de_computadoras_1);
            imprimirEstructura(ingenieria_en_software_2);
            imprimirEstructura(lenguajes_y_compiladores);
            imprimirEstructura(tendencias_informaticas);
            imprimirEstructura(pasantias);
            break;
        case 8:
            imprimirEstructura(sistemas_calidad);
            imprimirEstructura(ingenieria_economica);
            imprimirEstructura(atsi);
            imprimirEstructura(telecomunicaciones_1);
            imprimirEstructura(sistemas_distribuidos);
            break;
        default:
            printf("Nummero no correcto\n");
            break;
        }
    }

    return 0;
}

void imprimirEstructura(struct materia m)
{
    printf("\nN%cmero de materia: %d\nNombre: %s\nUnidad: %d\nCodigo: %d\nCupos: %d\nPrelacion: %d\nPrelacion_2: %d\nPrelacion_3: %d\nTexto: %s\nSede: %s\nSede_1: %s\nPertenece: %s\nHoras: %d\n",
           u, m.nmateria, m.nombre, m.unidad, m.codigo, m.cupos, m.prelacion, m.prelacion_2, m.prelacion_3, m.texto, m.sede, m.sede_1, m.pertenece, m.horas);
}