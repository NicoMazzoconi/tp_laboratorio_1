#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publicaciones.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#include "cliente.h"
#include "informar.h"

static int buscarLugarLibre(Publicaciones* array,int limite);
static int proximoId();

int publicaciones_init(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}

int publicaciones_buscarPorId(Publicaciones* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idPublicaciones == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int publicaciones_baja(Publicaciones* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicaciones_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int publicaciones_mostrar(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\n[RELEASE] %s - %d - %d",array[i].texto,array[i].idPublicaciones,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int publicaciones_mostrarDebug(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d",array[i].texto,array[i].idPublicaciones,array[i].isEmpty);
        }
    }
    return retorno;
}


int publicaciones_alta(Publicaciones* array,int limite, Cliente *arrayC, int limiteC)
{
    int retorno = -1;
    char texto[65];
    int rubro;
    int idCliente;
    int id;
    int indice;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("Texto?","Error","Overflow", texto,65,2))
            {
                if(!getValidInt("Rubro?", "Error", &rubro, 0, 50, 2))
                {
                    if(!getValidId(arrayC, limiteC, &idCliente))
                    {
                        retorno = 0;
                        array[indice].rubro = rubro;
                        array[indice].idCliente = idCliente;
                        strcpy(array[indice].texto,texto);
                        array[indice].idPublicaciones = id;
                        array[indice].isEmpty = OCUPADO;
                        array[indice].estado = 1;
                        printf("Texto: %s  IdCliente: %d\n", array[indice].texto, array[indice].idCliente);
                    }
                }
            }
        }
    }
    return retorno;
}



int publicaciones_modificacion(Publicaciones* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    indice = publicaciones_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
        {
            retorno = 0;
            strcpy(array[indice].texto,nombre);
        }


    }
    return retorno;
}


static int buscarLugarLibre(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}



/*int publicaciones_ordenar(Publicaciones* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Publicaciones auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}*/

int getValidId(Cliente *arrayC, int limiteC, int *idCliente)
{
    int i;
    int aux;
    getValidInt("IdCliente?", "Error", &aux, 0, 1000, 2);
    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].isEmpty && arrayC[i].idCliente == aux)
        {
            *idCliente = aux;
            return 0;
        }
    }
    printf("ID invalido");
    return 1;
}

int getValidIdPublicacion(Publicaciones *array, int limite, int *idPublicacion, int *indice)
{
    int i;
    int aux;
    getValidInt("IdPublicacion?", "Error", &aux, 0, 1000, 2);
    for(i=0;i<limite;i++)
    {
        if(!array[i].isEmpty && array[i].idPublicaciones == aux)
        {
            *idPublicacion = aux;
            *indice =i;
            return 0;
        }
    }
    printf("ID invalido");
    return 1;
}



int publicaciones_Estado(Publicaciones *array, int limite, Cliente *arrayC, int limiteC)
{
    int idPublicacion;
    int indicePublicacion;
    int indice;
    int opcion = -1;
    if(!getValidIdPublicacion(array, limite, &idPublicacion, &indicePublicacion))
    {
        indice = duenioPublicaciones(arrayC, limiteC, array, limite, idPublicacion);
        printf("Cliente seleccionado es: %s %s cuit: %s id: &d\n",arrayC[indice].nombre, arrayC[indice].apellido, arrayC[indice].cuit, arrayC[indice].idCliente);
    }
    getValidInt("Seleccione 1 pausar, 2 renaudar, 3 cancelar", "No valido", &opcion, 1,3,2);
    switch(opcion)
    {
    case 1:
        array[indicePublicacion].estado = 0;
        break;
    case 2:
        array[indicePublicacion].estado = 1;
        break;
    case 3:
        return 0;
    break;
    }

        return 0;

}





































