#include "Mercaderia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

void funciones_imprimirEntregas(ArrayList* pList)
{
    if(pList != NULL)
    {
        Mercaderia* auxMercaderia = Mercaderia_new();
        int i;
        for(i = 0; i < al_len(pList); i++)
        {
            auxMercaderia = al_get(pList, i);
            Mercaderia_printMercaderia(auxMercaderia);
        }
    }
}

void funciones_localidades(ArrayList* pList)
{
    if(pList != NULL)
    {
        char localidad[128];
        char localidadesEncontrada[128][128];
        Mercaderia* auxMercaderia = Mercaderia_new();
        int i,j;
        int p = 0;
        for(i=0; i< 128; i++)
        {
            strcpy(localidadesEncontrada[i], "sad");
        }
        for(i = 0; i < al_len(pList); i++)
        {
            auxMercaderia = al_get(pList, i);
            Mercaderia_getLocalidad(auxMercaderia, localidad);
            for(j = 0; j < 128; j++)
            {
                if(strcmp(localidad, localidadesEncontrada[j]) == 0)
                    break;
            }
            if(j == 128)
            {
                strcpy(localidadesEncontrada[p], localidad);
                p++;
            }
        }
        for(i=0; i < p; i++)
        {
            printf("%s\n", localidadesEncontrada[i]);
        }
    }
}

void funciones_generarArchivoDeReparto(ArrayList* pList, char* localidadUno, char* localidadDos, char* localidadTres)
{
    if(pList != NULL && localidadUno != NULL && localidadDos != NULL && localidadTres != NULL)
    {
        ArrayList* listaReparto = al_newArrayList();
        Mercaderia* auxMercaderia = Mercaderia_new();
        int i;
        char localidad[128];
        for(i = 0; i < al_len(pList); i++)
        {
            auxMercaderia = al_get(pList, i);
            Mercaderia_getLocalidad(auxMercaderia, localidad);
            if(strcmp(localidad, localidadUno) != 0)
                continue;
            /*if(strcmp(localidad, localidadDos) != 0)
            {

            }
            if(strcmp(localidad, localidadTres) != 0)
            {

            }           continue;*/
            al_add(listaReparto, auxMercaderia);
        }
        parse_writeArchivo(listaReparto, "entregas.csv");
    }
}
