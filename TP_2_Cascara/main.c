#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define QTY 20
#include <string.h>
#include "utn.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int id;
    EPersona lista[QTY];
    personaInit(lista, QTY);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                personaAlta(lista, QTY);
                break;
            case 2:
                id = getInt("Ingrese el ID a borrar");
                personaBaja(lista, QTY, id);
                break;
            case 3:
                ordenarPorNombre(lista, QTY, 0);
                mostrarPersonas(lista, QTY);
                break;
            case 4:
                graficoEdades(lista, QTY);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
