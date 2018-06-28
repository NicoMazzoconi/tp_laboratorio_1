#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int isValidName(char* name);


S_Empleado* Empleado_new()
{
    return (S_Empleado*) malloc(sizeof(S_Empleado));
}

void Empleado_delete(S_Empleado* this)
{
    free(this);
}

S_Empleado* Empleado_newParametros(int id, char* nombre, int horasTrabajadas)
{
    S_Empleado* auxEmp = Empleado_new();
    if(     !Empleado_setNombre(auxEmp, nombre)
       &&   !Empleado_setHorasTrabajadas(auxEmp, horasTrabajadas)
       &&   !Empleado_setId(auxEmp, id))
        return auxEmp;
    Empleado_delete(auxEmp);
    return NULL;
}

int Empleado_setId(S_Empleado* this,int id)
{
    int retorno=-1;
    int maximo = -1;
    if(this!=NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
            if(id > maximo)
            {
                maximo = id;
            }
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

int Empleado_getId(S_Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(S_Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(S_Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Verifica si el empleado trabaja mas de 120 horas
 *
 * \param item void* Empleado a verificar
 * \return int 0 si no las trabaja y 1 si trabajas mas de 120
 *
 */
int em_trabajaMasDe120Horas(void* item)
{
    int retorno = 0;
    if(item != NULL)
    {
        int horas;
        Empleado_getHorasTrabajadas(item, &horas);
        if(horas > 120)
            retorno = 1;
    }
    return retorno;
}

/** \brief Verifica si es un nombre
 *
 * \param name char* cadena de caracteres a verificar
 * \return int 0 si no es, 1 si lo es
 *
 */
static int isValidName(char* name)
{
    int retorno = 0;
    if(name != NULL && esSoloLetras(name) && (strlen(name) > 2))
    {
        retorno = 1;
    }
    return retorno;
}
