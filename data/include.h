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
#define d 179
#define mm 197

#define Hora_x_doc 3

struct docente
{
    char nombre[40], apellido[40], telefono_d[13], cedula_d[40], materia[30];
    int secciones_doc, disp_doc, insc_doc[4], dia[4], semestre;
};
struct ElementoHorario
{
    char nombre[12];
    char apellido[12];
    int entero;
};
struct advertencia
{
    int materia;
    int docentes;
};

//UBICACIONES DE DATOS DE LOS FICHEROS
const char* F_registros_doc =  "data/registros_doc";
const char* F_horario_dat =  "data/horario.txt";
const char* configuraciones =  "data/config.txt";