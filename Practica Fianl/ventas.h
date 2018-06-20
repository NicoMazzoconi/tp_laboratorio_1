#include "ArrayList.h"
#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
typedef struct{
    float precio;
    int codProducto;
    int idCliente;
    int cantidad;
    int idVenta;
}Ventas;
#endif // VENTAS_H_INCLUDED

void ventas_delete(Ventas* this);
Ventas* ventas_new();
Ventas* ventas_newParametros(float precio, int codProducto, int idCliente, int cantidad, int idVenta);
int ventas_setPrecio(Ventas* this, float precio);
int ventas_getPrecio(Ventas* this, float* precio);
int ventas_setCodProducto(Ventas* this, int codProducto);
int ventas_getCodProducto(Ventas* this, int* codProducto);
int ventas_setIdCliente(Ventas* this, int idCliente);
int ventas_getIdCliente(Ventas* this, int* idCliente);
int ventas_setCantidad(Ventas* this, int cantidad);
int ventas_getCantidad(Ventas* this, int* cantidad);
int ventas_setIdVenta(Ventas* this, int idVenta);
int ventas_getIdVenta(Ventas* this, int* idVenta);
int ventas_alta(ArrayList* pArrayVentas);
int ventas_baja(ArrayList* pArrayVentas, int id);

