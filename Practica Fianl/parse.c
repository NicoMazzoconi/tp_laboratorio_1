#include <stdio.h>
#include <stdlib.h>
#include "ventas.h"
#include "clientes.h"
#include <string.h>
#include "utn.h"
#include "ArrayList.h"

void parse_clientes(ArrayList* pArrayClientes, char* path)
{
    FILE* pFile;
    char nombre[64];
    char apellido[64];
    char dni[20];
    int idCliente;
    if(pArrayClientes != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        int i;
        Clientes* auxCliente = clientes_new();
        for(i = 0; i < al_len(pArrayClientes); i++)
        {
            auxCliente = al_get(pArrayClientes, i);
            clientes_getNombre(auxCliente, nombre);
            clientes_getApellido(auxCliente, apellido);
            clientes_getDni(auxCliente, dni);
            clientes_getIdCliente(auxCliente, &idCliente);
            fprintf(pFile, "%d,%s,%s,%s\n", idCliente, nombre, apellido, dni);
        }
        fclose(pFile);
    }
}
void parse_ventas(ArrayList* pArrayVentas, char* path)
{
    FILE* pFile;
    float precio;
    int codProducto;
    int idCliente;
    int cantidad;
    int idVenta;
    if(pArrayVentas != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        int i;
        Ventas* auxVentas = ventas_new();
        for(i = 0; i < al_len(pArrayVentas); i++)
        {
            auxVentas = al_get(pArrayVentas, i);
            ventas_getCantidad(auxVentas, &cantidad);
            ventas_getCodProducto(auxVentas, &codProducto);
            ventas_getIdCliente(auxVentas, &idCliente);
            ventas_getIdVenta(auxVentas, &idVenta);
            ventas_getPrecio(auxVentas, &precio);
            fprintf(pFile, "%d,%d,%d,%d,%.2f\n", idVenta, idCliente, codProducto, cantidad, precio);
        }
        fclose(pFile);
    }
}

void parse_leerClientes(ArrayList* pArrayClientes, char* path)
{
    FILE* pFile;
    int idCliente;
    char buffNombre[4000];
    char buffApellido[4000];
    char buffDni[4000];
    char buffIdCliente[4000];
    if(pArrayClientes != NULL && path != NULL)
    {
        pFile = fopen(path, "r");
        Clientes* auxCliente = clientes_new();
        if(pFile != NULL)
            while(!feof(pFile))
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffIdCliente, buffNombre, buffApellido, buffDni);
                idCliente = atoi(buffIdCliente);
                auxCliente = clientes_newParametros(buffNombre, buffApellido, buffDni, idCliente);
                al_add(pArrayClientes, auxCliente);
            }
        fclose(pFile);
    }
}

void parse_leerVentas(ArrayList* pArrayVentas, char* path)
{
    FILE* pFile;
    float precio;
    int codProducto;
    int idCliente;
    int cantidad;
    int idVenta;
    char buffPrecio[4000];
    char buffCod[4000];
    char buffIdC[4000];
    char buffIdV[4000];
    char buffQTY[4000];
    if(pArrayVentas != NULL && path != NULL)
    {
        pFile = fopen(path, "r");
        Ventas* auxVenta = ventas_new();
        if(pFile != NULL)
            while(!feof(pFile))
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffIdV, buffIdC, buffCod, buffQTY, buffPrecio);
                idVenta = atoi(buffIdV);
                idCliente = atoi(buffIdC);
                cantidad = atoi(buffQTY);
                codProducto = atoi(buffCod);
                precio = atof(buffPrecio);
                auxVenta = ventas_newParametros(precio, codProducto, idCliente, cantidad, idVenta);
                al_add(pArrayVentas, auxVenta);
            }
        fclose(pFile);
    }
}
