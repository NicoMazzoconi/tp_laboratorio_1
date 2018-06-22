#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int retorno = 0;
    if(fileName != NULL && listaEmpleados != NULL)
    {
        FILE* pFile;
        pFile = fopen(fileName, "r");
        char buffId[4096];
        char buffNombre[4096];
        char buffHoras[4096];
        int horas;
        int id;
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffId, buffNombre, buffHoras);
        while(!feof(pFile))
        {
            Empleado* auxEmp = empleado_new();
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffId, buffNombre, buffHoras);
            id = atoi(buffId);
            horas = atoi(buffHoras);
            auxEmp = empleado_newParametros(buffNombre, id, horas, 0);
            al_add(listaEmpleados, auxEmp);
            retorno = 1;
        }
        fclose(pFile);
    }
    return retorno; // OK
}

