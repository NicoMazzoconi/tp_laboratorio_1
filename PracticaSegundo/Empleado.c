#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"
#include "string.h"
int em_calcularSueldo(void* p, ArrayList* this, int i)
{
    int horas;
    int retorno = -1;
    int sueldo;
    if(p != NULL)
    {
        if(!empleado_getHoras(p, &horas))
        {
            if(horas <= 120)
            {
                sueldo = 180 * horas;
            }
            else
            {
                if(horas <= 160)
                {
                    horas = horas - 120;
                    sueldo = (120 * 180) + (horas * 240);
                }
                else
                {
                    horas = horas - 160;
                    sueldo = (120 * 180) + (40 * 240) + (horas * 350);
                }
            }
            if(!empleado_setSueldo(p, sueldo))
            {
                al_set(this, i, p);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int empleado_getHoras(Empleado* this, int* horas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int empleado_setSueldo(Empleado* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int empleado_setHoras(Empleado* this, int horas)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->horasTrabajadas = horas;
        retorno = 0;
    }
    return retorno;
}
int empleado_getSueldo(Empleado* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
int empleado_setId(Empleado* this, int id)
{
    int retorno = -1;
    static int maximo = -1;
    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
            if(id > maximo)
                maximo = id;
        }
        else
        {
            maximo++;
            this->id = maximo;
            retorno = 0;
        }
    }
    return retorno;
}
int empleado_getId(Empleado* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

Empleado* empleado_new()
{
    return (Empleado*) malloc(sizeof(Empleado));
}
Empleado* empleado_newParametros(char* nombre, int id, int hora, int sueldo)
{
    Empleado* auxEmp = empleado_new();
    if(     !empleado_setHoras(auxEmp, hora)
       &&   !empleado_setId(auxEmp, id)
       &&   !empleado_setSueldo(auxEmp, id)
       &&   !empleado_setNombre(auxEmp, nombre))
    {
        return auxEmp;
    }
    empleado_delete(auxEmp);
    return NULL;
}
void empleado_delete(Empleado* this)
{
    free(this);
}

