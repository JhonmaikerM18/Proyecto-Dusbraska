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
#define NN 165    // La Ñ
#define signo 168 // El signo ¿

#define s 196
//Contastentes
#define Hora_x_doc 3

//UBICACIONES DE DATOS DE LOS FICHEROS
#define F_registros_doc "data/registros_doc.txt"
#define F_horario_dat "data/horario.txt"
#define configuraciones  "data/config.txt"
#define F_materia "data/reg_de_materias.txt"
#define pause "pause>data/clear"

struct docente
{
    char nombre[40], apellido[40], telefono_d[13], cedula_d[40], materia[30];
    int secciones_doc, disp_doc, insc_doc[4], dia[4], semestre;
};
struct ElementoHorario
{
    char nombre[12];
    char apellido[12];
    int entero, choque;
};
struct materia
{
	char nombre[60], sede[12];
	int unidades, codigo, cupos, prelacion, secciones, pertenece, horas, semestre, alumnos_inscritos, docentes[3];
};
struct asignacion{
	char nombre_doc[30], nombre_mat[30];
	int numAsignaciones;
};
//Estructurassss
struct materia materias[30];
struct asignacion asignaciones[50];
struct ElementoHorario horario[5][6];
struct docente docentes[100];

