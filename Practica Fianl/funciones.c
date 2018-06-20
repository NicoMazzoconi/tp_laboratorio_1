#include <stdio.h>
#include <stdlib.h>
#include "ventas.h"
#include "clientes.h"
#include <string.h>
#include "utn.h"
#include "ArrayList.h"

int funciones_indexClienteId(ArrayList* pArrayClientes, int id)
{
    int i, auxId;
    Clientes* auxCliente = clientes_new();
    ArrayList* auxArrayClientes = al_newArrayList();
    auxArrayClientes = al_clone(pArrayClientes);
    al_sort(auxArrayClientes, clientes_compareLastName, 1);
    for(i = 0; i < al_len(auxArrayClientes); i++)
    {
        auxCliente = al_get(auxArrayClientes, i);
        clientes_getIdCliente(auxCliente, &auxId);
        if(id == auxId)
            return i;
    }
    al_deleteArrayList(auxArrayClientes);
    return -1;
}

void funciones_listarClientes(ArrayList* pArrayClientes)
{
    int i;
    char nombre[64];
    char apellido[64];
    char dni[20];
    int idCliente;
    if(pArrayClientes != NULL)
    {
        Clientes* auxCliente = clientes_new();
        for(i = 0; i < al_len(pArrayClientes); i++)
        {
            auxCliente = al_get(pArrayClientes, i);
            clientes_getApellido(auxCliente, apellido);
            clientes_getNombre(auxCliente, nombre);
            clientes_getDni(auxCliente, dni);
            clientes_getIdCliente(auxCliente, &idCliente);
            printf("%d\t%s\t%s\t%s\n", idCliente, nombre, apellido, dni);
        }
    }
}

void funciones_listarVentas(ArrayList* pArrayVentas, ArrayList* pArrayClientes, int cod)
{
    int i;
    int auxId, indice, auxIdVentas, cantidad, codProducto;
    float precio, monto;
    char nombre[64];
    char apellido[64];
    char dni[20];
    if(pArrayVentas != NULL && pArrayClientes != NULL)
    {
        Ventas* auxVentas = ventas_new();
        Clientes* auxClientes = clientes_new();
        for(i = 0; i < al_len(pArrayVentas); i++)
        {
            auxVentas = al_get(pArrayVentas, i);
            ventas_getIdCliente(auxVentas, &auxId);
            indice = funciones_indexClienteId(pArrayClientes, auxId);
            if(indice >= 0)
            {
                auxClientes = al_get(pArrayClientes, indice);
                ventas_getIdVenta(auxVentas, &auxIdVentas);
                clientes_getNombre(auxClientes, nombre);
                clientes_getApellido(auxClientes, apellido);
                clientes_getDni(auxClientes, dni);
                ventas_getCodProducto(auxVentas, &codProducto);
                ventas_getCantidad(auxVentas, &cantidad);
                ventas_getPrecio(auxVentas, &precio);
                monto = precio * cantidad;
                if(cod < 0 || cod == codProducto)
                    printf("%d\t%s\t%s\t%s\t%d\t%.2f\n", auxIdVentas, nombre, apellido, dni, codProducto, monto);
            }
        }
    }
}

void funciones_archivoVentas(ArrayList* pArrayVentas, ArrayList* pArrayClientes, char* path)
{
    int i;
    int auxId, indice, auxIdVentas, cantidad, codProducto;
    float precio, monto;
    char nombre[64];
    char apellido[64];
    char dni[20];
    FILE* pFile;
    if(pArrayClientes !=NULL && pArrayVentas != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        Ventas* auxVentas = ventas_new();
        Clientes* auxClientes = clientes_new();
        for(i = 0; i < al_len(pArrayVentas); i++)
        {
            auxVentas = al_get(pArrayVentas, i);
            ventas_getIdCliente(auxVentas, &auxId);
            indice = funciones_indexClienteId(pArrayClientes, auxId);
            if(indice >= 0)
            {
                auxClientes = al_get(pArrayClientes, indice);
                ventas_getIdVenta(auxVentas, &auxIdVentas);
                clientes_getNombre(auxClientes, nombre);
                clientes_getApellido(auxClientes, apellido);
                clientes_getDni(auxClientes, dni);
                ventas_getCodProducto(auxVentas, &codProducto);
                ventas_getCantidad(auxVentas, &cantidad);
                ventas_getPrecio(auxVentas, &precio);
                monto = precio * cantidad;
                fprintf(pFile, "%d\t%s\t%s\t%s\t%d\t%.2f\n", auxIdVentas, nombre, apellido, dni, codProducto, monto);
            }
        }
    }
    fclose(pFile);
}

void funciones_clientesMontos(ArrayList* pArrayClientes, ArrayList* pArrayVentas)
{
    int i,j,cantidad,ventas;
    char nombre[64];
    char apellido[64];
    char dni[20];
    int idCliente, auxId;
    float monto, precio;
    if(pArrayClientes != NULL && pArrayVentas != NULL)
    {
        Ventas* auxVentas = ventas_new();
        Clientes* auxClientes = clientes_new();
        for(i = 0; i < al_len(pArrayClientes); i++)
        {
            auxClientes = al_get(pArrayClientes, i);
            clientes_getApellido(auxClientes, apellido);
            clientes_getNombre(auxClientes, nombre);
            clientes_getDni(auxClientes, dni);
            clientes_getIdCliente(auxClientes, &idCliente);
            monto = 0;
            ventas = 0;
            for(j = 0; j < al_len(pArrayVentas); j++)
            {
                auxVentas = al_get(pArrayVentas, j);
                ventas_getIdCliente(auxVentas, &auxId);
                if(auxId == idCliente)
                {
                    ventas++;
                    ventas_getCantidad(auxVentas, &cantidad);
                    ventas_getPrecio(auxVentas, &precio);
                    monto = monto + (precio * cantidad);
                }
            }
            printf("%d\t%s\t%s\t%s\t%d\t%.2f\n", idCliente, nombre, apellido, dni, ventas, monto);
        }
    }
}
