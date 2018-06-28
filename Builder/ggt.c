#include "ggt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Ggt* ggt_new()
{
    return (Ggt*) malloc(sizeof(Ggt));
}

void ggt_delete(Ggt* this)
{
    free(this);
}

int ggt_setId(Ggt* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int ggt_getId(Ggt* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int ggt_setNombre(Ggt* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int ggt_getNombre(Ggt* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int ggt_setApellido(Ggt* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int ggt_getApellido(Ggt* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int ggt_setEdad(Ggt* this,int edad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->edad=edad;
        retorno=0;
    }
    return retorno;
}

int ggt_getEdad(Ggt* this,int* edad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *edad=this->edad;
        retorno=0;
    }
    return retorno;
}

