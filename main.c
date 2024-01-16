#include "data/login.h"
#include "data/estructuras.h"

int main()
{
    icon();
    system("mode con: cols=80 lines=25");
    cuadro(30,5,50,9);
    centrar_t("BIENVENIDO",40, 7);
    pantalla_carga(40, 20, 20, 6, 71, 1, 0);
    //login();
    //carga_de_materia();
    menu_est();
    // HILOS_HORARIO();
    system("pause>data/clear");
    return 0;
}