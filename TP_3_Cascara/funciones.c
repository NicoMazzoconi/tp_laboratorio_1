#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int funciones_GenerarPaginaWeb(Movie **movie, int *qtyMovieActual, int qtyMovieTotal, char* path)
{
    int retorno = -1;
    int i;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && movie != NULL && qtyMovieTotal > 0 && *qtyMovieActual >= 0 &&  qtyMovieTotal > *qtyMovieActual)
    {
        retorno = 0;
        fprintf(pFile, "<!DOCTYPE html>\n");
        fprintf(pFile, "<!-- Template by Quackit.com -->\n");
        fprintf(pFile, "<html lang='en'>\n");
        fprintf(pFile, "<head>\n");
        fprintf(pFile, "<meta charset='utf-8'>\n");
        fprintf(pFile, "<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile, "<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile, "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile, "<title>Lista peliculas</title>\n");
        fprintf(pFile, "<!-- Bootstrap Core CSS -->\n");
        fprintf(pFile, "<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pFile, "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
        fprintf(pFile, "<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pFile, "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
        fprintf(pFile, "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
        fprintf(pFile, "<!--[if lt IE 9]>\n");
        fprintf(pFile, "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
        fprintf(pFile, "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
        fprintf(pFile, "<![endif]-->\n");
        fprintf(pFile, "</head>\n");
        fprintf(pFile, "<body>\n");
        fprintf(pFile, "<div class='container'>\n");
        fprintf(pFile, "<div class='row'>\n");
        fprintf(pFile, "<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile, "<article class='col-md-4 article-intro'>\n");
        for(i=0;i<*qtyMovieActual;i++)
        {
            movie_getTitulo(movie[i], titulo);
            movie_getGenero(movie[i], genero);
            movie_getDescripcion(movie[i], descripcion);
            movie_getDuracion(movie[i], &duracion);
            movie_getPuntaje(movie[i], &puntaje);
            movie_getLink(movie[i], link);
            fprintf(pFile,"<a href='#'> <img class='img-responsive img-rounded' src='%s' alt=''> </a> <h3> <a href='#'>%s</a> </h3> <ul> <li>Género:%s</li> <li>Puntaje:%d</li> <li>Duración:%d</li> </ul> <p>%s</p>",link,titulo,genero,puntaje,duracion,descripcion);
        }
        fprintf(pFile, "</article>\n");
        fprintf(pFile, "<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile, "</div>\n");
        fprintf(pFile, "<!-- /.row -->\n");
        fprintf(pFile, "</div>\n");
        fprintf(pFile, "<!-- /.container -->\n");
        fprintf(pFile, "<!-- jQuery -->\n");
        fprintf(pFile, "<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pFile, "<!-- Bootstrap Core JavaScript -->\n");
        fprintf(pFile, "<script src='js/bootstrap.min.js'></script>\n");
        fprintf(pFile, "<!-- IE10 viewport bug workaround -->\n");
        fprintf(pFile, "<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pFile, "<!-- Placeholder Images -->\n");
        fprintf(pFile, "<script src='js/holder.min.js'></script>\n");
        fprintf(pFile, "</body>\n");
        fprintf(pFile, "</html>\n");
    }
    fclose(pFile);
    return retorno;
}

int funciones_movieLoad(Movie** movie, int* qtyMovieActual, int qtyMovieTotal, char* path)
{
    int retorno = -1;
    ///////////AUX////////////
    char bTitulo[100];
    char bGenero[50];
    char bDuracion[20];
    char bDescripcion[200];
    char bPuntaje[20];
    char bLink[200];
    char bIdMovie[10];
    ///////////int////////////
    int duracion;
    int puntaje;
    int idMovie;
    //////////////////////////////
    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile != NULL && movie != NULL && qtyMovieTotal > 0 && *qtyMovieActual >= 0 &&  qtyMovieTotal > *qtyMovieActual)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^\n]\n",bTitulo,bGenero,bDuracion,bDescripcion,bPuntaje,bLink,bIdMovie);
            duracion = atoi(bDuracion);
            puntaje = atoi(bPuntaje);
            idMovie = atoi(bIdMovie);
            movie[*qtyMovieActual] = movie_newLoad(bTitulo, bGenero, duracion, bDescripcion, puntaje, bLink, idMovie);
            (*qtyMovieActual)++;
        }
    }
    fclose(pFile);
    return retorno;
}

int funciones_MovieDump(Movie** movie, int* qtyMovieActual, int qtyMovieTotal, char* path)
{
    int retorno = -1;
    int i;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    int idMovie;
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && movie != NULL && qtyMovieTotal > 0 && *qtyMovieActual >= 0 &&  qtyMovieTotal > *qtyMovieActual)
    {
        retorno = 0;
        for(i=0;i<*qtyMovieActual;i++)
        {
            movie_getTitulo(movie[i],titulo);
            movie_getGenero(movie[i],genero);
            movie_getId(movie[i],&idMovie);
            movie_getDescripcion(movie[i], descripcion);
            movie_getDuracion(movie[i], &duracion);
            movie_getLink(movie[i], link);
            movie_getPuntaje(movie[i], &puntaje);
            fprintf(pFile,"%s@%s@%d@%s@%d@%s@%d\n",titulo,genero,duracion,descripcion,puntaje,link,idMovie);
        }
    }
    fclose(pFile);
    return retorno;
}
