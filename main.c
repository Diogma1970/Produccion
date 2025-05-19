#include <stdio.h>
#include "produccion.h"

int main() {
    int opcion;
    ingresar_recursos();
    ingresar_productos();

    do {
        printf("\nMenu:\n");
        printf("1. Editar producto\n");
        printf("2. Eliminar producto\n");
        printf("3. Editar recursos\n");
        printf("4. Calcular produccion\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: editar_producto(); break;
            case 2: eliminar_producto(); break;
            case 3: editar_recurso(); break;
            case 4: calcular_produccion(); break;
            case 5: break;
            default: printf("Opcion invalida.\n");
        }
    } while(opcion != 5);

    return 0;
}
