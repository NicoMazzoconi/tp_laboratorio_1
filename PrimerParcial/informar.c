#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "publicaciones.h"
#include "utn.h"

int duenioPublicaciones(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP, int idPublicacion)
{
    int i,j;
    for(i=0;i<limiteP;i++)
    {
        if(!arrayP[i].isEmpty && arrayP[i].idPublicaciones == idPublicacion)
        {
            for(j=0;j<limiteC;j++)
            {
                if(!arrayC[j].isEmpty && arrayC[j].idCliente == arrayP[i].idCliente)
                    return j;
            }
        }
    }
    return -1;
}

int contadorDeAvisos(Publicaciones *arrayP, int limiteP, int idCliente)
{
    int i;
    int contador =0;
    for(i=0;i<limiteP;i++)
    {
        if(!arrayP[i].isEmpty && arrayP[i].idCliente == idCliente)
            contador++;
    }
    return contador;
}
int mostrarClientesConAvisos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP)
{
    int retorno = -1;
    int i;
    int anuncios;
    retorno = 0;
    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].isEmpty)
        {
            anuncios = contadorDeAvisos(arrayP, limiteP, arrayC[i].idCliente);
            printf("\n[RELEASE] %s - %s - %s - %d - %d - %d",arrayC[i].nombre,arrayC[i].apellido,arrayC[i].cuit,arrayC[i].idCliente,arrayC[i].isEmpty, anuncios);
        }
    }
    return retorno;
}

int duenioPublicacionesCliente(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP, int idCliente)
{
    int i;
    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].isEmpty && arrayC[i].idCliente == idCliente)
        {
            return i;
        }
    }
    return -1;
}

int publicacionesActivas(Publicaciones *arrayP, int limiteP, Cliente *arrayC, int limiteC)
{
    int indice;
    int i;
    for(i=0;i<limiteP;i++)
    {
        if(!arrayP[i].isEmpty && arrayP[i].estado)
        {
            indice = duenioPublicacionesCliente(arrayC, limiteC, arrayP, limiteP, arrayP[i].idCliente);
            printf("Texto: %s, Rubro: %d, IdCliente: %d, CUIT: %s \n", arrayP[i].texto, arrayP[i].rubro, arrayP[i].idCliente, arrayC[indice].cuit);
        }
    }
    return 0;
}


int clienteMasAvisos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    for(i=0;i<limiteC;i++)
    {
        if(contador > maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=0;j<limiteP;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente)
                contador++;
        }
    }

    printf("El cliente con mas avisos es: %s, con %d avisos\n", arrayC[indice].nombre, maximo);
    return 0;
}
int clienteMasAvisosPausados(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    for(i=0;i<limiteC;i++)
    {
        if(contador > maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=0;j<limiteP;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente && !arrayP[j].estado)
                contador++;
        }
    }

    printf("El cliente con mas avisos pausados es: %s, con %d avisos\n", arrayC[indice].nombre, maximo);
    return 0;
}
int clienteMasAvisosActivos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    for(i=0;i<limiteC;i++)
    {
        if(contador > maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=0;j<limiteP;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente && arrayP[j].estado)
                contador++;
        }
    }

    printf("El cliente con mas avisos activos es: %s, con %d avisos\n", arrayC[indice].nombre, maximo);
    return 0;
}



int cantidadPublicacionActivasRubroIngresado(Publicaciones *arrayP, int limiteP)
{
    int i;
    int rubro;
    int contador = 0;
    getValidInt("Rubro?", "Error", &rubro, 0, 100, 2);
    for(i=0;i<limiteP;i++)
    {
        if(!arrayP[i].isEmpty && arrayP[i].rubro == rubro)
            contador++;
    }
    printf("El rubro elegido tiene %d publicaciones\n", contador);
    return 0;
}
int rubroMasPublicacionesActivas(Publicaciones *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    for(i=0;i<limiteP;i++)
    {
        if(contador > maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=i+1;j<limiteP;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].estado && arrayP[j].rubro == arrayP[i].rubro)
                contador++;
        }
    }

    printf("El rubro con mas avisos pausados es: %d, con %d avisos\n", arrayP[indice].rubro, maximo);
    return 0;
}
int rubroMenosPublicacionesActivas(Publicaciones *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    for(i=0;i<limiteP;i++)
    {
        if(contador < maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=i+1;j<limiteP;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].estado && arrayP[j].rubro == arrayP[i].rubro)
                contador++;
        }
    }

    printf("El rubro con mas avisos activos es: %d, con %d avisos\n", arrayP[indice].rubro, maximo);
    return 0;
}
