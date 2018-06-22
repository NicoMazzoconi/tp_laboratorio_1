#include "ArrayList.h"
#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

Empleado* empleado_new();
Empleado* empleado_newParametros(char* nombre, int id, int hora, int sueldo);
void empleado_delete(Empleado* this);
int em_calcularSueldo(void* p, ArrayList* this, int i);
int empleado_getHoras(Empleado* this, int* horas);
int empleado_setSueldo(Empleado* this, int sueldo);
int empleado_setHoras(Empleado* this, int horas);
int empleado_getSueldo(Empleado* this, int* sueldo);
int empleado_setNombre(Empleado* this, char* nombre);
int empleado_getNombre(Empleado* this, char* nombre);
int empleado_setId(Empleado* this, int id);
int empleado_getId(Empleado* this, int* id);
#endif // EMPLEADO_H_INCLUDED
