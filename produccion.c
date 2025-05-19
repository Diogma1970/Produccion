#include <stdio.h>
#include <string.h>
#include "produccion.h"

char recursos[MAX_RECURSOS][MAX_NOMBRE];
int cantidad_recursos[MAX_RECURSOS];
int total_recursos = 0;

char productos[MAX_PRODUCTOS][MAX_NOMBRE];
int tiempo_producto[MAX_PRODUCTOS];
int demanda_producto[MAX_PRODUCTOS];
int recurso_usado[MAX_PRODUCTOS][MAX_RECURSOS];
int total_productos = 0;

int tiempo_disponible;

void ingresar_recursos() {
    printf("Cantidad de tipos de recursos (max %d): ", MAX_RECURSOS);
    scanf("%d", &total_recursos);
    if (total_recursos <=0 || total_recursos > MAX_RECURSOS){   
        printf("La cantidad ingresada no es valida");
    }
    else{
    do{
    for (int i = 0; i < total_recursos; i++) {
        printf("Nombre del recurso %d: ", i + 1);
        scanf("%s", recursos[i]);
        printf("Cantidad disponible de %s: ", recursos[i]);
        scanf("%d", &cantidad_recursos[i]);
    }
    }while (total_recursos > MAX_RECURSOS);
}
}

void ingresar_productos() {
    printf("Cantidad de productos (max %d): ", MAX_PRODUCTOS);
    scanf("%d", &total_productos);
    if (total_productos <=0 || total_productos > MAX_PRODUCTOS){   
        printf("La cantidad ingresada no es valida");
    }
    else{
        do
        {
            for (int i = 0; i < total_productos; i++) {
                printf("Nombre del producto %d: ", i + 1);
                scanf("%s", productos[i]);
                printf("Tiempo de fabricacion por unidad: ");
                scanf("%d", &tiempo_producto[i]);
                if (tiempo_producto[i]<=0)
                {   
                    do
                    {
                        printf("Tiempo ingresado incorreto, ingrese una cantidad valida");
                        scanf("%d", &tiempo_producto[i]);
                    } while (tiempo_producto[i]<=0);
                }
                printf("Demanda (cantidad a producir): ");
                scanf("%d", &demanda_producto[i]);
                if (demanda_producto[i]<=0)
                {
                     do
                    {
                        printf("Cantidad ingresada incorrecta, ingrese una cantidad valida");
                        scanf("%d", &demanda_producto[i]);
                    } while (demanda_producto[i]<=0);
                }    
                for (int j = 0; j < total_recursos; j++) {
                    printf("Cantidad de %s que necesita una unidad de %s: ", recursos[j], productos[i]);
                    scanf("%d", &recurso_usado[i][j]);
                }
            }
        } while (total_productos>MAX_PRODUCTOS);
    }
}

void editar_producto() {
    char nombre[MAX_NOMBRE];
    printf("Nombre del producto a editar: ");
    scanf("%s", nombre);
    for (int i = 0; i < total_productos; i++) {
        if (strcmp(nombre, productos[i]) == 0) {
            printf("Nuevo nombre: ");
            scanf("%s", productos[i]);
            printf("Nuevo tiempo de fabricacion: ");
            scanf("%d", &tiempo_producto[i]);
            printf("Nueva demanda: ");
            scanf("%d", &demanda_producto[i]);
            for (int j = 0; j < total_recursos; j++) {
                printf("Nueva cantidad de %s usada por unidad: ", recursos[j]);
                scanf("%d", &recurso_usado[i][j]);
            }
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminar_producto() {
    char nombre[MAX_NOMBRE];
    printf("Nombre del producto a eliminar: ");
    scanf("%s", nombre);
    for (int i = 0; i < total_productos; i++) {
        if (strcmp(nombre, productos[i]) == 0) {
            for (int j = i; j < total_productos - 1; j++) {
                strcpy(productos[j], productos[j+1]);
                tiempo_producto[j] = tiempo_producto[j+1];
                demanda_producto[j] = demanda_producto[j+1];
                for (int k = 0; k < total_recursos; k++)
                    recurso_usado[j][k] = recurso_usado[j+1][k];
            }
            total_productos--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}
void editar_recurso() {
    char nombre[MAX_NOMBRE];
    printf("Nombre del recurso a editar: ");
    scanf("%s", nombre);
    for (int i = 0; i < total_recursos; i++) {
        if (strcmp(nombre, recursos[i]) == 0) {
            do {
                printf("Nueva cantidad disponible de %s: ", recursos[i]);
                scanf("%d", &cantidad_recursos[i]);
            } while (cantidad_recursos[i] <= 0);
            printf("Recurso actualizado.\n");
            return;
        }
    }
    printf("Recurso no encontrado.\n");
}

void calcular_produccion() {
    int total_tiempo = 0;
    int recursos_necesarios[MAX_RECURSOS] = {0};

    for (int i = 0; i < total_productos; i++) {
        total_tiempo += tiempo_producto[i] * demanda_producto[i];
        for (int j = 0; j < total_recursos; j++) {
            recursos_necesarios[j] += recurso_usado[i][j] * demanda_producto[i];
        }
    }

    printf("\nTiempo total requerido: %d\n", total_tiempo);
    printf("Recursos necesarios:\n");
    for (int j = 0; j < total_recursos; j++) {
        printf("- %s: %d (disponibles: %d)\n", recursos[j], recursos_necesarios[j], cantidad_recursos[j]);
    }

    printf("\nTiempo disponible: ");
    scanf("%d", &tiempo_disponible);

    int posible = 1;
    if (total_tiempo > tiempo_disponible) posible = 0;
    for (int j = 0; j < total_recursos; j++) {
        if (recursos_necesarios[j] > cantidad_recursos[j]) {
            posible = 0;
            break;
        }
    }

    if (posible){
        for (int j = 0; j < total_recursos; j++) {
            int *ptr_cantidad = &cantidad_recursos[j];
            *ptr_cantidad -= recursos_necesarios[j];
        }
        printf("\nLa produccion es posible con los recursos y tiempo disponible.\n");
    }
    else{
        printf("\nNo es posible cumplir la demanda con los recursos o tiempo disponibles.\n");
    }
}
