#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "informar.h"
#include "publicaciones.h"
#include "utn.h"
#define QTY_Cliente 100
#define QTY_Publicaciones 1000

int main()
{
    Cliente arrayCliente[QTY_Cliente];
    Publicaciones arrayPublicaciones[QTY_Publicaciones];
    int menu;
    int auxiliarId;

    cliente_init(arrayCliente,QTY_Cliente);
    publicaciones_init(arrayPublicaciones,QTY_Publicaciones);
    do
    {
        getValidInt("\n1.Alta Cliente\n2.Modificar Cliente\n3.Baja Cliente\n4.Publicar\n5.Pausar/Renaudar\n6.Imprimir Clientes con avisos\n7.Publicaciones activas\n8.Clientes con mas avisos activos y pausados\n9.Cantidad de publicaciones de x Rubro\n10.Rubro con mas y menos publicaciones\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                cliente_alta(arrayCliente,QTY_Cliente);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(arrayCliente,QTY_Cliente,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_baja(arrayCliente,QTY_Cliente,auxiliarId);
                break;
            case 4:
                publicaciones_alta(arrayPublicaciones, QTY_Publicaciones, arrayCliente, QTY_Cliente);
                break;
            case 5:
                publicaciones_Estado(arrayPublicaciones, QTY_Publicaciones, arrayCliente, QTY_Cliente);
                break;
            case 6:
                mostrarClientesConAvisos(arrayCliente, QTY_Cliente, arrayPublicaciones, QTY_Publicaciones);
                break;
            case 7:
                publicacionesActivas(arrayPublicaciones,QTY_Publicaciones, arrayCliente, QTY_Cliente);
                break;
            case 8:
                clienteMasAvisos(arrayCliente, QTY_Cliente, arrayPublicaciones, QTY_Publicaciones);
                clienteMasAvisosPausados(arrayCliente, QTY_Cliente, arrayPublicaciones, QTY_Publicaciones);
                clienteMasAvisosActivos(arrayCliente, QTY_Cliente, arrayPublicaciones, QTY_Publicaciones);
                break;
            case 9:
                cantidadPublicacionActivasRubroIngresado(arrayPublicaciones, QTY_Publicaciones);
                break;
            case 10:
                rubroMasPublicacionesActivas(arrayPublicaciones, QTY_Publicaciones);
                rubroMenosPublicacionesActivas(arrayPublicaciones, QTY_Publicaciones);
                break;

        }

    }while(menu != 11);

    return 0;
}
