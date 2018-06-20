#include <stdio.h>
#include <stdlib.h>
#include "ventas.h"
#include "clientes.h"
#include <string.h>
#include "utn.h"
#include "ArrayList.h"
#include "funciones.h"
#include "parse.h"

int main()
{
    int id, cod;
    ArrayList* pArrayVentas;
    ArrayList* pArrayClientes;
    pArrayVentas = al_newArrayList();
    pArrayClientes = al_newArrayList();
    parse_leerClientes(pArrayClientes, "datosClientes.txt");
    parse_leerVentas(pArrayVentas, "datosVentas.txt");
    int opcion;
    do{
        getValidInt("1)Alta cliente\n2)Baja cliente\n3)Modificacion cliente\n4)Listar clientes\n5)Realizar una venta\n6)Anular una venta\n7)Informar ventas\n8)Informar ventas por productos\n9)Generar informes de ventas\n10)Informar cantidad de ventas por cliente\n11)Salir\n",
                    "Opcion invalida\n", &opcion, 1, 11, 1);
        switch(opcion)
        {
        case 1:
            clientes_alta(pArrayClientes);
            parse_clientes(pArrayClientes, "datosClientes.txt");
            break;
        case 2:
            id = getInt("Id a borrar?");
            clientes_baja(pArrayClientes, id);
            parse_clientes(pArrayClientes, "datosClientes.txt");
            break;
        case 3:
            id = getInt("Id a modificar?");
            clientes_mod(pArrayClientes, id);
            parse_clientes(pArrayClientes, "datosClientes.txt");
            break;
        case 4:
            funciones_listarClientes(pArrayClientes);
            break;
        case 5:
            ventas_alta(pArrayVentas);
            parse_ventas(pArrayVentas, "datosVentas.txt");
            break;
        case 6:
            id = getInt("Id a borrar");
            ventas_baja(pArrayVentas, id);
            parse_ventas(pArrayVentas, "datosVentas.txt");
            break;
        case 7:
            funciones_listarVentas(pArrayVentas, pArrayClientes, -1);
            break;
        case 8:
            cod = getInt("Codigo del producto?\n");
            funciones_listarVentas(pArrayVentas, pArrayClientes, cod);
            break;
        case 9:
            funciones_archivoVentas(pArrayVentas, pArrayClientes, "InformeVenta.txt");
            break;
        case 10:
            funciones_clientesMontos(pArrayClientes, pArrayVentas);
            break;
        }
    }while(opcion != 11);
    parse_clientes(pArrayClientes, "datosClientes.txt");
    parse_ventas(pArrayVentas, "datosVentas.txt");
    return 0;
}
