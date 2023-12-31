#include "data/login.h"
#include "data/estructuras.h"

int main()
{
    
    // login();
    icon();
    carga_de_datos_doc();
    //int horario_asig(int x, int y, int dia, int hora, int seccion, int aula, char *nombre, char *materia, char *sede);
    void horario_mostrar();
    DWORD WINAPI hilos_docentes(LPVOID lpParam);
    int HILOS_HORARIO();

    system("pause>data/clear");
    return 0;
}