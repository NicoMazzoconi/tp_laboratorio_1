#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#include <string.h>

static int siguienteID();

/** \brief Inicializa la variable estado
 *
 * \param lista el array se pasa como parametro.
 * \param int sizeArray  tamaño de la array
 * \return int
 *
 */
int personaInit(EPersona lista[], int sizeArray)
{
    int i;
    int retorno = -1;
    if(sizeArray > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0;i<sizeArray;i++)
        {
            lista[i].isEmpty = 1;
        }
    }
    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible, -1 error
 */
int obtenerEspacioLibre(EPersona lista[], int sizeArray)
{
    int i;
    int retorno = -1;
    if(sizeArray > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<sizeArray;i++)
        {
            if(lista[i].isEmpty == 1)
            {
                return i;
            }
        }
    }
    return retorno;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni, -1 error
 */
int buscarPorDni(EPersona lista[], int dni, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<sizeArray;i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].dni == dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Da de alta una persona
 *
 * \param EPersona lista[] el array se pasa como parametro.
 * \param int sizeArray  tamaño de la array
 * \return int
 *
 */
int personaAlta(EPersona lista[], int sizeArray)
{
    int retorno = -1;
    char nombre[50];
    char dni[9];
    int edad;
    int indice;

    if(sizeArray > 0 && lista != NULL)
    {
        retorno = -2;
        indice = obtenerEspacioLibre(lista,sizeArray);
        if(indice >= 0)
        {
            retorno = -3;
            if(!getValidString("Nombre?\n","Error\n","Overflow", nombre,50,2))
            {
                if(!pedirDNI(dni, "DNI?\n", "Invalido\n", 2))
                {
                    if(!getValidInt("Edad??\n", "Error\n", &edad, 1, 99, 2))
                    {
                        retorno = 0;
                        strcpy(lista[indice].nombre,nombre);
                        strcpy(lista[indice].dni, dni);
                        lista[indice].edad = edad;
                        lista[indice].isEmpty = 0;
                        lista[indice].idEPersona = siguienteID();
                        if(lista[indice].edad < 19)
                            lista[indice].grafico = 0;
                        if(lista[indice].edad > 18 && lista[indice].edad < 36)
                            lista[indice].grafico = 1;
                        if(lista[indice].edad > 35)
                            lista[indice].grafico = 2;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Da de baja un persona
 *
 * \param EPersona lista[] el array se pasa como parametro.
 * \param int sizeArray tamaño de la array
 * \param int dni DNI de la persona a dar de baja
 * \return int
 *
 */
int personaBaja(EPersona lista[], int sizeArray, int dni)
{
    int retorno = -1;
    int indice;
    indice = buscarPorDni(lista, dni, sizeArray);
    printf("%d", indice);
    if(indice >= 0)
    {
        retorno = 0;
        lista[indice].isEmpty = 1;
    }
    return retorno;
}

/** \brief
 *
 * \param lista[] EPersona
 * \param sizeArray int
 * \return int
 *
 */
int mostrarPersonas(EPersona lista[], int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0;i<sizeArray;i++)
        {
            if(!lista[i].isEmpty)
            {
               printf("\nNombre %s, Edad %d, DNI %s, ID %d, GRH %d\n",lista[i].nombre,lista[i].edad,lista[i].dni, lista[i].idEPersona, lista[i].grafico);
            }
        }
    }
    return retorno;
}

/** \brief
 *
 * \param lista[] EPersona
 * \param sizeArray int
 * \param orden int
 * \return int
 *
 */
int ordenarPorNombre(EPersona lista[], int sizeArray, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    EPersona auxiliar;

    if(sizeArray > 0 && lista != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<sizeArray-1;i++)
            {
                    if(lista[i].isEmpty == 0 && lista[i+1].isEmpty == 0 )
                    {
                        if((strcmp(lista[i].nombre,lista[i+1].nombre) > 0 && !orden) || (strcmp(lista[i].nombre,lista[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = lista[i];
                            lista[i] = lista[i+1];
                            lista[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}

static int siguienteID()
{
    static int id = 0;
    id++;
    return id;
}

int graficoEdades(EPersona *lista, int QTY)
{
    int j,i;
    int grh0=0;
    int grh1=0;
    int grh2=0;
    int max=0;

    for(i=0;i<QTY;i++)
    {
        if(!lista[i].isEmpty)
        {
                if(lista[i].grafico == 0)
                {
                    grh0++;
                }
                if(lista[i].grafico == 1)
                {
                    grh1++;
                }
                if(lista[i].grafico == 2)
                {
                    grh2++;
                }
        }
    }
    int grh[3] = {grh0, grh1, grh2};
    for (i = 0; i < 3; i++)
    {
        if (grh[i] > max)
        {
            max = grh[i];
        }
    }
    for(i = max; i > 0; i--)
    {
        for (j = 0; j < 3; j++)
        {
            if (grh[j] >= i)
                printf("    *");
            else
                printf("     ");
        }
        putchar('\n');
    }
    printf("  <19  19a35 >35\n");
}
