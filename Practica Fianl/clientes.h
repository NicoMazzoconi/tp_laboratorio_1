#include "ArrayList.h"
#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct{
    char nombre[64];
    char apellido[64];
    char dni[20];
    int idCliente;
}Clientes;
#endif // CLIENTES_H_INCLUDED

void clientes_delete(Clientes* this);
Clientes* clientes_new();
Clientes* clientes_newParametros(char* nombre, char* apellido, char* dni, int idCliente);
int clientes_setNombre(Clientes* this, char* nombre);
int clientes_getNombre(Clientes* this, char* nombre);
int clientes_setApellido(Clientes* this, char* apellido);
int clientes_getApellido(Clientes* this, char* apellido);
int clientes_setDni(Clientes* this, char* dni);
int clientes_getDni(Clientes* this, char* dni);
int clientes_setIdCliente(Clientes* this, int idCliente);
int clientes_getIdCliente(Clientes* this, int* idCliente);
int clientes_alta(ArrayList* pArrayClientes);
int clientes_baja(ArrayList* pArrayClientes, int id);
int clientes_mod(ArrayList* pArrayClientes, int id);
int clientes_compareLastName(void* pClienteA, void* pClienteB);
