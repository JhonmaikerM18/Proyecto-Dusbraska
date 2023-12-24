#include "data/login.h"
#include "data/estructuras.h"

void icon();
int main()
{
    icon();
    //login(); 
    carga_de_datos_doc();
    //mostrar_datos_doc();

    system("pause>data/clear");
    return 0;
}

void icon(){
    HWND hwnd = GetConsoleWindow();

    // Cargar el icono desde un archivo .ico
    HICON hIcon = (HICON)LoadImage(NULL, "data/icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);

    // Establecer el nuevo icono para la ventana
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    return;
}