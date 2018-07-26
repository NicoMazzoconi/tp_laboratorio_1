#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Mercaderia.h"
#include <string.h>

int parse_leerArchivo(ArrayList* pList, char* path)
{
    int retorno = -1;
    if(pList != NULL && path != NULL)
    {
        FILE* pFile;
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            char bufProducto[4096];
            char bufDireccion[4096];
            char bufLocalidad[4096];
            char bufRecibe[4096];
            char bufId[4096];
            int id;
            char producto[128];
            char direccion[128];
            char localidad[128];
            char recibe[128];
            Mercaderia* auxMercaderia;// = Mercaderia_new();
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufId, bufProducto, bufDireccion, bufLocalidad, bufRecibe);
            while(!feof(pFile))
            {
            	retorno = 0;
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufId, bufProducto, bufDireccion, bufLocalidad, bufRecibe);
                id = atoi(bufId);
                strncpy(producto, bufProducto, 128);
                strncpy(direccion, bufDireccion, 128);
                strncpy(localidad, bufLocalidad, 128);
                strncpy(recibe, bufRecibe, 128);
                auxMercaderia = Mercaderia_newParametro(producto, direccion, localidad, recibe, id);
                if(auxMercaderia != NULL)
                {
                	al_add(pList, auxMercaderia);
				}
            }
            fclose(pFile);
        }
    }
    return retorno;
}

int parse_writeArchivo(ArrayList* pList, char* path)
{
    int retorno = -1;
    if(pList != NULL && path != NULL)
    {
    	FILE* pFile;
    	pFile = fopen(path, "w");
    	if(pFile != NULL)
    	{
    		Mercaderia* auxMercaderia;
    		char producto[128];
    		char direccion[128];
    		char localidad[128];
    		char recibe[128];
    		int id,i;
    		fprintf(pFile, "id,producto,direccion,localidad,recibe\n");
    		for(i = 0; i < al_len(pList); i++)
    		{
    			auxMercaderia = al_get(pList, i);
    			Mercaderia_getProducto(auxMercaderia, producto);
    			Mercaderia_getDireccion(auxMercaderia, direccion);
    			Mercaderia_getLocalidad(auxMercaderia, localidad);
    			Mercaderia_getRecibe(auxMercaderia, recibe);
    			Mercaderia_getId(auxMercaderia, &id);
    			fprintf(pFile, "%d,%s,%s,%s,%s\n", id, producto, direccion, localidad, recibe);
    			retorno = 0;
			}
		}
		fclose(pFile);
	}
    return retorno;
}

