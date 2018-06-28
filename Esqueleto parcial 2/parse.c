#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int parse_leerArchivo(ArrayList* pList, char* path, char* pathError)
{
    int retorno = -1;
    if(pList != NULL && path != NULL && pathError != NULL)
    {
        FILE* pFile, pFileError;
        pFile = fopen(path, "r");
        pFileError = fopen(pathError, "w");
        if(pFile != NULL && pFileError != NULL)
        {
            char bufId[4096];
            char bufName[4096];
            char bufLastName[4096];
            int id;
            void* auxStruct;
            while(!feof(pFile))
            {
            	retorno = 0;
                fscanf(pFile, "%[^,],%[^,],%[^\n]\n", bufId, bufName, bufLastName);
                id = atoi(bufId);
                axuStruct = struct_newParamateros(bufName, bufLastName, id)
                if(auxStruct != NULL)
                {
                	al_add(pList, auxStruct);
				}
				else
				{
					fprintf(pFileError,"%s,%s,%s\n", bufId,bufname,buflastname);
				}

            }
            fclose(pFile);
            fclose(pFileError);
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
    		void* auxStruc;
    		char* nombre;
    		char* apellido;
    		int id;
    		for(i = 0; i < al_len(pList), i++)
    		{
    			auxStruc = al_get(pList, i);
    			struct_getName(auxStruc, nombre);
    			struct_getApellido(auxStruc, apellido);
    			struct_getId(auxStruc, &id);
    			fprintf(pFile, "%d,%s,%s\n", id, nombre, apellido);
    			retorno = 0;
			}
		}
		fclose(pFile);
	}
    return retorno;
}

