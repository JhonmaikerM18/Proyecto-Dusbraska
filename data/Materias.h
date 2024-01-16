struct materia
{
	char nombre[60];
	int unidad;
	int codigo;
	int cupos;
	int prelacion;
	char texto[40];
	int sede;
	int pertenece;
	int horas;
	int nmateria;
};
struct libre_materia
{
	char nombre[60], sede[12];
	int unidades, codigo, cupos, prelacion, seccion, pertenece, horas, semestre, alumnos_inscritos, docentes[3];
};
struct asignacion{
	char nombre_doc[30], nombre_mat[30];
	int numero;
};

// Primer semestre.
struct materia compresion = {"Compresion y expresion linguistica", 3, 1472101, 105, 0, "---", 1, 1, 2, 1};
struct materia orientacion = {"Orientacion y cultura universitaria", 2, 1472102, 105, 0, "---", 0, 1, 2, 2};
struct materia Tecnica_est = {"Tecnica de estudio", 2, 1472103, 105, 0, "---", 1, 1, 2, 3};
struct materia matematica_1 = {"Matematica 1", 4, 1472104, 105, 0, "---", 1, 1, 2, 4};
struct materia quimica = {"Quimica", 4, 1472105, 105, 0, "---", 1, 1, 2, 5};
struct materia funda_inform = {"Fundamento de la informatica", 4, 1472106, 105, 0, "---", 1, 1, 2, 6};
struct materia lo_compu = {"Logica computacional", 4, 1472107, 105, 0, "---", 1, 1, 2, 7};

// Segundo semestre.

struct materia fisica_1 = {"Fisica 1", 4, 1472208, 105, 1472104, "---", 1, 2, 2, 8};
struct materia matematica_2 = {"Matematica 2", 4, 1472209, 105, 1472104, "---", 1, 2, 2, 9};
struct materia dibujo = {"Dibujo e interpretacion de planos", 3, 1472210, 105, 1472104, "---", 0, 2, 2, 10};
struct materia tecnicas_programacion_1 = {"Tecnicas de programacion 1", 4, 1472221, 105, 1472106, "---", 1, 2, 2, 11};
struct materia ingles_1 = {"Ingles_1", 1, 1472212, 105, 0, "---", 1, 2, 2, 12};
struct materia algebra_lineal = {"Algebra lineal", 3, 1472213, 105, 1472104, "---", 1, 2, 2, 13};
struct materia intro_a_la_admi = {"Introduccion a la administracion", 2, 1472214, 105, 1472104, "---", 1, 2, 2, 14};
// Tercer semestre.

struct materia desarrollo_humano = {"Desarrollo humano", 3, 1472315, 105, 0, "---", 1, 3, 2, 15};
struct materia fisica_2 = {"Fisica 2", 4, 1472316, 105, 1472208, "---", 1, 3, 2, 16};
struct materia laboratorio_fisica_1 = {"Laboratorio de fisica 1", 2, 1472317, 105, 1472208, "---", 1, 3, 2, 17};
struct materia ingles_tecnico = {"Ingles tecnico", 1, 1472318, 105, 1472212, "---", 1, 3, 2, 18};
struct materia matematica_3 = {"Matematica 3", 4, 1472319, 105, 1472209, "---", 1, 3, 2, 19};
struct materia matematica_discreta = {"Matematica discreta", 4, 1472320, 105, 1472209, "---", 1, 3, 2, 20};
struct materia tecnicas_programacion_2 = {"Tecnicas de programacion 2", 4, 1472321, 105, 1472221, "---", 1, 3, 2, 21};

// Cuarto semestre.

struct materia matematica_4 = {"Matematica 4", 4, 1472422, 105, 1472319, "---", 1, 4, 2, 22};
struct materia estadistica_1 = {"Estadistica 1", 3, 1472423, 105, 1472209, "---", 1, 4, 2, 23};
struct materia tecnicas_programacion_3 = {"Tecnicas de programacion 3", 4, 1472424, 105, 1472321, "---", 1, 4, 2, 24};
struct materia csd = {"Circuitos y sistemas digitales", 4, 1472425, 105, 1472316, "---", 1, 2, 2, 25};
struct materia laboratorio_fisica_2 = {"Laboratorio de fisica 2", 2, 1472427, 105, 1472316, "---", 0, 4, 2, 26};
struct materia estructura_de_datos = {"Estructura de datos", 4, 1472428, 105, 1472320, "---", 1, 4, 2, 27};

// Quinto semestre.

// Estadistica_2.
struct materia estadistica_2 = {"Estadistica_2", 3, 1472529, 105, 1472423, "---", 1, 5, 2, 28};
struct materia base_de_datos_1 = {"Sistema de bases de datos_1", 4, 1472530, 105, 1472424, "---", 1, 5, 2, 29};
struct materia A_computador = {"Arquitectura del computador", 3, 1472531, 105, 1472425, "---", 1, 5, 2, 30};
struct materia C_numerico = {"Calculo numerico", 4, 1472530, 105, 1472422, "---", 1, 5, 2, 31};
struct materia finanzas = {"Finanzas para ingeniero", 3, 1472533, 105, 1472214, "---", 1, 5, 2, 32};
struct materia algebra_de_estructuras = {"Algebra de estructuras", 3, 1472534, 105, 1472320, "---", 1, 5, 2, 33};
// Sexto semestre.

struct materia investigacion_de_operaciones = {"Investigacion de operaciones", 4, 1472634, 105, 1472529, "---", 1, 6, 2, 34};
struct materia sistemas_de_operaciones = {"Sistemas de operaciones", 4, 1472635, 105, 1472428, "---", 1, 6, 2, 35};
struct materia ingenieria_en_software_1 = {"Ingenieria en software 1", 4, 1472636, 105, 1472530, "---", 1, 6, 2, 36};
struct materia base_de_datos_2 = {"Sistema de bases de datos 2", 4, 1472637, 105, 1472530, "---", 1, 6, 2, 37};
struct materia informatica_industrial = {"Informatica industrial", 3, 1472638, 105, 1472422, "---", 1, 6, 2, 38};
struct materia innovacion_desarrollo = {"Informatica industrial", 3, 1472639, 105, 1472529, "---", 1, 6, 2, 39};

// Septimo semestre.

struct materia seminario_de_investigacion = {"Seminario de investigacion", 3, 2472740, 105, 1472636, "---", 1, 7, 2, 40};
struct materia redes_de_computadoras_1 = {"Redes de computadoras 1", 3, 2472742, 105, 1472635, "---", 1, 7, 2, 41};
struct materia ingenieria_en_software_2 = {"Ingenieria en software 2", 4, 2472743, 105, 1472636, "---", 1, 7, 2, 42};
struct materia lenguajes_y_compiladores = {"Lenguajes y compiladores", 3, 2472744, 105, 1472635, "---", 1, 7, 2, 43};
struct materia tendencias_informaticas = {"Tendencias informaticas", 2, 1472636, 105, 1472639, "/5 Sem. Aprob", 1, 7, 2, 44};
struct materia pasantias = {"Pasantias", 3, 2472746, 105, 0, "/6 Sem. Aprob", 1, 7, 2, 45};

// Octavo semestre.

struct materia sistemas_calidad = {"Sistemas de la calidad", 3, 2472847, 105, 1472634, "---", 1, 8, 2, 46};
struct materia ingenieria_economica = {"Ingenieria economica", 3, 2472848, 105, 1472533, "---", 1, 8, 2, 47};
struct materia atsi = {"Auditoria de tecnologias y sistemas de informacion", 3, 2472849, 105, 2472743, "---", 1, 8, 2, 48};
struct materia telecomunicaciones_1 = {"Telecomunicaciones_1", 3, 2472850, 105, 1472422, "---", 1, 8, 2, 49};
struct materia sistemas_distribuidos = {"Sistemas distribuidos", 3, 2472851, 105, 2472744, "---", 1, 8, 2, 50};

// Noveno
struct materia servicio_comunitatario = {"SERVICIO COMUNITARIO", 0, 4000101, 0, 0, "---", 0, 0, 0, 51};