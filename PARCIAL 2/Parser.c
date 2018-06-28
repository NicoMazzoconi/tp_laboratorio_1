#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"
#include <string.h>

/** \brief Lee un archivo y lo carga en el arraylist
 *
 * \param fileName char* Direccion del archivo
 * \param listaEmpleados ArrayList* el arraylist donde cargarlos
 * \return int 0 sino puedo leerlo, 1 si pudo
 *
 */
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
        char nombre[128];
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffId, buffNombre, buffHoras);
        while(!feof(pFile))
        {
            S_Empleado* auxEmp = Empleado_new();
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffId, buffNombre, buffHoras);
            id = atoi(buffId);
            horas = atoi(buffHoras);
            strncpy(nombre, buffNombre, sizeof(nombre));
            auxEmp = Empleado_newParametros(id, nombre, horas);
            al_add(listaEmpleados, auxEmp);
            retorno = 1;
        }
        fclose(pFile);
    }
    return retorno; // OK
}

