#include "data/login.h"
#include "data/estructuras.h"

void icon();
int main()
{
    valido = 0;
    icon();
    // login();
    printf("%cCuantos docentes van a quedar en registro? \n", signo);
    while (valido == 0)
    {
        if (scanf("%d", &cantidad_doc) != 1)
        {
            printf("Error: entrada no v%clida - ", aa);
            printf("Ingrese nuevamente > ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            if (cantidad_doc < 1)
            {
                printf("Error: entrada no v%clida - ", aa);
                printf("Ingrese nuevamente > ");
            }
            else if (cantidad_doc > 32)
            {
                printf("No tenemos suficientes recursos para alojar esa cantidad \n");
                printf("Ingrese nuevamente > ");
            }
            else // EL QUE MANDA A LA CARGA DE DATOS
            {
                valido = 1;
                fflush(stdin);
            }
        }
    }

    carga_de_datos_doc(cantidad_doc);
    // mostrar_datos_doc(cantidad_doc);

    system("pause>data/clear");
    return 0;
}

void icon()
{
    HWND hwnd = GetConsoleWindow();

    // Cargar el icono desde un archivo .ico
    HICON hIcon = (HICON)LoadImage(NULL, "data/icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);

    // Establecer el nuevo icono para la ventana
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    return;
}