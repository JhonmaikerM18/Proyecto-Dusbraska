#include "data/login.h"
#include "data/estructuras.h"

int main()
{
    icon();
    bloqueo_maximizar();
    HWND hwnd = GetConsoleWindow();
    SetConsoleTitle("HORARIO - MENU DE INICIO");
    system("mode con: cols=80 lines=25");
    cuadro(30,5,50,9);
    centrar_t("BIENVENIDO",40, 7);
    pantalla_carga(40, 20, 20, 6, 71, 0, 0);
    // login();
    carga_de_materia();
    printf("%cCuantos docentes van a quedar en registro? \n", signo);
    while (valido == 0)
    {
        if (scanf("%d", &cantidad_doc) != 1 || cantidad_doc < 1 || cantidad_doc > 42)
        {
            if (cantidad_doc < 1)
            {
                printf("Error: entrada no v%clida - Ingrese nuevamente > ", aa);
            }
            else
            {
                printf("No tenemos suficientes recursos para alojar esa cantidad. \nIngrese nuevamente > ");
            }
            while (getchar() != '\n')
                ;
        }
        else // EL QUE MANDA A LA CARGA DE DATOS
        {
            valido = 1;
            fflush(stdin);
            //carga_de_datos_doc(cantidad_doc, horario);
            mostrar_docentes(cantidad_doc);
        }
    }
    // HILOS_HORARIO();
    system("pause>data/clear");
    return 0;
}