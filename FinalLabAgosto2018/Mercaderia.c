#include "Mercaderia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

static int isValidProducto(char* producto);
static int isValidDireccion(char* direccion);
static int isValidLocalidad(char* localidad);
static int isValidRecibe(char* recibe);

Mercaderia* Mercaderia_new()
{
    return (Mercaderia*) malloc(sizeof(Mercaderia));
}

Mercaderia* Mercaderia_newParametro(char* producto,char* direccion,char* localidad,char* recibe,int id)
{
    Mercaderia* auxMercaderia = Mercaderia_new();
    if(     !Mercaderia_setProducto(auxMercaderia, producto)
       &&   !Mercaderia_setDireccion(auxMercaderia, direccion)
       &&   !Mercaderia_setLocalidad(auxMercaderia, localidad)
       &&   !Mercaderia_setRecibe(auxMercaderia, recibe)
       &&   !Mercaderia_setId(auxMercaderia, id))
        return auxMercaderia;
    Mercaderia_delete(auxMercaderia);
    return NULL;
}
void Mercaderia_delete(Mercaderia* this)
{
    free(this);
}

int Mercaderia_setProducto(Mercaderia* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL && !isValidProducto(producto))
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_getProducto(Mercaderia* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_setDireccion(Mercaderia* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL && !isValidDireccion(direccion))
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_getDireccion(Mercaderia* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_setLocalidad(Mercaderia* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL && !isValidLocalidad(localidad))
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_getLocalidad(Mercaderia* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_setRecibe(Mercaderia* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL && !isValidRecibe(recibe))
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_getRecibe(Mercaderia* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_setId(Mercaderia* this,int id)
{
    int retorno=-1;
    int maximo = -1;
    if(this!=NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            this->id=id;
            maximo = id;
        }
        else
        {
            if(id <= maximo)
            {
                maximo++;
                this->id = maximo;
            }
        }
    }
    return retorno;
}

int Mercaderia_getId(Mercaderia* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Mercaderia_printMercaderia(Mercaderia *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        char producto[128];
        char direccion[128];
        char localidad[128];
        char recibe[128];
        int id;
        Mercaderia_getProducto(this, producto);
        Mercaderia_getDireccion(this, direccion);
        Mercaderia_getLocalidad(this, localidad);
        Mercaderia_getRecibe(this, recibe);
        Mercaderia_getId(this, &id);
        printf("%d\t%s\t%s\t%s\t%s\n", id, producto, direccion, localidad, recibe);
    }
    return retorno;
}

static int isValidProducto(char* producto)
{
    int retorno = -1;
    if(producto != NULL)
    {
        int i;
        for(i = 0; i < strlen(producto); i++)
        {
            if((producto[i] < 'a' || producto[i] > 'z') && (producto[i] < 'A' || producto[i] > 'Z') && producto[i] != ' ')
            {
                retorno = -2;
                break;
            }
            retorno = 0;
        }
    }
    return retorno;
}

static int isValidDireccion(char* direccion)
{
    int retorno = -1;
    if(direccion != NULL)
    {
        int i;
        for(i = 0; i < strlen(direccion); i++)
        {
            if((direccion[i] < 'a' || direccion[i] > 'z') && (direccion[i] < 'A' || direccion[i] > 'Z') && (direccion[i] < '0' || direccion[i] > '9') && direccion[i] != ' ')
            {
                retorno = -2;
                break;
            }
            retorno = 0;
        }
    }
    return retorno;
}

static int isValidLocalidad(char* localidad)
{
    int retorno = -1;
    if(localidad != NULL)
    {
        int i;
        for(i = 0; i < strlen(localidad); i++)
        {
            if((localidad[i] < 'a' || localidad[i] > 'z') && (localidad[i] < 'A' || localidad[i] > 'Z'))
            {
                retorno = -2;
                break;
            }
            retorno = 0;
        }
    }
    return retorno;
}

static int isValidRecibe(char* recibe)
{
    int retorno = -1;
    if(recibe != NULL)
    {
        int i;
        for(i = 0; i < strlen(recibe); i++)
        {
            if((recibe[i] < 'a' || recibe[i] > 'z') && (recibe[i] < 'A' || recibe[i] > 'Z') && recibe[i] != ' ')
            {
                retorno = -2;
                break;
            }
            retorno = 0;
        }
    }
    return retorno;
}
