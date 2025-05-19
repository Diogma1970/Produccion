#ifndef PRODUCCION_H
#define PRODUCCION_H

#define MAX_RECURSOS 10
#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 30

extern char recursos[MAX_RECURSOS][MAX_NOMBRE];
extern int cantidad_recursos[MAX_RECURSOS];
extern int total_recursos;

extern char productos[MAX_PRODUCTOS][MAX_NOMBRE];
extern int tiempo_producto[MAX_PRODUCTOS];
extern int demanda_producto[MAX_PRODUCTOS];
extern int recurso_usado[MAX_PRODUCTOS][MAX_RECURSOS];
extern int total_productos;

extern int tiempo_disponible;

void ingresar_recursos();
void ingresar_productos();
void editar_producto();
void eliminar_producto();
void editar_recurso();
void calcular_produccion();

#endif
