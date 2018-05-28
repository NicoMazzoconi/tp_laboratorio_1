#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int movie_setId(Movie *this);
static int movie_getId(Movie *this, int* id);

Movie* movie_new()
{
    return (Movie*) malloc(sizeof(Movie));
}

void movie_delete(Movie* this)
{
    free(this);
}

Movie movie_newAlta(char* titulo, char* genero,char* duracion,char* descripcion,int puntaje,char* link)
{
    Movie *auxArray = movie_new();
    movie_setTitulo(auxArray, titulo);
    movie_setDescripcion(auxArray, descripcion);
    movie_setDuracion(auxArray, duracion);
    movie_setGenero(auxArray, genero);
    movie_setLink(auxArray, link);
    movie_setId(auxArray);
    movie_setPuntaje(auxArray, puntaje);
    return *auxArray;
}

int movie_Alta(Movie **ArrayMovie, int *qtyMovieActual)
{
    int retorno = -1;
    char auxTitulo[100];
    char auxGenero[50];
    char auxDuracion[20];
    char auxDescripcion[200];
    int auxPuntaje;
    char auxLink[200];
    if(ArrayMovie != NULL && *qtyMovieActual > 0)
    {
        if(!getValidString("Titulo?", "Error", "Demasiado largo", auxTitulo, 100, 2))
        {
            if(!getValidString("Genero?", "Error", "Demasiado largo", auxGenero, 50, 2))
            {
                if(!getValidString("Descripcion?", "Error", "Demasiado largo", auxDescripcion, 200, 2))
                {
                    if(!getValidString("Duracion?", "Error", "Demasiado largo", auxDuracion, 20, 2))
                    {
                        if(!getValidString("Link?", "Error", "Demasiado largo", auxLink, 200, 2))
                        {
                            if(!getValidInt("Puntaje?", "Error", &auxPuntaje, 1, 10, 2))
                            {
                                *ArrayMovie[*qtyMovieActual] = movie_newAlta(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLink);
                                *qtyMovieActual = *qtyMovieActual + 1;
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int movie_Baja(Movie **ArrayMovie, int *qtyMovieActual, int id)
{
    int retorno = -1;
    int i;
    int auxId;
    if(ArrayMovie != NULL && *qtyMovieActual > 0 && id >= 0)
    {
        for(i = 0; i < *qtyMovieActual; i++)
        {
            movie_getId(ArrayMovie[i], &auxId);
            if(auxId == id)
            {
                movie_delete(ArrayMovie[i]);
                retorno = 0;
                break;
            }
        }
    }
    if(i < *qtyMovieActual)
    {
        ArrayMovie[i] = ArrayMovie[*qtyMovieActual];
    }
    *qtyMovieActual = *qtyMovieActual - 1;
    return retorno;
}

int movie_setTitulo(Movie *this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo, titulo);
        retorno = 0;
    }
    return retorno;
}
int movie_getTitulo(Movie *this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        retorno = 0;
    }
    return retorno;
}
int movie_setGenero(Movie *this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero, genero);
        retorno = 0;
    }
    return retorno;
}
int movie_getGenero(Movie *this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        retorno = 0;
    }
    return retorno;
}
int movie_setDuracion(Movie *this, char* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        strcpy(this->duracion, duracion);
        retorno = 0;
    }
    return retorno;
}
int movie_getDuracion(Movie *this, char* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        strcpy(duracion, this->duracion);
        retorno = 0;
    }
    return retorno;
}
int movie_setDescripcion(Movie *this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(this->descripcion, descripcion);
        retorno = 0;
    }
    return retorno;
}
int movie_getDescripcion(Movie *this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion, this->descripcion);
        retorno = 0;
    }
    return retorno;
}
int movie_setLink(Movie *this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(this->link, link);
        retorno = 0;
    }
    return retorno;
}
int movie_getLink(Movie *this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(link, this->link);
        retorno = 0;
    }
    return retorno;
}
int movie_setPuntaje(Movie *this, int puntaje)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}
int movie_getPuntaje(Movie *this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}
static int movie_setId(Movie *this)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        ultimoId++;
        this->idMovie = ultimoId;
        retorno = 0;
    }
    return retorno;
}

static int movie_getId(Movie *this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->idMovie;
        retorno = 0;
    }
    return retorno;
}
