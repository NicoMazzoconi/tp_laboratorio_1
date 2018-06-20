#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <string.h>
#include "utn.h"
#include "ArrayList.h"

static int isValidName(char* name);
static int isValidLastName(char* LastName);
static int isValidDni(char* dni);

void clientes_delete(Clientes* this)
{
    free(this);
}
Clientes* clientes_new()
{
    return (Clientes*) malloc(sizeof(Clientes));
}
Clientes* clientes_newParametros(char* nombre, char* apellido, char* dni, int idCliente)
{
    Clientes* auxCliente = clientes_new();
    if(     !clientes_setNombre(auxCliente, nombre)
       &&   !clientes_setApellido(auxCliente, apellido)
       &&   !clientes_setDni(auxCliente, dni)
       &&   !clientes_setIdCliente(auxCliente, idCliente))
        return auxCliente;
    clientes_delete(auxCliente);
    return NULL;
}
int clientes_setNombre(Clientes* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && !isValidName(nombre))
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int clientes_getNombre(Clientes* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
int clientes_setApellido(Clientes* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && !isValidLastName(apellido))
    {
        strcpy(this->apellido, apellido);
        retorno = 0;
    }
    return retorno;
}
int clientes_getApellido(Clientes* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(apellido, this->apellido);
        retorno = 0;
    }
    return retorno;
}
int clientes_setDni(Clientes* this, char* dni)
{
    int retorno = -1;
    if(this != NULL && !isValidDni(dni))
    {
        strcpy(this->dni, dni);
        retorno = 0;
    }
    return retorno;
}
int clientes_getDni(Clientes* this, char* dni)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(dni, this->dni);
        retorno = 0;
    }
    return retorno;
}
int clientes_setIdCliente(Clientes* this, int idCliente)
{
    int retorno = -1;
    int maximo = -1;
    if(this != NULL)
    {
        if(idCliente >= 0)
        {
            this->idCliente = idCliente;
            if(idCliente > maximo)
                maximo = idCliente;
        }
        else
        {
            maximo++;
            this->idCliente = maximo;
        }
        retorno = 0;
    }
    return retorno;
}
int clientes_getIdCliente(Clientes* this, int* idCliente)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idCliente = this->idCliente;
        retorno = 0;
    }
    return retorno;
}
int clientes_alta(ArrayList* pArrayClientes)
{
    char nombre[64];
    char apellido[64];
    char dni[20];
    int retorno = -1;
    Clientes* auxCliente = clientes_new();
    if(pArrayClientes != NULL)
    {
        retorno = -2;
        if(getString("Nombre?", nombre))
            if(getString("Apellido?", apellido))
                if(getString("Dni?", dni))
                {
                    auxCliente = clientes_newParametros(nombre, apellido, dni, -1);
                    al_add(pArrayClientes, auxCliente);
                    retorno = 0;
                }
    }
    return retorno;
}
int clientes_baja(ArrayList* pArrayClientes, int id)
{
    int retorno = -1;
    if(pArrayClientes != NULL && id >= 0)
    {
        Clientes* auxCliente = clientes_new();
        int auxId;
        int i;
        retorno = -2;
        for(i = 0; i < al_len(pArrayClientes); i++)
        {
            auxCliente = al_get(pArrayClientes, i);
            clientes_getIdCliente(auxCliente, &auxId);
            if(auxId == id)
            {
                al_remove(pArrayClientes, i);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int clientes_mod(ArrayList* pArrayClientes, int id)
{
    char nombre[64];
    char apellido[64];
    char dni[20];
    int retorno = -1;
    int auxId, i;
    Clientes* auxCliente = clientes_new();
    if(pArrayClientes != NULL && id >= 0)
    {
        retorno = -2;
        for(i = 0; i < al_len(pArrayClientes); i++)
        {
            auxCliente = al_get(pArrayClientes, i);
            clientes_getIdCliente(auxCliente, &auxId);
            if(auxId == id)
            {
                retorno = -3;
                if(getString("Nombre?", nombre))
                    if(getString("Apellido?", apellido))
                        if(getString("Dni?", dni))
                        {
                            auxCliente = clientes_newParametros(nombre, apellido, dni, -1);
                            al_set(pArrayClientes, i, auxCliente);
                            retorno = 0;
                            break;
                        }
            }
        }
    }
    return retorno;
}
int clientes_compareLastName(void* pClienteA, void* pClienteB)
{
    char lastNameA[51];
    char lastNameB[51];
    clientes_getApellido(pClienteA,lastNameA);
    clientes_getApellido(pClienteB,lastNameB);
    return strcmp(lastNameA,lastNameB);
}
static int isValidName(char* name)
{
    return 0;
}
static int isValidLastName(char* LastName)
{
    return 0;
}
static int isValidDni(char* dni)
{
    return 0;
}
