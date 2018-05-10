#ifndef PUBLICACIONES_H_INCLUDED
#define PUBLICACIONES_H_INCLUDED
typedef struct
{
    char texto[65];
    int idCliente;
    int rubro;
    int estado;
    //------------
    int idPublicaciones;
    int isEmpty;
}Publicaciones;
#endif // PUBLICACIONES_H_INCLUDED

#include "cliente.h"
int publicaciones_init(Publicaciones* array,int limite);
int publicaciones_buscarPorId(Publicaciones* array,int limite, int id);
int publicaciones_baja(Publicaciones* array,int limite, int id);

int publicaciones_mostrar(Publicaciones* array,int limite);
int publicaciones_mostrarDebug(Publicaciones* array,int limite);
int publicaciones_alta(Publicaciones* array,int limite, Cliente *arrayC, int limiteC);
int publicaciones_modificacion(Publicaciones* array,int limite, int id);
int publicaciones_ordenar(Publicaciones* array,int limite, int orden);
int getValidId(Cliente *arrayC, int limiteC, int *idCliente);
int publicaciones_Pausar(Publicaciones *array, int limite);
int getValidIdPublicacion(Publicaciones *array, int limite, int *idPublicacion, int *indice);
int publicaciones_Estado(Publicaciones *array, int limite, Cliente *arrayC, int limiteC);




