#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayList.h"
#include <string.h>
#include "Mercaderia.h"
#include "parse.h"

int main()
{
    ArrayList* listaMercaderia;
    listaMercaderia = al_newArrayList();
    int opcion;
    char archivo[128];
    char localidadUno[128];
    char localidadDos[128];
    char localidadTres[128];
    do
    {
        getValidInt("1)Cargar archivo\n2)Imprimir entregas\n3)Imprimir localidades\n4)Generar archivo de reparto\n5)Salir\n", "Opcion invalida\n", &opcion, 1, 5, 2);
        switch(opcion)
        {
        case 1:
            getValidString("Ingrese el nombre del archivo\n", "Nombre invalido\n", "Nombre invalido\n", archivo, 25, 2);
            if(parse_leerArchivo(listaMercaderia, archivo) == -1)
            {
                printf("Error con el archivo o no existe\n");
            }
            else
                printf("Archivo cargado\n");
            break;
        case 2:
            funciones_imprimirEntregas(listaMercaderia);
            break;
        case 3:
            funciones_localidades(listaMercaderia);
            break;
        case 4:
            if(!getValidString("Ingrese la primer localidad\n", "Localidad invalida\n", "Localidad invalida\n", localidadUno, 128, 2))
                if(!getValidString("Ingrese la segunda localidad\n", "Localidad invalida\n", "Localidad invalida\n", localidadDos, 128, 2))
                    if(!getValidString("Ingrese la tercera localidad\n", "Localidad invalida\n", "Localidad invalida\n", localidadTres, 128, 2))
                        funciones_generarArchivoDeReparto(listaMercaderia, localidadUno, localidadDos, localidadTres);
            break;
        }
    }while(opcion != 5);
    return 0;
}
