#include <stdio.h>
#include <stdlib.h>
#include "ventas.h"
#include <string.h>
#include "utn.h"
#include "ArrayList.h"

void ventas_delete(Ventas* this)
{
    free(this);
}
Ventas* ventas_new()
{
    return (Ventas*) malloc(sizeof(Ventas));
}
Ventas* ventas_newParametros(float precio, int codProducto, int idCliente, int cantidad, int idVenta)
{
    Ventas* auxVenta = ventas_new();
    if(     !ventas_setPrecio(auxVenta, precio)
       &&   !ventas_setCodProducto(auxVenta, codProducto)
       &&   !ventas_setIdCliente(auxVenta, idCliente)
       &&   !ventas_setCantidad(auxVenta, cantidad)
       &&   !ventas_setIdVenta(auxVenta, idVenta))
        return auxVenta;
    ventas_delete(auxVenta);
    return NULL;
}
int ventas_setPrecio(Ventas* this, float precio)
{
    int retorno = -1;
    if(this != NULL && precio > 0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}
int ventas_getPrecio(Ventas* this, float* precio)
{
    int retorno = -1;
    if(this != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}
int ventas_setCodProducto(Ventas* this, int codProducto)
{
    int retorno = -1;
    if(this != NULL && codProducto > 0)
    {
        this->codProducto = codProducto;
        retorno = 0;
    }
    return retorno;
}
int ventas_getCodProducto(Ventas* this, int* codProducto)
{
    int retorno = -1;
    if(this != NULL)
    {
        *codProducto = this->codProducto;
        retorno = 0;
    }
    return retorno;
}
int ventas_setIdCliente(Ventas* this, int idCliente)
{
    int retorno = -1;
    if(this != NULL && idCliente > 0)
    {
        this->idCliente = idCliente;
        retorno = 0;
    }
    return retorno;
}
int ventas_getIdCliente(Ventas* this, int* idCliente)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idCliente = this->idCliente;
        retorno = 0;
    }
    return retorno;
}
int ventas_setCantidad(Ventas* this, int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad > 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int ventas_getCantidad(Ventas* this, int* cantidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}
int ventas_setIdVenta(Ventas* this, int idVenta)
{
    int retorno = -1;
    static int maximo = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(idVenta >= 0)
        {
            this->idVenta = idVenta;
            if(idVenta > maximo)
                maximo = idVenta;
        }
        else
        {
            maximo++;
            this->idVenta = maximo;
        }
    }
    return retorno;
}
int ventas_getIdVenta(Ventas* this, int* idVenta)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idVenta = this->idVenta;
        retorno = 0;
    }
    return retorno;
}
int ventas_alta(ArrayList* pArrayVentas)
{
    int retorno = -1;
    float precio;
    int codProducto;
    int idCliente, cantidad;
    Ventas* auxVenta = ventas_new();
    if(pArrayVentas != NULL)
    {
        retorno = -2;
        if(!getValidFloat("Precio)", "Precio invalido", &precio, 1, 100000, 2))
            if(!getValidInt("Codigo del producto?", "Codigo invalido", &codProducto, 0, 10000, 2))
                if(!getValidInt("Id del cliente?", "id invalido", &idCliente, 0, 1000, 2))
                    if(!getValidInt("Cantidad?", "Cantidad invalida", &cantidad, 1, 100, 2))
                    {
                        auxVenta = ventas_newParametros(precio, codProducto, idCliente, cantidad, -1);
                        al_add(pArrayVentas, auxVenta);
                        retorno = 0;
                    }
    }
    return retorno;
}
int ventas_baja(ArrayList* pArrayVentas, int id)
{
    int retorno = -1;
    if(pArrayVentas != NULL && id >= 0)
    {
        Ventas* auxVentas = ventas_new();
        int auxId;
        int i;
        retorno = -2;
        for(i = 0; i < al_len(pArrayVentas); i++)
        {
            auxVentas = al_get(pArrayVentas, i);
            ventas_getIdVenta(auxVentas, &auxId);
            if(auxId == id)
            {
                al_remove(pArrayVentas, i);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
