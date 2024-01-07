struct materia
{
	char nombre[60];
	int unidad;
	int codigo;
	int cupos;
	int prelacion;
	int prelacion_2;
	int prelacion_3;
	char texto[40];
	char sede[40];
	char sede_1[40];
	char pertenece[40];
	int horas;
	int nmateria;
};

	// Primer semestre.
	// Compresion y expresion linguistica.
	struct materia compresion = {"Compresion y expresion linguistica", 3, 1472101, 105, 0, 0, 0, "---", "Atlantico", "---", "Primer semestre", 2,1};
	// Orientacion y cultura universitaria.
	struct materia orientacion = {"Orientacion y cultura universitaria", 2, 1472102, 105, 0, 0, 0, "---", "Villa Asia", "Atlantico", "Primer semestre", 2,2};
	// Tecnicas de estudio e investigacion.
	struct materia Tecnica_est = {"Tecnica de estudio", 2, 1472103, 105, 0, 0, 0, "---", "Atlantico", "---", "Primer semestre", 2,3};
	// Matematica_1.
	struct materia matematica_1 = {"Matematica 1", 4, 1472104, 105, 0, 0, 0, "---", "Atlantico", "---", "Primer semtres", 2,4};
	// Quimica general.
	struct materia quimica = {"Quimica", 4, 1472105, 105, 0, 0, 0, "---", "Atlantico", "---", "Primer semestre", 2,5};
	// Fundamentos de la informatica.
	struct materia funda_inform = {"Fundamento de la informatica", 4, 1472106, 105, 0, 0, 0, "---", "Altlantico", "---", "Primer semestre", 2,6};
	// Logica computacional.
	struct materia lo_compu = {"Logica computacional", 4, 1472107, 105, 0, 0, 0, "---", "Atlantico", "---", "Primer semestre", 2,7};

	// Segundo semestre.

	// Fisica 1.
	struct materia fisica_1 = {"Fisica 1", 4, 1472208, 105, 1472104, 0, 0, "---", "Atlantico", "---", "Segundo semestre", 2,8};
	// Matematica 2.
	struct materia matematica_2 = {"Matematica 2", 4, 1472209, 105, 1472104, 0, 0, "---", "Altlantico", "---", "Segundo  semestre", 2,9};
	// Dibujo e interpretacion de planos.
	struct materia dibujo = {"Dibujo e interpretacion de planos", 3, 1472210, 105, 1472104, 0, 0, "---", "Villa Asia", "---", "Segundo semestre", 2,10};
	// Tecnicas de programacion 1.
	struct materia tecnicas_programacion_1 = {"Tecnicas de programacion 1", 4, 1472221, 105, 1472106, 0, 0, "---", "Atlantico", "Villa Asia", "Segundo semestre", 2,11};
	// Ingles 1.
	struct materia ingles_1 = {"Ingles 1", 1, 1472212, 105, 0, 0, 0, "---", "Atlantico", "---", "Segundo semestre", 2,12};
	// Algebra lineal.
	struct materia algebra_lineal = {"Algebra lineal", 3, 1472213, 105, 1472104, 0, 0, "---", "Atlantico", "---", "Segundo semestre", 2,13};
	// Introduccion a la administracion.
	struct materia intro_a_la_admi = {"Introduccion a la administracion", 2, 1472214, 105, 1472104, 0, 0, "---", "Atlantico", "---", "Segundo semestre", 2,14};

	// Tercer semestre.

	// Desarrollo humano.
	struct materia desarrollo_humano = {"Desarrollo humano", 3, 1472315, 105, 0, 0, 0, "---", "Altlantico", "---", "Tercer semetre", 2,15};
	// Fisica 2.
	struct materia fisica_2 = {"Fisica 2", 4, 1472316, 105, 1472208, 0, 0, "---", "Altlantico", "---", "Tercer semestre", 2,16};
	// Laboratorio de fisica 1.
	struct materia laboratorio_fisica_1 = {"Laboratorio de fisica 1", 2, 1472317, 105, 1472208, 0, 0, "---", "Villa Asia", "---", "Tercer semestre", 2,17};
	// Ingles tecnico.
	struct materia ingles_tecnico = {"Ingles tecnico", 1, 1472318, 105, 1472212, 0, 0, "---", "Atlantico", "---", "Tercer semestre", 2,18};
	// Matematica 3.
	struct materia matematica_3 = {"Matematica 3", 4, 1472319, 105, 1472209, 0, 0, "---", "Atlantico", "---", "Tercer semestre",2,19};
	// Matematicas discretas.
	struct materia matematica_discreta = {"Matematica discreta", 4, 1472320, 105, 1472209, 0, 0, "---", "Atlantico", "---", "Tercer semestre", 2,20};
	// Tecnicas de programacion 2.
	struct materia tecnicas_programacion_2 = {"Tecnicas de programacion 2", 4, 1472321, 105, 1472221, 0, 0, "---", "Atlantico", "---", "Tercer semestre", 2,21};

	// Cuarto semestre.

	// Matematica 4.
	struct materia matematica_4 = {"Matematica 4", 4, 1472422, 105, 1472319, 0, 0, "---", "Atlantico", "---", "Cuarto semestre", 2,22};
	// Estadistica 1.
	struct materia estadistica_1 = {"Estadistica 1", 3, 1472423, 105, 1472209, 0, 0, "---", "Altlantico", "---", "Cuarto semestre",2,23};
	////Tecnicas de programacion 3.
	struct materia tecnicas_programacion_3 = {"Tecnicas de programacion 3", 4, 1472424, 105, 1472321, 0, 0, "---", "Altlantico", "---", "Cuarto semestre", 2,24};
	// Circuitos y sistemas digitales.
	struct materia csd = {"Circuitos y sistemas digitales", 4, 1472425, 105, 1472316, 0, 0, "---", "Atlantico", "---", "Cuarto semestre", 2,25};
	// Laboratorio de fisica 2.
	struct materia laboratorio_fisica_2 = {"Laboratorio de fisica 2", 2, 1472427, 105, 1472316, 1472317, 0, "---", "Villa Asia", "Cuarto semestre", 2,26};
	// Estructuras de datos.
	struct materia estructura_de_datos = {"Estructura de datos", 4, 1472428, 105, 1472320, 1472321, 0, "---", "Altlantico", "---", "Cuarto semestre", 2,27};

	// Quinto semestre.

	// Estadistica 2.
	struct materia estadistica_2 = {"Estadistica 2", 3, 1472529, 105, 1472423, 0, 0, "---", "Atlantico", "---", "Quinto semestre", 2, 28};
	// Sistemas de bases de datos 1.
	struct materia base_de_datos_1 = {"Sistema de bases de datos 1", 4, 1472530, 105, 1472424, 1472428, 0, "---", "Atlantico", "---", "Quinto semestre", 2, 29};
	// Arquitectura del computador.
	struct materia A_computador = {"Arquitectura del computador", 3, 1472531, 105, 1472425, 0, 0, "---", "Atlantico", "---", "Quinto semestre", 2, 30};
	// Calculo numerico.
	struct materia C_numerico = {"Calculo numerico", 4, 1472530, 105, 1472422, 0, 0, "---", "Atlantico", "---", "Quinto semestre", 2, 31};
	// Finanzas para ingenieros.
	struct materia finanzas = {"Finanzas para ingeniero", 3, 1472533, 105, 1472214, 0, 0, "---", "Atlantico", "---", "Quinto semestre", 2,32};
	// Algebra de estructuras.
	struct materia algebra_de_estructuras = {"Algebra de estructuras", 3, 1472534, 105, 1472320, 0, 0, "---", "Atlantico", "---", "Quinto semestre", 2,33};

	// Sexto semestre.

	// Investigacion de operaciones.
	struct materia investigacion_de_operaciones = {"Investigacion de operaciones", 4, 1472634, 105, 1472529, 1472534, 0, "---", "Atlantico", "---", "Sexto semestre", 2};
	// Sistemas de operaciones.
	struct materia sistemas_de_operaciones = {"Sistemas de operaciones", 4, 1472635, 105, 1472428, 1472531, 0, "---", "Atlantico", "---", "Sexto semestre", 2};
	// Ingenieria en software 1.
	struct materia ingenieria_en_software_1 = {"Ingenieria en software 1", 4, 1472636, 105, 1472530, 0, 0, "---", "Atlantico", "---", "Sexto semestre", 2};
	// Sistemas de bases de datos 2.
	struct materia base_de_datos_2 = {"Sistema de bases de datos 2", 4, 1472637, 105, 1472530, 0, 0, "---", "Atlantico", "---", "Sexto semestre", 2};
	// Informatica industrial.
	struct materia informatica_industrial = {"Informatica industrial", 3, 1472638, 105, 1472422, 1472530, 1472531, "---", "Atlantico", "---", "Sexto semestre", 2};
	// Innovacion y desarrollo.
	struct materia innovacion_desarrollo = {"Informatica industrial", 3, 1472639, 105, 1472529, 1472531, 1472533, "---", "Atlantico", "---", "Sexto semestre", 2};

	// Septimo semestre.

	// Seminario de investigacion.
	struct materia seminario_de_investigacion = {"Seminario de investigacion", 3, 2472740, 105, 1472636, 0, 0, "---", "Atlantico", "---", "Septimo semestre", 2};
	// Redes de computadoras 1.
	struct materia redes_de_computadoras_1 = {"Redes de computadoras 1", 3, 2472742, 105, 1472635, 0, 0, "---", "Atlantico", "---", "Septimo semestre", 2};
	// Ingenieria de software 2.
	struct materia ingenieria_en_software_2 = {"Ingenieria en software 2", 4, 2472743, 105, 1472636, 1472637, 0, "---", "Atlantico", "---", "Septimo semestre", 2};
	// Lenguajes y compiladores.
	struct materia lenguajes_y_compiladores = {"Lenguajes y compiladores", 3, 2472744, 105, 1472635, 0, 0, "---", "Atlantico", "---", "Septimo semestre", 2};
	// Tendencias informaticas.
	struct materia tendencias_informaticas = {"Tendencias informaticas", 2, 1472636, 105, 1472639, 0, 0, "/5 Sem. Aprob", "Atlantico", "---", "Septimo semestre", 2};
	// Pasantias.
	struct materia pasantias = {"Pasantias", 3, 2472746, 105, 0, 0, 0, "/6 Sem. Aprob", "Se debe asignar el lugar", "---", "Septimo semestre", 2};

	// Octavo semestre.

	// Sistemas de la calidad.
	struct materia sistemas_calidad = {"Sistemas de la calidad", 3, 2472847, 105, 1472634, 0, 0, "---", "Atlantico", "---", "Octavo semestre", 2};
	// Ingenieria economica.
	struct materia ingenieria_economica = {"Ingenieria economica", 3, 2472848, 105, 1472533, 1472634, 0, "---", "Atlantico", "---", "Octavo semestre", 2};
	// Auditoria de tecnologias y sistemas de informacion.
	struct materia atsi = {"Auditoria de tecnologias y sistemas de informacion", 3, 2472849, 105, 2472743, 2472745, 0, "---", "Atlantico", "---", "Octavo semestre", 2};
	// Telecomunicaciones 1.
	struct materia telecomunicaciones_1 = {"Telecomunicaciones 1", 3, 2472850, 105, 1472422, 2472742, 0, "---", "Atlantico", "---", "Octavo semestre", 2};
	// Sistemas distribuidos.
	struct materia sistemas_distribuidos = {"Sistemas distribuidos", 3, 2472851, 105, 2472744, 0, 0, "---", "Atlantico", "---", "Octavo semestre", 2};